#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void ImprimirArray(int array[],int num_elem);
void GenerarArray(int array[],int num_elem,int minimo,int maximo);

int main() {
	const int LONGITUD=100;
	int num_elem=0;
	int minimo=0;
	int maximo=0;
	int array[LONGITUD];
	
	cout << "NUM_ELEM" << endl;
	cin >> num_elem;
	
	for(int i=0; i < num_elem; i++)
		array[i]=0;
		
	cout << "MIN-MAX" << endl;
	cin >> minimo >> maximo;
	
	GenerarArray(array,num_elem,minimo,maximo);
	ImprimirArray(array,num_elem);
	
	return 0;
}

void GenerarArray(int array[],int num_elem,int minimo,int maximo){
	for(int i=0; i < num_elem; i++)
		array[i]=rand() % (maximo+1) + minimo;
}

void ImprimirArray(int array[],int num_elem){
	cout << num_elem << endl;
	
	for(int i=0; i < num_elem; i++)
		cout << array[i] << " ";
}
	
