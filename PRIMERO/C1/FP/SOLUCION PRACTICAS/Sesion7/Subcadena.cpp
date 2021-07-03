/*Programa que dada una cadena de caracteres y dos posicionesdentro de la cadena,
x e y, devuelva otra cadena con los caracteres comprendidos entre las componentes
x e y (inclusiv).
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int LONGITUD = 200;
	char vector[LONGITUD], resultado[LONGITUD];
	int amplitud, x , y, k = 0, contador = 0;
	
	cout << "Introduzca la amplitud del vector que va a utilizar: ";
	cin >> amplitud;
	
	
	cout << "\nIntroduzca los componentes del vector de caracteres: ";
	
	for (int i = 0; i < amplitud; i++){				//Se inicia un bucle for que tome los valores del vector
		cin >> vector[i];
	}
	
	cout << "\nIntroduzca la posición a partir de la cual quiere cortar el vector: ";
	cin >> x;
	cout << "\nIntroduzca la posición hasta la cual quiere cortar el vector: ";
	cin >> y;
	
	for (int j = (x-1); j <= (y-1); j++){			//Se inicia un bucle for que asigne los valores entre la posición x e y a un valor resultado
		resultado[k] = vector[j];						//a la vez que aumenta en uno el valor del contador para medir la ampllitud del vector resultado
		k++;
		contador++;
	}
	
	cout << "\nEl vector resultado es: ";
	
	for (int l = 0; l < contador; l++){			//Se muestra en pantalla el resultado
		cout << resultado[l] << " ";
	}
	
	cout << "\n";
	
	system("pause");
}
	
	
