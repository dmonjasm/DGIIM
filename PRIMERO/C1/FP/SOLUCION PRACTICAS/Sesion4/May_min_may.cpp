/*Programa que pase una letra mayuscula introducida por el usuario en minuscula, una letra minuscula
introducida por el usuario en mayuscula y almacene un caracter no alfab�tico en una variable.
*/

#include <iostream> 			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matem�ticas cmath

using namespace std;

int main() {
	char letra_original, letra_convertida;			//Se declaran las variables de tipo caracter que usaremos
	const int DISTANCIA_MAY_MIN = 'a' - 'A';		//Se declara la constante para pasar de mayuscula a minscula y vicerversa
	

	cout << "Introduzca un caracter: ";			//Se pide al usuario que introduzca un caracter cualquiera
	cin >> letra_original;			//Se guarda dicho caracter
	
	
	if ((letra_original >= 'A')&&(letra_original <= 'Z'))				//Se establece un condicional para ver si el caracter es una letra mayuscula
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;		//Si se cumple la condici�n establecida se realiza la siguiente operaci�n
		
	else {																			//Si la condici�n establecida anteriormente no se cumple se ejecuta el siguiente bloque
		if ((letra_original >= 'a')&&(letra_original <= 'z'))			//Se establece otra condici�n para comprobar si la letra es minuscula
			letra_convertida = letra_original - DISTANCIA_MAY_MIN;	//Si se cumple la condici�n establecida se ejecuta la siguente operacion
			
		else 																			//Si la condici�n para ver si la letra es minuscula no se cumple se ejecuta el siguiente bloque
			letra_convertida = letra_original;								//Se ejecuta la siguiente operaci�n
	}
		

	cout << "\nSu caracter convertido es: " << letra_convertida << "\n\n";				//Se anuncia el resultado en pantalla
	
	system("pause");
}
