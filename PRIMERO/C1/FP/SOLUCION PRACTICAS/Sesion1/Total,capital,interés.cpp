/*Programa para calcular el total de dinero a partir de un inter�s y un capital
Se necesita: inter�s y capital
             inter     cap
Se obtiene: total
            tot
*/

#include <iostream>   //Se incluye la biblioteca iostream
#include <cmath>      //Se incluye la biblioteca de operaciones matematicas

using namespace std;

int main() {
	double inter;    //Se declaran las variables del inter�s,
	double cap;      //el capital 
	double tot;      //y el total
	
	cout << "Introduzca el valor del capital: ";
	cin >> cap;
	cout << "Introduzca el valor del interes: ";
	cin >> inter;
	
	tot = cap + cap * (inter / 100);   //Declaro el algoritmo con el que obtendr� el total
	
	cout << "\nEl valor del total es: " << tot << "\n";
	
	system("pause");
}

            
