#include <iostream>
#include <ctime> // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
#include <chrono> // para high_resolution_clock
using namespace std;
using namespace std::chrono;
void ordenar(int *v, int n) {
 for (int i=0; i<n-1; i++)
 for (int j=0; j<n-i-1; j++)
 if (v[j]>v[j+1]) {
 swap(v[j],v[j+1]);
 //alternatva al swap
 /*int aux = v[j];//incluir algorithm
 v[j] = v[j+1];
 v[j+1] = aux;*/
 }
}

void sintaxis() {
 cerr << "Sintaxis:" << endl;
 cerr << " TAM: Tamaño del vector (>0)" << endl;
 cerr << " VMAX: Valor máximo (>0)" << endl;
 cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
 exit(EXIT_FAILURE);
}
int main(int argc, char * argv[]) {
 if (argc!=3) // Lectura de parámetros
 sintaxis();
 int tam=atoi(argv[1]); // Tamaño del vector
 int vmax=atoi(argv[2]); // Valor máximo
 if (tam<=0 || vmax<=0)
 sintaxis();

 // Generación del vector aleatorio
 int *v=new int[tam]; // Reserva de memoria
 srand(time(0)); // Inicialización generador números pseudoaleatorios
 for (int i=0; i<tam; i++) // Recorrer vector
 v[i] = rand() % vmax; // Generar aleatorio [0,vmax[



 high_resolution_clock::time_point start,//punto de inicio
 end; //punto de fin
 duration<double> tiempo_transcurrido; //objeto para medir la duracion en segundos
 start = high_resolution_clock::now(); //anotamos el instante actual
 ordenar(v,tam); // de esta forma forzamos el peor caso
 end=high_resolution_clock::now(); // Anotamos el tiempo de finalización
 tiempo_transcurrido = duration_cast<duration<double> >(end - start);
 // Mostramos resultados
 cout << tam << "\t" << tiempo_transcurrido.count() << endl;
 delete [] v; // Liberamos memoria dinámica
}
