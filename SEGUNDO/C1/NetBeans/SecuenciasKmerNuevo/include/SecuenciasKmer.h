/**
 * @file SecuenciasKmer.h
 * @author MP
 */
#ifndef SECUENCIASKMER_H
#define SECUENCIASKMER_H
#include "Kmer.h"

const std::string MAGIC="MP-KMER";

/**
 * @brief Clase SecuenciasKmer
 */
class SecuenciasKmer{
public:
	/**
	 * @brief Constructor base
	 */
	SecuenciasKmer();

	/**
	 * @brief Constructor para pre-reservar memoria
	 * @param nkm Número de kmer pre-reservados
	 */
	SecuenciasKmer(long nkm);

	/**
	 * @brief Constructor de copia
	 * @param orig La secucncia que se quiere copiar
	 */
	//SecuenciasKmer(const SecuenciasKmer& orig); 

	/**
	 * @brief Destructor
	 */
	~SecuenciasKmer(); 

	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param orig Parámetro rhs de la asignación
	 * @return this para concatenación de asignaciones de derecha a izquierda
	 */
	//SecuenciasKmer& operator=(const SecuenciasKmer& orig); 

	/**
	 * @brief Añade un kmer al final del vector
	 * @param km El kmer a insertar
	 * @precond El vector tiene espacio libre
	 * @return @p true si ha sido posible la inserción, @p false si el vector 
	 * está lleno
	 * 
	 * @deprecated Este método ya no se va a usar más
	 */
	bool addKmer(const Kmer &km);
	
	/**
	 * @brief Consulta la secuencia de Kmer
	 * @param p La posición de la secuencia que se quiere consultar
	 * @precond La posición @p p es correcta
	 * @return Una copia del Kmer que ocupa la posición @p p
	 */
	Kmer getPosicion(long p) const;

	/**
	 * @brief Añade un nuevo Kmer
	 * @param p La posición en la que se quiere insertar el Kmer
	 * @precond La posición @p p es correcta
	 * @param km El Kmer a insertar
	 */
	void setPosicion(long p, const Kmer & km);

	/**
	 * @brief Borra la posición @p p de la secuencia y compacta la secuencia
	 * @param p La posición a borrar
	 * @precond La posición @p p es correcta
	 */
	void deletePosicion(long p);
	/**
	 * @brief Consulta el número de Kmer existentes. 
	 * @return El tamaño de la secuencia de Kmer
	 */
	inline long getSize() const { return _nKmer; };

	/**
	 * @brief Busca un kmer en la lista de kmer
	 * @param km El Kmer que se está buscando
	 * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
	 */
	long findKmer(const std::string& km, long inicial=0) const;

	/**
	 * @brief Ordena la secuencia de Kmer de mayor a menor frecuencia
	 */
	void ordenar();
	
	/**
	 * @brief Elimina los kmer duplicados y suma las frecuencias de cada par de duplicados 
	 * Además, elimina los Kmer con frecuencias nulas.
	 */
	void zipSecuenciasKmer();
	
	/**
	 * @brief Lee el vector de Kmer desde el teclado 
	 */
	void readSecuenciasKmer();
	/**
	 * @brief Escribe el Kmer en pantalla 
	 */
	void writeSecuenciasKmer(int frecmin=0) const;
	
	/**
	 * @brief Serializa y guarda una secuencia en un fichero
	 * @param fichero El fichero de salida
	 * @return @b false si ha habido algún tipo de error, @b true en otro caso
	 */
	bool saveFichero(const char *fichero) const;

	/**
	 * @brief Recupera una serialización de una secuencia desde un fichero y 
	 * reconstruye la secuencia de kmers
	 * @param fichero Fichero que contiene una secuencia serializada
	 * @precond Se deben normalizar los kmer leídos
	 * @precond El fihero de entrada debe ser del tipo esperado (MP-KMER)
	 * @precond Debe haber suficiente espacio en memoria para cargar el fichero
	 * @return @b false si ha habido algún tipo de error, @b true en otro caso
	 */
	bool loadFichero(const char *fichero);

private:
	Kmer* _conjunto;     /// Vector dinámico de kmer
	int _nKmer;         /// Número de kmer en el vector dinámico

	/**
	 * @brief Reserva memoria para una secuencia de Kmers
	 * @param n El número de Kmers que se reservan
	 */
	void reservarMemoria(long n);
	/**
	 * @brief Libera la memoria 
	 */
	void liberarMemoria();
	/**
	 * @brief Copia el objeto que se pasa como argumento
	 * @param otro El objeto que se copia
	 */
	//void copiar(const SecuenciasKmer& otro);

};




#endif

