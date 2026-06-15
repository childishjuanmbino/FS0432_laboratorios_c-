#include <iostream>
#include <omp.h>
#include <vector>

int main(){
	int suma = 0;
	int N = 10000;
	
	std::vector<double> A(N, 1.0);
	std::vector<double> B(N, 2.0);
	std::vector<double> C(N);
	
	double start_time = omp_get_wtime();
	
	#pragma omp parallel for
	for (int i = 0; i <= N; i++){
		suma += i;
	}
	
	double end_time = omp_get_wtime();
	
	std::cout << "Suma: " << suma << std::endl;

	return 0;
}
