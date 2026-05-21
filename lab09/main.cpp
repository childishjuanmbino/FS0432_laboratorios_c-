#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

double f(double x, double t)
{
	return -x + std::sin(t);
}

double exacta(double t)
{
	 return (0.5*(std::sin(t) - std::cos(t)) + 1.5*std::exp(-t));
}

void euler(std::vector<double>& t,
           std::vector<double>& x_num,
           std::vector<double>& x_ex,
           std::vector<double>& error,
           double t0,
           double tf,
           double h)
{
int N = static_cast<int>((tf - t0) / h);


double x = 1.0;
double tiempo = t0;


	for(int n = 1; n <= N; n++)
	{	
	t.push_back(tiempo);
	x_num.push_back(x);
	
	x_ex.push_back(exacta(tiempo));
	
	error.push_back(std::abs(x - exacta(tiempo)));
	
	x = x + h * f(x, tiempo);
	tiempo += h;
	}
}

int main()
{
	std::vector<double> t;
	std::vector<double> x_num;
	std::vector<double> x_ex;
	std::vector<double> error;


	double t0 = 0.0;
	double tf = 10.0;
	double h = 0.1;

	euler(t, x_num, x_ex, error, t0, tf, h);
	

	std::cout << std::fixed << std::setprecision(6);

	std::cout << "t\tEuler\t\tExacta\t\tError\n";
	for (size_t i = 0; i < t.size(); i++)
	{
		std::cout << t[i] << "\t" << x_num[i] << "\t" << x_ex[i] << "\t" << error[i] << "\n";
	}

	std::cout << "Error maximo:" << std::abs(*max_element(error.begin(), error.end())) << std::endl;

	plt::plot(t, x_num, {{"label", "Euler"}} );
        plt::plot(t, x_ex, {{"label", "Exacta"}} );

      	plt::title("Aproximacion");
        plt::xlabel("Tiempo");
        plt::ylabel("Valor");

        plt::legend();
        plt::grid(true);
        plt::show();

	plt::plot(t, error, {{"label", "Error"}} );

        plt::title("Error Absoluto vs tiempo");
        plt::xlabel("Tiempo");
        plt::ylabel("Error Absoluto");

        plt::legend();
        plt::grid(true);
        plt::show();
}

