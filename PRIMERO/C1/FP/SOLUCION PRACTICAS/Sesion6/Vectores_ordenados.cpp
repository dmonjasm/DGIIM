
/*Programa que lea desde teclado dos vectores ordenados y que los una
dando lugar a un tercer vector que tenga los elementos de los otros dos vecotres
estando el tercer vector ordenado.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 20;
	int vector_1[LONGITUD],vector_2[LONGITUD], vector_3[LONGITUD];
	int amplitud_1, amplitud_2, amplitud_3;
	int i = 0, j = 0, desplazar;
	
	cout << "Introduzca la amplitud del vector 1: ";
	cin >> amplitud_1;
	cout << "\nIntroduzca la amplitud del vector 2: ";
	cin >> amplitud_2;
	
	amplitud_3 = amplitud_1 + amplitud_2;
	
	if ((amplitud_1 > LONGITUD)||(amplitud_2 > LONGITUD)){		//Establezco un condicional que devuelva erros si la amplitud de alguo de los vectores es mayor al espacio reservado
		cout << "\nError: la amplitud de alguno de los vectores es mayor que la memoria reservada para ellos.";
	}
	else{
		cout << "\nIntroduzca los valores del vector 1: ";
		for (i = 0; i < amplitud_1; i++){		//Inicio un bucle for para dar valor a los elementos del vector 1 y a los primero elementos del vector 3
			cin >> vector_1[i];
			vector_3[j] = vector_1[i];
			j++;
		}
		cout << "\nIntroduzca los valores del vector 2: ";
		for (i = 0; i < amplitud_2; i++){		//Inicio un bucle for para dar valor a los elementos del vector 2 y a los ultimos elementos del vector 3
			cin >> vector_2[i];
			vector_3[j] = vector_2[i];
			j++;
		}
		
		for (int izqda = 1; izqda < amplitud_3; izqda++){ 		//Inicio un bucle que contiene otro bucle for dentro de si mismo 
			desplazar = vector_3[izqda];								//el segundo bucle da a un elemento del vector el valor de su anterior si el anterior es mas pequeño.
																				//y lo repite nuevamente hasta llegar al primer elemento del vector
														
			for (i = izqda; i > 0 && desplazar < vector_3[i -1]; i--)
				vector_3[i] = vector_3[i-1];
			
			vector_3[i] = desplazar;								
		}
	}
		
		for (int i = 0; i < amplitud_3; i++)					//Se establece un bucle que muestre los elementos del vector
			cout << vector_3[i] << " ";
			
		system("pause");
	}
			
