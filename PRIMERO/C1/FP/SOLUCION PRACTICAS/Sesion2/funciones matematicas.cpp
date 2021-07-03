/*Programa que introduciendo las variables necesarias aplique una serie de 
algoritmos.
Se necesita: un valor de x, un valor de y, un valor de h
							x					y					h
Se obtiene: unos resultados a, b y c tras aplicar los algoritmos
									 a  b   c
*/

#include <iostream>			//Se declara la biblioteca iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	double x, y, h;											//Declara las variables x, y, h
	double formula_1, formula_2, formula_3;			//Declara las variables formulas que contendran los algoritmos a utilizar
	double pot1, pot2, pot3;								//Declara las variables pot que se usaran para almacenar algunas cuantas de los algoritmos para reducir su longitud
	
	
	cout << "Introduzca un valor de x: ";			//Se pide al usuario un valor para x
	cin >> x;
	cout << "Introduzca un valor de y: ";			//Se pide al usuario un valor para y
	cin >> y;
	cout << "Introduzca un valor de h: ";			//Se pide al usuario un valor para h
	cin >> h;
	
	pot1 = (pow(x,2) / y);									//Se declara un algoritmo para pot1
	pot2 = (pow(x,3) / (1 + y));							//Se declara un algoritmo para pot2
	pot3 = (pow(M_E,x) / pow (x,2));						//Se declara un algoritmo para pot3
	formula_1 = (1 + pot1) / pot2;												//Se declara el alguritmo 1
	formula_2 = (1 + (sin(h) / 3) - (cos(h) / 7)) / (2 * h);				//Se declara el algoritmo 2
	formula_3 = sqrt(1 + pow(pot3,2));											//Se declara el algoritmo 3
	
	
	cout << "El valor de a tras aplicar el algoritmo 1 es: " << formula_1;						//Se anuncia en pantalla el resultado del algoritmo 1
	cout << "\nEl valor de b tras aplicar el algoritmo 2 es: " << formula_2;					//Se anuncia en pantalla el resultado del algoritmo 2
	cout << "\nEl valor de c tras aplicar el algoritmo 3 es: " << formula_3 << "\n\n";		//Se anuncia en pantalla el resultado del algoritmo 3
	
	
	system("pause");
}
