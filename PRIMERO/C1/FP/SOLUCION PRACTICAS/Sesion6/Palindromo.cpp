/*Programa que nos diga si una secuencia de caracteres es un palindromo, es decir, 
que se lea igual de izquierada a dererecha que de derecha a izquierda.
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const char TERMINADOR = '#';
	const int LONGITUD = 200;
	char secuencia[LONGITUD];
	int i = 0, k = 0;
	bool palindromo;
	int mitad;
	
	cout << "Introduzca el valor de la secuencia: ";
	cin >> secuencia[i];
	
	while (secuencia[i] != TERMINADOR){			//Se inicia un bucle en el que si el valor del vector es distinto del TERMINADOR ejecute el sigueinte bloque
		
		i++;
																				//Aumenta en uno el valor de i y guarda un nuevo valor en el vector y asi hasta que se deje de cumplir la condicion while
		cout << "\nIntroduzca el valor de la secuencia: ";
		cin >> secuencia[i];
		
	}
	
	i--;
	mitad = i / 2;
	
		
	do {				//Se inicia un bucle que se ejecuta y si se cumple que k sea menor que mita y que palindromo sea true se ejecutara nuevaente
		if (secuencia[k] == secuencia[i]){		//Se establece un condicional en el que si el primer vector es igual que el ultimo se aumente en un el valor de k
			i--;											//se reduzca en uno el valor de i y se le de a palindromo el valor de true
			k++;
			palindromo = true;
		}
			
		else{				//Si no se cumple se muestra en pantalla un mensaje de error y se le da a palindromo el valor false y por tanto termina el bucle
			cout << "\nLa secuencia introducida no es un palindromo.\n";
			palindromo = false;
		}
	}while ((k < (mitad))&&(palindromo == true));
	
	if (palindromo == true)			//Si palindromo es true entonces se mostrara en pantalla el resultado
		cout << "\nLa secuencia introducida es un palindromo.\n";
	
	system("pause");
}
