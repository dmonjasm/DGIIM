/*Programa que realice una multiplicación por el algoritmo de la multiplicación
rusa para dos numeros enteros.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int multiplicando, multiplicador;
	int suma,contador;
		suma = 0;
	
	cout << "Introduzca un multiplicando entero: ";
	cin >> multiplicando;
	cout << "Introduzca un multiplicador entero: ";
	cin >> multiplicador;
	
	contador = 1;
	
	if ((multiplicando % 2)!= 0)			//Se establece un condicional donde si el resto de la división de la variable multiplicando entre dos es distinto de 0	
		suma = suma + multiplicador;		//(es decir si es impar) la variable suma toma el valor del resultado de la suma de la variable multiplicador con el valor anterior de suma
	else 
		suma = suma;
	
	cout << "Iteracion\tMultiplicando\tMultiplicador\n";
	cout << contador << "\t" << multiplicando << "\t" << multiplicador << "\n";
		
	do {				//Se inicia un bucle donde se ejecuta el bloque siguiente y si se cumple que la variable multiplicando tiene un valor distinto de  se repite
		
		multiplicando = multiplicando / 2;			//La variable multiplicando toma el valor del cociente de su anterior valor entre dos
		multiplicador = multiplicador * 2;			//La variable multiplicador toma el valor del producto de su anterior valor por dos
		contador++;
		
		cout << contador << "\t" << multiplicando << "\t" << multiplicador << "\n";
		
		if ((multiplicando % 2) != 0)			//Se establece un condicional donde si multiplicando es impar suma toma el valor de la suma de su anterior valor mas el valor de multiplicador
			suma = suma + multiplicador;
		else
			suma = suma;
			
	}while (multiplicando != 1);
	
	cout << "El resultado del producto por el metodo de la multiplicacion rusa es: " << suma << "\n";
	
	system("pause");
}
	
