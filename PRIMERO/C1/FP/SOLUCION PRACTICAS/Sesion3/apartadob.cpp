/*Programa para comprobar si hay errores de precisi�n o de desbordamiento
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
	long grande;
	int chico1, chico2;
		chico1 = 123456789;
		chico2 = 123456780;
	
	grande = chico1 * chico2;
	
	cout << "El valor del producto es: " << grande << "\n\n";
	
	system("pause");
	
}

/*En este caso a pesar de que hemos usado long para que el resultado disponga de m�s memoria
el d�gito que se deber�a obtener a partir del producto entre chico1 y chico2 sigue siendo demasiado
grande de forma que como en el caso anterior de produce un desbordamiento como consecuencia de un 
d�gito exageradamente grado.
*/
