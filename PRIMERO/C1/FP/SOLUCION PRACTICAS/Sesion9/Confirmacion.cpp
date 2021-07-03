#include <iostream>
#include <cmath>

using namespace std;

/*Funcion que devuelva true si letras es S o false si letras es N*/
bool Confirmar(char letras){
	cout << "¿Confirmar (S/N)?\n";
	cin >> letras;
	
	/*si letras es S se devuelve true*/
	if(letras == 'S')
		return true;
	
	/*si letras es N se devuelve false*/
	if(letras == 'N')
		return false;

}

int main() {
	bool confirmacion;
	char caracter;
	
	confirmacion = Confirmar(caracter);
	
	cout << confirmacion << "\n";
	
system("pause");
}
