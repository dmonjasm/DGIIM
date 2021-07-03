#include <iostream>
#include <cmath>

using namespace std;

/*Clase compuesta de tres variables de tipo real */
class Recta{
	public:
		double A, B, C;
};

int main (){
	Recta segmento_1, segmento_2;
	double pendiente1, pendiente2;
	
	cout << "Introduzca los valores de A, B y C de la recta 1: ";
	cin >> segmento_1.A >> segmento_1.B >> segmento_1.C;
	
	cout << "\nIntrodzuca los valores de A, B y C de la recta 2: ";
	cin >> segmento_2.A >> segmento_2.B >> segmento_2.C;
	
	pendiente1 = - segmento_1.A / segmento_1.B;		//Algorimto para calcular las pendientes de ambas rectas
	pendiente2 = - segmento_2.A / segmento_2.B;
	
	cout << "\nLa pendiente de la recta 1 es: " << pendiente1 << "\n";
	
	cout << "\nLa pendiente de la recta 2 es: " << pendiente2 << "\n";
	
	system("pause");
}
