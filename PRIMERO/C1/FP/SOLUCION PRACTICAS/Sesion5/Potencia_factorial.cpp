/*Programa que calcule la funcion potencia x^n, y la funcion factorioal n! con n un valor
entero y x un valor real
*/

#include <iostream>			//Se declara la biblioteca de E/S iostream

using namespace std;

int main() {
	double base, resultado_potencia;						//Se introducen las variables reales que serán la base y el resultado de la potencia
	int exponente, resultado_factorial, factorial;	//Se establecen las variables enteras que seran el exponente, la base del facotrial y su resultado
	int contador_potencia, contador_factorial;		//Se establecen los contadores para los bucles que utilizaremos
	
	cout << "Introduzca un numero real x: ";		//Se pide al usuario que introduzca un numero real x
	cin >> base;			//Se guarda el numero introducido en la variable base
	cout << "\nIntroduzca un numero entero n: ";	//Se pide al usuario que introduzca un numero entero n
	cin >> exponente;		//Se guarda el numero introducido en la variable entero
	
	resultado_potencia = base;			//Se le asigna a la variable resultado el valor de la variable base
	
	if (exponente == 0)					//Se establece la condición de que si el exponente es 0 el resultado sea 1
		resultado_potencia = 1;
	else
		if (exponente == 1)				//Se establece la condición de que si el exponente es 1 el resultado sea igual a la base
			resultado_potencia = base;	
	
	for (contador_potencia = 2; contador_potencia <= exponente; contador_potencia++){	//Se inicia un bucle controlado por contador
		resultado_potencia = base * resultado_potencia;				//En el se establece que el resultado de la potencia es el resultado del producto de la base por el resultado
	
}
	cout << "\nEl resultado de la potencia del numero real elevado al entero es: " << resultado_potencia << "\n";		//Se meustra en pantalla el resultado
	
	if (exponente == 0)					//Se establece la condición de que si la base del factorial es 0 el resultado sea 1
		resultado_factorial = 1;
		
	resultado_factorial = exponente;			//Al resultado se le asigna el valor de la base del factorial
	factorial = exponente;						//A una variable factorial se le asigna el valor de la base del factorial
	
	for (contador_factorial = 1; contador_factorial < exponente; contador_factorial++){			//Se inicia un bucle controlado por contador
		factorial--;															//Si el contador es menor que el exponenete se ejecuta el bucle 
		resultado_factorial = resultado_factorial * factorial;	//El cuerpo del bucle establece que se le reste uno al valor del factorial y se haga el producto de este por el resultado
																					//del factorial hasta el momento
	}
		

	
	cout << "\nEl resultado del factorial del numero entero introducido es: " << resultado_factorial << "\n";		//Se anuncia en pantalla el resultado
		
	system("pause");
}
