#include <iostream>

using namespace std;

int main() {
	int numero_1, numero_2;
	int cifra, copia;
	int contador = 0;
	
	cout << "\nIntroduzca un primer numero: ";
	cin >> numero_1;
	cout << "\nIntroduzca un segundo numero: ";
	cin >> numero_2;
	
	while (numero_1 > numero_2){
		cout << "\nIntroduzca un nuevo primer numero: ";
		cin >> numero_1;
		cout << "\nIntroduzca un nuevo segundo numero: ";
		cin >> numero_2;
	}
	
	cout << "\nIntroduzca el numero que quiere comprobar que esta contenido: ";
	cin >> cifra;
	
	for(int i = numero_1; i <= numero_2; i++){
		copia = i;
		
		do{
			if((copia % 10) == cifra)
				contador++;
			
			copia = copia / 10;
		}while(copia != 0);
	}
	
	cout << "\nEl número aparece " << contador << " veces.\n";
	
	system("pause");
}
