#include "integracion.h"

double trapecio(double* f, int n, double h){
	double sum = 0;
	for (int i = 1; i < n-1; i++){
		sum += f[i];
	}
	return (h/2.0)*(f[0]+ 2.0*sum + f[n]);
}


double simpson(double* f, int n, double h){
	double sumpar = 0;
	double sumimpar = 0;
	if (n % 2 ==0) {
		for (int i = 1; i < n -1; i++)
			if (i % 2 == 0){
				sumpar += f[i];
			}
			else{
			sumimpar += f[i];
			}
		return (h/3.0)*(f[0] + 4.0*sumimpar + 2.0*sumpar + f[n]);
	}
	else{
	return 0.0;
	}
}


