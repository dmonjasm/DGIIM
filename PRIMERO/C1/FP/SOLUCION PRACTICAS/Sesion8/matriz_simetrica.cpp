#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int FILAS = 200;
	const int COLUMNAS = 200;
	const int AMPLITUD = 1000;
	double matriz[FILAS][COLUMNAS], matriz2[FILAS][COLUMNAS];
	int filas, columnas, amplitud2, filas_viceversa;
	double vector[AMPLITUD], vector2[AMPLITUD];
	int contador = 0;
	int contador_vector = 0;
	int suma = 0;
	
	
	cout << "Introduzca el numero de filas de la matriz: ";
	cin >> filas;
	cout << "\nIntroduzca el numero de columnas de la matriz: ";
	cin >> columnas;
	
	if(filas != columnas)
		cout << "\nLa matriz introducida no es cuadrada.\n";
	else{
		/*Bucle for que calcula los valores de la matriz simetrica. */
		cout << "\nIntroduzca los valores de la matriz simetrica: ";
		for(int i = 0; i < filas; i++){
			for(int j = 0;j < columnas; j++){
				cin >> matriz[i][j];
			}
		}
		
		/*Bucle for que asigna a un vector los valores de la matriz simetrica de la diagonal
		principal y lo que estan por debajo de esta */
		for(int i = 0; i < filas; i++){
			for(int j = 0;(j <= i); j++){
				vector[contador] = matriz[i][j];
				contador++;
			}
		}
		
		/*Bucle for que muestra los resultados en forma de vector*/
		cout << "\nEl vector de la matriz es: ";
		for (int i = 0; i < contador; i++){
			cout << vector[i] << " ";
		}
	}
	cout << "\n";
	
	cout << "\nIntroduzca la amplitud del que va a introducir: ";
	cin >> amplitud2;
	
	cout << "\nIntroduzca un vector para calcular la matriz asociada a dicho vector: ";
	for(int i = 0; i < amplitud2; i++){
		cin >> vector2[i];
	}
	
	/*Establezco un bucle for que calcule el numero de filas y columnas de la matriz simetrica asociada al vector*/
	for(int i = 1; (i < amplitud2)&&(suma != amplitud2); i++){
		filas_viceversa = i;
		suma = suma + i;
	}
	
	for(int i = 0; i < amplitud2; i++){
		cout << vector[i] << " ";
	}
	
	/*Establezco un bucle for que establezca la matriz asociada al vector*/
	for(int i = 0; i < filas_viceversa; i++){
		for(int j = 0; j <= i; j++){
			matriz2[i][j] = vector[contador_vector];
			matriz2[j][i] = vector[contador_vector];
			contador_vector++;
		}
	}
	
	/*Establezco un bucle for que muestre en pantalla la matriz simetrica asociada al vector*/
	cout << "\nLa matriz asociada al vector introducido es: ";
	for(int i = 0; i < filas_viceversa; i++){
		for(int j = 0; j < filas_viceversa; j++){
			cout << matriz2[i][j] << " ";
		}
		cout << "\n";
	}
	
	system("pause");
}	
