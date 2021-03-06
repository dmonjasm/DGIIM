/*Programa que lea una secuencia que codifica un n?mero entero y devuleva
el n?mero entero.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int entero, primo, contador_ceros, dato;
	string secuencia;
		secuencia = "\nIntroduzca una secuencia o un numero (1 o 0): ";
		entero = 1;
		primo = 0;

		
	do {				//Se inicia un bucle do while en el que se ejecuta un bloque y luego si se cumple la condici?n de que el contador de ceros sea distinto de cinco se repite hasta
						//que la condici?n se deje de cumplir
		cout << secuencia;
		cin >> dato;
		
		if (dato == 1){			//Se establece un condicional en el que si el dato es igual a uno asigne a contador_ceros el valor cero y aumente en una unidade el valor de primo
			contador_ceros = 0;
			primo++;
		}
		else 							//Si el dato es distinto de uno y a la vez es igual a cero y primo es distinto de cero se establece el algoritmo para calcular el entero, se asigna
			if ((dato == 0)&&(primo != 0)){			//a primo el valor cero y se aumenta en una unidad el valor 0
				entero = primo * entero;
				primo = 0;
				contador_ceros++;
			}
			else{					//Si el dato es distinto de cero, primo es igual a cero o ambas a la vez se asigna a primo el valor cero y se aumenta en uno el contador de ceros.
				primo = 0;
				contador_ceros++;
			}
		
	
		
		}while (contador_ceros != 5);
		
		cout << "El numero entero asociado a la secuencia es: " << entero << "\n";
		
		system("pause");
	}
		
