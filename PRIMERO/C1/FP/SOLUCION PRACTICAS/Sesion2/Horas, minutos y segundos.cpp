/*Programa que lea tres variables (horas, minutos y segundos) y que calcule estos mismos pero en su rango correspondiente.
Se necesita: horas, minutos y segundos.
					hor	min		seg
Se obtienen: horas, minutos y segundos ordenados.
					hor2	min2		seg2
*/

#include <iostream>		//Se declara la biblioteca iostream
#include <cmath>			//Se declara la biblioteca de operaciones matemáticas cmath

using namespace std;

int main() {
	int hor, min, seg;					//Declara las variables que se van a introducir
	int hor2, min2, seg2, dias2;		//Declara las variables que se van a obtener

	
	cout << "Introduzca el valor de las horas: ";			//Introduce la variable hor
	cin >> hor;
	cout << "Introduzca el valor de los minutos: ";			//Introduce la variable min	
	cin >> min;
	cout << "Introduzca el valor de los segundos: ";		//Introduce la variable seg
	cin >> seg;
	
	
	seg2 = seg % 60;							//Introduzco el algoritmo para calcular los segundos
	min2 = (min % 60) + (seg / 60);		//Introduzco el algoritmo para calcular los minutos
	hor2 = (hor % 24) + (min / 60);		//Introduzco el algoritmo para calcular las horas
	dias2 = (hor / 24);						//Introduzco el algoritmo para calcular los dias
	
	cout << "\nDentro de su rango el valor es de: " << dias2 << " dias " << hor2 << " horas " << min2 << " minutos y " << seg2 << " segundos.\n";
	
	
	system("pause");
}
