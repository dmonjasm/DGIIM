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
			if((x != 0)||(y != 0)){		//Se establece que si x e y son simultaneamente 0 se de a A y B el valor 1
				A = x;
				B = y;
				C = z;
			}
			else
				A = 1;
				B = 1;
				C = z;
		}
		/*Funcion que modifica el valor de los datos privados A, B y C */
		void setABC(){
			double valor1, valor2, valor3;
			
			cout << "\nIntroduzca los valores de A, B y C: ";
			cin >> valor1 >> valor2 >> valor3;
			
			if((valor1 != 0)||(valor2 != 0)){			//Se establece el condicional en el que si los valores 1 y 2 son simlutaneamente nulos se le asigne 
			A = valor1;											//a los valores A y B le valor 1
			B = valor2;
			C = valor3;
		}
		
			else{
				A = 1;
				B = 1;
				C = valor3;
		}
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
	Recta segmento(12, 1234, 20.123);
	
	cout << "\nLos valores iniciales de A, B y C son: " << segmento.As() << " " << segmento.Bs() << " " << segmento.Cs() << "\n";
	
	segmento.setABC();
	
	cout << "\nLos valores de A, B y C son: " << segmento.As() << " " << segmento.Bs() << " " << segmento.Cs() << "\n";
	
	system("pause");
} 
