#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <unistd.h>

//Generador de ejemplos para el problema de encontrar el máximo y el mínimo.
//Simplemente, para rellenar el vector de tamaño n genera n enteros aleatorios entre 0 y INT.MAX_INT

// Si se quieren generar vectores distintos de diferente tamaño, basta modificar la semilla:

void minMax(int *T,int &maximo, int &minimo, int tamanio){
	minimo = T[0];
	maximo = T[0];

	for(int i=1; i < tamanio;i++){
		if (T[i]<minimo){
			minimo=T[i];
		}
		else if (T[i] > maximo){
			maximo=T[i];
		}
	}
}

int main(int argc, char** argv){

	if (argc != 2 && argc != 3){
		cerr << "Formato: " << argv[0] << " <num_elem> [<semilla>]" << endl;
		return -1;
	}

	int n = atoi(argv[1]);
	

	int * T = new int[n];
	assert(T);

	int min, max;
	
	cout << n << " ";
	for(int z=0; z<10; z++){
		int seed = getpid();
		srand(seed);
		
		if(argc == 3){
			seed = atoi(argv[2]);
		}	

		for (int j=0; j<n; j++) {
			T[j]=rand();
		}
		
		clock_t time_ini = clock();
		minMax(T,max,min,n);
		clock_t time_fi = clock();
	
		cout << (time_fi-time_ini)/(double)CLOCKS_PER_SEC << " ";
	}
	
	cout << endl;

	delete[] T;

	return 0;

}
