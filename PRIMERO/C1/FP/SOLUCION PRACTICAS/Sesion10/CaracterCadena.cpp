#include <iostream>
#include <cmath>

using namespace std;

/* Funcion tipo bool que pida la amplitud de una cadena, los elementos de dicha cadena, y que compruebe si la letra introducida
por el usuario esta incluida en la cadena, y devuelva true o false en funcion de si el caracter pertenece o no */
bool Pertenencia(char letra){
	const int LONGITUD = 200;
	int amplitud;
	char vector[LONGITUD];
	bool no_pertenece = true;
	
	
	cout << "\nIntroduzca la amplituda de la cadena: ";
	cin >> amplitud;
	
	/*Se inicia un bucle for que recoja los elementos de la cadena */
	cout << "\nIntroduzca los elementos de la cadena: ";
	for(int i = 0; i < amplitud; i++){
		cin >> vector[i];
	}
	
	/*Se inicia un bucle for que comprueba si la letra introducida pertenece a la cadena */
	for(int i = 0; (i < amplitud)&&(no_pertenece); i++){
		if ( letra == vector[i])
			no_pertenece = false;
		else
			no_pertenece = true;
		}
	
	return no_pertenece;
}

int main() {
	char caracter;
	bool no_pertenece;
	cout << "\nIntroduzca un caracter cualquiera: ";
	cin >> caracter;
	
	no_pertenece = Pertenencia(caracter);
	
	if(no_pertenece)
		cout << "\nEl caracter introducido no pertenece a la cadena.\n";
	else
		cout << "\nEl caracter introducido pertenece a la cadena.\n";
	
	
	
	system("pause");
}
		
	
	
