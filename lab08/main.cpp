#include <iostream>
#include <numbers>
#include <cmath>
#include "funciones.h"
#include "integracion.h"
	

int main(){

int n;
double pi = std::acos(-1.0);

std::cout << "Ingrese el numero de intervalos: " << std::endl;
std::cin >> n;


double* x = new double[n];

double* f = new double[n];

double h = 1.0 / n;

for (int i = 0; i < n; i++)
{
	x[i] = i * h;
	f[i] = funcion(x[i]);
}



std::cout << "Por metodo de trapecio compuesto: " << trapecio(f, n, h) << std::endl;
std::cout << "Por metodo de simpson: " << simpson(f, n, h) << std::endl;
std::cout << "El valor exacto de pi: " << pi << std::endl;
std::cout << std::endl;
std::cout << "El valor absoluto del metodo del trapecio compuesto: " << std::abs(pi - trapecio(f, n, h)) << std::endl;
std::cout << "El error absoluto del metodo de Simpson: " << std::abs(pi - simpson(f, n, h)) << std::endl;
delete[] x;
delete[] f;
}

