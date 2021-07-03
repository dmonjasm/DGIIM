#include <iostream>
#include <cmath>

using namespace std;

void imprimirArray(int array[],int num_elem);
void leerArray(int array[],int LONGITUD, int &num_elem);
int buscarMinimoArray(int array[],int inicio,int final);
int main() {
	const int LONGITUD=100;
	int array[LONGITUD];
	int num_elem=0;
	
	leerArray(array,LONGITUD, num_elem);
	
	int inicio=0;
	int final=num_elem;
	int minimo = 0;
	
	minimo=buscarMinimoArray(array,inicio,final);
	
	imprimirArray(array,num_elem);
	cout << "\n" << minimo << endl;
	
	return 0;
}

void leerArray(int array[],int LONGITUD, int &num_elem){
	
	do{
		cout << "NUM_ELEM" << endl;
		cin >> num_elem;
	}while((num_elem<0)||(num_elem >= LONGITUD));
	
	for(int i=0; i < num_elem; i++)
		cin >> array[i];
}

int buscarMinimoArray(int array[],int inicio,int final){
	int minimo=array[inicio];
	int posicion_min=inicio;
	
	for(int i=inicio; i < final; i++){
		if(array[i]<minimo){
			minimo=array[i];
			posicion_min=i;
		}
	}
	
	return posicion_min;
}

void imprimirArray(int array[],int num_elem){
	cout << num_elem << endl;
	
	for(int i=0; i < num_elem; i++)
		cout << array[i] << " ";
}
