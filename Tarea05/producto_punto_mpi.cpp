#include <iostream>
#include <mpi.h>
#include <cmath>
#include <vector>

double f(double x) { return std::sin(x); }

int main(int argc, char **argv) {

	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	const int N = 128000;
	
	
	std::vector<double> A(N);
	std::vector<double> B(N);
	
	
	int local_N = N / size;
	
	std::vector<double> local_A(local_N);
	std::vector<double> local_B(local_N);
	
	int inicio = rank * local_N;
	int fin = (rank + 1) * local_N;
	
	double t0 = MPI_Wtime();
	
	
	if (rank == 0) {
		for (int i = 0; i < N; i++) {
			A[i] = f((double)i);
			B[i] = 2 * f((double)i);
		}
		for (int i = 0; i < local_N; i++) {
			local_A[i] = A[i];
			local_B[i] = B[i];
		}
		for (int p = 1; p < size; p++) {
		int start = p* local_N;
		
		MPI_Send(&A[start], local_N, MPI_DOUBLE, p, 0, MPI_COMM_WORLD);
		MPI_Send(&B[start], local_N, MPI_DOUBLE, p, 1, MPI_COMM_WORLD);
		}
	}
	else {
	MPI_Recv(&local_A[0], local_N, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    	MPI_Recv(&local_B[0], local_N, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
            }
       
       
	double suma_local = 0.0;
	
	for (int i = 0; i < local_N; i++) {

    		double prod = local_A[i] * local_B[i];

    suma_local += prod;
}
	
	//for (int i = inicio; i < fin; i++)
	//{
	//	suma_local += local_A[i] * local_B[i];
	//}
	
	
	double suma_global = 0.0;
	
	
	
	MPI_Reduce(&suma_local, &suma_global, 1 , MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 
	
	
	
	double t1 = MPI_Wtime();
	
	if (rank == 0) {
		std::cout << "El resultado del producto punto es: " << suma_global << std::endl;
		std::cout << "El tiempo de ejecucion: " << (t1- t0) << "s" << std::endl;
	}	
	MPI_Finalize();
	return 0;
}


