#include <iostream>
#include <cmath>

using namespace std;

/*Clase en la cual se disponen de tres variables de tipo double y una función que calcula la pendiente usando dichos datos double */
class Recta{
	private:
		double A, B, C;
	public:
		
		void setA(){				//Funcion void que sirve para modifica le dato privado A
			double valor;
			
			cout << "\nIntroduzca un valor para A: ";
			cin >> valor;
			
			A = valor;
		}
		
		double As(){			//Funcion double para devolver el valor de C
			return A;
		}
		
		void setB(){				//Funcion void que sirve para modificar el dato privado B
			double valor;
			
			cout << "\nIntroduzca un valor para A: ";
			cin >> valor;
			
			B = valor;
		}
		
		double Bs() {				//Funcion double para devolver el valor de B
			return B;
		}
		
		void setC(){				//Funcion void que sirve para modifica el dato privado C
			double valor;
			
			cout << "\nIntroduzca un valor para A: ";
			cin >> valor;
			
			C = valor;
		}
		
		double Cs(){			//Funcion double para devolver el valor de C
			return C;
		}
};

int main() {
	Recta segmento_1;
	
	segmento_1.setA();
	segmento_1.setB();
	segmento_1.setC();
	
	cout << "\nEl valor de A es: " << segmento_1.As();
	cout << "\nEl valor de B es: " << segmento_1.Bs();
	cout << "\nEl valor de C es: " << segmento_1.Cs() << "\n";
	
	system("pause");
}
