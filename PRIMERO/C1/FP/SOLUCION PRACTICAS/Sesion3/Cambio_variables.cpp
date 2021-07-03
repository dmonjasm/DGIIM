/*Programa para intercambiar el valor de tres variables x, y y z.
Se necesita: tres variables y una auxiliar.
				x	y	z						aux
Se obtiene: tres variables con sus valores cambiados.
*/

#include <iostream>			//Incluyo la biblioteca de E/S iostream
#include <cmath>				//Incluyo la biblioteca de operaciones matematicas cmath
#include <string> 			//Incluyo la biblioteca de cadenas de caracteres string


using namespace std;


int main() {
	string resultado;
			resultado = "El nuevo valor de";			//Declaro una cadena de caracteres que se repetira varias veces
	int x, y, z, aux;			//Declaro las variables que se van a utilizar en el programa.
			x = 10;				//Les asigno valores a las variables
			y = 20;				//declaradas según el enunciado
			z = 30;				//del problema
		
			
	aux = x;			//Declaro las siguientes igualdades
	x = z;			//con las cuales cambiaré el valor
	z = y;			//de las distintas variables declaradas
	y = aux;			//anteriormente.
	
	
	cout << resultado << " x es: " << x << "\n";		//Anuncio por pantalla el valor de x tras el intercambio de valores
	cout << resultado << " y es: " << y << "\n";		//Anuncio por pantalla el valor de y tras el intercambio de valores
	cout << resultado << " z es: " << z << "\n";		//Anuncio por pantalla el valor de z tras el intercambio de valores
	
	system("pause");
}
