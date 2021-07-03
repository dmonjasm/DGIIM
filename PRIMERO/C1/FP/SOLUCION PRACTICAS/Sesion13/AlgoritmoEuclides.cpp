#include <iostream>

using namespace std;

/*La función de tipo entero de MCD tiene dos datos de tipo entero, si el segundo de estos datos es cero entonces el maximo comun divisor es el primero de los numeros introducidos
si el segundo de los datos es distinto de cero entonces se hace el resto del primer numero entre el segundo y se repite la función  */
int MCD(int un_entero, int otro_entero){
	int maximo;
	
	if(otro_entero == 0)		//Si el segundo entero es cero el maximo comun divisor es el primero de los numeros
		maximo = un_entero;
		
	else
		maximo = MCD(otro_entero, un_entero % otro_entero);	//Si el segundo entero es distinto de cero el maximo comun divisor es el maximo comun divisor del segundo y el resto
																				// del primero entre el segundo 
	return maximo;
	}
	
int main() {
	int maximo_comun;
	int un_entero, otro_entero;
	
	cout << "\nIntroduzca los enteros de lso que quiere calcular el maximo comun divisor: ";
	cin >> un_entero >> otro_entero;
	
	maximo_comun = MCD (un_entero, otro_entero);
	
	cout << "\nEl maximo comun divisor de " << un_entero << " y " << otro_entero << " es: " << maximo_comun << "\n";
	
	system("pause");
}
		
