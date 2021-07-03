/**
 * @file Kmer.h
 * @author MP
 */
#ifndef Kmer_H
#define Kmer_H

/**
 * @brief Clase Kmer
 */
class Kmer{
public:
	/**
	 * @brief Constructor base
	 */
	Kmer();
	/**
	 * @brief Construye e inicializa el Kmer
	 * @param c Cadena inicial
	 * @param f Frecuencia inicial
	 */
	Kmer(const std::string & c, int f);
	/**
	 * @brief Consulta el valor del Kmer 
	 * @return La cadena del Kmer
	 */
	std::string getCadena() const;
	/**
	 * @brief Consulta el valor del Kmer 
	 * @return La frecuencia del Kmer
	 */
	int getFrecuencia() const;
	/**
	 * @brief Modifica la cadena del Kmer
	 * @param c La nueva cadena
	 */
	void setCadena(const std::string &c);
	/**
	 * @brief Modifica la frecuencia del Kmer
	 * @param f La nueva frecuencia
	 */
	void setFrecuencia(int f);
	/**
	 * @brief Lee el Kmer desde el teclado 
	 */
	void readKmer();
	/**
	 * @brief Escribe el Kmer en pantalla 
	 */
	void writeKmer() const;

private:
	std::string _kmer;
	int _frecuencia;
};


#endif 
