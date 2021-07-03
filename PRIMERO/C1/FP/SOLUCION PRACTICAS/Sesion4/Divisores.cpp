/*Programa que lea desde teclado un entero e imprima en pantalla todo sus divisores propios.
Para obtener los divisores, basta recorrer todos los enteros menores que el valor introducido 
y comprobar si lo dividen. A continuación, mejorar el ejercicio obligando al usuario a introducir
un entero positivo, usando un filtro con un bucle post test (do while):
Se necesita: un entero introducido por el usuario.
					tope
Se obtiene: los divisores propios de dicho entero
					divisor
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	int tope, divisor;			//Se declaran las variables de tipo entero con las que se trabajara
	

	do {																	//Se introduce un bucle en el que se realiza una acción, y si el resultado de esa acción es distinto de lo establecido en el while se
		cout << "Introduzca un numero entero: ";				//se vuelve a realizar la acción repetidamente hasta que se obtenga un resultado que satisfaga la condición establecida en while.
		cin >> tope;
	}while (tope < 0);
	
	divisor = tope;													//Se le asigna a la variable divisor el mismo valor que el de la variable tope
	
	while (divisor > -(tope)){																//Se establece que si la variable divisor es mayor que el opuesto de tope se repita la siguiente acción hasta que deje de serlo
		if ((tope % divisor) == 0)															//Si el resto del cociente de tope entre divisor es 0 se muestra el mensaje escrito en pantalla y al valor de divisor se le resta uno
			cout << divisor << " es un divisor del entero introducido\n";
			divisor--;
		}
		
	
	system("pause");
}
		
