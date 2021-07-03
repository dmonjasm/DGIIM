/**
 * @file SecuenciasKmer.h
 * @author Daniel Monjas Miguélez
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
	SecuenciasKmer(const SecuenciasKmer& orig); 

	/**
	 * @brief Destructor
	 */
	~SecuenciasKmer(); 

	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param orig Parámetro rhs de la asignación
	 * @return this para concatenación de asignaciones de derecha a izquierda
	 */
	SecuenciasKmer& operator=(const SecuenciasKmer& orig); 

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
	 * @brief Consulta el número de Kmer existentes. 
	 * @return El tamaño de la secuencia de Kmer
	 */
	inline long getSize() const { return _nKmer; };

	/**
	 * @brief Busca un kmer en la lista de kmer
	 * @param km El Kmer que se está buscando
	 * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
	 */
	long findKmer(const std::string& km) const;
	
	/**
	 * @brief Ordena la secuencia de Kmer de mayor a menor frecuencia
	 */
	void ordenar();

	/**
	 * @brief Serializa y guarda una secuencia en un fichero
	 * @param fichero El fichero de salida
	 * @return @b false si ha habido algún tipo de error, @b true en otro caso
	 */
	bool saveFichero(const char *fichero) const;

	/**
	 * @brief Recupera una serialización de una secuencia desde un fichero y 
	 * reconstruye el idioma
	 * @param fichero Fichero que contiene un idioma serializado
	 * @return @b false si ha habido algún tipo de error, @b true en otro caso
	 */
	bool loadFichero(const char *fichero);

	/**
	 * @brief Calcula la distancia entre dos diccionarios
	 * @param otro El segundo diccionario para consultar la distancia
	 * @return La distancia
	 */
	double distancia(const SecuenciasKmer & d) const;

	friend std::ostream & operator<<(std::ostream & os, const SecuenciasKmer & s);
	friend std::istream & operator>>(std::istream & os, SecuenciasKmer & s);

	/**
	 * @brief Borra la posición @p p de la secuencia y compacta la secuencia
	 * @param p La posición a borrar
	 * @precond La posición @p p es correcta
	 * 
	 * @deprecated Este método ya no se va a usar más
	 */
	void deletePosicion(long p);
	
	/**
	 * @brief Elimina los kmer duplicados y suma las frecuencias de cada par de duplicados 
	 * Además, elimina los Kmer con frecuencias nulas.
	 * 
	 * @deprecated Este método ya no se va a usar más
	 */
	void zipSecuenciasKmer();

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
	void copiar(const SecuenciasKmer& otro);


};

/**
 * @brief Serialización de una secuencia para su inserción en un flujo de salida.
 * @param os Flujo de salida
 * @param i Secuencia a serializar
 * @return El mismo flujo de salida para inserciones consecutivas
 */
std::ostream & operator<<(std::ostream & os, const SecuenciasKmer & i);

/**
 * @brief Reconstruye un Diccionario a partir de una serialización
 * @param is Flujo de entrada desde el que se extrae la serialización
 * @param i Diccionario reconstruido
 * @return El mismo flujo de entrada para extracciones consecutivas
 */
std::istream & operator>>(std::istream & is, SecuenciasKmer & i);



#endif

