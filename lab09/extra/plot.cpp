#include <vector>
#include <cmath>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


int main()
{
	std::vector<double> x;
	std::vector<double> y1;
	std::vector<double> y2;


double PI = std::acos(-1);

for(double t = 0.0; t <= 2*PI; t += 0.01)
{
	x.push_back(t);
	y1.push_back(std::sin(t));
	y2.push_back(std::cos(t));
}

	plt::plot(x, y1, {{"label", "sin(x)"}} );
	plt::plot(x, y2, {{"label", "cos(x)"}} );

	plt::title("Funciones Trigonometricas");
    	plt::xlabel("x");
    	plt::ylabel("y");

    	plt::legend();
    	plt::grid(true);
    	plt::show();

    return 0;
    }

