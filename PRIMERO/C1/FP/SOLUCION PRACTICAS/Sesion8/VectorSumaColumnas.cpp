/*Programa que tenga como entrada una mariz de reales y produzca como salida
un vectro con la suma de los elementos de cada fila.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int FILAS = 100;
	const int COLUMNAS = 100;
	int matriz[FILAS][COLUMNAS], vector[FILAS], suma_filas[FILAS];
	int fila, columna;
	
	cout << "Introduzca el numero de filas de la matriz: ";
	cin >> fila;
	cout <<  "\nIntroduzca el numero de columnas de la matriz: ";
	cin >> columna;
	
	cout << "\nIntroduzca los componentes de la matriz por filas: \n";
	for(int i = 0; i < fila; i++){				//Se inicia un bucle for que tome los valores de la matriz
		for(int j = 0; j < columna; j++){
			cin >> matriz[i][j];
		
		}
	}
	
	/*Se inicia un bucle for que calcule la suma de los elementos de cada fila de la matriz */
	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			suma_filas[i] = suma_filas[i] + matriz [i][j];
		}
	}
	
	/*Se inicia un bucle for que muestre el valor de la suma de los elementos de cada fila */
	cout << "\nEl vector resultado de la suma de las filas es: ";
	for(int i = 0; i < fila; i++){
		cout << suma_filas[i] << " ";
	}

	for (int j = 0; j < columna; j++){				//Se inicia un bucle for que a cada posición del vector le asigne el valor de la suma de los elementos de cada columna de la matriz
		for(int k = 0; k < fila; k++){
			vector[j] = vector[j] + matriz[k][j];
			
		}
	}
	
	cout << "\nEl vector resultado de la suma de las columnas es: ";			//Se inicia un bucle for que muestra los resultados
	for(int i = 0; i < columna; i++){
		cout << vector[i] << " ";
	}
	cout << "\n";	
	system("pause");
}
