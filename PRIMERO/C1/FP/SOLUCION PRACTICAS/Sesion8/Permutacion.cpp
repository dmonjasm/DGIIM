#include <iostream>
#include <cmath>

using namespace std;

struct Permutacion{
	int permutacion[200];
	int amplitud;
};

int main() {
	Permutacion vector;
	int k, numero = 1;
	bool permutable = true;
	
	cout << "\nIntroduzca la amplitud de la permutacion: ";
	cin >> vector.amplitud;
	
	/*Se inicia un bucle for que tome los valores del vector.permutacion*/
	cout << "\nIntroduzca los valores de la permutacion: ";
	for(int i = 0; i < vector.amplitud; i++){
		cin >> vector.permutacion[i];
	}
	
	/*Se inicia un bucle for que compruebe si la permutación introducida es correcta */
	for(int i = 0; (i < vector.amplitud)&&(permutable); i++){
		for(int j = i+1; (j < vector.amplitud)&&(permutable); j++){
			if (vector.permutacion[i] == vector.permutacion[j])
				permutable = false;
			else
				permutable = true;
			}
		}
	
	/*Si la permutacion no es correcta se muestra error y el programa finaliza, sino el programa continua*/
	if (permutable == false)
		cout << "\nLa permutacion introducida no es correcta.\n";
	else{
		
		/*Se inicia un bucle for que calcule la combinacion de la permutacion */
		for(int i = 0; i < vector.amplitud; i++){
			numero = numero * vector.permutacion[i];
		}
	
	/*Se muestra en pantalla el cuadrado de la combinacion de la permutacion */
	cout << "\nEl cuadrado de la permutacion es: " << pow(numero,2) << "\n";
	
	cout << "\nIntroduzca un numero k para calcular la potencia k-esima de la permutacion: ";
	cin >> k;
	
	/*Se muestra en pantalla la potencia k-esima de la combinacion de la permutacion, donde k ha sido introduzido por el usuario */
	cout << "\nLa potencia k-esima de la permutacion es: " << pow(numero,k) << "\n";
}

system("pause");
}
	
	
