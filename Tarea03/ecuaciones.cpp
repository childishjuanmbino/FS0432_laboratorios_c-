#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

std::vector<double> lorenz(std::vector<double>& r, double sigma, double rho, double beta)
{
	double x = r[0];
	double y = r[1];
	double z = r[2];
	std::vector<double> L(3);
	L[0] = sigma*(y-x);
	L[1] = x*(rho-z) - y;
	L[2] = x*y - beta*z;
	return L;
}


std::vector<std::vector<double>> euler(double t0, double tf, double h, double x0, double y0, double z0)
{
int N = static_cast<int>((tf - t0) / h) + 1;

std::vector<std::vector<double>> r(N, std::vector<double>(3));

	r[0][0] = x0;
	r[0][1] = y0;
	r[0][2] = z0;
	for(int n = 1; n < N; n++)
	{	
	std::vector<double> F = lorenz(r[n-1], 10, 28, 8/3);
	r[n][0] = r[n-1][0] + h*F[0];
	r[n][1] = r[n-1][1] + h*F[1];	
	r[n][2] = r[n-1][2] + h*F[2];
	}
	return r;
}

std::vector<std::vector<double>> rk2 (double t0, double tf, double h, double x0, double y0, double z0)
{

int N = static_cast<int>((tf - t0) / h) + 1;

std::vector<std::vector<double>> r(N, std::vector<double>(3));


        r[0][0] = x0;
        r[0][1] = y0;
        r[0][2] = z0;
	for(int n = 0; n < N; n++)
	{
	std::vector<double> k1 = lorenz(r[n], 10, 28, 8/3);
	std::vector<double> k2 = lorenz(r[n] + rescalar(k1, h/2), 10, 28, 8/3);
        r[n][0] = r[n][0] + h*k2[0];
        r[n][1] = r[n][1] + h*k2[1];
        r[n][2] = r[n][2] + h*k2[2];
        }
        return r;
}

std::vector<double> rescalar(std::vector<double> v, double m)
	{
		std::vector<double> u(v.size())
		for (size_t n = 0; n <= v.size(); n++)
	{
	u[n] = v[n] * m;
	}
	return u;
	}
std::vector<std::vector<double>> rk4 (double t0, double tf, double h, double x0, double y0, double z0)
{

int N = static_cast<int>((tf - t0) / h) + 1;

std::vector<std::vector<double>> r(N, std::vector<double>(3));


        r[0][0] = x0;
        r[0][1] = y0;
        r[0][2] = z0;
        for(int n = 0; n < N; n++)
        {
        std::vector<double> k1 = lorenz(r[n], 10, 28, 8/3);
        std::vector<double> k2 = lorenz(r[n] + rescalar(k1, h/2), 10, 28, 8/3);
	std::vector<double> k3 = lorenz(r[n] + rescalar(k2, h/2), 10, 28, 8/3);
	std::vector<double> k4 = lorenz(r[n] + rescalar(k3, h), 10, 28, 8/3);


        r[n][0] = r[n][0] + (h/6)*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
        r[n][1] = r[n][1] + (h/6)*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);
        r[n][2] = r[n][2] + (h/6)*(k1[2] + 2*k2[2] + 2*k3[2] + k4[2]);
        }
        return r;
}


PYBIND11_MODULE(ecuaciones, m)
{
    m.def("euler", &euler);
    m.def("rk2", &rk2);
    m.def("rk4", &rk4);
}
