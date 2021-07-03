/*Programa que lea enteros desde teclado y calcule cuántos se han introducido y cual es
el mínimo de dichos valores (pueden ser positivos o negativos). Se dejará de leer datos
cuando el usuario introduzca el valor 0.
*/

#include <iostream> 			//Se declara la biblioteca de E/S iostream
#include <cmath>				//Se declara la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	int variable, contador, minimo;			//Declaro las variables de tipo entero que se utilizarán en el programa
	contador = 0;									//Le asigno a la variable contador, que contará los numeros introducidos el valor 0
	minimo = 0;										//Le asigno a la variable minimo el valor 0 que sería el valor minimo en caso de introducir unicamente un numero
	variable = 0;									//Le asigno a la variable variable el valor 0 que sería el valor que tomaría en caso de que el usuario introdujese solo un numero
	
	do {
		if ((variable <= minimo)&&(minimo != 0))												//Se declara un condicional en el que si la variable es menor o igual que el minimo, y es distinta de cero,
			minimo = variable;																		//el minimo tome el valor de la variable
		else 																								//Si no se cumple el condicional de arriba entonces la variable sera 0 y el minimo tambien y por tanto o se han introducido numeros
			minimo = variable;
			
		cout << "Introduzca un valor entero (puede ser negativo o positivo): ";			//Se pide al usuario que introduzca un numero entero que se asignara a la varaible variable
		cin >> variable;
		
		contador++;									//Aumenta en uno el valor de la variable contador cada vez que se ejecuta el bucle
		
	}while (variable != 0);						//Se establece que si el valor de variable es distinto de cero se vuelva a ejecutar el bulce repetidamente hasta que el valor de variable sea 0
	
	
	 if(contador == 1){																													//Se establece que si el valor de la variable contador es 1 implica que el usuario solo ha introducido el 0
		cout << "Solo ha introducido un numero para terminar de resgistrar datos.\n";									//que es el numero que hace que la maquina deje de pedir valores para la variable variable
		cout << "No hay minimo ya que solo ha introducido el numero para terminar de resgistrar datos.\n";		//Por tanto, es como si no se hubiese introducido ningun numero
}
	else{
		cout << "Ha introducido " << (contador - 1) << " numeros.\n";					//Si el contador tiene asignado un valor distinto de 1 entonces significa que se han introducido mas de un unmero
		cout << "El minimo numero introducido es: " << minimo << "\n";					//y por tanto que en este caso si hay minimo
	}
	
	system("pause");
}
