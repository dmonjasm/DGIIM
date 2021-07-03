/*Programa para calcular el valor que toma x en la función gaussiana a partir de la media y la desviación típica.
Se necesita: la media, la desviación típica y el valor de x
                med        desv                  vx
Se obtiene: el valor de 'y' de la función gaussiana
                                          gauss
*/

#include <iostream>  //Declara la biblioteca iostream
#include <cmath>     //Declara la biblioteca de operaciones matematicas

using namespace std;

int main() {
	double med;      //Declara las variables media
	double desv;     //desviación típica
	double vx;       //valor de x
	double gauss;
	double paso1;
	
	
	desv = sqrt(0.2);   //Declaro unos valores determinados para la desviación tipica
	med = 0;            //y para la media
	
	
	cout << "Introduza el valor de x: ";
	cin >> vx;
	
   paso1 = (-1 / 2) * pow((vx - med) / desv,2);
   gauss = (1 / (desv * sqrt(2 * M_PI))) * pow(M_E, paso1);
	
	cout << "\nEl valor de la funcion gaussiana en x= " << vx << " es: " << gauss << "\n";
	
	system("pause");
}
