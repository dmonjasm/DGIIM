#include <iostream>
#include <cmath>

using namespace std;
/* Funcion void que tiene como parametros un vector y una amplitud, y que devuelve dos vectores
uno que contiene los numeros pares del vector parametro y otro que contiene los numeros impares*/
void VectorSalida(int vector[], int amplitud){
	const int LONGITUD = 200;
	int pares[LONGITUD], impares[LONGITUD];
	int contador_pares = 0, contador_impares = 0;
	
	/*Bucle for que comprueba uno por uno los elementos del vector parametro, para ver si son pares o impares,
	y en funcion de lo que sean los almacena en el vector de los pares o en el de los impares */
	for(int i = 0; i < amplitud; i++){
		if((vector[i] % 2) == 0){
			pares[contador_pares] = vector[i];
			contador_pares++;
		}
		else{
			impares[contador_impares] = vector[i];
			contador_impares++;
		}
	}
	
	cout << "\nLos numeros pares pertenecientes al vector introducido son: ";
	for(int i = 0; i < contador_pares; i++){
		cout << pares[i] << " ";
	}
	
	cout << "\nLos numeros impares pertenecientes al vector introducido son: ";
	for(int j = 0; j < contador_impares; j++){
		cout << impares[j] << " ";
	}
}

int main() {
	const int LONGITUD = 200;
	int vector[LONGITUD];
	int amplitud;
	
	cout << "\nIntroduzca la amplitud del vector de enteros: ";
	cin >> amplitud;
	
	/*Bucle for que tome los elementos que componen un vector de enteros */
	cout << "\nIntroduzca los elementos del vector de enteros: ";
	for (int i = 0; i < amplitud; i++){
		cin >> vector[i];
	}
	
	VectorSalida(vector, amplitud);
	cout << "\n";
	
	system("pause");
}

	
	
