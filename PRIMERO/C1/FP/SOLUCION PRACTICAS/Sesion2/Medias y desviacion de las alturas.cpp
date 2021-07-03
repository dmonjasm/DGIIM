/* Programa para calcular la media aritmetica muestral y la desviación estandar muestral de la altura de tres personas
Se necesita: la edad de tres personas
 					pers1	pers2	pers3
Se obtiene: la media aritmetica muestral y la desviación estandar
					med 									 desv
*/

#include <iostream>		//Se inlcuye la biblioteca iostream
#include <cmath> 			//Se incluye la bilbioteca de operaciones matematicas cmath

using namespace std; 

int main() {
	double pers1;			//Declara las variables de la altura de la persona 1
	double pers2;			// la altura de la persona 2
	double pers3;			//la altura de la persona 3
	double med;				// la media muestral de las alturas
	double desv;			// la desviacion estandar muestral de las alturas

	
	cout << "Introduzca la altura de la persona 1: ";			//Se pide al usuario que introduzca la altura de la persona 1
	cin >> pers1;
	cout << "Introduzca la altura de la persona 2: ";			//Se pide al usuario que introduzca la altura de la persona 2
	cin >> pers2;
	cout << "Introduzca la altura de la persona 3: ";			//Se pide al usuario que introduzca la altura de la persona 3
	cin >> pers3;
	
	med = ((pers1 + pers2 + pers3) / 3);																				//Se declara el algoritmo para calcular la media muestral de las alturas
	desv = sqrt ((pow((pers1 - med),2) + pow ((pers2 - med),2) + pow((pers3 - med),2)) / 3);			//Se declara el algoritmo para calcular la desviacion estandar muestral de las alturas
	
	cout << "La media aritmetica muestral de las alturas es: " << med;							//Se anuncia el resultado de la media aritmetica muestral al usuario
	cout << "\nLa desviacion estandar muestral de las alturas es: " << desv << "\n";			//Se anuncia el resultado de la desviacion estandar muestral al usuario
	
	system("pause");
}
