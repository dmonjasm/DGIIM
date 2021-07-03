#include <iostream>

using namespace std;

class Racional{
	private:
		int entero_1, entero_2;
		int racional;
	
	public:
		Racional() {
			entero_1 = 1;
			entero_2 = 2;
			racional = entero_1 / entero_2;
		}
		
		Racional(int a, int b){
			if(b != 0){
				entero_1 = a;
				entero_2 = b;
				racional = a / b;
			}
			
			else{
				entero_1 = a;
				entero_2 = 2;
				racional = a / 2;
			}
		}
		
		void setEntero1(){
			cout << "\nIntroduzca el primer entero: ";
			cin >> entero_1;
		}
		
		int Entero1(){
			return entero_1;
		}
		
		void setEntero2(){
			cout << "\nIntroduzca el segundo entero: ";
			cin >> entero_2;
		}
		
		int Entero2(){
			return entero_2;
		}
		
		double Raci(){
			return racional;
		}
		
		double Irreducible(int a, int b){
			int MCD = 1;
			int auxiliar;
			int numerador, denominador;
			double irreducible;
			
			if(a > b){
				auxiliar = a;
				a = b;
				b = auxiliar;
			}
			
			for(int i = 2; i <= a; i++){
				if(((a % i) == 0)&&((b % i) == 0))
					MCD = i;
				}
			
			numerador = a / MCD;
			denominador = b / MCD;
			irreducible = numerador / denominador;
			
			return irreducible;
		}
	};
	
	int main() {
		Racional prueba;
		
		prueba.setEntero1();
		prueba.setEntero2();
		
		cout << "\nEl racional irreducible es: " << prueba.Irreducible(prueba.Entero1(), prueba.Entero2()) << "\n";
		
		system("pause");
	}
