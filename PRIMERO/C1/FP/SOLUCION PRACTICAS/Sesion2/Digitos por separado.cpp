/*Programa que muestre los dígitos de un numero entero (en este caso siempre de tres cifras) por separado.
Se necesita: un numero entero
						ent
Se obtiene: las cifras del numero entero por separado
						a b c
*/

#include <iostream>		//Se declar a la biblioteca iostream
#include <cmath> 			//Se declara la biblioteca de operaciones matemáticas cmath

using namespace std;

int main() {
	int ent;			//Declaro las variables que se 
	int a;			//van a utilizar en el 
	int b;			//algoritmo y la que se va 
	int c;			//a pedir al usuario
	
	cout << "Introduzca un numero entero: ";
	cin >> ent;
	
	a = (ent / 100);									  	//Introduzco el algoritmo para calcular el digito de las centenas
	b = (ent - (a * 100)) / 10;						//Introduzco el algoritmo para calcular el digito de las decenas
	c = (ent - (a * 100) - (b * 10)) / 1;			//Introduzco el algoritmo para calcular el digito de las unidades
	
	cout << "\nLos digitos del numero entero son: " << a << " " << b << " " << c << "\n";		//Muestro el valor de los digitos por separado
	
	system("pause");
}
