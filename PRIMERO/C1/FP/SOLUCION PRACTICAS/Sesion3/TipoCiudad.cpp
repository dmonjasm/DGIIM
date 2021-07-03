/*Programa que pida el nombre de dos ciudade y su situacion en abscisas y ordenadas.
Se necesita: nombre y situación.
					nombre_1 nombre_2 / situacion_1 situacion_2
Se obtiene:la concatenacion de ambos nombre y el producto de sus situaciones.
					nombre_final						situacion_3
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath
#include <string>				//Se declara la biblioteca de cadenas de caracteres string

using namespace std;

struct TipoPunto{			//Declara la estructura TipoPunto
	double abscisa;
	double ordenada;
};
struct TipoCiudad{		//Declara la estructura TipoCiuad
	TipoPunto situacion;
	string nombre;
};

int main() {
	TipoCiudad ciudad_1, ciudad_2, ciudad_3;				//Declaro las variables de tipo ciudad que se utilizaran
	
	cout << "Introduzca el nombre de la ciudad 1: ";							//Se pide al usuario el nombre de la ciudad 1 y se guarda
	cin >> ciudad_1.nombre;
	cout << "\nIntroduzca el valor de abscisas de la ciudad 1: ";			//Se pide al usuario la situacion de la ciudad 1 en abscisas y se guarda
	cin >> ciudad_1.situacion.abscisa;
	cout << "\nIntroduzca el valor de ordenadas de la ciudad 1 : ";		//Se pide al usuario la situacion de la ciudad 1 en ordenadas y se guarda
	cin >> ciudad_1.situacion.ordenada;
	cout << "\nIntroduzca el nombre de la ciudad 2: ";							//Se pide al usuario el nombre de la ciudad 2 y se guarda
	cin >> ciudad_2.nombre;
	cout << "\nIntroduzca el valor de abscisas de la ciudad 2: ";		//Se pide al usuario la situacion en abscisas de la ciudad 2 y se guarda
	cin >> ciudad_2.situacion.abscisa;
	cout << "\nIntroduzca el valor de ordenadas de la ciudad 2: ";		//Se pide al usuario la situacion en odenadas de la ciudad 2 y se guarda
	cin >> ciudad_2.situacion.ordenada;
	
	ciudad_3.nombre = ciudad_1.nombre + ciudad_2.nombre;															//Se declara el algoritmo para obtener el nombre de la ciudad 3
	ciudad_3.situacion.abscisa = ciudad_1.situacion.abscisa * ciudad_2.situacion.abscisa;				//Se declara el algoritmo para obtener la situacion en abscisas de la ciudad 3
	ciudad_3.situacion.ordenada = ciudad_1.situacion.ordenada * ciudad_2.situacion.ordenada;			//Se declara el algoritmo para obtener la situacion en ordenadas de la ciudad 3
	
	cout << "El nombre de la ciudad 3 es: " << ciudad_3.nombre << "\n";										//Se anuncia en pantalla el nombre de la ciudad 3 y la situacion 
	cout << "La situacion en abscisas de la ciudad 3 es: " << ciudad_3.situacion.abscisa << "\n";	//en ordenadas y abascisas de la ciudad 3
	cout << "La situacion en ordenadas de la ciudad 3 es: " << ciudad_3.situacion.ordenada << "\n\n";
	
	system("pause");
}
