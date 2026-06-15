#include <iostream>
#include <omp.h>
#include <vector>

int main(){

	int N = 10000;
	
	std::vector<double> A(N, 1.0);
	std::vector<double> B(N, 2.0);
	double producto_punto;
	
	double start_time = omp_get_wtime();
	
	#pragma omp parallel for reduction(+ : producto_punto)
	for (int i = 0; i <= N; i++){
		producto_punto += A[i] * B[i];
	}
	
	double end_time = omp_get_wtime();
	
	std::cout << "El resultado del producto punto: " << producto_punto << std::endl;

	return 0;

}
