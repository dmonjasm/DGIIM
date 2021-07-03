/*Pograma que compruea si dos matrices son iguales.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int FILAS = 100;
	const int COLUMNAS = 100;
	int matriz1[FILAS][COLUMNAS], matriz2[FILAS][COLUMNAS];
	int fila1, columna1, fila2, columna2;
	bool iguales = true;
	
	cout << "Introduzca el numero de filas de la matriz 1: ";
	cin >> fila1;
	cout << "\nIntroduzca el numero de filas de la matriz 2: ";
	cin >> fila2;
	cout << "\nIntroduzca el numero de columnas de la matriz 1: ";
	cin >> columna1;
	cout << "\nIntroduzca el numero de columnas de la matriz 2: ";
	cin >> columna2;
	
	if ((fila1 != fila2)||(columna1 != columna2))			//Se establece un condicional en el que si las filas de la matriz 1 y 2 no son iguales o las columnas no son iguales muestre error
		cout << "\nLas matrices 1 y 2 no pueden ser iguales puesto que tienen distinto numero de filas o distinto numero de columnas.\n";			//y el programa termina
	
	else{				//si son iguales el progama continua
	cout << "\nIntroduzca los valores de la matriz 1 por filas: ";
	for(int i = 0; i < fila1; i++){						//Se inicia un bucle for que tome los valores de las filas y las columnas de la matriz 1
		for(int j = 0; j < columna1; j++){
			cin >> matriz1[i][j];
		}
	}
	
	cout << "\nIntroduzca los valores de la matriz 2 por filas: ";
	for(int i = 0; i < fila2; i++){						//Se inicia un bucle for que tome los valores de las filas y las columnas de la matriz 2
		for(int j = 0; j < columna2; j++){
			cin >> matriz2[i][j];
		}
	}
	
	for(int i = 0; i < fila1 && iguales == true; i++){
		for(int j = 0; j < columna1 && iguales == true; j++){			//Se inicia un bucle for que compare los valores que se encuentran en la misma posicion en la matriz 1 y la 2
			if (matriz1[i][j] == matriz2[i][j])								//si algun valor no coincide se le asigna el valor false a la variable iguales y se para el bucle
				iguales = true;
			else
				iguales = false;
			}
		}
	
	if (iguales == true)														//Si una vez terminado el bucle la variable iguales tiene asignado el valor true las matrices son iguales
		cout << "\nLas matrices 1 y 2 son iguales.\n";
	else																			//sino las matrices son disintas
		cout << "\nLas matrices 1 y 2 no son iguales.\n";
	}	
	system("pause");
}	
