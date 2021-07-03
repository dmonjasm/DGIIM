#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int main() {
	string nombre, login;
	int numero, contador = 0, contador_2 = 0;
	int constante;
	


	cout << "Introduzca su nombre y apellidos: ";
	getline(cin,nombre);
	cout << "\nIntroduzca un numero con el que sugerirle un login (preferiblemente pequeno): ";
	cin >> numero;
	
	/*Inicio un bucle for que convierta todos los elementos de la cadena de caracteres que sean letras mayusculas en su correspondiente letra minuscula */
	for(int i = 0; i < nombre.size(); i++){
		if((nombre[i] >= 'A')&&(nombre[i] <= 'Z'))
			nombre[i] = tolower(nombre[i]);
	cout << nombre[i];
		}
	
	/*Inicio un bucle do while que saque el login tomando los n primeros digitos de cada subcadena donde n es el numero introducido por el usuario */
	constante = contador + numero;
	do{
		if((nombre[contador] != ' ')&&(contador < constante)){
			login[contador_2] = nombre[contador];
			contador_2++;
		}
		else{
			if(nombre[contador] == ' ')
				constante = contador + numero + 1;
			}
		contador++;
		}while(contador < nombre.size());
		
	
	cout << "\nSu login sugerido es: ";
	for(int i = 0 ; i < contador_2; i++){
		cout << login[i];
	}
	
	cout << "\n";
		
	system("pause");
}
