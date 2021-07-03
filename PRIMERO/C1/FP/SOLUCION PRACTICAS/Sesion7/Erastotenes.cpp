/*Program que muestre una lista de numeros primos menores que un cierto
numero introducido. Estos numeros se deben obtener mediante el metodo
de la criba de Erastotenes.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int LONGITUD = 200;
	int vector[LONGITUD], valor = 0, resultado[LONGITUD];
	int numero;
	bool primo;
		resultado[LONGITUD] = {0};
	
	cout << "Introduzca el numero cuyos primos menores que el quiere calcular: ";
	cin >> numero;
	
	for (int i = 2; i < numero; i++){
		vector[i] = i;
}
	for (int j = 2; j < numero; j++){
		for (int k = 2; (k < numero)&&(primo); k++){
			if (vector[j] != k){
				if ((vector[j] % k) != 0)
					primo = true;
				else
					primo = false;
				}
			else
				primo = true;
			}
		if (primo){
			resultado[valor] = vector[j];
			cout << resultado[valor];
			valor++;
		}
	}
	
	for (int l = 0; l <= valor; l++){
		cout << resultado[l] << " ";
	}
	
	cout << "\n";
	
	system("pause");
}
			
			
			
			
					
	
	

