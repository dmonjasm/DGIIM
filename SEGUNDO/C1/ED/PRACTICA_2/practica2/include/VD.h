#ifndef VD_h
#define VD_h

template <class T>
class VD{
	private:
		T * datos;		//zona de memoria para almacenar los datos de tipo T
		int reservados;		//espacio asignado a datos
		int n;			//numero de datos almacenados
		/**
		* @brief Reserva nuevotam memoria para el vector dinámico
		* @param nuevotam: nuevo tamaño que tendrá el vector dinámico tras la redimension
		* @pre Nuevotam debe de ser >0
		*/
		void resize (int nuevotam);
		/**
		* @brief Copia en el objeto que llama la función el objeto v
		* @param v: objeto a copiar
		*/
		void Copiar(const VD<T> &v);
		/**	
		* @brief Libera la memoria reservada para el vector dinámico
		* @pre El vector dinámico no debe estar apuntando a nullptr
		*/
		void Liberar();

	public:
		/**
		* @brief Constructor por defecto y con parametro
		* @param tam:elementos a reservar para el vector dinámico
		* @note si no se proporciona un valor para tam se tomara como 10 
		*/
		VD(int tam=10);
		/**
		* @brief Constructor de copia
		* @param original: vector dinamico original que se va a copiar
		*/		
		VD(const VD<T> & original);
		/**
		* @brief Destructor. Elimina la memoria asociada al vector dinámico
		*/
		~VD();
		/**
		* @brief Operador de asignacion
		* @param v: vector dinámico fuente
		* @return una referencia al objeto al que apunta this
		*/
		VD<T> &operator=(const VD<T> &v);
		/**
		* @brief Devuelve el numero de datos almacenados en el vector dinamico
		*/
		inline int size() const {return n;}
		/**
		* @brief Consulta y modifica el elemento i-esimo
		* @param i: posicioin del vector a modifica y/o consultar
		* @return una referencia al i-esimo elemento del vector dinámico
		*/
		inline T &operator[](int i){return datos[i];}	//version no constante
			
		inline T &operator[](int i) const {return datos[i];}	//versión constante
		/**
		* @brief Inserta un objeto en la posicion pos del vector dinámico
		* @param d: objeto a insertar
		* @param pos: posicion donde insertar.
		* @pre pos debe estar comprendido entre 0 y size()
		* @post aumenta en uno el vector dinamico
		*/
		void Insertar(const T dato_insertar, const int indice_insertar);
		/**
		* @brief Elimimina el elemento en la posición pos del vector dinamico
		* @param pos: posicon del elemento a borrar
		*/
		void Borrar(const int indice_borrar);		
};



#include "VD.cpp"
#endif
