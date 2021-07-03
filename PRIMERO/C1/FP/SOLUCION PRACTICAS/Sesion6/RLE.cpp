/*Programa que lea una secuencia de números naturales terminada con un número
negativo y la ocodifique meidante el método RLE.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int dato, secuencia, contador;
	
	cout << "Introduzca la secuencia de datos a codificar (separando los naturales con espacios): \n";
	cin >> dato;				
	
	secuencia = dato;
	contador = 1;
	
	do {						//Se inicia un bucle do while que se ejecuta una vez y si al llegar al final se cumple la condición establecida en while se repite
								//nuevamente hasta que la condición while se deje de cumplir
		cin >> dato;
		
		if (dato == secuencia){			//Se establece un condicional en el que si el valor de la variable dato es igual al valor de la variable secuencia
			contador++;						//aumente en uno el valor del contador
		}
		else {															//Si no se cumple que el valor de la variable secuencia sea igual al dato introducido
			cout << contador << " " << secuencia << " ";		//se muestra en pantalla el numero de veces que se ha introducido el anterior dato
			secuencia = dato;											//tras el cout la variable secuencia toma el valor nuevo que le hemos otorgado a dato
			contador = 1;												//y se reestablece el contador a uno
}
} while (dato > -1);				//La condición del while es que el dato que introduce le usuario tiene que ser mayor que -1

cout << "\n";				//Por estética pongo este cout para que no se mezclen los datos de salida con el mensaje que da el sistema al ejecutar el system("pause")
system ("pause");
}
