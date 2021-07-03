/*Programa que lea desde teclado un resgistro, el cual termina al leer @
y que diga qué pais el que más hortalizas exporta y las tonealadas que exporta.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const char TERMINADOR = '@';
	char pais, hortalizas;
	int  toneladas, suma_espana, suma_francia, suma_alemania;
		suma_espana = 0;
		suma_francia = 0;
		suma_alemania = 0;

	do {			//Se inicia un bucle do while que ejecuta el siguiente bloque y si se cumple la condición de while lo vuelve a ejecutar hasta que deje de cumplirse
		cout << "Introduzca un país (E: Espana/F: Francia/ A: Alemania): ";
		cin >> pais;
		
		if (pais != '@'){			//Se establece un condicional en el que si el valor de pais es distinto del literal de caracter '@' ejecute el siguiente bloque
			cout << "\nIntroduzca el tipo de hortaliza exportada (T: Tomates/P: Patatas/E: Espinacas): ";		//Se piden datos al usuario y se guardan en las variables
			cin >> hortalizas;
			cout << "\nIntroduzca el numero de toneladas exportados: ";
			cin >> toneladas;
			
			if (pais == 'E')			//Si el valor de la variable pais es igual al literal de caracer 'E' 
				suma_espana = suma_espana + toneladas;			//se le asigna a suma_espana el valor de la suma de las toneladas con el anterior valor de la variable
			else{
				if (pais == 'F')		//Si el valor de la variable pais es igual al literal de caracter 'F'
					suma_francia = suma_francia + toneladas;	//se le asigna  a suma_espana el valor de la suma de las toneladas con el anterior valor de la variable
				else{
		 			if (pais == 'A')		//Si el valor de la variable pais es igual al literal de caracter 'A'
					 	suma_alemania = suma_alemania + toneladas;		//se le asigna a suma_alemania el valor de la suma de las toneadas con el anterior valor de la variable
					else
						pais = '@';		//Si no se cumple ninguna de las anteriores condiciones se le asigna a pais el literal de caracter '@' y termina el bucle
						}
					}
							
			}
			
		}while (pais != TERMINADOR);			//Si pais es distinto de la constante de caracter TERMINADOR se repite el bucle
		
		if ((suma_espana > suma_francia)&&(suma_espana > suma_alemania))		//Se establece un condicional que compruebe cual de las sumas es mayor
			cout << "El pais que mas vende es Espana con " << suma_espana << "\n";	//Muestra el resultado en pantalla
		if ((suma_francia > suma_espana)&&(suma_francia > suma_alemania)) 			//Se establece un condicional que comprueba cual de las sumas es mayor
			cout << "El pais que mas vende es Francia con " << suma_francia << "\n";//Muestra el reusltado en pantalla		
		if ((suma_alemania > suma_espana)&&(suma_alemania > suma_francia))	//Se establece un condicional que compruebe cual de las sumas es mayor
			cout << "El pais que mas vende es Alemania con " << suma_alemania << "\n";//Muestra el resultado en pantalla	
		
		system("pause");
	}
