/*Programa para calcular el �rea y la longitud de una circunferencia a partir del radio
Se necesita: radio
             rad
Se obtiene: area y longitud
            are    longt
*/

#include <iostream>   //Declara la biblioteca iostream
#include <cmath>      //Declara la biblioteca de operaciones matem�ticas

using namespace std;

int main() {
	double rad;    //Declara las variables que se utilizar�n: radio,
	double are;    //area
	double longt;   //y longitud
	
	cout << "Introduzca el valor del radio: ";
	cin >> rad;
	
	are = M_PI * pow(rad,2);
	longt = 2 * M_PI * rad;
	
	
	cout << "\nEl valor del area es: " << are << "\n";
	cout << "\nEl valor de la longitud es: " << longt << "\n\n";
	
	
	system("pause");
}
