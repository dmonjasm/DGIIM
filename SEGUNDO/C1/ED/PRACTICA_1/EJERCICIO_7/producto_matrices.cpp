#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void sintaxis() {
 cerr << "Sintaxis:" << endl;
 cerr << " FIL1:numero de filas de la primera matriz" << endl;
 cerr << " COL1:numero de columnas de la primera matriz" << endl;
 cerr << " FIL2:numero de filas de la segunda matriz" << endl;
 cerr << " COL2:numero de columnas de la segunda matriz" << endl;
 cerr << " VMAX: Valor máximo (>0)" << endl;
 cerr << " Genera dos matrices de dimension FIL1xCOL1 y FIL2xCOL2" << endl; 
 exit(EXIT_FAILURE);
}

void producto(int **m_1, int **m_2,int filas_1,int columna_1, int filas_2, int columna_2,int **m_3){

int valor=0;

for(int i=0 ; i < filas_1;i++){
	for(int j=0; j < columna_2; j++){
		for(int k = 0; k < columna_1; k++)
			valor = m_1[i][k]*m_2[k][j] + valor;
		
		m_3[i][j] = valor;
		valor = 0;
	}
}		
}

int main (int argc, char *argv[]){
if(argc!=6)
sintaxis();
int fil_1=atoi(argv[1]);
int col_1=atoi(argv[2]);
int fil_2=atoi(argv[3]);
int col_2=atoi(argv[4]);
int vmax=atoi(argv[5]);

if(vmax<=0 || col_1!=fil_2)
sintaxis();

int **matriz_1=new int *[fil_1];
int **matriz_2=new int *[fil_2];
int **matriz_resultado=new int *[fil_1];

for(int i=0; i < fil_1; i++)
	matriz_1[i]=new int[col_1];

for(int i=0; i < fil_2; i++)
	matriz_2[i]=new int[col_2];

for(int i=0; i < fil_1; i++)
	matriz_resultado[i]=new int[col_2];

srand(time(0));

for(int i=0; i < fil_1;i++)
	for(int j=0; j < col_1; j++)
		matriz_1[i][j]= rand() % vmax;

for(int i=0; i < fil_2;i++)
        for(int j=0; j < col_2; j++)
                matriz_2[i][j]= rand() % vmax;

high_resolution_clock::time_point start, 
end;
duration<double> tiempo_transcurrido;
start = high_resolution_clock::now();
producto(matriz_1, matriz_2, fil_1, col_1, fil_2,col_2,matriz_resultado);
end=high_resolution_clock::now();
tiempo_transcurrido= duration_cast<duration<double> >(end - start);

for(int i=0; i < fil_1; i++){
	delete [] matriz_1[i];
	delete [] matriz_resultado[i];
}

for(int i=0; i < fil_2; i++)
	delete [] matriz_2[i];

cout << fil_1 << "\t" << tiempo_transcurrido.count() << endl;

delete [] matriz_1;
delete [] matriz_2;
delete [] matriz_resultado;
}


