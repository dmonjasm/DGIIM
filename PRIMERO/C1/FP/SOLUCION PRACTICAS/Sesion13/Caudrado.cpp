#include <iostream> 

using namespace std;

const int FILAS = 100;
const int COLUMNAS = 100;

bool CuadradoMagico(int filas, int columnas, int matriz[FILAS][COLUMNAS]){
	int suma_1 = 0;
	int suma_auxiliar = 0;
	bool iguales = false;
	int filas_auxiliar = 0, columnas_auxiliar = columnas - 1;
	
	for(int i = 0; i < filas; i++)
		suma_1 = suma_1 + matriz[i][i];
		
	for(int i = 0; (i < filas)&&(iguales); i++){
		for(int j = 0; j < columnas; j++){
			suma_1 = suma_1 + matriz[i][j];
		}
		
		if(suma_1 == suma_auxiliar)
			iguales = true;
		
		else
			iguales = false;
		}
	
	if(iguales){
	suma_1 = 0;
	
	do{
		suma_1 = filas_auxiliar + columnas_auxiliar;
		
		filas++;
		columnas--;
	}while(filas_auxiliar < filas);
	
	if(suma_1 == suma_auxiliar)
		return true;
	else
		return false;
	}
	
	else
		return false;
	}
	
	int main (){
		int matriz[FILAS][COLUMNAS];
		int filas, columnas;
		bool magico;
		
		cout << "\nIntroduzca el numero de filas de la matriz: ";
		cin >> filas;
		cout << "\nIntroduzca el numero de columnas de la matriz: ";
		cin >> columnas;
		
		if((columnas == filas)&&(((columnas % 2) != 0)||((filas % 2) != 0))){
			for(int i = 0; i < filas; i++){
				for(int j = 0; j < columnas; j++){
					cin >> matriz[i][j];
				}
			}
			
			magico = CuadradoMagico(filas, columnas, matriz);
			
			if(magico)
				cout << "\nLa matriz es un cuadrado magico.\n";
			else
				cout << "\nLa matriz no es un cuadrado magico.\n";
		}
		
		else
			cout << "\nLa matriz no es un cuadrado magico.\n";
			
		system("pause");
	}
		
		
			
		
