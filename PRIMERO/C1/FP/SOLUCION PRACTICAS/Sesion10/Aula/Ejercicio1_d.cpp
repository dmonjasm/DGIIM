#include <iostream>
#include <cmath>

using namespace std;

/*Clase en la cual se disponen de tres variables de tipo double y una función que modifica el valor de las varaibles A, B y C que son datos
privados */
class Recta{
	private:
		double A, B, C;
	public:
		
		/*Funcion que modifica el valor de los datos privados A, B y C */
		void setABC(){
			double valor1, valor2, valor3;
			
			cout << "\nIntroduzca los valores de A, B y C: ";
			cin >> valor1 >> valor2 >> valor3;
			
			A = valor1;
			B = valor2;
			C = valor3;
		}
		
		double As(){
			return A;
		}
		
		double Bs(){
			return B;
		}
		
		double Cs(){
			return C;
		}		
};

int main(){
	Recta segmento;
	
	segmento.setABC();
	
	cout << "\nLos valores de A, B y C son: " << segmento.As() << " " << segmento.Bs() << " " << segmento.Cs() << "\n";
	
	system("pause");
} 
