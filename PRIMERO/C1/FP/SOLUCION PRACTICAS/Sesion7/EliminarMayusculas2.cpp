/*Progama que utilize dos variables que nos digan en cada momento la componente
que se está leyendo y el sitió donde tiene que escribirse.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	char posicion_lectura[LONGITUD], posicion_escritura[LONGITUD];
	int amplitud, j = 0, contador = 0;
	
	cout << "Introduzca la amplitud del vector: ";
	cin >> amplitud;
	
	for (int i = 0; i < amplitud; i++){
		cout << "\nIntroduzca las componentes del vector: ";			//Se inicia un bucle for que toma los valores del vector posicion_lectura
		cin >> posicion_lectura[i];								
		
		if ((posicion_lectura[i] <= 'z')&&(posicion_lectura[i] >= 'a')){   //Despues se inicia un condicional en el que si el valor de posicion de lectura en una posición i
			posicion_escritura[j] = posicion_lectura[i];							 //Es una letra mayucula posición escritura toma ese valor, y se aumenta en uno la posición de 
			j++;																				 //posicion de escritura y de posición de lectura, y el valor del contador, con el cual pretendemos 
			contador++;																		 //saber la amplitud del vector posicion de lectura
		}
	}
	
	cout << "\nEl vector eliminando las mayúsculas es: ";
	
	for (int k = 0; k < contador; k++){				//Se muestran en pantalla los resultados.
		cout << posicion_escritura[k] << " ";
	}
	
	cout << "\n";
	
	system("pause");
}
	
