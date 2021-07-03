#include <iostream>
#include <cmath>

using namespace std;

class EnteroLargo{
	private:
		static const int LONGITUD = 200;
		int num_elementos, digitos[LONGITUD];
	
	public:
		EnteroLargo(){
			num_elementos = 0;
			digitos[0] = 0;
		}
		
		void setNum_elementos(){
			cout << "\nIntroduzca el numero de digitos del numero entero: ";
			cin >> num_elementos;
		}
		
		void setDigitos(){
			cout << "\nIntroduzca los digitos del numero (separandolos por espacios): ";
			for(int i  = 0; i < num_elementos; i++){
				cin >> digitos[i];
			}
		}
		
		void Menor(int numero[], int amplitud){
			bool menor1 = false;
			bool menor2 = false;
			bool iguales = false;
			
			if(amplitud > num_elementos)
				cout << "\nEl primer numero es menor que el segundo.";
			else{
				if(num_elementos > amplitud)
					cout << "\nEl segundo numero es menor que el primero.";
				else{
					for(int i = 0; (i < amplitud)&&(iguales); i++){
						if(digitos[i] > numero[i]){
							menor2 = true;
							iguales = false;
						}
						else{
							if(digitos[i] < numero[i]){
								menor1 = true;
								iguales = false;
							}
							else{
								menor1 = false;
								menor2 = false;
								iguales = true;
							}
						}
					}
				}
				if(menor1)
					cout << "\nEl numero 1 es menor que el numero 2.";
				else{
					if(menor2)
						cout << "\nEl numero 2 es menor que el numero 1.";
			}
		}
	}

		
		void Mayor(int numero[], int amplitud){
			bool mayor1 = false;
			bool mayor2 = false;
			bool iguales = true;
			
			if(num_elementos > amplitud)
				cout << "\nEl primer numero es mayor que el segundo.";
			else{
				if(num_elementos < amplitud)
					cout << "\nEl segundo numero es mayor que el primero.";
				else{
					for(int i = 0; (i < amplitud)&&(iguales); i++){
						if(digitos[i] > numero[i]){
							mayor1 = true;
							iguales = false;
						}
						else{
							if(digitos[i] < numero[i]){
								mayor2 = true;
								iguales = false;
							}
							else{
								mayor1 = false;
								mayor2 = false;
								iguales = true;
							}
						}
					}
					if(mayor1)
						cout << "\nEl numero 1 es mayor que el numero2.";
					else{
						if(mayor2)
							cout << "\nEl numero 2 es mayor que el numero 1.";
					
				}
			}
		}
	}
			
		void Igual(int numero[], int amplitud){
			bool iguales = false;
				
			if(amplitud != num_elementos)
				cout << "\nLos numeros son distintos.";
			else{
				for(int i = 0; (i < amplitud)&&(iguales); i++){
					if(numero[i] == digitos[i])
						iguales = true;
					else
						iguales = false;
					}
				if(iguales)
					cout << "\nLos numeros introducidos son iguales.";
				else
					cout << "\nLos numeros introducidos son distintos.";
			}
		}
		
		void Distinto(int numero[], int amplitud){
			bool distintos = false;
			
			if(amplitud != num_elementos)
				cout << "\nLos numeros son distintos.";
			else{
				for(int i = 0;(i < amplitud)&&(distintos == false); i++){
					if(numero[i] == digitos[i])
						distintos = false;
					else
						distintos = true;
					}
					if(distintos)	
						cout << "\nLos numeros introducidos son distintos.";
					else	
						cout << "\nLos numeros introducidos son iguales.";
					}
	}
		
		void MenorIgual(int numero[], int amplitud){
			bool iguales = false;
			
			if(num_elementos < amplitud)
				cout << "\nEl numero 1 es menor o igual que el numero 2.";
			else{
				if(num_elementos == amplitud){
					for(int i = 0; (i < amplitud)&&(iguales == false); i++){
						if(numero[i] == digitos[i])
							iguales = true;
						else{
							if(digitos[i] < numero[i])
								iguales = false;
							}
						}
					if(!iguales)
						cout << "\nEl numero 1 es menor o igual que el numero 2.";
					else{
						if(iguales)
							cout << "\nEl numero 1 es menor o igual que el numero 2.";
						}
					}
				else
					cout << "\nEl numero 2 es menor o igual que el numero 1.";
				}
			}
		
		void MayorIgual(int numero[], int amplitud){
			bool iguales = false;
			
			if(num_elementos > amplitud)
				cout << "\nEl numero 1 es mayor o igual que el numero 1.";
			else{
				if(num_elementos == amplitud){
					for(int i = 0;(i < amplitud)&&(iguales == false); i++){
						if(numero[i] == digitos[i])
							iguales = true;
						else{
							if(digitos[i] > numero[i])
								iguales = false;
							}
						}
					if(digitos)
						cout << "\nEl numero 1 es mayor o igual que el numero 2.";
					else{
						if(!digitos)
							cout << "\nEl numero 1 es mayor o igual que el numero 2.";
						}
					}
				else
					cout << "\nEl numero 2 es mayor o igual que el numero 1.";
				}
			}
			
		void Suma(int numero[], int amplitud){
			int nueva_amplitud = num_elementos - 1;
			int resultado[LONGITUD];
			int contador = 0;
			int nueva_amplitud2 = amplitud - 1;
			
			if(amplitud < num_elementos){
				for(int i = (amplitud - 1); i >= 0; i--){
					resultado[contador] = numero[i] + digitos[nueva_amplitud];
					nueva_amplitud--;
					
					if((resultado[contador - 1] > 10)&&(contador >= 1))
						resultado[contador]++;
						
					contador++;
				}
			}
			
			else{
				
				if(amplitud > num_elementos){
					for(int i = num_elementos - 1; i >= 0; i--){
						resultado[contador] = numero[nueva_amplitud2] + digitos[i];
						nueva_amplitud2--;
						
						if((resultado[contador - 1] > 10)&&(contador >= 1))
							resultado[contador]++;
							
						contador++;
					}
				}
				
				else{
					if(amplitud == num_elementos){
						for(int i = amplitud - 1; i >= 0; i--){
							resultado[contador] = numero[nueva_amplitud2] + digitos[i];
							
							if((resultado[contador - 1] > 10)&&(contador >= 1))
								resultado[contador]++;
							
							contador++;
						}
					}
				}
			}
			
		cout << "\nLa suma de los dos numeros es: ";
		for(int i = 0; i < contador; i++){
			cout << resultado[i];
		}
		
		cout << "\n";
	}
};


int main() {
	EnteroLargo numero;
	const int LONGITUD = 200;
	int numero_2[LONGITUD];
	int amplitud;
	
	numero.setNum_elementos();
	numero.setDigitos();
	
	cout << "\nIntroduzca el numero de digitos del segundo numero: ";
	cin >> amplitud;
	
	cout << "\nIntroduzca los digitos del segundo numero: ";
	for(int i = 0; i < amplitud; i++){
		cin >> numero_2[i];
	}
	
	numero.Menor(numero_2, amplitud);
	
	numero.Mayor(numero_2, amplitud);
	
	numero.Igual(numero_2, amplitud);
	
	numero.Distinto(numero_2, amplitud);
	
	numero.MenorIgual(numero_2, amplitud);
	
	numero.MayorIgual(numero_2, amplitud);
	
	numero.Suma(numero_2, amplitud);
	
	system("pause");
}		
