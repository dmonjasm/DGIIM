/*Programa para pasar un caracter introducido por el usuario en mayuscula a 
minúscula mediante la equivalencia entre caracteres y enteros*/

#include <iostream>		//Se introduce la biblioteca de E/S iostream

using namespace std;

int main() {
	char caracter;			//Se declaran las variables que van a ser utilizadas
	
	cout << "Introduzca un caracter en mayusculas: ";			//Se pide al usuario que introduzca un caracter en mayusculas
	cin >> caracter;														//Se guarda el caracter introducido por el usuario
	
	caracter = caracter + 32;			//Al valor del caracter en la tabla ASCII le sumo 32 ya que entre toda letra mayuscula y su minuscula hay una diferencia de 32
	
	cout << caracter << "\n\n";		//Muestra el resultado
	
	system("pause");
	
}
	
