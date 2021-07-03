/*Programa que lea un numero entero desde tecado e indique si es desgarrable.
*/

#include <iostream>			
#include <cmath>

using namespace std;

int main() {
	int numero, izquierda, derecha, divisor;
	int resultado, suma;
	
	divisor = 1;
	izquierda = numero;
	derecha = 0;
	
	cout << "Introduzca un numero entero: ";
	cin >> numero;
	
	while ((resultado != numero)&&(divisor <= numero)){			//Iniciamos un bucle que se repita siempre que se cumpla que el resultado sea distinto del numero introducido 
		izquierda = numero / divisor;								//y que el divisor sea menor que el numero. Dentro de el bucle se le asigna a la valor izquierda el resultado del cociente
		derecha = numero % divisor;								//de el numero entre el divisor. A derecha se le asigna el resto del cociente del numero entre el divisor. Se ejecuta la suma
		suma = izquierda + derecha;								//de ambas variables y se almacena en una variable. Se multiplica por diez al divisor, ya que con el se pretenden sacar 
		divisor = divisor * 10;										//unidades, centenas y decenas que lo componen. Por ultimo se hace a potencia al cuadrado de la variable suma. Si el resultado
		resultado = pow (suma,2);									//es igual al numero con esto se deja de cumplir la condición del bucle y este se para
		
	}
	
	if (numero == resultado)											//Se establece un condicional en el que si el numero es igual a la variable resultado se muestra que es desgarrable
		cout << "El numero introducido es desgarrable.\n";
		
	else 																		//si no es igual a la variable resultado se muestra que el numero no es desgarrable
		cout << "El numero introducido no es desgarrable.\n";
		
	system("pause");
	
}
		
