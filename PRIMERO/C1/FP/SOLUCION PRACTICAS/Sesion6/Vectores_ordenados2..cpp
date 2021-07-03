/*Programa que una dos vectores ordenados y den lugar a un tercer vector 
también ordenado que es la unión de ambos.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	int vector1[LONGITUD], vector2[LONGITUD], vector3[LONGITUD];
	int amplitud1, amplitud2, amplitud3;
	int i = 0, valor = 0, l = 0;
	
	cout << "Introduzca la amplitud del vector 1: ";
	cin >> amplitud1;
	cout << "Introduzca la amplitud del vector 2: ";
	cin >> amplitud2;
	
	amplitud3 = amplitud1 + amplitud2;
	
	
	
	if ((amplitud1 > LONGITUD)||(amplitud2 > LONGITUD))			//Codicional que muestra un mensaje de erro si la amplitud de alguno de los vectores es mayor que la memoria reservada
		cout << "\nError: la amplitud introducida para alguno de los vectores supera a la memoria reservada.";
		
	else {
		for (int i = 0; i < amplitud1; i++){				//Bucle for que toma los valores del vector 1 
			cout << "Introduzca los valores del vector 1: ";
			cin >> vector1[i];
		}
		for (int j = 0; j < amplitud2; j++){				//Bucle for que toma los valores del vector 2
			cout << "Introduzca los valores del vector 2: ";
			cin >> vector2[j];
		}
		
	for (int i = 0; 0 < amplitud1; i++){			//Bule for en el que si el vector1 en la posición i es mayor o igual que el vector2 en la posicion valor se de al primer elemento del  
																// vector 3 el valor del vector 2 en la posicion valor y se pasa a la siguiente posición del vector 
		if (vector1[i] >= vector2[valor]){
			vector3[l] = vector2[valor];
			l++;
			do{				//Se inicia un bucle do while en el que si al aumentar el valor de valor el vector2 en la posicion valor sigue siendo menor que el vector 1 en la posicion 
				valor++;		//i se le asigne al segundo valor del vector 3 el valor del vector 2 en su posición valor
				if (vector1[i] > vector2[valor]){
					vector3[l] = vector2[valor];
					l++;
				}
				else{			//Si vector 1 en su posición i es menor que el vector 2 en posición valor se asigna a vector tres en su posición l el valor del vector 1 en i
					vector3[l] = vector1[i];
					l++;
				}
			}while (vector1[i] > vector2[valor]);			//este bucle se repite siempre que el vector1 en su posición i sea mayor que el vector 2 en su posición valor
		}
			else{			//Si vector1 en su posición i es mayor que vecor 2 en su posición valor directamente se asigna a vector3 en su posición l el valor de vector1 en su posición i
				vector3[l] = vector1[i];
				l++;
			}
		}			//Basicamente el bucle for compara los elementos del vector 1 y del vector 2 y los situa en el vector 3 ordenandolos de menor a mayor
	}	
		for (int m = 0; vector3[m] < 100; m++)			//Se muestran los valores de vector3 que sean menor que 100 ordenadamente
			cout << vector3[m] << " ";
			
		system("pause");
	}
	
	/*Por alguna razón cuando en el bucle for que muestra los resultados no termina de funcionar*/
	
	
				
				
					
				
					
