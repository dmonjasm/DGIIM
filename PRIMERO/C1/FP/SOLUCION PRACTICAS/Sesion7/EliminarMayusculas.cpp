/*Programa que modifique un vector de caracteres eliminando las mayúsculas
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	char vector[LONGITUD], mayusculas[LONGITUD];
	bool minusculas[LONGITUD];
	int amplitud, l = 0, contador = 0;
	
	cout << "Introduzca la amplitud del vector: ";
	cin >> amplitud;
	
	for (int i = 0; i < amplitud; i++){							//Inicio un bucle for para guardar los componentes del vector 
		cout << "\nIntroduzca los valores del vector: ";	//y que al mismo tiempo identifique y guarde en un vector de tipo bool
		cin >> vector[i];												//que componentes son mayusculas y cuales minusculas
		
		if ((vector[i] <= 'Z')&&(vector[i] >= 'A'))
			minusculas[i] = false;
		else{
			minusculas[i] = true;
			contador++;
		}
		}
		
		
	
	for (int k = 0; k < amplitud; k++){				//Se inicia otro bucle for en el que cuando el vector minusculas tenga valor true se asigna al vector mayusculas 
		if (minusculas[k]){								//el valor que vector tiene en esa posicion
			mayusculas[l] = vector[k];
			l++;
		}
	}
	
	cout << "El vector tras eliminar las mayusculas es: ";
	for (int m = 0; m < contador; m++){								//Se muestra en pantalla el resultado
		cout << mayusculas[m] << " ";
	}
	
	cout << "\n";
	
	system("pause");
}
		
	
	
