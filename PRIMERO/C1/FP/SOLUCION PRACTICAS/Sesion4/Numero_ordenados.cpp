/*Programa que lea tres enteros desde teclado y nos diga si están ordenados o no, independientemente
de su orden.
Se necesita: tres numeros enteros
					entero_1		entero_2 	entero_3
Se obtiene: mensaje diciendo si estan ordandos o no
*/

#include <iostream> 			//Incluyo la biblioteca de E/S iostream
#include <cmath> 				//Incluyo la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	int entero_1, entero_2, entero_3;			//Declaro las variables enteras entero_1, entero_2 y entero_3
	bool mayor, menor;								//Declaro las variables de tipo logica mayor y menor
	
	cout << "Introduzca un primer numero entero: ";			//Pide al usuario que introduzca un primer numero entero
	cin >> entero_1;			//Se guarda este primer numero entero
	cout << "Introduzca un segundo numero entero: ";		//Pide al usuario que introduzca un segundo numero entero
	cin >> entero_2;			//Se guarda este segundo numero entero
	cout << "Introduzca un tercer numero entero: ";			//Pide al usuairo que introduzca un tercer numero entero
	cin >> entero_3;			//Se guarda este tercer numero entero
	
	
	mayor = (entero_1 > entero_2)&&(entero_1 > entero_3);		//Establezco el condicional que nos dirá si los numeros estan ordenados de mayor a menor
	menor = (entero_1 < entero_2)&&(entero_1 < entero_3);		//Establezco el condicional que nos dirá si los numeros estan ordenados de menor a mayor
	
	
	if (mayor||menor)				//Establezco la condición que hará que se muestre un mensaje u otro
		cout << "\nLos numeros enteros introducidos estan ordenados.\n\n";				//Si se cumple una de las dos condiciones se muestra el mensaje en pantalla
	else 
		cout << "\nLos numeros enteros introducidos no estan ordenados.\n\n";			//Si no se muestra ninguna de las condiciones se muestra el mensaje en pantall
	
	
	system("pause");
}
		
	
	
