#include <iostream>
#include <vector> // biblioteca con la definicion de la clase

using namespace std;

int main(){
    // Declaracion de objetos de la clase vector
    vector<int> vec1;
    vector<int> vec2(10); // inicializa componentes a cero
    vector<int> vec3(10,5); // inicializa componentes a 5
    
    // La funcion miembro size devuelve la longitud del vector
    cout << "\nLa longitud de los vectores es: ";
    cout << vec1.size() << " " << vec2.size() << " " << vec3.size() << "\n";
    
    cout << "El vector 2 es: ";
    for (int i=0; i<vec2.size(); i++)
        cout << vec2[i] << " "; // acceso a componentes con el operador []
    cout << "\n";
    
    cout << "El vector 3 es: ";
    for (int i=0; i<vec3.size(); i++)
        cout << vec3[i] << " ";
    cout << "\n";
    
    vec1 = vec3; // operador de asignacion sobrecargado
    
    cout << "Ahora, el vector 1 es: ";
    for (int i=0; i<vec1.size(); i++)
        cout << vec1[i] << " ";
    cout << "\n";
    
    cout << "Introduce valores pare el vector 2:";
    for (int i=0; i<vec2.size(); i++)
        cin >> vec2[i];
    
    cout << "Ahora, el vector 2 es: ";
    for (int i=0; i<vec2.size(); i++)
        cout << vec2[i] << " ";
    cout << "\n";
    
    if ( vec1 != vec2 )
        cout << "El vector 1 es diferente al vector 2" << "\n";
    
    while ( !vec1.empty() )
        vec1.pop_back();
    
    cout << "El vector 1 tiene tamanno: " << vec1.size() << "\n";
    
    while ( !vec2.empty() ){
        vec1.push_back( vec2.back() );
        vec2.pop_back();
    }
    
    cout << "El vector 1 tiene tamanno: " << vec1.size() << "\n";
}

