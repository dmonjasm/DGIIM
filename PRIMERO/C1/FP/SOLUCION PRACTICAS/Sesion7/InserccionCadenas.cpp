/*Construir programa que inserte una cadena de caracteres dentro de otra
cadena, en una determniada posición
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	char vector1[LONGITUD], vector2[LONGITUD], vector3[LONGITUD];
	int amplitud1, amplitud2, posicion, contador = 0;
	
	cout << "Introduzca la amplitud del vector 1: ";
	cin >> amplitud1;
	cout << "\nIntroduzca la amplitud del vector 2: ";
	cin >> amplitud2;
	
	cout << "\nIntroduzca las componentes del vector 1: ";
	for (int i = 0; i < amplitud1; i++){			//Se inicia un bucle for que tome las componentes del vector 1
		cin >> vector1[i];
	}
	
	cout << "\nIntroduzca las componenetes del vector 2: ";
	for (int j = 0; j < amplitud2; j++){			//Se inicia un bucle for que tome las componentes del vector 2
		cin >> vector2[j];
	}
	
	cout << "\nIntroduzca la posicion en la que quiere insertar el vector 2: ";
	cin >> posicion;
	
	for (int k = 0; k < posicion; k++){				//Se inicia un bucle for que da a un vector 3 las componentes del vector 1 hasta la posicion indicada por el usuario
		vector3[k] = vector1[k];
	}
	for (int l = posicion; l < (amplitud2 + posicion); l++){			//Se inicia un bucle for que inserta el vector 2 en la posicion dada por el usuario
		vector3[l] = vector2[contador];
		contador++;
	}
	
	contador = posicion;
	for (int m = (posicion + amplitud2); m < (amplitud1 + amplitud2); m++){			//Se inicia un bucle for que inserta las componentes del vector 1 tras insertar el vector 2
		vector3[m] = vector1[contador];
		contador++;
	}
	
	cout << "\nEl vector resultado es: ";
	
	for (int n = 0; n < (amplitud1 + amplitud2); n++){			//Se inicia un bucle for que muestre los resultados
		cout << vector3[n] << " ";
	}
	
	cout << "\n";
	
	system("pause");
}
	


		
	
		
