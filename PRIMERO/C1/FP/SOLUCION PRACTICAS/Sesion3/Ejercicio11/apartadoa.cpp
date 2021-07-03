/*Prueba para comprobar si los siguientes programas tienen problemas de precisi�n o de desbordamiento.
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

/*Una vez se ejecuta el problema se observa que solo muestra diez d�gitos que es claramente menor
al valor del producto de chico1 por chico2, adem�s si se realizan las cuentas con una calculadora normal
se observa que las cifras dadas tambi�n son err�neas por lo que podemos deducir que hay un error de desbordamiento.
*/
