#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/*Se inicia un clase que dispone de cuatro variables privadas y funciones para tratar con dichas variables */
class Libro{
	private:
		string autor, titulo, editorial;
		int anio;
	
	public:
		Libro(){
			autor = "Pio Baroja";
			titulo = "El arbor de la ciencia";
			editorial = "VicensVives";
			anio = 1911;
		}
		
		/*Se inicia una funcion para dar valor a las variables privadas */
		void setLibro(){
			string cadena;
			
			cout << "\nIntroduzca el titulo de un libro, su autor, la editorial y el anio de publicacion: ";
			getline(cin, titulo);
			getline(cin, autor);
			getline(cin, editorial);
			cin >> anio;
		}
		
		string Titulo(){
			return titulo;
		}
		
		string Autor(){
			return autor;
		}
		
		string Editorial(){
			return editorial;
		}
		
		int Anio(){
			return anio;
		}
		
		/*Se inicia una funcion para mostrar los datos de los libros introducidos */
		void Resultado(string autor, string titulo, string editorial, int anio){
			cout << "\nLos datos del libro introducido son: \n";
			cout << "Titulo: " << titulo << "\n";
			cout << "Autor: " << autor << "\n";
			cout << "Editorial: " << editorial << "\n";
			cout << "Anio de publicacion: " << anio << "\n";
		}
		
		/*Se inicia una funcion que compara dos libros y si son iguales devuelve true y si no lo son devuelve false */
		bool Comparacion(string titulo, string autor, string editorial, int anio, string titulo2, string autor2, string editorial2, int anio2){
			if(titulo != titulo2)
				return false;
			else{
					if(autor != autor2)
						return false;
					else{
						if(editorial != editorial2)
							return false;
						else{
							if(anio != anio2)
								return false;
							else
								return true;
							}
						}
					}
				}
			};
	
	int main(){
		Libro primero, segundo;
		
		primero.setLibro();
		segundo.setLibro();
		
		if(primero.Comparacion(primero.Titulo(), primero.Autor(), primero.Editorial(), primero.Anio(), segundo.Titulo(),segundo.Autor(), segundo.Editorial(),segundo.Anio()))
			cout << "\nLos libros introducidos son el mismo.\n";
		
		else
			cout << "\nLos libros introducidos son distintos.\n";
			
		cout << "Los datos de los libros introducidos son: \n";
		cout << "Libro 1: ";
		primero.Resultado(primero.Titulo(),primero.Autor(),primero.Editorial(),primero.Anio());
		cout << "\nLibro 2: ";
		segundo.Resultado(segundo.Titulo(),segundo.Autor(),segundo.Editorial(),segundo.Anio());
		
		system("pause");
	}
