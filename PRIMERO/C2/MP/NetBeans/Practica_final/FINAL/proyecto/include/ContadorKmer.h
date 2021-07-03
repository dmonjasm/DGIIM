/** 
 * @file ContadorKmer.h
 * @author Daniel Monjas Miguélez
*/
#ifndef CONTADORKMER_H
#define CONTADORKMER_H

#include <string>

#include "Kmer.h"
#include "SecuenciasKmer.h"

/**
 * @brief Clase ContadorKmer
 */
class ContadorKmer {
public:	 
   static const std::string INI_VALIDOS; ///> Caracteres válidos por omisión
	static const int INI_K; ///< Tamaño del kmer por omisión
	
	/**
	 * @brief Constructor por defecto 
	 */
	ContadorKmer(); 
	/**
	 * @brief Constructor con parámetros. 
	 * @param ok Cadena de caracteres válidos
	 * @param k Tamaño de los Kmer
	 */
	ContadorKmer(const std::string & validos, int k);
	/**
	 * @brief Constructor de copia
	 * @param orig El objeto que se copia en en el constructor
	 */
	ContadorKmer(const ContadorKmer & orig);  
	/**
	 * @brief Destructor de la clase 
	 */
	~ContadorKmer(); 
	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param orig Parámetro rhs de la asignación
	 * @return this para concatenación de asignaciones de derecha a izquierda
	 */
	ContadorKmer& operator=(const ContadorKmer& orig);
	/**
	 * @brief Consulta el número de perfiles activos en el contador
	 * @return Número de perfiles
	 */
	int getNumPerfiles() const;
	/**
	 * @brief Devuelve el número máximo de kmers posibles, el cual depende del 
	 * número de caracteres válidos y del tamaño del kmer
	 * @return El número de kmers posible
	 */
	long getNumKmer() const;
	/**
	 * @brief Añade una fila al contador y pone todos los elementos a 0 
	 */
	void addPerfil();
	/**
	 * @brief Añade una fila al contador e inicializa la fila con los datos
	 * contenidos en la secuencia
	 * @param perfil Secuencia de Kmers que se va a introducir en la fila recien creada
	 */
	void addPerfil(SecuenciasKmer perfil);
	/**
	 * @brief Añade un kmer al perfil indicado. Si la frecuencia del kmer es 0, se incrementa 
	 * el contador en 1. En otro caso, se incrementa el contador con la frecuencia del kmer
	 * @param perfil Fila del contador a la que se añade el kmer
	 * @param km El kmer a añadir
	 * @precond @p perfil debe indicar una fila correcta del contador
	 * @return @retval true si ha sido posible la operación @retval false en caso contrario
	 */
	bool addKmer(int perfil, const Kmer &tg);
	/**
	 * @brief Devuelve una fila del contador como una secuencia de Kmers, eliminando los 
	 * kmer cuya frecuencia sea estrictamente inferior a la frecuencia mínima indicada. La 
	 * secuencia de kmers debe devolverse ordenada de mayor a menor frecuencia
	 * @param perfil La fila del contador que se va a extraer
	 * @param frecmin Frecuencia mínima de los kmers que se van a extraer
	 * @return Una secuencia de kmers ordenada 
	 */
	SecuenciasKmer getSecuenciasKmer(int perfil, int frecmin) const;

	/**
	 * @brief Carga las secuencias de texto de un fichero de texto, identifica los kmers 
	 * y calcula sus frecuencias, según lo indicado en el enunciado de la práctica y las 
	 * almacena en una fila del contador, incrementandola a los valores que ya hubiese en
	 * la fila
	 * @param perfil Fila del contador que se va a actualizar
	 * @param nfichero Nombre del fichero .dna que contiene la secuencia de adn
	 * @return @retval true si se ha cargado con éxito @retval false en otro caso
	 */
	bool calcularFrecuenciasKmer(int perfil, const char* nfichero);


private:
	int ** _contador, ///< Matriz bidimensional para contar kmers agrupados en perfiles
			  _nperfiles; ///< Número de perfiles de la matriz
	std::string _VALIDOS;	///< Caracteres válidos reales del contador
	int _K;						///< Tamaño real de kmer
	long _NKMER;				///< Número máximo de kmers en cada fila del contador

	/**
	 * @brief Reserva la memoria dinámica necesaria para una matriz2D de @a n x @a n
	 * @param n Número de filas y columnas de la matriz2D (es una matriz cuadrada)
	 */
	void reservarMemoria(int npersonas);

	/**
	 * @brief Libera la memoria dinámica reservada para la matriz2D
	 */
	void liberarMemoria();

	/**
	 * @brief Duplica el objeto que se pasa por parámetro en el objeto actual
	 * @param otro El objeto que se quiere copiar
	 */
	void copiar(const ContadorKmer & otro);
	/**
	 * @brief Normaliza un Kmer. La longitud debe ser exactamente la fijada por @p K y cualquier carácter
	 * ausente o nó @p VALIDO debe ser sustituido por el carácter comodín @p VALIDOS[0].
	 * Igualmente, cualquier carácter @p VALIDO debe pasarse a minúscula. Finalmente, la frecuencia
	 * debe ser >= 0
	 * @param km El Kmer a normalizar
	 * @return Una copia normalizada de @p km
	 */
	Kmer normalizaKmer(const Kmer & ng) const; 

	/**
	 * @brief Dado un kmer, calcula el índice asociado a él. Este índice determina la
	 * columna, de forma biunivoca, en la que se almacenará el contador del kmer
	 * @param t El kmer
	 * @return Un valor entero que se puede usar como índice para acceder a las columnas
	 * de la matriz del contador
	 */
	long getIndiceKmer(const Kmer &t) const;
	/**
	 * @brief Operación inversa a @p getIndiceKmer(), es decir, dado el índice de una columna
	 * reconstruye el kmer que  biunívocamente está asociado a él
	 * @param i Un valor válido de columnas del contador
	 * @return El kmer biunívocamente asociado a @p i. Se ignora la frecuencia del kmer
	 */
	Kmer getIndiceInversoKmer(long i) const;
};


#endif
