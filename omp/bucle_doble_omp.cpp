#include <iostream>
#include <omp.h>
#include <vector>

int main(){
	int suma = 0;
	int N = 1000;
	int M = 1000;
	
	std::vector<double> A(N, 1.0);
	std::vector<double> B(N, 2.0);
	std::vector<double> C(N);
	
	double start_time = omp_get_wtime();
	
	#pragma omp parallel for collapse(2) reduction(+ : suma)
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= M; j++){
			suma += (i + j);
		}
	}
	
	double end_time = omp_get_wtime();
	
	std::cout << "Suma: " << suma << std::endl;
	std::cout << "Tiempo de ejecucción: " << (end_time - start_time)
		<< " segundos" << std::endl;

	return 0;
}
