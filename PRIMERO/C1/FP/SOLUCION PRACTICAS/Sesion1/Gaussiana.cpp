/*Programa para calcular el valor que toma x en la funci�n gaussiana a partir de la media y la desviaci�n t�pica.
Se necesita: la media, la desviaci�n t�pica y el valor de x
                med        desv                  vx
Se obtiene: el valor de 'y' de la funci�n gaussiana
                                          gauss
*/

#include <iostream>  //Declara la biblioteca iostream
#include <cmath>     //Declara la biblioteca de operaciones matematicas

using namespace std;

int main() {
	double med;      //Declara las variables media
	double desv;     //desviaci�n t�pica
	double vx;       //valor de x
	double gauss;
	double paso1;
	
	
	desv = sqrt(0.2);   //Declaro unos valores determinados para la desviaci�n tipica
	med = 0;            //y para la media
	
	
	cout << "Introduza el valor de x: ";
	cin >> vx;
	
   paso1 = (-1 / 2) * pow((vx - med) / desv,2);
   gauss = (1 / (desv * sqrt(2 * M_PI))) * pow(M_E, paso1);
	
	cout << "\nEl valor de la funcion gaussiana en x= " << vx << " es: " << gauss << "\n";
	
	system("pause");
}
