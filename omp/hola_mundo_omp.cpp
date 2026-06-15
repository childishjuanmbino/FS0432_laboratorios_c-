#include <iostream>
#include <omp.h>

int main(){

	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		int num_threads = omp_get_num_threads();
		std::cout << "hola desde hilo: " << tid
			<< " de " << num_threads
			<< " " << std::endl;
			}
			
	return 0;
			}
