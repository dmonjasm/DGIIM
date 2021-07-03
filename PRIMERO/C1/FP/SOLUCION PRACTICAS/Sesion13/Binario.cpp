#include <iostream>
#include <vector>

using namespace std; 

/*Funcion que pasa, por medio de recursividad, el numero dado a codigo binario */
int Binario(int numero) {
	int digito, digito2;
	int siguiente_numero;
	
	if ((numero / 2) <= 1){					//Si el cociente del numero entre dos es menor o igual que 1 entonces se tiene que el primer digito sera el cociente del numero entre dos
		digito = numero / 2;					//y el segundo digito sera el resto de esta misma operación
		digito2 = numero % 2;
		digito = digito * 10 + digito2;
		return digito;
	}
	
	else{
		siguiente_numero = numero / 2;			//Si el cociente del numero partido de dos es mayor que 1 entonce se calcula el siguiente numero sobre el que se ejecutara la función
		digito = (numero % 2) + (10 * Binario (siguiente_numero));		//Y se establece que el numero en binario es el resto del cociente del numero entre dos mas
		return digito;			// diez veces la aplicación de la función a numero calculado anteriormente.
	}
}

int main() {
	int numero;
	int binario;
	
	cout << "\nIntroduzca un numero a partir del cual calcular su forma en binario: ";
	cin >> numero;
	
	binario = Binario(numero);
	
	cout << "\nEl numero introducido pasado a codigo binario es: " << binario << "\n";
	
	system("pause");
}
	

		
		
