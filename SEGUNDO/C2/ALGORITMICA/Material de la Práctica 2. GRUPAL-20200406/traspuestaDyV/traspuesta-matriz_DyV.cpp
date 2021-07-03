#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <unistd.h>
using namespace std;

void trueque_milindron(int ** matriz, int fiA, int ciA, int fiB, int ciB, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int aux= matriz[i+fiA][j+ciA];
			matriz[i+fiA][j+ciA]=matriz[i+fiB][j+ciB];
			matriz[i+fiB][j+ciB]=aux;
		}
	}

}
void traspuesta(int ** matriz,int fi, int ff, int ci, int cf){

	if(fi<ff){
		int fm = (fi+ff)/2;
		int cm = (ci+cf)/2;
		traspuesta(matriz, fi,fm,ci,cm); //M11
		traspuesta(matriz, fi,fm,cm+1,cf); //M12
		traspuesta(matriz, fm+1,ff,ci,cm); //M21
		traspuesta(matriz, fm+1,ff,cm+1,cf); //M22
		trueque_milindron(matriz, fm+1, ci, fi, cm+1, ff-fm);
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

	int seed = getpid();
	srand(seed);

	cout << n << " ";

	for (int j=0; j < 10; j++){

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matriz[i][j]=rand()%20;
		}
	}


	clock_t tantes = clock();
	//Calculo traspuesta
	traspuesta(matriz,0,n-1,0,n-1);

	clock_t tdespues = clock();



	cout << (double)(tdespues - tantes)/CLOCKS_PER_SEC << " ";

	}

	cout << endl;
	

	for(int i=0; i<n; i++){
		delete[] matriz[i];
	}
	delete[] matriz;





}
