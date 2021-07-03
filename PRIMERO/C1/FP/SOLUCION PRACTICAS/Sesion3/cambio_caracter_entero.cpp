/*Programa que pase un caracter a un numero entero y que imprima el valor que queremos.
*/

#include <iostream>

using namespace std;

int main() {
	int entero;				//Declaro la variable de tipo int entero
	char caracter;			//Declaro la variable de tipo char caracter
	
	cout << "Introduzca un entero comprendido entre el 1 y el 9: ";		//Pido al usuario que introduzca un valor entero entre 1 y 9
	cin >> caracter;																		//El sistema almacena dicho valor en función de su valor en la tabla ASCII
	
	entero = caracter - 48;				//Introduzco el algoritmo que transformará el caracter introducido por el usuario en un entero
	
	cout << entero << "\n\n";			//Muestro el resultado en pantalla
	
	system("pause");
}
