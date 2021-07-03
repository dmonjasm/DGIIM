#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const long m = 1073741824;

double f(double x){
    return 4.0/(1+x*x);
}

double calcular_integral_secuencial(){
    double suma = 0.0;

    for(long j=0; j < m; j++)
    {
        const double xj = double(j+0.5)/m;
        suma += f(xj);
    }

    return suma/m;
}

int main(int argc, char * argv[]){

    time_point<steady_clock> inicio=steady_clock::now();
    const double resultado = calcular_integral_secuencial();
    time_point<steady_clock> final=steady_clock::now();
    duration<float,micro> duracion = final - inicio;

    cout << "Valor de PI: 3.14159265358979312" << endl;
    cout << "Resultado secuencial: " << std::setprecision(20) << resultado << endl;
    cout << "Numero de muestras (m): " << m << endl;
    cout << "Tiempo secuencial: " << duracion.count() << endl;

    return 0;
}