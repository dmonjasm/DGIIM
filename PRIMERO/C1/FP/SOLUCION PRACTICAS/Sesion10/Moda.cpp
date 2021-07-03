#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};
/* Se establece una funcion que calcule la moda de un vector de caracteres */
void Moda(string cadena, int amplitud){
	const int LONGITUD = 200;
	char letra[LONGITUD];
	int frecuencia[LONGITUD];
	int contador = 1, contador_frecuencia = 0;
	bool no_iguales = true;
	int maximo, posicion = 0;
	FrecuenciaCaracter resultado;
	
	/*Se almacenan los elementos del vector en otro vector cuyos elementos no se repitan*/
	letra[0] = cadena[0];
	for(int i = 1; i < amplitud; i++){
		
		for(int j = i - 1; (j >= 0)&&(no_iguales); j--){
			if(cadena[i] != letra[j])
				no_iguales = true;
			else	
				no_iguales = false;
			}
			
		if(no_iguales){
			letra[contador] = cadena[i];
			contador++;
		}	
	}
	
	/*Se calcula el numero de veces que aparece cada letra del vector letras en el primer vector y se almacena en otro vector frecuencia */
	for(int i = 0; i < contador; i++){
		
		for(int j = 0; j < amplitud; j++){
			if(letra[i] == cadena[j])
				contador_frecuencia++;
			}
			
		frecuencia[i] = contador_frecuencia;
		contador_frecuencia = 0;
	}
	
	/*Se almacena el maximo del vector en la variable maximo y la posicion del maximo en la variable vector */
	maximo = frecuencia[0];
	for(int i = 0;  i < contador; i++){
		if(frecuencia[i] > maximo){
			maximo = frecuencia[i];
			posicion = i;
		}
	}
			
	
	/*Se da a la variable resultado el elemento del vector letra cuya posicion coincide con el maximo y lo mismo con la frecuencia */	
	resultado.caracter = letra[posicion];
	resultado.frecuencia = frecuencia[posicion];
	
	cout << "\nEl caracter mas frecuente es, " << resultado.caracter << " con " << resultado.frecuencia << " apariciones.\n";	
}

int main() {
	int amplitud;
	string cadena;
	
	cout << "\nIntroduzca los elementos de la cadena: ";
	getline(cin, cadena);
	
	amplitud = cadena.size();
	
	Moda(cadena, amplitud);
	
	system("pause");
}	
