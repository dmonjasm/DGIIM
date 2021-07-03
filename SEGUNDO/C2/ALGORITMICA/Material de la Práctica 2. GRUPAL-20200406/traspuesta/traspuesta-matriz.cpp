#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <unistd.h>
using namespace std;


void traspuesta(int **matriz,int n){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int aux = matriz[i][j];
			matriz[i][j]=matriz[j][i];
			matriz[j][i]=aux;		
		}
	}
}

int main(int argc, char** argv){

	if(argc!=2){
		cerr << "Error en el numero de argumentos.\n";
		exit(-1);
	}

	int n = atoi(argv[1]);

	if(int(log2(n))!=log2(n)){
		cerr << "n no es potencia de 2.\n";		
		exit(-1);
	}

	int ** matriz;
	matriz = new int*[n];
	for(int i=0; i<n; i++){
		matriz[i]=new int[n];
	}

	assert(matriz);
	cout << n << " ";
	for(int z=0; z<10; z++){
		int seed = getpid();
		srand(seed);
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				matriz[i][j]=rand()%20;
			}
		}

		/*for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << matriz[i][j] << " ";
			}
			cout << endl;
		}*/

		clock_t time_ini;
		time_ini=clock();
		
		//Calculo traspuesta
		traspuesta(matriz,n);

		clock_t time_fi;
		time_fi=clock();
		
		/*cout << "\n\nLa trapuesta es:\n";
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << matriz[i][j] << " ";
			}
			cout << endl;
		}*/

		cout <<(time_fi-time_ini)/(double)CLOCKS_PER_SEC<<" ";
	}

	cout << endl;	

	for(int i=0; i<n; i++){
		delete[] matriz[i];
	}
	delete[] matriz;





}
