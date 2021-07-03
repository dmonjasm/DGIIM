#include <iostream>
#include <cmath>

using namespace std;

/* Funcion que calcula la letra minuscula asociada a cada letra mayuscula*/
char Transformacion(char letra){
	const char DIF_MAY_MIN = 'a' - 'A';
	char minuscula;
	
	minuscula = letra + DIF_MAY_MIN;			//Se establece el algoritmo que cambiará de mayuscula a minuscula y se devuelve el resultado
	
	return minuscula;
}

int main() {
	char caracter;
	
	cout << "Introduzca una letra cualquiera: ";
	cin >> caracter;
	
	/*Se establece un condicional en el que si la letra es mayuscula se muestre su correspondiente minuscula, si la letra no es mayuscula es muestra el 
	caracter en si mismo*/
	if((caracter >= 'A')&&(caracter <= 'Z')){
		caracter = Transformacion(caracter);
		cout << "\nLa letra transformada es: " << caracter << "\n";
	}
	else
		cout << "\nLa letra transformada es: " << caracter << "\n";
	
		
	system("pause");
}
		
