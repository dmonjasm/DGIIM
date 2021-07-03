#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct ParejaCaracterEntero{
	int numero_repeticiones;
	char letra;
};

class VectorParejasCaracterEntero{
	private: 
		vector<char> frase;
	public:
		void setFrase(){
			int amplitud;
			char valor;
			
			cout << "\nIntroduzca la amplitud de la frase: ";
			cin >> amplitud;
			cin.ignore();
			
			cout << "\nIntroduzca los elementos de la frase: ";
			for(int i = 0; i < amplitud; i++){
				cin.get(valor);
				frase.push_back(valor);
			}
			
			cout << "\nLos elementos de la frase son: ";
			for(int i = 0; i < frase.size(); i++){
				cout << frase[i];
			}
			
			cout << "\n";
		}
		
		void BorrarLetras(ParejaCaracterEntero valor){
			int contador = 0;
			int posicion = 0;
			char auxiliar;
			
			do{
				if(frase[posicion] == valor.letra){
					contador++;
					posicion++;
					auxiliar = frase[posicion];
					for(int i = posicion; i < frase.size(); i++){
						if((i + 1) < frase.size())
							frase[i] =  frase[i+1];
						}
					
					frase[frase.size() - 1] = auxiliar;
					
					frase.pop_back();
				}
				
				else
					posicion++;
			}while(contador < valor.numero_repeticiones);
			
			cout << "\nEl vector tras borrar las letras es: ";
			for(int i = 0; i < (frase.size() - valor.numero_repeticiones); i++){
				cout << frase[i];
			}
			
			cout << "\n";
		}
						
						
};

int main() {
	VectorParejasCaracterEntero prueba;
	ParejaCaracterEntero valor;
	
	prueba.setFrase();
	
	cout << "\nIntroduzca la letra que quiere borra: ";
	cin >> valor.letra;
	
	cout << "\nIntroduzca el numero de veces que desea borrar la letra: ";
	cin >> valor.numero_repeticiones;
	
	prueba.BorrarLetras(valor);
	
	system("pause");
}
			
