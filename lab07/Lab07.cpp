#include <iostream>

void imprimir(double* notas, int numNotas){
	
        for (int i = 0; i < numNotas; i++)
        {
        std::cout << "Nota[" << i << "] = " << notas[i] <<" " << std::endl;
        }
}

void calificacion(double* notas, int numNotas, int& reprobados, int& sobresalientes, int& aprobados){
	
	for (int i = 0; i < numNotas; i++)
		if (notas[i] >= 90)
		{
			sobresalientes++;
		}
		else if (notas [i] >= 67.5)
		{
		aprobados++;
		}
		else 
		{
		reprobados++;
		}

	std::cout << "Sobresalientes: " << sobresalientes << std::endl;
	std::cout << "Aprobados: " << aprobados << std::endl;
	std::cout << "Reprobados:" << reprobados << std::endl;

}

void maxmin(double* notas, int numNotas){
	double max = 0;
	double min =100;
	for (int i = 0; i < numNotas; i++){
		if (notas[i] > max)
		{
		       max = notas[i];
		}
		if (notas[i] < min)
		{
			min = notas[i];
		}
	}
	std::cout << "La nota maxima es: " << max << std::endl;
	std::cout << "La nota minima es: " << min << std::endl;
}

int main() {
	double notas[10];
	double nota = 0;
	int i = 0;
	int numNotas = 10;
	int sobresalientes = 0;
	int aprobados = 0;
	int reprobados = 0;
	do
	{	
		std::cout << "Ingrese su nota: ";
		std::cin >> nota;
		if (nota == -1)
		{
			break;
		}
		else if (nota > 100.0)	
		{
			continue;
		}
		else if (nota < 0.0)
		{	
			continue;
		}
		else
		{
		notas[i] = nota;
		}	
		i++;
	} while(nota != -1);
	
	imprimir(notas, numNotas);
	calificacion(notas, numNotas, reprobados, sobresalientes, aprobados);	
	maxmin(notas, numNotas);
}
