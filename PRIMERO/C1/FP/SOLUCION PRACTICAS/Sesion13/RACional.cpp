#include <iostream>

using namespace std;

class Racional {
	private:
		int numerador;
		int denominador;
	
	public:
		Racional(){
			numerador = 1;
			numerador = 2;
		}
		
		Racional(int a, int b){
			if(b != 0){
				numerador = a;
				denominador = b;
			}
			
			else{
				numerador = a;
				denominador = 2;
			}
		}
		
		void setNumerador(){
			cout << "\nIntroduzca el numerador del racional: ";
			cin >> numerador;
		}
		
		int mostrarNumerador(){
			return numerador;
		}
		
		void setDenominador(){
			cout << "\nIntroduzca el denominador del racional: ";
			cin >> denominador;
		}
		
		int mostrarDenominador(){
			return denominador;
		}
		
		double Irreducible(int a, int b){
			int num = a;
			int den = b;
			double divisor = 0;
			double racional = 0;
			
			for(int i = 2; i <= a; i++){
				if(((num % i) == 0)&&((den % i) == 0))
					divisor = i;
				}
			
			if(divisor == 0)
				divisor = 1;
			
			numerador = num / divisor;
			denominador = den / divisor;
			racional = numerador / denominador;
			
			return racional;
		}
		
	};
	
	int main() {
		Racional prueba;
		double racional;
		
		prueba.setNumerador();
		prueba.setDenominador();
		
		racional = prueba.Irreducible(prueba.mostrarNumerador(),prueba.mostrarDenominador());
		
		cout << "\nEl racional irreducible es: " << racional << "\n";
		
		system("pause");
	}
			
			
