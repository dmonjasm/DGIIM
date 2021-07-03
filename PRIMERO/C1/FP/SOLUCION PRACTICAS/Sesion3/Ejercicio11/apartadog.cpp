/*Programa para probar si se producen problemas de prescisión o problemas de desbordamiento.
*/

#include <iostream> 
#include <cmath>

using namespace std;

int main() {
	float chico;
	double grande;
			grande = 2e+150;
			chico = grande;
	
	cout << "El resultado es: " << chico << "\n\n";
	
	system("pause");
}

/*En este problema ocurre lo mismo que en el anterior con una pequeña diferencia.
Aquí el desbordamiento se produce no porque la maquina no sea capaz, sino porque el espacio
que la maquina reserva para las variables de tipo float es demasiado pequeño para numeros como
el dado por la variable grande. Si chico en lugar de ser una variable de tipo float fuese de tipo
double si que mostraría el numero dado pero como es float no es capaz.
*/
