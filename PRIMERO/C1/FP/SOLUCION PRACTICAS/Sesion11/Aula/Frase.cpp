#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Frase{
	private:
		vector<char> frase;
	public:
		void setFrase(){
			int amplitud;
			char valores;
			
			cout << "\nIntroduzca la amplitud de la frase que va a utilizar: ";
			cin >> amplitud;
			cin.ignore();
			
			
			cout << "\nIntroduzca la frase: ";
			for(int i = 0; i < amplitud; i++){
				cin.get(valores);
				frase.push_back(valores);
			}
			
			cout << "\nLos valores de la frase son: ";
			for(int i = 0; i <= frase.size(); i++){
				cout << frase[i];
			}
		}
		
		void Palabra(int numero){
			const int LONGITUD = 200;
			int posicion[LONGITUD];
			int contador = 0;
			
			for(int i = 0; i < frase.size(); i++){
				if((i == 0)&&(frase[i] != ' ')){
					posicion[contador] = i;
					contador++;
				}
				else{
					if((frase[i] != ' ')&&(frase[i-1] == ' ')){
						posicion[contador] = i;
						contador++;
					}
				}
			}
			if(numero-1 <= contador)
			cout << "\nLa palabra numero k esta en la posicion " << posicion[numero-1];
			
			else
				cout << "\nLa palabra numero k esta en la posicion -1.";
		}
		
		void BorraPalabra(int k_esima){
			char auxiliar;
			const int LONGITUD = 200;
			int posicion[LONGITUD];
			int contador = 0;
			
			for(int i = 0; i < frase.size(); i++){
				if((i == 0)&&(frase[i] != ' ')){
					posicion[contador] = i;
					contador++;
				}
				else{
					if((frase[i] != ' ')&&(frase[i-1] == ' ')){
						posicion[contador] = i;
						contador++;
					}
				}
			}
			
			for(int i = posicion[k_esima - 1]; i < frase.size(); i++){
				if(frase[i] != ' '){
					auxiliar = frase[i];
					
					for(int j = i + 1; j < frase.size(); j++){
						frase[j-1] = frase[j];
					}
					
					frase[frase.size() - 1] = auxiliar;
					
					frase.pop_back();
				}
			}
			
			cout << "\nEl vector con la palabra borrada es: ";
			for(int i = 0; i < frase.size(); i++){
				cout << frase[i];
			}
		}
					
				
		void NumeroPalabras(){
			const int LONGITUD = 200;
			int posicion[LONGITUD];
			int contador = 0;
			
			for(int i = 0; i < frase.size(); i++){
				if((i == 0)&&(frase[i] != ' ')){
					posicion[contador] = i;
					contador++;
				}
				else{
					if((frase[i] != ' ')&&(frase[i-1] == ' ')){
						posicion[contador] = i;
						contador++;
					}
				}
			}
			
			cout << "\nEl numero de palabras de la frase es: " << contador;
	}		
			
			void EliminaBlancosIniciales(){
				const int LONGITUD = 200;
				char vector[LONGITUD];
				int contador = 0;
				bool blanco = true;
				int posicion = 0;
				
				for(int i = 0; (i < frase.size())&&blanco; i++){
					if(frase[i] == ' '){
						contador++;
						blanco = true;
					}
					else
						blanco = false;
				}
				
				for(int i = contador -1; i < frase.size(); i++){
					vector[posicion] = frase[i];
					posicion++;
				}
			
				cout << "\nEl vector sin espacios en blanco al principio es: ";
				for(int i = 0; i < posicion; i++){
					cout << vector[i];
				}
			}
						
	};
	
	int main() {
		Frase oracion;
		int numero;
		
		oracion.setFrase();
		
		cout << "\nIntroduzca el numero de palabra cuya posicion quiere encontrar: ";
		cin >> numero;
		oracion.Palabra(numero);
		
		oracion.NumeroPalabras();
		
		cout << "\nIntroduzca el numero de palabra cuya posicion quiere encontrar: ";
		cin >> numero;
		oracion.BorraPalabra(numero);
		
		oracion.EliminaBlancosIniciales();
		
	}
			
			
		
