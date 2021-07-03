/*Programa que permitar saber si dos vectores de enteros son iguales.
Se asume que son guales si el número de componenetes útiles de amos vetores
es el mismo, y el valor de sus componentes coincide uno a uno.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int LONGITUD = 200;
	int vector_1[LONGITUD], vector_2[LONGITUD];
	int amplitud_1, amplitud_2;
	int k;
	bool igualdad;
	
	cout << "Introduzca la amplitud del vector 1 que va a utilizar(debe ser como maximo 200): ";
	cin >> amplitud_1;
	cout << "\nIntroduzca la amplitud del vector 2 que va a utilizar(debe ser como maximo 200): ";
	cin >> amplitud_2;
	
	if (amplitud_1 != amplitud_2)			//Se establece un condicional en el que si la amplitud de los vectores es distinta muestre un mensaje de error y pause el programa
		cout << "\nLos vectores tienen longitudes distintas y por tanto no son iguales.\n";
	
	else{			//Si la amplitud de los vectores es igual entonces se ejecutan los bucle for
		for (int i = 0; i < amplitud_1; i++){			//Se establece un bucle que pida tantos datos como la amplitud que el usuario ha introducido
		
			cout << "Introduzca los numeros del vector 1 (maximo 200): ";
			cin >> vector_1[i];
		
	}
	
		for (int j = 0; j < amplitud_2; j++){			//Se establece otro bucle que pida tantos datos como la amplitud que el usuario ha introducido
		
			cout << "Introduzca los numeros del vector 2 (maximo 200): ";
			cin >> vector_2[j];
		
	}

	
		k = 0;			//Se establece un contador que se utilizará en el bucle do while
		
		do {			//Se inicia un bucle do while que se repetira siempre que la variable booleana sea true y el contador sea menor o igual que la amplitud.
			if (vector_1[k] == vector_2[k])			//Se establece un condicional que compara los terminos de los vectores y si se cumple se le asigna true a igualdad
				igualdad = true;
			else 
				igualdad = false;							//Si no se le asigna fals a la variable igualdad
			
			k++;
		}while ((igualdad = true)&&(k < amplitud_1));
		
		if (igualdad == true)			//Si el ultimo valor de igualdad es true los componenetes son iguales
			cout << "\nLos componenetes del vector 1 son iguales que los componentes del vector 2.\n";
		else			//Si no alguno de los componentes es distinto
			cout << "\nLos componenetes del vector 2 no son iguales que los componenete del vector 2.\n";
		}
		
		system("pause");
	}

	
	
