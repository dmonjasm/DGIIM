/*Programa que deermine si un elemento se encuentra en un conjunto
incorore un nuevo elemento al conjunto
calcule la unión de dos conjuntos
calcule la intersección de dos conjuntos.
*/

#include <iostream>
#include <cmath>

using namespace std;

struct TipoConjunto{
	int num_elem;
	int elementos[1000];
};

int main() {
	TipoConjunto prueba, suma, interseccion;
	int elemento, elemento2;
	bool pertenece, insercion;
	int suma_elementos = 0;
	
	cout << "Introduzca la amplitud del vector: ";
	cin >> prueba.num_elem;
	
	cout << "\nIntroduzca los elementos del vector: ";
	
	for (int i = 0; i < prueba.num_elem; i++){			//Se inicia un bucle for que tome los elementos del vector
		cin >> prueba.elementos[i];
	}
	
	cout << "\nIntroduza el elemento que quiere comprobar si se encuentra en el conjunto: ";
	cin >> elemento;
	
	for (int j = 0; (j < prueba.num_elem)&&(pertenece == false); j++){			//Se inicia un bucle for que compare los elementos del vector con el elemento dado por el usuario
		if (prueba.elementos[j] == elemento)												//si se encuentra alguna coincidencia el bucle termina y el numero pertenece
			pertenece = true;																		//si no se encuentra compara el elemento con todos los del vector y al terminar muestra que no pertenece
		else
			pertenece = false;
}
	if (pertenece)
		cout << "\nEl numero introducido pertenece al conjunto.\n";
	else
		cout << "\nEl numero introducido no pertenece al conjunto.\n";
		
	
	cout << "\nIntroduzca el elemento que quiere incorporar al conjunto: ";
	cin >> elemento2;
	
	for (int k = 0;( k < prueba.num_elem)&&(insercion == false); k++){			//Se inicia un bucle for en el que si el elemento introducido es menor o igual que el vector en alguna
		if (prueba.elementos[k] >= elemento2){												//de sus posiciones se desplacen todos los elementos del vector a partir de esa posicion una posicion 
			for(int l = prueba.num_elem; l >= (k + 1); l--){							//a la derecha y la posicion toma el valor del elemento, el bucle termina una vez se asigna al elemento
				prueba.elementos[l] = prueba.elementos[l - 1];							//una posicion del vector
			}
			prueba.elementos[k] = elemento2;
			insercion = true;
		}
		else{																							//si no el vector permanece tal cual
			prueba.elementos[k] = prueba.elementos[k];
			insercion = false;
		}	
		}
	
	cout << "\nEl vector con la nueva componente es: ";
	
	for (int m = 0; m <= prueba.num_elem; m++){			//Se muestra en pantalla el resultado
		cout << prueba.elementos[m] << " ";
	}
	
	cout << "\n";
	
	cout << "\nIntroduzca la amplitud del vector que quiere unir con el anterior: ";
	cin >> suma.num_elem;
	

	
	cout << "\nIntroduzca los componentes del vector que quiere unir con el anterior: ";
	for (int i = 0; i < suma.num_elem; i++){				//Se inicia un bucle for que tome los valores del vector suma
		cin >> suma.elementos[i];
	}
	
	for (int j = suma.num_elem; j <= (prueba.num_elem + suma.num_elem); j++){		//Se inicia un bucle for que añada al vector suma los valores del vector prueba
		suma.elementos[j] = prueba.elementos[suma_elementos];
		suma_elementos++;
	}
	
	cout << "\nLa union de ambos conjuntos es: ";
	for (int i = 0; i <= (suma.num_elem + prueba.num_elem); i++){			//Se inicia un bucle for que muestre por pantalla los resultados.
		cout << suma.elementos[i] << " ";
	}
	
	cout << "\n";
	
	cout << "\nIntroduzca la amplitud del vector del cual quiere calcular la intersección con el anterior: ";
	cin >> interseccion.num_elem;
	
	cout << "\nIntroduzca los componentes del vector interseccion: ";
	for (int i = 0; i < interseccion.num_elem; i++){						//Se inicia un bucle for que tome los valores del vector interseccion
		cin >> interseccion.elementos[i];
	}
	
	for (int i = 0; i < prueba.num_elem; i++){
		for (int j = 0; j < interseccion.num_elem; j++){
			if (prueba.elementos[i] == interseccion.elementos[j])
				interseccion.elementos[i] = prueba.elementos[i];			//No consigo que funciones la parte de la interseccion
			else
				interseccion.elementos[i] = 0;
		}
	}
	
	cout << "\nLa interseccion de ambos vectores es: ";
	for (int i = 0; i < prueba.num_elem; i++){
		cout << interseccion.elementos[i] << " ";
	}
	
	cout << "\n";
	
	system("pause");
}
		
