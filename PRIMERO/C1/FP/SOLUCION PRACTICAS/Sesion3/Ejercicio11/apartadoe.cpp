/*Programa para probar si hay errores de precision o de desboramiento de datos.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double real, otro_real;
			real = 2e34;
	
	otro_real = real + 1;
	otro_real = otro_real - real;
	
	cout << "El resultado es: " << otro_real << "\n\n";
	
	system("pause");
}

/*Este programa da como resultado 0. Esto se debe a que la suma de real=2e34 con 1 da un numero
en el que el uno parece tan insignificante que la maquina lo omite de forma que al hacer despues
la resta de otro_real - real cuyo resultado se supone 1 la maquina da lugar a un 0, luego en este
programa hay un error de precision.
*/
