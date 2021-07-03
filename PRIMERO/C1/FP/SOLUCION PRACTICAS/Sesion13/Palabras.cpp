#include <iostream>
#include <cstring>

using namespace std;

bool Iguales(string cadena, string cadena_2){
	int posicion_minimo = 0;
	char minimo = 'a';
	char intercambia = 'a';
	bool iguales = true;
	
	if(cadena.size() == cadena_2.size()){
		if(cadena[0] == cadena[0]){
			if(cadena[cadena.size() - 1] == cadena[cadena.size() -1]){
				for(int i = 1; i < cadena.size() - 1; i++){
					minimo = cadena[i];
					posicion_minimo = i;
					
					for(int j = i+1; j < cadena.size() - 1; j++){
						if(cadena[j] < minimo){
							minimo = cadena[j];
							posicion_minimo = j;
						}
					}
				
					intercambia = cadena[i];
					cadena[i] = cadena[posicion_minimo];
					cadena[posicion_minimo] = intercambia;
				}
				
				for(int i = 1; i < cadena.size() - 1; i++){
					minimo = cadena_2[i];
					posicion_minimo = i;
					
					for(int j = i+1; j < cadena.size() - 1; j++){
						if(cadena[j] < minimo){
							minimo = cadena_2[j];
							posicion_minimo = j;
						}
					}
				
					intercambia = cadena_2[i];
					cadena_2[i] = cadena_2[posicion_minimo];
					cadena_2[posicion_minimo] = intercambia;
				}
				
				for(int i = 1; i < cadena.size() -1; i++){
					if(cadena[i] == cadena_2[i])
						iguales = true;
					else
						iguales = false;
					}
				
				if(iguales)
					return true;
				else
					return false;
			}
		}
	}
	
	else
		return false;
	}
	
	int main(){
		string cadena1, cadena2;
		bool iguales = true;
		
		cout << "\nINtroduzca la amplitud de la primera cadena: ";
		cin >> cadena1;
		
		cout << "\nIntroduzca la amplitud de la segunda cadena: ";
		cin >> cadena2;
		
		iguales = Iguales(cadena1, cadena2);
		
		if (iguales)
			cout << "\nLas cadenas son iguales.\n";
			
		else
			cout << "\nLas cadenas son distintas.\n";
			
		system("pause");
	}
		
		
		
				
				
					
					
					
