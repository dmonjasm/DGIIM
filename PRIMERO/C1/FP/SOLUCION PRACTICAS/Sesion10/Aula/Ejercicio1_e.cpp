#include <iostream>
#include <cmath>

using namespace std;

/*Clase en la cual se disponen de tres variables de tipo double y una función que modifica el valor de las varaibles A, B y C que son datos
privados , y además contiene un constructor que le da un valor inicial a A, B y C*/
class Recta{
	private:
		double A, B, C;
	public:
		
		/*Establezco un constructor que de unos valores iniciales a los valores A, B y C de cualquier variable de tipo Recta */
		Recta(double x, double y, double z){
			A = x;
			B = y;
			C = z;
		}
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
	Recta segmento(12.34, 15.68, 20.123);
	
	cout << "\nLos valores iniciales de A, B y C son: " << segmento.As() << " " << segmento.Bs() << " " << segmento.Cs() << "\n";
	
	segmento.setABC();
	
	cout << "\nLos valores de A, B y C son: " << segmento.As() << " " << segmento.Bs() << " " << segmento.Cs() << "\n";
	
	system("pause");
} 
