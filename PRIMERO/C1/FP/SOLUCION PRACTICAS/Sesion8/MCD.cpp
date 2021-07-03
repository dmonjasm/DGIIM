#include <iostream>
#include <cmath>

using namespace std;

/*Establezco una funcion que calcule el maximo comun divisor a dos numeros introducidos por el usuario */
int MCD (int a, int b){
	int maximodivisor;
	if(a < b){
		for(int i = 1; i <= a; i++){
			if(((a % i) == 0)&&((b % i) == 0))
				maximodivisor = i;
			else
			 	maximodivisor = maximodivisor;
			 }
	}
	else{
		for(int i = 1; i <= b; i++){
			if(((a % i) == 0) &&((b % i) == 0))
				maximodivisor = i;
			else
				maximodivisor = maximodivisor;
			}
		}
	return maximodivisor;
}
		

int main() {
	int numero_1, numero_2;
	int maximocomundivisor;
	
	cout << "Introduzca un primer numero: ";
	cin >> numero_1;
	cout << "\nIntroduzca un segundo numero: ";
	cin >> numero_2;
	
	/*Asigno el valor del maximo comun divisor de dos numeros a una variable */
	maximocomundivisor = MCD(numero_1, numero_2);
	
	cout << "\nEl maximo comun divisor de ambos numero es: " << maximocomundivisor << "\n";
	
	system("pause");
}

	
	
	
