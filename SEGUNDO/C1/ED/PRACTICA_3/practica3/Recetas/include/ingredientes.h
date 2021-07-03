#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include "ingrediente.h"
#include <vector>
#include <iostream>
#include <string>


using namespace std;

class ingredientes{
	private:
		vector<ingrediente> datos;		//Vector dinámico de tipo ingrediente ordenado segun el nombre
		vector<int> indice;			//Vector de enteros que contendra el orden segun el tipo
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
		* @brief Sobrecarga del operador [] que devuelve la informacion del dato contenido en la posicion i del vector dinamico
		* @param i: posicion del vector dinamico a mostrar
		*/
		inline ingrediente& operator[](int i){return datos.at(i);}		//operador no constante
		inline ingrediente operator[](int i) const{return datos.at(i);}		//opeardor constante
		/**
		* @brief Sobrecargar del operador de asignacion para poder asignar directamente el valor de un miembro de la clase ingredientes a otro miembro de la clase
		* @param original: miembro de la clase ingredientes cuya información se quiere copiar
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
		vector<string> getTipos();

		class iterator{
			private:	
				vector<ingrediente>::iterator it;

			public:
				/**
				* @brief Constructor sin parámetros
				*/
				inline iterator(){};	//
				/**
				* @brief Constructor de copia
				* @param i:se copia en el iterador que llama a la función el iterador i
				*/
				inline iterator(const iterator & i){it = i.it;};		//
				/**
				* @brief Se apunta el iterador que invoca la función a la posición siguiente a la que apunta en el momento de la llamada
				* @return iterador que apunta a la siguiente posicion que se pide
				*/
				iterator & operator++();		//
				/**
				* @brief Se apunta el iterador que invoca la función a la posición anterior a la que se apunta en el momento de la llamada
				* @return iterador que apunta a la posición anterior que el original
				*/
				iterator & operator--();		//
				/** 
				* @brief Se sobrecargar el operador de comparación para comprobar si dos iteradores son iguales
				* @param i: iterador con el que se quiere comparar
				* @return true si son iguales, false si no lo son
				*/
				bool operator==(const iterator & i);	//
				/**
				* @brief sobrecarga del operador distinto para comprobar si dos iteradores son distintos
				* @param i:iterador con el que se comparará
				* @return true si son distintos, false si no lo son
				*/
				bool operator!=(const iterator & i);	//
				/**
				* @brief Sobrecarga del operador *, se devuelve el contenido a donde apunta el iterador invocante de la llamada
				* @return se devuelve el ingrediente contenido en la posicion a la que se llama
				*/
				ingrediente operator*() const{return *it;};	//
				friend class ingredientes;
		};
		
		class const_iterator{
			private:
				vector<ingrediente>::const_iterator it;
			public:
				/**
				* @brief Constructor sin parámetros
				*/
				inline const_iterator(){};  //
				/**
				* @brief Constructor de copia
				* @param i:se copia en el iterador que llama a la función el iterador i
				*/
				inline const_iterator(const const_iterator & i){it=i.it;};  //
				/**
				* @brief Sobrecarga del operador *, se devuelve el contenido a donde apunta el iterador invocante de la llamada
				* @return se devuelve el ingrediente contenido en la posicion a la que se llama
				*/
				ingrediente operator* () const {return *it;};		   //
				/**
				* @brief Se apunta el iterador que invoca la función a la posición siguiente a la que apunta en el momento de la llamada
				* @return iterador que apunta a la siguiente posicion que se pide
				*/
				const_iterator & operator++();		   //
				/**
				* @brief Se apunta el iterador que invoca la función a la posición anterior a la que se apunta en el momento de la llamada
				* @return iterador que apunta a la posición anterior que el original
				*/
				const_iterator & operator--();		   //
				/**
				* @brief sobrecarga del operador distinto para comprobar si dos iteradores son distintos
				* @param i:iterador con el que se comparará
				* @return true si son distintos, false si no lo son
				*/
				bool operator==(const const_iterator & i); //
				/**
				* @brief Sobrecarga del operador *, se devuelve el contenido a donde apunta el iterador invocante de la llamada
				* @return se devuelve el ingrediente contenido en la posicion a la que se llama
				*/
				bool operator!= (const const_iterator & i);//
				friend class ingredientes;
		};
		
		iterator begin(){	iterator i;
					i.it=datos.begin();
					return i;};

		iterator end(){		iterator i;
					i.it=datos.end();
					return i;};

		const_iterator begin() const{	const_iterator i;
						i.it=datos.begin();
						return i;};

		const_iterator end() const{ const_iterator i;
						i.it=datos.end();
						return i;};
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
