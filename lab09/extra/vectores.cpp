/*

pybind11: Enlazando C++ con Python
----------------------------------

pybind11 es una biblioteca de C++ que permite
crear enlaces entre C++ y Python. Esto facilita
aprovechar la velocidad y eficiencia de C++ 
mientras se mantiene la facilidad de uso de Python.

Equivalencias entre tipos de datos en Python y C++:
---------------------------------------------------

Python <-> C++:
list <-> std::vector
str <-> std::string
dict <-> std::map
int <-> int
float <-> double

Instalación de pybind11:
------------------------

conda activate Fis-Comp
pip install pybind11

Compilación de la librería C++:
-------------------------------

g++  vectores.cpp \
-O3 -Wall -shared -std=c++17 -fPIC \
$(python3 -m pybind11 --includes) \
-o vectores$(python3-config --extension-suffix)

*/


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <iostream>

namespace py = pybind11;



double producto_punto(const std::vector<double>& a, const std::vector<double>& b)
{
	double result = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		result += a[i] * b[i];
	}
	return result;
}

std::vector<double> sumar_vectores(const std::vector<double>& a, const std::vector<double>& b)
{
	std::vector<double> result(a.size());
	for (size_t i = 0; i < a.size(); i++)
	{
		result[i] = a[i] + b[i];
	}
	std::cout << "Suma de vectores desde c++" << std::endl;
	return result;
}

std::vector<double> resta_vectores(const std::vector<double>& a, const std::vector<double>& b)
{
        std::vector<double> result(a.size());
        for (size_t i = 0; i < a.size(); i++)
        {
                result[i] = a[i] - b[i];
        }
        std::cout << "Resta de vectores desde c++" << std::endl;
	return result;
}

PYBIND11_MODULE(vectores, m)
{
	m.def("producto_punto", &producto_punto);
	m.def("sumar_vectores", &sumar_vectores);
	m.def("resta_vectores", &resta_vectores);
}

















