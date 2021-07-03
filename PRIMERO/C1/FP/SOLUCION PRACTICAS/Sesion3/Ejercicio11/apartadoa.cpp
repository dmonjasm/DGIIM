/*Prueba para comprobar si los siguientes programas tienen problemas de precisión o de desbordamiento.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int chico, chico1, chico2;
		chico1 = 123456789;
		chico2 = 123456780;
		chico = chico1 * chico2;
		
	cout << "El resultado es: " << chico << "\n\n";
	
	system("pause");
}

/*Una vez se ejecuta el problema se observa que solo muestra diez dígitos que es claramente menor
al valor del producto de chico1 por chico2, además si se realizan las cuentas con una calculadora normal
se observa que las cifras dadas también son erróneas por lo que podemos deducir que hay un error de desbordamiento.
*/
