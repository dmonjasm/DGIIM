/* Variación del ejercicio 7 de la relación 1, en el cual se haran unas estructuras condicionales
independientes y mostrarán un mensaje en pantalla.
*/

#include <iostream>		//Se inlcuye la biblioteca iostream
#include <cmath> 			//Se incluye la bilbioteca de operaciones matematicas cmath
#include <string>			//Se incluye la biblioteca de cadenas de caracteres

using namespace std; 

int main() {
	double pers1;			//Declara las variables de la altura de la persona 1
	double pers2;			//la altura de la persona 2
	double pers3;			//la altura de la persona 3
	double med;				// la media muestral de las alturas
	double desv;			// la desviacion estandar muestral de las alturas
	string mayor, menor, igual, altura;					//Declaro las variables de cadena de caracteres que se van a utilizar
			altura = "La altura de la persona ";			//Les doy un valor a las variables cadena de caracter
			mayor = " es mayor que la media\n";
			menor = " es menor que la media\n";
			igual = " es igual que la media\n";
		

	
	cout << "Introduzca la altura de la persona 1: ";			//Se pide al usuario que introduzca la altura de la persona 1
	cin >> pers1;
	cout << "Introduzca la altura de la persona 2: ";			//Se pide al usuario que introduzca la altura de la persona 2
	cin >> pers2;
	cout << "Introduzca la altura de la persona 3: ";			//Se pide al usuario que introduzca la altura de la persona 3
	cin >> pers3;
	
	med = ((pers1 + pers2 + pers3) / 3);																				//Se declara el algoritmo para calcular la media muestral de las alturas
	desv = sqrt ((pow((pers1 - med),2) + pow ((pers2 - med),2) + pow((pers3 - med),2)) / 3);			//Se declara el algoritmo para calcular la desviacion estandar muestral de las alturas
	
	cout << "La media de las alturas es: " << med << "\n";			//Muestro en pantalla el resultado de la media
	cout << "La desviación estandar es: " << desv << "\n";			//Muestro en pantalla el resultado de la desviación
	
	if (pers1 != med){									//Introduzco la condición para cuando la altura es distinta de la media
		if (pers1 > med)								//Si la altura es mayor que la media muestra ese mensaje en pantalla
			cout << altura << '1' << mayor;
		else							//Si la altura es menor que la media muestra ese mensaje en pantalla
			cout << altura << '1' << menor;
}
	else 													//Si la altura no es distinta de la media por deducción sera igual y lo mostrara en pantalla
		cout << altura << '1' << igual;
		
	

	if (pers2 != med){									//Introduzco la condición para cuando la altura es distinta de la media
		if (pers2 > med) 								//Si la altura es mayor que la media muestra ese mensaje en pantalla
			cout << altura << '2' << mayor;
		else												//Si la altura es menor que la media muestra ese mensaje en pantalla
			cout << altura << '2' << menor;
}
	else 													//Si la altura no es distinta de la media por deducción sera igual y lo mostrara en pantalla
		cout << altura << '2' << igual;
		

	if (pers3 != med){									//Introduzco la condición para cuando la altura es distinta de la media
		if (pers3 > med)							//Si la altura es mayor que la media muestra ese mensaje en pantalla					
			cout << altura << '3' << mayor;
		else												//Si la altura es menor que la media muestra ese mensaje en pantalla
			cout << altura << '3' << menor;
}
	else 													//Si la altura no es distinta de la media por deducción sera igual y lo mostrara en pantalla
		cout << altura << '3' << igual;
		
	system("pause");
}
