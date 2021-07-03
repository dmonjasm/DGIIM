#include <iostream>
#include <cstring>

using namespace std;

/*Clase examen que incluye tres variables privadas, una es un vector string que contiene las preguntas, otro es un vector char que contiene la respuesta del test y otro es
una variable de tipo entero que contiene el numero de preguntas.*/
class Examen{
	private:
		static const int PREGUNTAS = 200;
		string relacion[PREGUNTAS];
		char respuestas[PREGUNTAS];
		int numero_preguntas;
		
	public:
		Examen(){
			numero_preguntas = 0;
			relacion[0] = ' ';
			respuestas[0] = ' ';
		}
	
	/*Se inicia una función tipo void que pida tantas preguntas y respuestas como el numero introducido, y las almacene en el vector de preguntas y en el de respuestas
	respectivamente */		
		void NuevaPregunta(int numero){							
			string nueva_pregunta;
			
			
			cout << "\nIntroduzca la nueva pregunta: ";
			cin.ignore();
			
			for(int i = 0; i < numero; i++){
				getline(cin, relacion[numero_preguntas]);
				numero_preguntas++;
			}
			
			numero_preguntas = 0;
			cout << "\nIntroduzca la respuesta a la pregunta introducida: ";
			for(int i = 0; i < numero; i++){
				cin >> respuestas[numero_preguntas];
				numero_preguntas++;
			}
		}
		
		int NumPreguntas(){								//Funcion tipo int que devuelve el numero de preguntas del test introducidas hasta el momento
			return numero_preguntas;
		}
		
		string GetEnunciado(int numero){				//Funcion tipo string que devuelve la pregunta asociada al numero introducido
			return relacion[numero - 1];
		}
		
		char GetRespuesta(int numero){				//Funcion tipo char que devuelve la respuesta asociada al numero introducido
			return respuestas[numero - 1];
		}
	};
	
	int main() {
		Examen test;
		int numero;
		
		cout << "\nIntroduzca el numero de preguntas del test: ";
		cin >> numero;
		
		test.NuevaPregunta(numero);
		cout << "\nEl numero de preguntas del test son: " << test.NumPreguntas() << "\n";
		
		cout << "\nIntroduzca el numero de pregunta cuyo enunciado quiere ver: ";
		cin >> numero;
		
		cout << "\nLa pregunta es: " << test.GetEnunciado(numero) << "\n";
		cout << "\nLa respuesta es: " <<	test.GetRespuesta(numero) << "\n";
		
		cout << "\n";
		
		system("pause");
	}
		
