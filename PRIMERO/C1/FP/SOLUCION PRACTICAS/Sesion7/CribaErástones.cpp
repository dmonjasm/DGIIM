/*Para obener una lista de todos los números primos menores que un determinado
numero n se puede utlizar la Criba de Eratóstenes, metodo que consiste en hacer
una lista de todos los números desde 2 haste n-1. Tomamos el 2 y tachamos todos 
los múltiplos de 2. Luego tomamos el siguiente número que se encuentra después
de 2 y que esté sin tachar, tachando de nuevo todos sus múltiplos. Repetimos hasta 
que se acaben los números. Los numeros que queden sin tachar son los que no tienen 
divisores. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	int vector[LONGITUD];
	int numero;
	bool primo[LONGITUD];
	
	cout << "Introduzca un numero del que calcularemos los primos menores que el: ";
	cin >> numero;
	
	for (int i = 2; i < numero; i++){			//Inicio un bucle for que almacene todos los valores entre 2 y el numero - 1 en un vector
		vector[i] = i;
		primo[i] = true;								//Al mismo tiempo se da a todos los valores de un vector de tipo bool el valor verdadero
	}
	
	for (int j = 2; j < numero; j++){			//Se inicia un bucle for en el que si el valor del vector es distinto de dos
		if (vector[j] != 2){
			for(int m = 2; (m < vector[j])&&(primo[j] == true); m++){			//Divide ese valor entre los numeros menores que el y en caso de que el resto de la division sea cero
				if ((vector[j] % m) != 0)													//a el vector bool se le asigna el valor false en esa posicion
					primo[j] = true;
				else
					primo[j] = false;
				}
			}
		else							//Si el vector es igual a dos se le considera primo directamente
			primo[j] = true;
	}
				
	cout << "\nLos primos menores que el numero introducido son: ";
	
	for (int l = 2; l < numero; l++){			//Se inicia un bucle for que muestre solo los valores del vector que tienen asociado un valor true en el vector booleano
		if (primo[l])
			cout << vector[l] << " ";	
	}
	cout << "\n";
	
	system("pause");
}	
