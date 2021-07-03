/*Programa para probar si se produce un problema de precisión o de desbordamiento
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double resultado, real1, real2;
			real1 = 123456789.1;
			real2 = 123456789.2;
			
	resultado = real1 * real2;
	cout.precision(1000);
	
	cout << "El resultado es: " << resultado << "\n\n";
	
	system("pause");
}
/*En este programa el problema es que el producto de real1 por real2 es un numero tan exageradamente
grande que la maquina no es capaz de representar todos los numeros en la pantalla, sino que muestra
un decimal multiplicado por una potencia de diez lo que da lugar a un error de precision ya que en
ese decimal de seguro se han perdido numeros ya que la maquina no es capaz de repesentarlo como un
unico numero sino que lo muestra como un producto por una potenia de base diez. Este problema se podría
arreglar estableciendo con la orden cout.precision(numero_digitos) un numero_digitos suficientemente alto 
para que se muestre entero el numero pero en ese caso los decimales quedarían omitidos pues en numeros 
tan grandes la maquina redondea automaticamente dando lugar a un error de precision.
*/ 
