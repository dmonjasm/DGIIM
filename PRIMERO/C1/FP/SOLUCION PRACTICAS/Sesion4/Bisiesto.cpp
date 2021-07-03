/*Programa que lea un año introducido por el usuario y diga si es bisiesto o no
Se necesita: año
					year
Se obtiene: si es bisiesto o no
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	int year;
	bool bisiesto;
	
	cout << "Introduzca un anio: ";
	cin >> year;
	
	bisiesto = (((year % 4) == 0)&&((year % 100) != 0))||((year % 400) == 0);
	
	if (bisiesto)
		cout << year << " es bisiesto.\n\n";
	
	else 
		cout << "\n" << year << " no es bisiesto,\n\n";
		
	system("pause");
	
}
