/*Programa que a partir del ejercicio 14 calcule cuantos años had de pasar hasta llegar a 
doblar, como mínimo, el capital inicial. 
*/

#include <iostream>			//Se declara la biblioteca de E/S isotream
#include <cmath>				//Se declara la biblioteca de operacones matematicas cmath

using namespace std;

int main() {
	double capital_inicial, interes_anual;			//Se declaran las variables capital_inicial e interes_anual
	double capital_general;								//Se declara la variable que se usará para calcular el incremento del capital inicial anualmente
	int anios;												//Se declara la variable entera anios que servirá como contador en el bucle
	
	cout << "Introduzca le capital inicial que ha sido depositado: ";			//Se pide al usuario el valor del capital inicial depositado
	cin >> capital_inicial;			//Se guarda el valor introducido por el usuario
	cout << "\nIntroduzca el interes anual que se aplicara: ";					//Se pide al usuario el valor del interes anual a aplicar
	cin >> interes_anual;			//Se gaurda el valor introducido por el usuario
	
	capital_general = capital_inicial;			//Como queremos conservar el valor del capital inicial pasamos su valor a otra variable que sera la que usemos para calcular el incremento de capital
	anios = 0;											//Como anios será el contador en el bucle le asignamos el valor cero
	
	do {													//Se establece un bucle que ejecute el siguiente bloque hasta que se deje de cumplir la condición establecida en el while
		capital_general = capital_general + (capital_general * (interes_anual / 100));			//Se establece el algoritmo para calcular el incremento de capital cada año
		anios++;											//Se aumenta en uno el valor de la variable anios
	}while (capital_general < (2 * capital_inicial));														//Se repetira el bucle hasta que el capital general sea igual o mayor que el doble del capital inicial
	
	cout << "Transcurriran " << anios << " hasta que el capital sea el doble, como mínimo, del capital incial depositado.\n";		//Se muestran los años transcurridos por pantalla
		
	system("pause");
}
		
