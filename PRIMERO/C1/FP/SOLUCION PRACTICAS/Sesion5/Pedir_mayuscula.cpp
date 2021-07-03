/*Programa que lea un caracter desde obligando al usuario que sea una letra mayuscula
Calcula la letra minuscula correspondiente y la imprime en pantalla. 
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	const int DIST_MAY_MIN = 'A' - 'a';					//Establecemos la constante entera que existe entra 'A' y 'a'			
	char letra_introducida, letra_transformada;		//Establecemos las variables de tipo caracter que se leera desde teclado y que se mostrará en pantalla una vez transformada en minuscula
	
	do {																	//Se inicia un bucle que ejecuta un bloque, y si después de ejecutar dicho bloque se cumple la condición while se termina, si no se repite
		cout << "Introduzca una letra mayuscula: ";			//Se pide al usuario que introduzca una letra mayuscula
		cin >> letra_introducida;									//Se guarda dicha letra
		
}while ((letra_introducida < 'A')||(letra_introducida > 'Z'));			//Si la letra introducia es menor que el valor asociado a 'A' o mayor que el valor asociado a 'Z' se vuelve a ejecutar el bloque

letra_transformada = letra_introducida - DIST_MAY_MIN;					//Se establece el algoritmo para transformar la letra introducida en minúscula

cout << "\nLa letra minuscula correspondiente a la letra mayuscula introducida es: " << letra_transformada << "\n\n";		//Se muestra el resultado en pantalla

system("pause");
}
	
