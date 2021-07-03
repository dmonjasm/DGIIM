#include <iostream>
#include <cmath>

using namespace std;

/*Se inicia una funcion void que calcule todos los numeros perfectos menores que el introducido y los muestre */
void Perfecto(int a){
	int suma = 0;
	
	for(int i = 1; i < (a-1); i++){
		for (int j = 1; (j < i); j++){
			if((i % j) == 0)
				suma = suma + j;
			}
			if(suma == i){
				cout << i << " ";	
				suma = 0;
			}
			else
				suma = 0;
			}
		}
		
int main(){
	int numero;
	
	cout << "Introduzca un numero: ";
	cin >> numero;
	
	cout << "\nLos numeros perfectos menores que el introducido son: \n";
	Perfecto(numero);			//Se muestran todos lo numeros obenidos de la funcion anterior
	cout << "\n";
	
	system("pause");
}

