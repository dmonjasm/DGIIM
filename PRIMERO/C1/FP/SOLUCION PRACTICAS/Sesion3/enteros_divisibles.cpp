/*Programa que lea dos valores enteros introducidos por el usuario y que diga si cualquiera
de ellos divide al otro o no de forma entra.(No hace falta decir quien divide a quien).
*/

#include <iostream>			//Declaro la biblioteca de E/S iostream
#include <cmath>				//Declarao la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	int entero_1, entero_2;					//Declaro las variables de tipo int que introducira el usuario
	int division_1, division_2;			//Declaro las variables que diran si un numero divide al otro o no
	
	
	cout << "Introduzca un valor entero: ";			//Se pide al usuario que introduzca un valor entero
	cin >> entero_1;											//Se guarda dicho valor como entero_1
	cout << "Introduzca otro valor entero: ";			//Se pide al usuario que introduzca un valor entero
	cin >> entero_2;											//Se guarda dicho valor como entero_2
	
	division_1 = entero_1 % entero_2;			//Declaro el algoritmo con el que calculo si entero_2 divide de forma entera a entero_1
	division_2 = entero_2 % entero_1;			//Declaro el algortimo con el que calculo si entero_1 divide de forma entera a entero_"
	
	if ( (division_1 == 0) || (division_2 == 0))										//Establezco una condición 
		cout << "Uno de los enteros divide al otro de forma entera\n\n";		//Si la condición establecida se cumple se mostrara en pantalla este mensaje
		
	else 																											//Establezco unas acciones en caso de que no se cumpla la condición if
		cout << "Los enteros no son divisibles entre ellos de forma entera\n\n";			//Si no se cumple la condicion if muestra en pantalla este mensaje
		
	
	system("pause");
}
	
	
