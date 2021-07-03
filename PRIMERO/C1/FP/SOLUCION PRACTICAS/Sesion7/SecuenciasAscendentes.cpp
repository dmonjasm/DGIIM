/*Programa que calcule el número de secuencias ascendentes de un vector 
de enteros
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	int vector[LONGITUD];
	int amplitud, minimo, secuencia = 1;
	
	
	cout << "Introduzca la amplitud del vector: ";
	cin >> amplitud;
	
	for (int i = 0; i < amplitud; i++){								//Se inicia un bucle for que tome los valores de las componentes del vector
		cout << "\nIntroduzca las componentes del vector: ";
		cin >> vector[i];
	}

	for (int j = 0; j < amplitud; j++){				//Se inicia un bucle for que compare cada posición del vector con su siguiente
		if (vector[j] <= vector[j + 1])			//Se establece un condicional en el que si el vector en una posicion es menor que le vector en su posicion siguiente
			secuencia = secuencia;					//la variable secuencia mantenga su valor
		else
			secuencia++;				//Si no el valor de la variable secuencia aumenta en uno.
		}
	
	cout << "\nEl numero de secuencias ascendentes es: " << secuencia << "\n";
		
	
	system("pause");
}

