/*Programa para comprobar si las expresiones empleadas son erroneas, est�n mal formuladas 
y dar el tipo de dato que es dicho valor.
*/

#include <iostream>

using namespace std;

int main() {
	int x, y, z;		//Declaro las variables tipo enteros pedidas en el enunciado
	char a;				//Declaro la variable tipo char pedida en el enunciado
		x = 4;		//Asigno a las variables de tipo entero los
		y = 4;		//valores escritos en el enunciado
		z = 4;	

	cout << (2 + 3 < 5 + 8) << "\n";									//Declaro la expresion logica a) del ejercicio
	cout << (2 < 3 < 4) << "\n";										//Declaro la expresion logica b) del ejercicio
	cout << ((7 / 3) + 4.0) << "\n";									//Declaro la expresion logica c) del ejercicio
	cout << (x == 4&&y == 3||z != 2 == 1 != 2) << "\n";		//Declaro la expresion logica d) del ejercicio
	cout << (x <= 4|| x >= 4) << "\n";								//Declaro la expresion logica e) del ejercicio
	cout << (x < 4&&x > 4) << "\n";									//Declaro la expresion logica f) del ejercicio
	cout << (z > 6||a < 'z'&&a > 'a'||z < 6) << "\n";			//Declaro la expresion logica g) del ejercicio
	
	
	system("pause");
}
/*La expresi�n a) devuelve el valor 1, que es un tipo de dato l�gico y nos indica que la condici�n que hemos 
establecido es verdadera 

La expresi�n b) devuelve el valor 1, que tambien es un tipo de dato l�gico y nos indica que la condici�n que 
hemos establecido tambi�n es verdadera

La expresi�n c) devuelve el valor 6, lo cual es err�neo ya que la maquina ha omitido los decimales. Esto se debe
a que cuando realizamos operaciones en la orden cout hay que especificar que los numeros que utilizamos son reales
como en este caso hemos usado 7 y 3, que son enteros, en lugar de 7.0 y 3.0 que ser�an los que la maquina considera
reales nos muestra el redondeo a 6. Es un tipo de dato entero.

La expresi�n d) nos muestra 1, que es un tipo de dato l�gico y nos indica que la condici�n que hemos escrito es 
verdadera.

La expresi�n e) nos muestra 1, que es un tipo de dato l�gico y nos indica que la condici�n que hemos escrito es
verdadera.

La expresi�n f) nos muestra 0, que es un tipo de dato l�gico y nos indica que la condici�n que hemos escrito es 
falsa.

La expresi�n g) nos muestra 1, que es un tipo de dato l�gico y nos indica que la condici�n que hemos escrito es
verdadera.
*/
