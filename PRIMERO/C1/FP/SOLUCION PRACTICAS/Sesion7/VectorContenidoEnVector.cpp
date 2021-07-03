/*Programa que dados dos vectores de enteros devuelva las veces que el segundo
aparece en el primero.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
   const int LONGITUD = 200;
   int vector1[LONGITUD], vector2[LONGITUD];
   int amplitud1, amplitud2;
   int k = 0, l = 0;
   int contenido = 0;
   bool pertenece;
   
   cout << "Introduzca la amplitud del vector 1: ";
   cin >> amplitud1;
   cout << "\nIntroduzca la amplitud del vector 2: ";
   cin >> amplitud2;
   
   for (int i = 0; i < amplitud1; i++){
      cout << "\nIntroduzca los valores del vector 1:";
      cin >> vector1[i];
   }
   
   for (int j = 0; j < amplitud2; j++){
      cout << "\nIntroduzca los valores del vector 2: ";
      cin >> vector2[j];
   }
   
 do {
 	if (vector2[k] = vector1[l]){
 		for (int i = 1; (i < amplitud2)&&(pertenece == true); i++){			//No consigo que funcione si el orden se tiene que conservar en ambos vectores
 			if (vector2[k + i] == vector1[l + i])
 				pertenece = true;
 			else
 				pertenece = false;
 			}
 		if (pertenece = true)
 			contenido++;
 		else
 			contenido = contenido;
 	}
	else
		l++;
	}while (l < amplitud1);
	
	cout << "\nEl vector 2 está contenido " << contenido << " veces en el vector 1\n";
	
	system("pause");
}
 				
   	
   
	
   			
   	
      
   

