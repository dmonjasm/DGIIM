/*Programa que intercambie dos componenetes de un vector de enteros. 
*/

#include <iostream>
#include <cmath>

using namespace std;
int main(){
   const int LONGITUD = 200;
   int vector[LONGITUD], amplitud;
   int componente1, componente2, aux;
   
   cout << "Introduzca la ampmlitud del vector (< 200): ";
   cin >> amplitud;
   
   for (int i = 0; i < amplitud; i++){       //Se inicia un bucle for que pida y guarde los valores del vector
      cout << "\nIntroduzca los valores del vector: ";
      cin >> vector[i];
   }
   
   cout << "\nIntroduzca la primera componente que quiere intercambiar: ";
   cin >> componente1;
   cout << "\nIntroduzca la segunda componente que quiere intercambiar: ";
   cin >> componente2;
   
   if (((componente1 <= 0)||(componente1 > amplitud))||((componente2 <= 0)||(componente2 > amplitud)))      //Se establece un condicional que compruebe si las componentes
      cout << "\nAlguna o ambas de las componentes introducidas no es válida.";                             //introducidas es valida y que muestre error si no lo son
   else
      cout << "\nAmbas componentes son válidas.";           
    
   aux = vector[componente1 - 1];                     //Establezco un algoritmo para realizar el cambio de las componentes
   vector[componente1 - 1] = vector[componente2 - 1];
   vector[componente2 - 1] = aux;
      
   cout << "\nEl vector con los componentes intercambiados es: ";
   
   for (int k = 0; k < amplitud; k++){       //Inicio un bucle for que muestre el vector con las componentes cambiadas
      cout << vector[k] << " ";
   }
   cout << "\n";
   
   system("pause");
}
      
   
