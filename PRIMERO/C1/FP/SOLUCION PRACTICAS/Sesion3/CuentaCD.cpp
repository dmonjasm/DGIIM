/*Programa en el que se establece algunas variables con el objetivo de ver si alguna es erronea
y en caso de que asi sea indicar donde se encuentra el error.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct CuentaCD {
	double saldo;
	double tasa_de_interes;
	int plazo;
	char inicial1;
	char inicial2;
};

int main() {
	CuentaCD cuenta;
	string mensaje;
			mensaje = "Introduzca un valor: ";
	
	cout << mensaje;
	cin >> cuenta.saldo;
	
	system("pause");
	
	
	cout << mensaje;
	cin >> cuenta.tasa_de_interes;
	
	system("pause");
	
	
	cout << mensaje;
	cin >> CuentaCD.plazo;
	
	
	system("pause");
	
	
	cout << mensaje;
	cin >> cuenta_ahorros.inicial1;
	
	
	system("pause");
	
	
	cout << mensaje;	
	cin >> cuenta.inicial2;
	
	system("pause");
	
	
	cout << mensaje;
	cin >> cuenta;
	
	
	system("pause");
}
/*En el apartado a) se almacena un valor de tipo real ya que la variable 'saldo' contenida en la 
estructura CuentaCD es de tipo double que almacena valores reales.

En el apartado b) se almacena un valor de tipo real ya que la variable 'tasa_de_interes' contenida
en la estructura CuentaCD es de tipo dobule que almacena valores reales.

En el apartado c) el programa dará error ya que cuando se quiere almacenar una variable empleando
una estructura hay que declararla primero, no vale con escribir el nombre de la estructura. En este
caso la maquina da como error que esperaba un expressión antes del punto, es decir, entre CuentaCD y 
.plazo.

En el apartado d) el programa dará error ya que la variable cuenta_ahorros no se ha declarado anteriormente
por lo que el compilador no la reconoce.

En el apartado e) se almacena un valor de tipo caracter ya que la variable 'inicial2' contenida
en la estructura CuentaCD es de tipo char que almacena caracteres.

En el apartado f) no se almacena nada ya que a pesar de que cuenta si que se ha declarado como variable
de tipo CuentaCD  no se especifica que tipo de dato dentro de los posibles en cuenta se quiere almacenar.
*/
