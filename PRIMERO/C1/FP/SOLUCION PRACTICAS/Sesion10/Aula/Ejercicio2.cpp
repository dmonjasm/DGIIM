#include <iostream>
#include <cmath>

using namespace std;

/*Se crea una clase que disponga de dos variables privadas, un constructor, una funci�n para calcular el total obtenido por a�o
, otra funci�n para calcular los a�os hasta doblar el capital inicial y funciones para modificar y mostrar las variables privadas*/
class DepositoSimulacion{
	private: 
		double capital, interes;
	public:
		
		/*Se inicia un constructor en el que se dan valores a capital e interes siempre que cumplan unas ciertas condiciones */
		DepositoSimulacion(double a, double b){
			if((a <= 0)||(b <= 0)){			//Los valores iniciales deben de ser mayores o iguales que cero, sino el constructor le asignar� un valor por defecto
				if(a <= 0)
					capital = 1;
				else
					interes = 1;
			}
			else
				capital = a;
				interes = b;
			}		
			
		/*Se inicia una funci�n void ne la que se calcula el total obtenido cada a�o al aplicar el inter�s */
		void Inversion(double capital, double interes, int anios){
			double total;
			
			for(int i = 0; i < anios; i++){								//Bucle for que calcula el total de cada a�o y lo muestra por pantalla
				
				total = capital + capital * (interes / 100);
				capital = total;
				
				cout << "\nEl total en el anio " << i+1 << " es: " << total << "\n";
		}
	}
		
		/*Se inicia una funci�n tipo double que devuelve el tiempo en a�os requerido para doblar el capital */
		double Anios_necesarios(double capital, double interes){
			double total;
			int capital_inicial, tiempo_transcurrido = 0;
				capital_inicial = capital;
			if(interes > 0){													//La operacion se realizar� solo si el interes es positivo, sino jamas se podr� doblar el capital
			do{
				
				total = capital + capital * (interes / 100);			//Se inicia un bucle for que realiza el calculo de total y aumenta un contador siempre que el total 
				capital = total;												//sea menor que el valor inicial del capital
				tiempo_transcurrido++;
				
			}while(total < (2 * capital_inicial));
			
			return tiempo_transcurrido;
		}
			else																	//Si el interes es negativo se devuelve nan
				return NAN;
			
		}			
		
		/*Se inicia una funci�n void para darle valor a la variable privada capital */
		void setCapital(){					
			cout << "\nIntroduzca el capital: ";
			cin >> capital;
			
			if(capital <= 0){
				cout << "\nIntroduzca un capital valido: ";
				cin >> capital;
			}
		}
		
		/*FUncion double para mostrar el valor de capital */
		double Capital(){
			return capital;
		}
		
		/*Se inicia una funci�n void para darle valor a la variable interes */
		void setInteres(){
			cout << "\nIntroduzca el interes a aplicar: ";
			cin >> interes;
		}
		
		/*Funcion double para mostra el valor de la variable interes */
		double Interes(){
			return interes;
		}	
};

int main() {
	DepositoSimulacion inversion(500, 12.3);
	double anios;
	
	inversion.setCapital();
	inversion.setInteres();
	
	cout << "\nIntroduzca el numero de anios que depositara el capital: ";
	cin >> anios;
	
	if(anios <= 0){
		cout << "\nIntoruzca un numero de a�os mayor que 0: ";
		cin >> anios;
	}
	
	cout << "\nEl capital sera: \n";
	inversion.Inversion(inversion.Capital(), inversion.Interes(), anios);
	
	cout << "\nEl numero de anios necesarios para doblar el capital inicial sera: \n"; 
	cout << inversion.Anios_necesarios(inversion.Capital(), inversion.Interes()) << "\n";
	
	
	system("pause");
}
	

