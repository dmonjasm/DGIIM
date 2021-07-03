/*Programa que encuentra la subsecuencia de numeros ordenada, de menor a mayor,
de mayor longitud contenida en una secuencia de numeros introducida por el usuario.
El programa debe decir la posición donde empieza la subsecuencia y su longitud.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int secuencia, menor, inicio;
	int contador, longitud;
	int mayor_longitud, menor_inicio;
	
	cout << "Introduzca una secuencia de enteros: ";
	cin >> secuencia;
	
	contador = 1;
	menor = secuencia;
	longitud = 1;
	inicio = contador;
	menor_inicio = inicio;
	mayor_longitud = longitud;
	
	while ((secuencia < 101)&&(secuencia > -1)){				//Se inicia un bucle while que se ejecute siempre que secuencia sea menor que 101 y mayor que -1
		
		cout << "\nIntroduzca una secuencia de enteros: ";
		cin >> secuencia;
		contador++;
		
		if ((secuencia < 101)&&(secuencia > -1)){				//Se establece la condición de que el bloque solo se ejecute cuando secuencia es menor que 101 y mayor que -1
																			//para evitar que se tomen en cuenta estos numeros a la hora de buscar la mayor subsecuencia
			if ((secuencia > menor)||(secuencia == menor)){			//Se establece el condicional en el que si secuencia es mayor o igual que el valor de menor 
				menor = secuencia;											//le asigne a menor el valor de secuencia
				longitud++;														//aumente en uno el valor de longitud
				if (longitud > mayor_longitud){				//Dentro del condicional se establece otro condicional en el que si longitud es mayor que mayor_longitud
					mayor_longitud = longitud;					//le asigne a mayor_longitud el valor e longitud y a menor_inicio el valor de inicio
					menor_inicio = inicio;
			}
				else
					mayor_longitud = mayor_longitud;			//sino mayor_longitud mantiene su valor
					menor_inicio = menor_inicio;
			}
			else {						//Si el primer condicional no se cumple implica que secuencia es menor estricto que menor y entonces
				inicio = contador;	//la variable inicio toma el valor del contador
				menor = secuencia;	//menor toma el valor del nuevo dato de secuencia
				longitud = 1;			//y a longitud se le da el valor de 1
		}
	}
}
	
	cout << "La mayor subsecuencia dentro de la secuencia introducida empieza en " << menor_inicio << " y tiene una longitud de " << mayor_longitud << "\n";
	
	system("pause");
}
