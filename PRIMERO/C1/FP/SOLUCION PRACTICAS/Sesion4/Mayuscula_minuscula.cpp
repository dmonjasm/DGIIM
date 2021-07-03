/*Programa que lea un caracter desde teclado, compruebe a través de una estructura condicional si es
mayuscula y en caso de ser mayuscula nos muestre en pantalla ese mismo caracter en minuscula.
Si no es mayuscula se asociara el valor de la funcion a otra variable y se mostrará en pantalla.
*/

#include <iostream> 			//Se inlcuye la biblioteca de E/S iostream
#include <cmath> 				//Se inlcuye la biblioteca de operaciones matematicas cmath

using namespace std;

int main() {
	char letra_original, letra_convertida;				//Se declaran las variables de tipo caracter
	const int DISTANCIA_MAY_MIN ='a' - 'A';			//Se declara como constante entera la diferencia entre una letra minuscula y una mayuscula
	bool es_mayuscula;										//Se declara una variable de tipo logico es_mayuscula
	
	cout << "\nIntroduzca una letra: ";			//Se pide al usuario una letra
	cin >> letra_original;			//Se guarda dicha letra
	
	if ((letra_original >= 'A')&&(letra_original <= 'Z')){			//Se establece el bloque que se ejecutara si se cumple que la letra original sea mayor que 'A' y menor que 'Z'
		es_mayuscula = true;				//Se declara le da a es_mayuscula el valor de verdadero
			if (es_mayuscula)				//Se establece que si es_mayuscula es verdadero se ejecute el siguiente bloque
				letra_convertida = letra_original + DISTANCIA_MAY_MIN;			//Se establece que la letra_convertida sea la suma de la original y la constante
			}
	else {			//Se establece que si la primera condicion no se cumle se ejecute el siguiente bloque
		es_mayuscula = false;			//Se le da a la variable es_mayuscula el valor de falso
		letra_convertida = letra_original;			//Se establece que la letra_convertida sea igual a la original
	}
	
	cout << "\nEl caracter " << letra_original << " una vez convertido es: " << letra_convertida << "\n\n";			//Se anuncia en pantalla el resultado
	
	system("pause");
}
	
		
			
	
