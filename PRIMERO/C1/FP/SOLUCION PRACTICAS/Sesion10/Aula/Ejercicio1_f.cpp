#include <iostream>
#include <cmath>

using namespace std;

/*Clase en la cual se disponen de tres variables de tipo double, privadas, y tres funciones que muestran el valor de estas variables, ademas se dispone de un
constructor que le da un valor incial a las variables A, B y C */
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
	
	system("pause");
} 
