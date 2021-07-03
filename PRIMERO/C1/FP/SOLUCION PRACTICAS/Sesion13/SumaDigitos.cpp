#include <iostream>
#include <cmath>

using namespace std;

/*Se inicia una función recursiva de tipo int que requiere de un dato de tipo entero. Si este dato esta comprendido entre 9 y 1 se devuelve directamente, pero
si es mayor que 9 se hace su resto y se repite el proceso para el numero dividido entre diez */ 
int SumaDigitos (int numero){
	int resultado = 0;
	
	if((numero > 0)&&(numero < 10))	//Si el numero esta entre 9 y 10 el resultado toma el valor del numero
		resultado = numero;
		
	else
		resultado =(numero % 10) + SumaDigitos( numero / 10);		//Si el numero es mayor que 9 se hace el resto del numero y se repite el proceso para la decima parte del numero
		
	return resultado;
}

int main() {
	int numero;
	int resultado;
	
	cout << "\nIntroduzca el numero cuya suma de digitos quiere calcular: ";
	cin >> numero;
	
	while (numero <= 0){			//Bucle de tipo while que asegura que el usuario introduzca un numero entero positivo
		cout << "\nIntroduzca un numero entero positivo: ";
		cin >> numero;
		
	}
	
	resultado = SumaDigitos(numero);
	
	cout << "\nLa suma de los digitos del numero es: " << resultado << "\n";
	
	system("pause");
}
	
	
	
		
