/*Programa que lea dos secuencias de enteros desde teclado y nos diga si todos los valores de la
primera secuencia son mayores que todos los valores de la segunda secuencia.
*/

#include <iostream>        //Se declara la biblioteca de E/S isotream
#include <cmath>           //Se declara la biblioteca de operaciones matematicas cmath
#include <string>          //Se declara la biblioteca de cadena de caracteres string

using namespace std;

int main()  {
   const int TERMINADOR = 0;                    //Se declara la constante entero que indicará el final de ambos bucles del programa
   int dato;                                    //Se declara la variable que almacenara los enteros introducidos desde teclado       
   int mayor, menor;                            //Se declaran las variable que guardarán el numero más pequeño de la secuencia 1 y el más grande de la secuencia 2
	string secuencia1, secuencia2;
		secuencia1 = "Introduzca un numero para la secuencia 1: ";		//Puesto que se van a repetir estos mensajes creo una variable de tipo cadena de caracter que los contengan
		secuencia2 = "Introduzca un numero para la secuencia 2: ";		// y les asigno un valor a ambas variables
		
	cout << secuencia1;			//Se muestra la variable tipo string guardada anteiriormente
	cin >> dato;					//Se guarda el valor introducido en la variable de tipo entero dato
	menor = dato;					//Se le asigna a la variable menor el primer dato de la secuencia para descartar el caso de que solo tuviese un elemento la secuencia
	
	while (dato != TERMINADOR){						//Se inicia un bucle en el que cuando dato sea distitno de 0 se repita todo el bloque a ejecutar
		cout << "\n" << secuencia1;					//Se muestra en pantalla el mensaje de antes
		cin >> dato;										//Se guarda el valor introducido en la variable dato
	
		if ((dato < menor)&&(dato != TERMINADOR))	//Se establece la condición de que si la variable dato es menor que la variable menor y distinta de cero, la variable menor tome el valor de dato
			menor = dato;
		else 
			menor = menor;									//Si no la variable menor conserva su valor
}
	cout << secuencia2;			//Se muestra el mensaje para la secuencia 2
	cin >> dato;					//Se guarda el valor introducido en la variable dato
	mayor = dato;					//Se asigna a la variable menor el primer dato introducido en caso de que solo hubiese un elemento en la secuencia 2
	
	while (dato != TERMINADOR){						//Se inicia un bucle en el que cuando dato sea distinto de 0 se ejecute el bloque de nueveo
		cout << "\n" << secuencia2;					//Se muestra el mensaje para la secuencia 2
		cin >> dato; 										//Se almacena la variable dato
		
		if ((dato > mayor)&&(dato != TERMINADOR))	//Si dato es mayor que la variable mayor y distinta de cero la variable mayor toma el valor de dato
			mayor = dato;
		else 													//Si no la variable valor conserva su valor inicial
			mayor = mayor;
			
	}
   if (menor > mayor)                                                                                             //Si menor es mayor que mayor se muestra
      cout << "\nTodos los valores de la secuencia uno son mayores que todos lo valores de la secuencia 2.\n";    //este mensaje
   else     
      if ((menor == 0)||(mayor == 0))                                                              //Si menor o mayor es igual a cero se muestra                                                                                     
         cout << "No se ha introducido ningún valor en alguna de las secuencias.\n";               //este menseje
      else                                                                                                           //Sino se muestra
         cout << "\nAlgun valor de la secuencia uno es menor que algun valor de la secuencia 2.\n";                  //este mensaje
   
   system("pause");
}
      
      
      
      
      

   
 
   

