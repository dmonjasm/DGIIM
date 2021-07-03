#include <iostream>
#include <cmath>

using namespace std;

class Conjunto{
	private :
		static const int MAXELEM = 100;
		int num_elem;
		int elementos[MAXELEM];
	
	public:
		Conjunto(){
			num_elem = 0;
			elementos[0] = 0;
		}
		
		void setConjunto(){
			cout << "\nIntroduzca la amplitud del conjunto: ";
			cin >> num_elem;
			
			cout << "\nIntroduzca los elementos del conjunto: ";
			for(int i = 0; i < num_elem; i++){
				cin >> elementos[i];
			}
		}
		
		void Ordenacion(){
			int minimo, posicion_minimo, intercambia;
			
			for (int izda = 0; izda < num_elem; izda++){
				minimo = elementos[izda];
				posicion_minimo = izda;
			
				for(int i = izda + 1; i < num_elem; i++){
					if(elementos[i] < minimo){
						minimo = elementos[i];
						posicion_minimo = i;
					}
				}
				
				intercambia = elementos[izda];
				elementos[izda] = elementos[posicion_minimo];
				elementos[posicion_minimo] = intercambia;
		}
			cout << "\nLos elementos del vector ordenado son: ";
			for(int i = 0; i < num_elem; i++){
				cout << elementos[i] << " ";
			}
		}
		
		bool Contenido(int entero){
			bool dentro;
			for(int i = 0; (i < num_elem)&&(dentro == false); i++){
				if(entero == elementos[i])
					dentro = true;
				else
					dentro = false;
				}
			
			if(dentro)
				return true;
			else
				return false;
			}
		
		void Insertar(int entero){
			int amplitud;
			if(Contenido(entero))
				cout << "\nEl entero ya esta en el conjunto";
			else{
				amplitud = num_elem;
				amplitud++;
				elementos[amplitud - 1] = entero;
				
				Ordenacion();
				
				cout << "\nEl conjunto con el nuevo elemento es: ";
				for(int i = 0; i < amplitud; i++){
					cout << elementos[i] << " ";
				}
			}
		}
		
		void Eliminar(int posicion){
			int amplitud, tope;
				amplitud = num_elem;
				
			if(posicion >= 0 && posicion < amplitud){
				tope = amplitud - 1;
				
				for(int i = posicion; i < tope; i++)
					elementos[i] = elementos[i + 1];
					
				amplitud--;
			}
		}
		
		void Union(Conjunto numero2){
			for(int i = 0; i < numero2.num_elem; i++){
				elementos[num_elem] = numero2.elementos[i];
				
				num_elem++;
			}
			
			for(int i = 0; i < num_elem; i++){
				for(int j = i+1; j < num_elem; j++){
					if(elementos[i] == elementos[j])
						Eliminar(j);
					}
				}
			
			Ordenacion();
			
			cout << "\nLa union ordenada de los dos vectores es: ";
			for( int i = 0; i < num_elem; i++){
				cout << elementos[i] << " ";
			}
		}
		
		void Interseccion(Conjunto numero2){
			const int LONGITUD = 300;
			int contador = 0;
			int resultado[LONGITUD];
			
			for(int i = 0; i < num_elem; i++){
				for(int j = 0; j < numero2.num_elem; j++){
					if(elementos[i] == numero2.elementos[i])
						resultado[contador] = elementos[i];
						contador++;
					}
				}
			
			for(int i = 0; i < contador; i++){
				for(int j = i+1; j < contador; j++){
					if(resultado[i] == resultado[j])
					Eliminar(j);
				}
			}
			
			Ordenacion();
			
			cout << "\nLa interseccion de los dos elementos es: ";
			for(int i = 0; i < contador; i++){
				cout << resultado[i] << " ";
			}
		}
	};

	
	
	int main() {
		Conjunto inicio, resultado;
		int entero;
		int posicion;
		
		inicio.setConjunto();
		inicio.Ordenacion();
		
		
		cout << "\nIntroduzca el entero que quiere comprobar si esta contenido en el conjunto: ";
		cin >> entero;
		
		
		if(inicio.Contenido(entero))
			cout << "\nEl numero introducido esta contenido en el conjunto.";
		else
			cout << "\nEl numero introducido no esta contenido en el conjunto. ",
			
			
		cout << "\nIntroduzca el entero que desea incorporar al conjunto: ";
		cin >> entero;
		
		
		inicio.Insertar(entero);
		
		
		cout << "\nIntroduzca la posicion dle vector que desea eleminiar: ";
		cin >> posicion;
		
		
		inicio.Eliminar(posicion);
		
		
		resultado.setConjunto();
		
		inicio.Union(resultado);
		inicio.Interseccion(resultado);
		
		system("pause");
	}				
