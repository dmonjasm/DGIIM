/*Progrmama para probar si hay un problema de precision o un problema de desbordamiento
*/

#include <iostream> 
#include <cmath>

using namespace std;

int main() {
	double real, otro_real;
			real = 1e+300;
			otro_real = 1e+200;
	
	otro_real = real * otro_real;
	
	cout << "El resultado es: " << otro_real << "\n\n";
	
	system("pause");
}

/*En este programa el resultado da inf, luego hay un error de desbordamiento, ya que el 
producto de real * otro_real es tan desmesurado que se sale de los valores que la maquina 
es capaz de manejar dando lugar a un resultado que la maquina aproxima a infinito, pero
que en realidad se supone que es 1e+500.
*/
