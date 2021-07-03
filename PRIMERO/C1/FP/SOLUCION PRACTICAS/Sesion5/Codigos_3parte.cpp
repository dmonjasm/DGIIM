/*Programa que tenga como entrada factores primos y como salida el 
producto de ellos 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int primo, entero;
	entero = 1;
	
	do {
	cin >> primo;
	if (primo != -1)
		entero = entero * primo;
	else
		primo = -1;
	
	
	
} while (primo != -1);
	cout << "El numero entero calculado a partir de los primos es: " << entero << "\n";
	
	system("pause");
}
