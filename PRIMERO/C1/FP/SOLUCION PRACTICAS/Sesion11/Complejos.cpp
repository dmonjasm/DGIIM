#include <iostream>
#include <cmath>

using namespace std;

/*Clase que contiene dos variables privadas una que contiene el valor real del complejo y otro que contiene el valor imaginario del complejo.
Además se dispone de un contador que da valores iniciales a la parte real e imaginaria de cada numero, una funcion para sumar, otra para multiplicar,
otra para restar, y una para devolver las partes complejas y reales de cada numero */
class Complejos{
	private:
		double real, complejo;
	
	public: 
		/*Constructor*/
		Complejos(double x, double y){	//Se da valor inicial a las partes real e imaginaria del numero complejo
			real = x;
			complejo = y;
		}
		
		/*Funcion que sirve para dar que el usuario de valor a la parte real y compleja del numero */
		void setComplejo(){
			cout << "\nIntroduzca la parte real del primer numero complejo: ";
			cin >> real;
			
			cout << "\nIntroduzca la parte imaginaria del primer numero complejo: ";
			cin >> complejo;
		}
		
		double Real(){
			return real;
		}
										//Funciones para devolver las partes real e imaginaria del numero complejo
		double Complejo(){
			return complejo;
		}
		
		/*Funcion tipo void para calcular la suma de dos numeros complejos y que muestra por pantalla las partes real y compelja del resultado */		
		void Suma(double x, double y, double r, double t){
			double suma_real;
			double suma_compleja;
			
			suma_real = x + r;
			suma_compleja = y + t;
			
			cout << "\nLa suma de ambos numeros complejos es: " << suma_real << " i" << suma_compleja << "\n";	
		}
		
		/*Funcion tipo void para calcular la resta de dos numeros complejos y que muestra por pantalla las partes real y compelja del resultado */
		void Resta(double x, double y, double r, double t){
			double resta_real;
			double resta_compleja;
			
			resta_real = x - r;
			resta_compleja = y - t;
			
			cout << "\nLa resta de ambos numeros complejos es: " << resta_real << " i" << resta_compleja << "\n";	
		}
		
		/*FUncion tipo void para calcula el producto de dos numeros complejos y que meustra por pantalla las partes real y compleja del resultado */
		void Producto(double x, double y, double r, double t){
			double parte_real;
			double parte_compleja;
			
			parte_real = (x * r) - (y * t);
			parte_compleja = (x * t) + (y * r);
			
			cout << "\nEl producto de ambos numeros complejos es: " << parte_real << " i" << parte_compleja << "\n";			
		}
	};
	
int main() {
	Complejos numero_1(1,4), numero_2(2,3);
	char operacion;
	
	numero_1.setComplejo();
	numero_2.setComplejo();
	
	cout << "\nIntroduzca el tipo de operacion que quiera realizar (s=suma/r=resta/p=producto): ";
	cin >> operacion;
	
	switch(operacion){			//Switch en el que depende del caracter introducido se realiza una u otra operacion con los datos introducidos
		case 's':
			numero_1.Suma(numero_1.Real(), numero_1.Complejo(), numero_2.Real(), numero_2.Complejo());
			break;
		case 'r':
			numero_1.Resta(numero_1.Real(), numero_1.Complejo(), numero_2.Real(), numero_2.Complejo());
			break;
		case 'p':
			numero_1.Producto(numero_1.Real(), numero_1.Complejo(), numero_2.Real(), numero_2.Complejo());
			break;
		default: NAN;
	}
	
	system("pause");
}	
