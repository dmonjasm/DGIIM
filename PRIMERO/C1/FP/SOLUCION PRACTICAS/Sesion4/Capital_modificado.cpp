/* Construid un program que lea el capital, el interés y un numero de años N, y calcule e 
imprima todo el dinero obtenido durante cada uno de los N años, suponiendo que todo lo ganado 
(incluido el capital original C) se reinvierte a plazo fijo durante el siguiente año.
*/

#include <iostream>        //Se declara la biblioteca de E/S iostream
#include <cmath>           //Se declara la biblioteca de operaciones matematicas cmath
#include <string>          //Se declara la biblioteca de cadenas de caracteres string

using namespace std;

int main() {
   double capital, interes;            //Se declaran las variables de tipo real
   int anios, contador_anios;          //Se declaran las variables de tipo entero
   string salida;                      //Se declara una cadena de caracter que se repetira
      salida = "Total en el año numero ";    //Se le asigna valor a dicha cadena de caracter
      contador_anios = 0;              //Se asigna valor a la variable contador_anios
   
   cout << "Introduzca el capital depositado: \n";                         //Se pide el capital depositado
   cin >> capital;               //Se guarda en la vairable capital
   cout << "Introduzca el interes que se le aplicará: \n";                 //Se pide el interés a aplicar
   cin >> interes;               //Se guarda en la variable interes
   cout << "Introduzca durante cuantos años se deposita el capital: \n";   //Se pide los años que se depositará el capital
   cin >> anios;                 //Se guarda en la variable anios
   
   do {
      capital = capital + (capital * (interes / 100));                  //Se establece el algoritmo con el que se calcula el nuevo capital tras un año de deposito
      contador_anios++;                                                 //El contador llevará la cuenta de los años transcurridos
      cout << salida << contador_anios << " = " << capital << "\n";     //Se anuncia el resultado en pantalla de cada año 
   }while(contador_anios < anios);                                      //Se establece la condición que si se cumple hará que el bucle se repita
   
   system("pause");
}
