/*Programa para calcular las distancias que ha recorrido dos locomotoras que circulan por la misma via
a dos velocidades definidas por el usuarioy una distancia tambien definida por el usuario, antes de colisionar.
Se necesita: velocidad de la locomotora 1, velocidad de la locomotora 2 y la distancia que las separa
											V1					V2										D
Se obtiene: el tiempo en el que colisionaran
						t
*/

#include <iostream> 
#include <cmath>

using namespace std;

int main() {
	double Velocidad1;			//Se declaran la variables de a velocidad de la locomotora 1
	double Velocidad2;			//la velocidad de la locomotora 2
	double Distancia_total;			//la distancia que separa las estaciones
	double distancia1;			//la distancia recorrida por la locomotora 1 antes de colisionar
	double distancia2;			//la distancia recorrida por la locomotora 2 antes de colisionar
	double tiempo;			//el tiempo que ha pasado
	
	
	cout << "Introduzca la velocidad de la locomotora 1: ";					//Se pide al usuario que introduzca la variable V1
	cin >> Velocidad1;
	cout << "Introduzca la velocidad de la locomotora 2: ";					//Se pide al usuario que introduzca la variable V2
	cin >> Velocidad2;
	cout << "Introduzca la distancia que separa ambas estaciones: ";		//Se pide al usuario que introduzca la variable D
	cin >> Distancia_total;
	
	tiempo = Distancia_total / (Velocidad1 + Velocidad2);		//Se declara el algoritmo para calcular el tiempo transcurrido antes de colisionar
	distancia1 = Velocidad1 * tiempo;				//Se declara el algoritmo para calcular la distancia recorrida por la locomotora 1
	distancia2 = Velocidad2 * tiempo;				//Se declara el algoritmo para calcular la distancia recorrida por la locomotora 2
	
	cout << "La distancia que ha recorrido la locomotora 1 antes de colisionar es: " << distancia1;							//Se muestran en pantalla los resultados para la locomotora 1
	cout << "\nLa distancia que ha recorrido la locomotora 2 antes de colisionar es: " << distancia2 << "\n\n";			//Se muestran en pantalla los resultados para la locomotora 2
	
	system("pause");
}
	
	
