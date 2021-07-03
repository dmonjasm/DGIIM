/*Programa que muestre el mayor numero perfecto que sea menor a un numero dado
por el usuario.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int numero, divisor, suma;
	bool numero_perfecto;
	
	cout << "Introduzca un numero entero: ";
	cin >> numero;
	
	do {					//Se inicia un bucle do while que ejecute el bloque siguiente y se repita si después de ejecutar el bloque el valor de la variable numero_perfecto es false
		numero--;		//Se reduce en una unidad el valor de numero pues se busca el maximo numero perfecto que sea menor que el introducido
		suma = 0;
		
		for (divisor = 1; divisor < numero; divisor++){		//Se inicia un bucle por contador que se repite hasta que el divisor es igual al numero 
			if ((numero % divisor) == 0)			//Se establece un condicional en el que si el resto de numero entre divisor es cero entonces se 
				suma = suma + divisor;				//le asigna a suma el valor de la adición de divisor mas el anterior valor de la suma
			else
				suma = suma;
			}
		if (suma == numero)					//Terminado el bloque se establece un condicional en el que si la suma de los divisores es igual que el numero
			numero_perfecto = true;			//se le asigne a la variable booleana numero_perfecto el valor true
		else
			numero_perfecto = false;		//Si no se cumple la condición se le asigna a la variable numero_perfecto el valor false, lo que hará que se repita el bucle
			
}while (numero_perfecto == false);

cout << "El maximo numero perfecto que es menor que el numero introducido es: " << numero << "\n";

system("pause");
}
