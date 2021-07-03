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

void minmaxMilindronDyV(int i,int j, int & max, int & min, int *T){
    if(i < j-1){
        int medio = (i+j)/2;
        int max1=T[0], max2=T[0], min1=T[0], min2=T[0];
        minmaxMilindronDyV(i,medio,max1,min1, T);
        minmaxMilindronDyV(medio+1,j,max2,min2, T);

        if(max1 > max2)
            max = max1;
        else
            max = max2;

        if(min1 < min2)
            min = min1;
        else
            min = min2;
    }

    else if(i == j-1){
        if(T[i] > T[j]){
            max = T[i];
            min = T[j];
        }

        else{
            max = T[j];
            min = T[i];
        }
    }

    else{
        max = T[i];
        min = max;
    }
}
int main(int argc, char** argv){

	if (argc != 2 && argc != 3){
		cerr << "Formato: " << argv[0] << " <num_elem> [<semilla>]" << endl;
		return -1;
	}

	int n = atoi(argv[1]);
	
	int seed = getpid();
	if(argc == 3){
		seed = atoi(argv[2]);
	}

	int * T = new int[n];
	assert(T);

	srand(seed);
	
	for (int j=0; j<n; j++) {
		T[j]=rand()%(2*n+1);
	}
	cout << n << " ";
	for(int i=0; i < 10; i++){

	int max=T[0],min=T[0];

    	clock_t tantes = clock();

   	minmaxMilindronDyV(0,n-1,max,min,T);

    	clock_t tdespues = clock();

    	cout << (double)(tdespues - tantes)/CLOCKS_PER_SEC << " ";
	}

	cout << endl;

	delete [] T;

    return 0;
}
