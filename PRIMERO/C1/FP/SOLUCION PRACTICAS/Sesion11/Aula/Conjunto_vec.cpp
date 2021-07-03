#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Conjunto{
	private:
		vector<int> vec1;
	public:
		Conjunto(){
			vector<int> vec1(10);
		}
		
		void setVector(){
			int amplitud;
			int minimo, posicion_minimo, intercambia;
		
		cout << "\nIntroduzca la amplitud del vector: ";
		cin >> amplitud;
		
		vector<int> vec1(amplitud);
		
		cout << "\nIntroduzca los elementos del vector: ";
		for(int i = 0; i < vec1.size(); i++){
			cin >> vec1[i];
		}
		
		cout << "\nERROR";

		for(int i = 0; i < vec1.size(); i++){
			minimo = vec1[i];
			
			for(int j = i+1; j < vec1.size(); j++){
				if(vec1[j] <= minimo){
					minimo = vec1[j];
					posicion_minimo = j;
				}
			}
			
			intercambia = vec1[i];
			vec1[i] = minimo;
			vec1[posicion_minimo] = intercambia;
		}
	
	
		cout << "\nEl vector ordenado es: ";
		for(int i = 0; i < vec1.size(); i++){
			cout << vec1[i] << " ";
	}
}
		bool Contenido(int entero){
			int amplitud = vec1.size();
			bool contenido = false;
			
			for(int i = 0; (i < amplitud)&&(contenido = false); i++){
				if(vec1[i] == entero)
					contenido = true;
				else 
					contenido = false;
				}
			if(contenido)
				return true;
			else
				return false;
		}
		
		void Insertar(int entero){
			int minimo, posicion_minimo, intercambia;
		
			vec1.push_back(entero);
			
			int amplitud = vec1.size();
			
			for(int i = 0; i < amplitud; i++){
				minimo = vec1[i];
				
				for(int j = i+1; j < amplitud; j++){
					if(vec1[j] < minimo){
						minimo = vec1[j];
						posicion_minimo = j;
					}
				
				intercambia = vec1[i];
				vec1[i] = minimo;
				vec1[posicion_minimo] = intercambia;
			}
		}
		
		cout << "\nEl vector ordenado tras insertar el numero es: ";
		for(int i = 0; i < amplitud; i++){
			cout << vec1[i] << " ";
		}	
	}
	
		void Eliminar(int posicion){
			int auxiliar;
			int amplitud = vec1.size();
			int minimo, posicion_minimo, intercambia;
			
			auxiliar = vec1[posicion - 1];
			vec1[posicion - 1] = vec1[amplitud - 1];
			vec1[amplitud - 1] = auxiliar;
			
			vec1.pop_back();
			
			amplitud = vec1.size();
			
			for(int i = 0; i < amplitud; i++){
				minimo = vec1[i];
				
				for(int j = i+1; j < amplitud; j++){
					if(vec1[j] < minimo){
						minimo = vec1[j];
						posicion_minimo = j;
					}
				}
				
				intercambia = vec1[i];
				vec1[i] = minimo;
				vec1[posicion_minimo] = intercambia;
			}
			
			cout << "\nEl vector ordenado tras eleminar un elementos es: ";
			for(int i = 0; i < amplitud; i++){
				cout << vec1[i] << " ";
			}
		}
	};
		
	int main() {
		Conjunto vector;
		int posicion;
		int entero;
		
		
		vector.setVector();
		
		cout << "\nIntroduzca el numero que quiere comprobar si esta incluido en el conjunto: ";
		cin >> entero;
		
		if(vector.Contenido(entero))
			cout << "\nEl numero introducido esta incluido en el conjunto.";
		else
			cout << "\nEl numero introducido no esta incluido en el conjunto.";
		
		cout << "\nIntroduzca la posicion del conjunto que quiera eliminar: ";
		cin >> posicion;
		
		vector.Eliminar(posicion);
		
		system("pause");
	}
