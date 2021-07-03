#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include "ingrediente.h"
#include "VD.h"
#include <iostream>
#include <string>


using namespace std;

class ingredientes{
	private:
		VD<ingrediente> datos;		//Vector dinámico de tipo ingrediente ordenado segun el nombre
		VD<int> indice;			//Vector de enteros que contendra el orden segun el tipo
	public:
		/**
		* @brief Constructor sin parametros
		*/
		ingredientes();
		/**
		* @brief Inserta un ingrediente en la posicion pos
		* @param insertado: ingrediente que se va a insertar
		* @param pos: posicion en la que se va a insertar
		*/
		
		void Insertar (const ingrediente & insertado); //
		/**
		* @brief Devuelve el numero de datos contenidos en el vector dinamico ordenado por nombre
		*/		
		inline int size() const {return datos.size();}; //
		/**
		* @brief Borra el ingrediente con el nombre indicado
		* @param pos:posicion cuyo ingrediente se va a eliminar
		*/
		void borrar(const string & nombre); //
		/**
		* @brief Devuelve el ingrediente que se encuentra en la posicion pos del vector dinámico
		* @param pos: posicion cuyo ingrediente se quiere devolver
		*/
		inline ingrediente Obtener_ingrediente(int pos) {return datos[pos];}; //
		/**
		* @brief Modifica el contenido de la posicion pos del vector de ingredientes por el ingrediente nuevo
		* @param pos: posicion del vector dinamico que se va a modificar almacenando nuevo
		* @param nuevo: ingrediente que estará contenido en la posicion pos
		*/		
		void setIngrediente(int pos, const ingrediente & nuevo); //
		/**
		* @brief Devuelve la información de un ingrediente dado su nombre
		* @param nombre: nombre del ingrediente
		*/
		ingrediente get(const string & n);
		/**
		* @brief Devuelve todos los ingredientes de un tipo tipo
		* @param tipo: tipo del cual se devolverán los ingredientes
		*/
		ingredientes getIngredienteTipo(const string & tipo); //
		/**
		* @brief Busca si el ingrediente a insertar pertenece o no al vector dinamico, y en que posicion se debería insertar
		* @param insertar: ingrediente que se comprueba si pertenece y en que posicion se va a insertar
		* @return pair<boo.,int> donde bool indica si esta o no en el vector dinámico y int en que posición se insertaría
		*/
		pair<bool,int> Buscar_nombre(const ingrediente & insertar); //
		/**
		* @brief Consulta y/o modifica la posicion i del vector dinamico de ingredientes
		* @param i:posicion que se va a consultar
		*/
		pair<bool,int> Buscar_tipo(const ingrediente & insertar); //
		/**
                 * @brief Para acceder a la posición i-ésima del dato miembro datos
                 * @param i
                 * @return datos[i]
                 */
                inline ingrediente& operator[](int i){return datos[i];}		//operador no constante
		/**
                 * @brief Se trata del operador [] constante que sirve para obtener la posición i-esima de datos
                 * @param i
                 * @return datos[i]
                 */
                inline ingrediente& operator[](int i) const{return datos[i];}		//opeardor constante
		/**
                 * @brief Sobrecarga Operador de asignación. Asigna a una variable ingrediente un dato de tipo ingrediente
                 * @param original
                 * @return  this
                 */
                ingredientes operator=(const ingredientes & original);
                friend std::ostream & operator<<(std::ostream &os,const ingredientes & i); //Funcion amiga
		friend std::istream & operator>>(std::istream &is, ingredientes & i);	//Funcion amiga
		/**
		* @brief Se imprimen los ingredientes del vector dinamico por tipo
		* @param os:flujo de salida
		*/
		void ImprimirPorTipo(std::ostream &os); //
		/**
		* @brief Se devuelve un vector dinamico de string con todos los tipos almacenados
		*/
		VD<string> getTipos();
		
};
/**
* @brief Se almacenan los datos de i en el fichero al que apunte el flujo de salida os
* @param os: flujo de salida
* @i: ingrediente cuyos datos se van a almacenar
*/
std::ostream & operator<<(std::ostream &os,const ingredientes & i); //
/**
* @brief Se almacenan los datos contenidos en el fichero al que apunta el flujo de entrada is en la variable i
* @param is:flujo de entrada
* @param i:ingrediente que recibe los datos
*/
std::istream & operator>>(std::istream &is, ingredientes & i); //	

#endif
