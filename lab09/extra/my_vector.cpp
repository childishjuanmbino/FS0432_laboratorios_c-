#include <iostream>
	
class Vector	
{

	private:
		double* elem;
		int _size;

	public:
		Vector(const int size)
		{
			elem = new double[size];
			_size = size;
		}	
	
~Vector()
{
	std::cout << "Esto es una llamada al destructor" << std::endl;
	delete[] elem;
}

int size()
{
	return _size;
}

double& operator[](const int i)
{
	return elem[i];
}


};
int main()
{
	Vector v{10};
	
	std::cout << v.size() << std::endl;
	
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i*1.0;
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
}

