#include <iostream>
#include <omp.h>
#include <vector>

int main(){

	int N = 1000000;
	
	std::vector<double> A(N, 1.0);
	std::vector<double> B(N, 2.0);
	std::vector<double> C(N);
	
	double start_time = omp_get_wtime();
	
	#pragma omp parallel for
	for (int i = 0; i < N; i++){
		C[i] = A[i] - B[i];
	}
	
	double end_time = omp_get_wtime();
	
	std::cout << "Tiempo de ejecucción: " << (end_time - start_time)
		<< " segundos" << std::endl;

	return 0;

}
