#include <iostream>
#include <vector>

using namespace std;

/*Se establece una clase liga que dispone de tres datos privados, una matriz que almacena la tabla de equipos
un vector que almacena los puntos de cada equipo, y una variable que contiene el numero de equipos.
Además tiene métodos para establecer la tabla y mostrar los puntos de cada equipo. */
class Liga{
	private: 
		vector < vector <char> > partido;
		vector <int> resultado;
		int equipos;
		
	public:
		
		/*Funcion que sirve para almacenar la tabla en la matriz */
		void setTabla(){
			char final;
			
			cout << "\nIntroduzca el numero de equipos: ";
			cin >> equipos;
			
			cout << "\nIntroduzca los resultado de cada partido de cada equipo: ";
			for(int i = 0; i < equipos; i++){
				for(int j = 0; j < equipos; j++){			//bucle for que almacena los datos de la tabla
					if(j != i){
						cin >> final;
						partido[i].push_back(final);
					}
				}
			}
		}
	
		/*Funcion que cuenta los puntos de cada equipo */
		void ResultadoTabla(){
			int suma_puntos = 0;
			
			for(int i = 0; i < equipos; i++){				//Bucle for que pasa uno a uno por todas las posiciones de la matriz
				for(int j = 0 ; j < equipos; j++){
					if(j != i){
						switch(partido[i][j]){			//Switch que en función del valor de una posicion de la patriz da unos puntos u otros al equipo
							case '1':
								suma_puntos = suma_puntos + 3;
								break;
							case 'X':
								suma_puntos = suma_puntos + 1;
								break;
							case '2':
								suma_puntos = suma_puntos + 0;
								break;
							default:
								suma_puntos = suma_puntos;
							}
						}
					}
				
				resultado.push_back(suma_puntos);
				
				suma_puntos = 0;
			}
		
			for(int i = 0; i < equipos; i++){
				cout << "\nLos puntos del equipo " << i+1 << " son: " << resultado[i] << "\n";
			}
		}
	};
	
	int main () {
		Liga santander;
		
		santander.setTabla();
		
		santander.ResultadoTabla();
		
		system("pause");
	}
