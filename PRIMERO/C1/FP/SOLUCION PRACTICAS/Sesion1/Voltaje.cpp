/*Programa para hallar el voltaje empleando la fórmula de la ley de Ohm.
Se necesita: intensidad y resistencia
             intens       resis
Se obtiene: voltaje
            vol
*/

#include <iostream>   //Se incluye la biblioteca E/S
#include <cmath>      //Se incluye la biblioteca de operaciones matemáticas

using namespace std;

int main() {
	double vol;       //Declara las variables para
	double intens;    //guardar la intensdad, la resistencia
	double resis;     //y el voltaje
	
	cout << "Introduzca el valor de la intensidad: ";   //Se pide un valor para intens y se guarda
	cin >> intens;
	cout << "Introduzca el valor de la resistencia: ";  //Se pide un valor par resis y se guarda
	cin >> resis;
	
	vol = intens * resis; //Introduzco el algoritmo por el cual se obtiene el voltaje
	
	cout << "n\El valor del voltaje es: " << vol << "\n";
		
	system("pause");
}
