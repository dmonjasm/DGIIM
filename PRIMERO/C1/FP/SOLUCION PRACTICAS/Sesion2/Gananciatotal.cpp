/*Programa para hallar lo que gana un diseñador y tres fabricantes al vender un producto 
teniendo en cuenta que el diseñador gana el doble que cada uno de los fabricantes dada la ganancia total
de la venta de los productos.
Se necesita: ganancia total
    				gantot
Se obtiene: lo que gana cada trabajador y el diseñador
					trabj1 trabj2 						dis
*/

#include <iostream>	//Se inlcuye la biblioteca iostream
#include <cmath>     //Se incluye la bilbioteca de operaciones matemáticas cmath

using namespace std;

int main() {
	double trabj;			//Declara las variables que se van a 
	double dis;				//utilizar en el algoritmo y la que 
	double gantot;			//se le va a pedir al usuario
	
	
	cout << "Introduzca las ganancias totales obtenidas por la venta del producto: ";		//Pide al usuario que introduzca el valor de la variable gantot
	cin >> gantot;
	
	
	trabj = gantot / 5;			//Declaro los algoritmos a partir de los cuales
	dis = trabj * 2;				//se calculara el dinero que gana los trabajadores y el diseñador
	
	
	cout << "Cada fabricante ganara: " << trabj << "\n";			//Se anuncia en pantalla lo que ganara cada fabricante
	cout << "El disenador ganara: " << dis << "\n\n";				//Se anuncai en pantalla lo que ganara el diseñador
	
	system("pause");
}
