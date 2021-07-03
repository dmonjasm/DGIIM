/*Programa que modifique un vector, eliminando todas las repeticiones de un
mismo valor*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	int vector[LONGITUD];
	int amplitud;
	
	cout << "Introduzca la amplitud del vector: ";
	cin >> amplitud;
	
	for (int i = 0; i < amplitud; i++){				//Se establece un bucle for para pedir los valores del vector hasta la amplitud dada por el usuario
		
		cout << "\nIntroduzca los valores del vector: ";
		cin >> vector[i];
		
	}
	
	for (int i = 0; i < amplitud; i++){			//Se inicia un bucle for que tiene dentro otro bucle for, el primer bucle da un valor del vector y en el segundo este se compara
															//con todos los demas elementos del vector, al terminar la comparación se aumente en uno el valor del vector y se vuelve a comparar
		for (int j = i+1; j < amplitud; j++){	//en el segundo bucle y asi sucesivamente
			
			if (vector[i] == vector[j]){			//Cuando se tiene que dos valores del vector en posiciones distintas son iguales, se elimina uno de ellos que sustituye su valor por 
															//por el de la siguiente posición
				vector[j] = vector[j+1];

		}
			else
				vector[j] = vector[j];
			}
		}
		
	cout << "\nEl vector resultante eliminando las repeticiones es: \n";

	for (int k = 0; vector[k] < 100; k++){			//Se inicia un bucle for que vaya mostrando los valores del vector que son menor que un cierto valor, para evitar
																//los exagerados numeros que se obtiene de aquellas posiciones que están vacías
		cout << vector[k] << " ";
		
	}
	
	system("pause");
}
				
