#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*Clase que cuenta con una variable privada de tipo vector, y que posee metodos para dar valor a dicho vector, realizar la union y la interseccion de dos vectores, eliminar una 
posicion del vector, insertar un elemento al vector y comprobar si un elemento pertenece al vector */
class Conjunto{
	private:
		vector<int> vec1;
		
	public:
		Conjunto(){
			vector<int> vec1;
		}
		
		/*Clase para definir los valores del conjunto y ordenarlos de menor a mayor */
		void setConjunto(){
			int minimo, posicion_minimo, intercambia;
			int amplitud, valor;
			
			cout << "\nIntroduzca la amplitud del conjunto: ";
			cin >> amplitud;
			
			cout << "\nIntroduzca los valores del conjunto: ";
			for(int i = 0; i < amplitud; i++){									//Se toman los valores del vector
				cin >> valor;
				
				vec1.push_back(valor);
			}
			
			for(int i = 0; i < vec1.size(); i++){
				minimo = vec1[i];
				posicion_minimo = i;
				
				for(int j = i+1; j < vec1.size(); j++){						//Se ordenan de mayor a menor los valores del vector
					if(vec1[j] < minimo){
						minimo = vec1[j];
						posicion_minimo = j;
					}
				}
				
				intercambia = vec1[i];
				vec1[i] = minimo;
				vec1[posicion_minimo] = intercambia;
			}
			
			cout << "\nLos valores del conjunto ordenado son: ";
			for(int i = 0; i < vec1.size(); i++){
				cout << vec1[i] << " ";
			}
			
			cout << "\n";
		}
		
		/*Funcion bool que comprueba si un entero esta contenido en el vector*/
		bool Contenido (int entero){
			bool dentro = false;
			
			for(int i = 0; (i < vec1.size())&&(dentro == false); i++){			//Si el entero esta contenido se devuelve true, si no se devuelve false
				if(vec1[i] == entero)
					dentro = true;
				else
					dentro = false;
				}
			
			if(dentro)
				return true;
			else
				return false;
	}
		
		/*Funcion para insertar un entero en el conjunto previamente definido */
		void Insertar (int entero){
			int minimo, posicion_minimo, intercambia;
			
			vec1.push_back(entero);			//Se añade al final del conjunto y luego se ordena de nuevo el conjunto
			
			for(int i = 0; i < vec1.size(); i++){
				minimo = vec1[i];
				posicion_minimo = i;
				
				for(int j = i+1; j < vec1.size(); j++){
					if(vec1[j] < minimo){
						minimo = vec1[j];
						posicion_minimo = j;
					}
				}
				
				intercambia = vec1[i];
				vec1[i] = minimo;
				vec1[posicion_minimo] = intercambia;
			}
			
			cout << "\nEl conjunto ordenado tras insertar el numero entero es: ";
			for(int i = 0; i < vec1.size(); i++){
				cout << vec1[i] << " ";
			}
			
			cout << "\n";
		}
		
		/*Funcion para eliminar una posicion */
		void Eliminar(int posicion){
			int ultima_posicion = vec1.size() - 1;
			int intercambia, minimo, posicion_minimo;
			
			intercambia = vec1[posicion-1];
			vec1[posicion-1] = vec1[ultima_posicion];
			vec1[ultima_posicion] = intercambia;
			
			vec1.pop_back();
			
			for(int i = 0; i < (vec1.size()-1); i++){
				minimo = vec1[i];
				posicion_minimo = i;
				
				for(int j = i+1; j < (vec1.size()-1); j++){
					if(vec1[j] < minimo){
						minimo =vec1[j];
						posicion_minimo = j;
					}
					
					intercambia = vec1[i];
					vec1[i] = minimo;
					vec1[posicion_minimo] = intercambia;
				}
			}
			
			cout << "\nEl conjunto ordenado tras eliminar la posicion es: ";
			for(int i = 0; i < vec1.size(); i++){
				cout << vec1[i] << " ";
			}
		}
		
		/*Funcion para realizar la union de dos conjuntos */
		void Union(){
			const int LONGITUD = 200;
			int suma[LONGITUD];
			int resultado[LONGITUD];
			int contador = 0, amplitud;
			int minimo, posicion_minimo, intercambia;
			
			cout << "\nIntroduzca la amplitud del conjunto que desea unir: ";
			cin >> amplitud;
			
			cout << "\nIntroduzca los elementos del conjunto que desea unir: ";
			for(int i = 0; i < amplitud; i++){
				cin >> suma[i];
			}
			
			/*Se almacenan al final del vector los valores del segundo vector que no esten previamente en este y luego se ordenan obteniendo la union */
			for(int i = 0; i < amplitud; i++){
				if(Contenido(suma[i]) == false)
					vec1.push_back(suma[i]);
			}
			
			for(int i = 0; i < vec1.size(); i++){
				minimo = vec1[i];
				posicion_minimo = i;
				
				for(int j = i+1; j < vec1.size(); j++){
					if(vec1[j] < minimo){
						minimo = vec1[j];
						posicion_minimo = j;
					}
				}
				
				intercambia = vec1[i];
				vec1[i] = minimo;
				vec1[posicion_minimo] = intercambia;
			}
			
			cout << "\nEl conjunto ordenado resultado de la union de ambos conjuntos es: ";
			for(int i  = 0; i < vec1.size(); i++){
				cout << vec1[i] << " ";
			}
			
			cout << "\n";
		}
			
			
				
			
			
		void Interseccion(){
			const int LONGITUD = 200;
			int interseccion[LONGITUD];
			int resultado[LONGITUD];
			int contador = 0, amplitud;
			int minimo, posicion_minimo, intercambia;
			
			cout << "\nIntroduzca la amplitud del vector: ";
			cin >> amplitud;
			
			cout << "\nIntroduzca los elementos del vector: ";
			for(int i = 0; i < amplitud; i++){
				cin >> interseccion[i];
			}
			
			for(int i = 0; i < vec1.size(); i++){
				for(int j = 0; j < amplitud; j++){
					if(vec1[i] == interseccion[j]){
						resultado[contador] = vec1[i];
						contador++;
					}
				}
			}
			
			for(int i = 0; i < contador; i++){
				minimo = resultado[i];
				posicion_minimo = i;
				
				for(int j = i+1; j < contador; j++){
					if(resultado[j] < minimo){
						minimo = resultado[j];
						posicion_minimo = j;
					}
				}
				
				intercambia = resultado[i];
				resultado[i] = minimo;
				resultado[posicion_minimo] = intercambia;
			}
			
			cout << "\nLa interseccion de los dos vectores es: ";
			for(int i = 0; i < contador; i++){
				cout << resultado[i] << " ";
			}
		}			
	};
	
	
	int main() {
		Conjunto prueba;
		int entero, posicion;
		char operacion;
		
		prueba.setConjunto();
		
		cout << "\nIntroduzca un entero para comprobar si esta contenido en el conjunto: ";
		cin >> entero;
		
		if(prueba.Contenido(entero))
			cout << "\nEl entero introducido esta contenido en el conjunto.\n";
		else
			cout << "\nEl entero introducido no esta contenido en el conjunto.\n";
		
		cout << "\nIntroduzca la operacion que desea realizar (i = insertar/ e = eliminar /u = union / r = interseccion): ";
		cin >> operacion;
		
		switch(operacion){
			case 'i':	
				cout << "\nIntroduzca el numero que quiere insertar en el conjunto: ";
				cin >> entero;
		
				prueba.Insertar(entero);
				break;
			case 'd':
				cout << "\nIntroduzca la posicion del conjunto que quiere eliminar: ";
				cin >> posicion;
		
				prueba.Eliminar(posicion);
				break;
			case 'u':		
				prueba.Union();
				break;
		
			case 'r':
				prueba.Interseccion();
				break;
			default: NAN;
	}
		system("pause");
	}
				
