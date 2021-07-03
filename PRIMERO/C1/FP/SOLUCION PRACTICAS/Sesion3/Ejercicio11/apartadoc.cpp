/*Programa para probar si se producen errores de prescisión o de desbordamiento.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double resultado, real1, real2;
		real1 = 123.1;
		real2 = 124.2;
		
	resultado = real1 * real2;
	cout.precision(10);
	
	cout << "El resultado es: " << resultado << "\n\n";
	
	system("pause");
}

/*En este caso si se escribe el numero de digitos (esto incluye decimales y enteros)
que se quieren observar adecaudamente el resultado es correcto, mientras que si no se 
especifica el numero de digitos que se quieren ver habrá un problema de precisión.
*/

