#include <iostream>
#include <cmath>

using namespace std;

/*Clase en la cual se disponen de tres variables de tipo double y una función que calcula la pendiente usando dichos datos double */
class Recta{
	public:
		double A, B, C;
	public:
		
		double setPendiente(double A,double B){				//Funcion que calcule la pendiente de una recta usando los valores de la variables double A y B
			double pendiente;
			
			pendiente = - (A / B);
			
			return pendiente;
		}
		
		double setOrdenada(double x, double A, double B, double C){				//Funcion que calcula las ordenadas utilizando una abscisa dada por el usuario
			double ordenada;
			
			ordenada = (-C -(x * A)) / B;
			
			return ordenada;
		}
		
		double setAbscisa(double y, double A, double B, double C){				//Funcion que calcula las abscisas utilizando una ordenada dada por el usuario
			double abscisa;
			
			abscisa = (-C -(y * B)) / A;
			
			return abscisa;
		}
};

int main() {
	Recta segmento_1, segmento_2;
	double x, y;
	
	cout << "Introduzca los valores de A, B y C de la recta 1: ";
	cin >> segmento_1.A >> segmento_1.B >> segmento_1.C;
	
	cout << "\nLa pendiente de la recta 1 es: " << segmento_1.setPendiente(segmento_1.A, segmento_1.B) << "\n";
	
	cout << "\nIntroduzca los valores de A, B y C de la recta 2: ";
	cin >> segmento_2.A >> segmento_2.B >> segmento_2.C;
	
	cout << "\nLa pendiente de la recta 2 es: " << segmento_2.setPendiente(segmento_2.A, segmento_2.B) << "\n";
	
	cout << "\nIntroduzca el punto de abscisa donde quiere calcular el valor de las ordenadas: ";
	cin >> x;
	
	cout << "\nEl valor de las ordenadas en el punto de abscisa dado es: " << segmento_1.setOrdenada(x, segmento_1.A, segmento_1.B, segmento_1.C) << "\n";
	
	cout << "\nIntroduzca el punto de ordenada donde quier calcular el valor de la abscisas: ";
	cin >> y;
	
	cout << "\nEl valor de las abscisas en el punto de ordenada dado es: " << segmento_1.setAbscisa(y, segmento_1.A, segmento_1.B, segmento_1.C) << "\n";
	
	system("pause");
}
	
	
	
