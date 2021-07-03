#include <iostream>
#include <cmath>

using namespace std;

int main() {
	const int FILAS = 200;
	const int COLUMNAS = 200;
	int matriz[FILAS][COLUMNAS], matriz2[FILAS][COLUMNAS];
	int util_filas, util_columnas;
	int minimo[FILAS], mayor;
	int mayor_filas[FILAS], menor_columnas[COLUMNAS];
	int matriz_multiplicacion[FILAS][COLUMNAS];
	int filas_multiplicacion, columnas_multiplicacion;
	int resultado[FILAS][COLUMNAS];
	bool maxmin;
	

	
	cout << "Introduzca el numero de filas de la matriz: ";
	cin >> util_filas;
	cout << "\nIntroduzca el numero de columnas de la matriz: ";
	cin >> util_columnas;
	
	/*Inicio un bucle for que tome los valores de la matriz introducida por el usuario*/
	cout << "\nIntroduzca las componentes de la matriz por filas: ";
	for(int i = 0; i < util_filas; i++){
		for(int j = 0; j < util_columnas; j++){
			cin >> matriz[i][j];
		}
	}
	
	/*Inicio un bucle for que calcule la traspuesta de la matriz introducida por el usuario*/
	for(int i = 0; i < util_columnas; i++){
		for(int j = 0; j < util_filas; j++){
			matriz2[i][j] = matriz[j][i];
		}
	}
	
	/*Inicio un bucle for que muestre la matriz traspuesta de la introducida por el usuario*/
	cout << "\nLa matriz transpuesta de la introducida es: ";
	for(int i = 0; i < util_columnas; i++){
		for(int j = 0; j < util_filas; j++){
			cout << matriz2[i][j] << " ";
		}
		cout << "\n";
	}
	
	/*Inicio un bucle que almacene el minimo que cada fila en un vector*/
	for(int i = 0; i < util_filas; i++){
		minimo[i] = matriz[i][0];
		for(int j = 0; j < util_columnas; j++){
			if(minimo[i] >= matriz[i][j])
				minimo[i] = matriz[i][j];
			}
	}
	
	/*Inicio un bucle for que calcule el maximo de entre los componentes del vector*/
	mayor = minimo[0];
	for(int i = 0; i < util_filas; i++){
		if(mayor <= minimo[i])
			mayor = minimo[i];
		}
	
	cout << "\nEl mayor numero de entre los minimos de cada fila es: " << mayor << "\n";
	
	/*Inicio un bucle for que calcule el mayor elemento de cada fila*/
	for(int i = 0; i < util_filas; i++){
		mayor_filas[i] = matriz[i][0];
		for(int j = 0; j < util_columnas; j++){
			if(mayor_filas[i] <= matriz[i][j])
				mayor_filas[i] = matriz[i][j];
			}
		}
	
	/*Inicio un bucle for que calcule el menor elemento de cada columna*/
	for(int i = 0; i < util_columnas; i++){
		menor_columnas[i] = matriz[0][i];
		for(int j = 0; j < util_filas; j++){
			if(menor_columnas[i] >= matriz[j][i])
				menor_columnas[i] = matriz[j][i];
			}
		}
	/*Se inicia un bucle for que compare el maximo de cada fila con los minimos de cada columna*/
	for(int i = 0; (i < util_filas)&&(maxmin == false); i++){
		for(int j = 0; (j < util_columnas)&&(maxmin == false); j++){
			if(mayor_filas[i] == menor_columnas[j])
				maxmin = true;
			else
				maxmin = false;
			}
		}
		
	/*Se inicia un condicional en el que si algun maximo de una fila coincide con el minimo de su columna se muestran los siguientes mensajes.*/
	if (maxmin)
		cout << "\nExiste un numero que es a la vez el maximo de su fila y el minimo de su columna.\n";
	else
		cout << "\nNo existe un numero que es a la vez el maximo de su fila y el minimo de su columna.\n";
		
	cout << "\nIntroduzca las filas de la matriz que quiere multiplicar: ";
	cin >> filas_multiplicacion;
	cout << "\nIntroduzca las columnas de la matriz que quiere multiplicar: ";
	cin >> columnas_multiplicacion;
	
	/* Si las filas de las nueva matriz son distinta de las columnas de la matriz con la que se va a multiplicar se muestra error */
	if(filas_multiplicacion != util_columnas)
		cout << "\nNo se puede multiplicar porque las columnas de la primera son distintas que las filas de la segunda.\n";
	/*Si no el programa sigue y se toman los valores de la matriz que vamos a multiplicar */
	else{
		for (int i = 0; i < filas_multiplicacion; i++){
			for(int j = 0; j < columnas_multiplicacion; j++){
				cin >> matriz_multiplicacion[i][j];
			}
		}
		
	/*Se inicia un bucle for que realice la multiplicacion de ambas matrice al mismo tiempo que va mostrando la matriz resultado */
			cout << "\n El resultado de multiplicar ambas matrices es: ";
		for(int i = 0; i < util_filas; i++){
			for(int j = 0; j < columnas_multiplicacion; j++){
				
				for(int k = 0; k < filas_multiplicacion; k++){
					resultado[i][j] += matriz[i][k] * matriz_multiplicacion[k][j];
				
				}
				cout << resultado[i][j] << " ";
			}
			cout << "\n";
		}
	}
				
	system("pause");
}
