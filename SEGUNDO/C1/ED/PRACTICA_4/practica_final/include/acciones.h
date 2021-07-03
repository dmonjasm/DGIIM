#ifndef ACCIONES_H
#define ACCIONES_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

class acciones{
    private:
        map<string, unsigned char> datos;
    
    public:
        /**
         * @brief Constructor sin parametros
        **/
        acciones(){};
        /**
         * @brief Constructor de copia
         * @param copia map del cual se quiere copiar el contenido
        **/
        acciones(const map<string, unsigned char> & copia){datos=copia;};
        /**
         * @brief Devuelve los operandos asociados a una clave dada
         * @param clave Clave cuyos operandos se quieren conocer
         * @return numero de operandos asociados a dicha clave
        **/
        unsigned char operator[](const string & clave){return datos[clave];};
        /**
         * @brief Devuelve si el objeto actual esta vacio
         * @return true si esta vacio, false en caso contrario
        **/
        bool empty(){return datos.empty();};
        /**
         * @brief Devuelve el tamaño actual del objeto
         * @return Un entero indicando el numero de elementos del map
        **/
        int size(){return datos.size();};
        /**
         * @brief Inserta el objeto pasado como parametro en el map
         * @param insertar pair que se insertara
        **/
        void insertar(const pair<string, unsigned char> insertar){datos.insert(insertar);};
        /**
         * @brief Elimina el objeto que tiene la clave buscada si existe
         * @param clave que se quiere eliminar del map
        **/
        void borrar(const string & clave){datos.erase(clave);};
        acciones & operator=(const acciones & copiar){datos=copiar.datos;
                                                        return *this;};
        class iterator{
        private:
            map<string, unsigned char>::iterator it;
        public:
            /**
             * @brief Constructor sin parámetros
             */
            iterator(){};
            /**
             * @brief Constructor de copia con parámetros
             * @param i: iterador el cual se copiará
             */
            iterator(const iterator & i){it=i.it;};
            /**
             * @brief Sobrecarga del operador de incremento, se incrementa la posición a la que apunta el iterador
             * @return Se devuelve una referencia a iterator
             */
            iterator & operator++(){++it;
                                   return *this;};
            /**
             * @brief Sobrecarga del operador de decremento, se decrementa la posición a la que se apunta el iterador
             * @return Se devuelve una referencia a iterator
             */                        
            iterator & operator--(){--it;
                                return *this;};
            /**
             * @brief Sobrecarga del operator ==, devuelve si dos iteradores son iguales
             * @param i: iterador con el que se compara
             * @return true si son iguales, false en caso contrario
             */                        
            bool operator==(const iterator & i){return i.it==it;};
            /**
             * @brief Sobrecarga del operator !=, devuelve si dos iteradores son distintos
             * @param i: iterador con el que se va a comparar
             * @return true si son distintos, false en caso contrario
             */
            bool operator!=(const iterator & i){return i.it!=it;};
            /**
             * @brief Sobrecarga del operador *, se devuelve el pair al que apunta el iterador
             * @return Se retorna el unsigned que apunta el iterador
             */
            pair<string,unsigned char> operator*(){return *it;};
            friend class acciones;    
        };
    
    
        class const_iterator{
        private:
            map<string, unsigned char>::const_iterator it;
        
        public:
            /**
             * @brief Constructor sin parámetros
             */
            const_iterator(){};
            /**
             * @brief Constructor de copia
             * @param i: const_iterator que se copiará
             */
            const_iterator(const const_iterator & i){it=i.it;};
            /**
             * @brief Sobrecarga del operador de incremento, se incrementa la posición a la que apunta el iterador
             * @return Se devuelve una referencia a iterator
             */
            const_iterator & operator++(){++it;
                                       return *this;}
            /**
             * @brief Sobrecarga del operador de decremento, se decrementa la posición a la que se apunta el const_iterador
             * @return Se devuelve una referencia a const_iterator
             */ 
            const_iterator & operator--(){--it; 
                                        return *this;};
            /**
             * @brief Sobrecarga del operator !=, devuelve si dos const_iteradores son iguales
             * @param i: const_iterador con el que se va a comparar
             * @return true si son iguales, false en caso contrario
             */                               
            bool operator==(const const_iterator & i){return it==i.it;};
            /**
             * @brief Sobrecarga del operator !=, devuelve si dos const_iteradores son distintos
             * @param i: const_iterador con el que se va a comparar
             * @return true si son distintos, false en caso contrario
             */
            bool operator!=(const const_iterator & i){return it!=i.it;};
            /**
             * @brief Sobrecarga del operador *, se devuelve el pair al que apunta el const_iterador
             * @return Se retorna el unsigned char que apunta el const_iterador
             */
            pair<string, unsigned char> operator*() const{return *it;};
            friend class acciones;
        };
    
        /**
         * @brief Se devuelve un iterator a la primera posicion del contenedor
         * @return iterator apuntando a la primera posición del contenedor
         */
        iterator begin(){
                    iterator i;
                    i.it=datos.begin();
                    return i;
        }
        /**
         * @brief Se devuelve un iterator a la última posicion del contenedor
         * @return iterator apuntando a la última posición del contenedor
         */
        iterator end(){
                iterator i;
                i.it=datos.end();
                return i;
        }
    
        /**
         * @brief Se devuelve un const_iterator a la primera posicion del contenedor
         * @return const_iterator apuntando a la primera posición del contenedor
         */
        const_iterator begin() const{
                    const_iterator i;
                    i.it=datos.begin();
                    return i;
        }
        /**
         * @brief Se devuelve un const_iterator a la última posicion del contenedor
         * @return const_iterator apuntando a la última posición del contenedor
         */
        const_iterator end() const{
                const_iterator i;
                i.it=datos.end();
                return i;
        }
        /**
         * @brief sobrecarga del operador de salida
        **/
        friend std::ostream & operator <<(std::ostream &os, const acciones & salida);
        /**
         * @brief Sobrecarga del operador de entrada
        **/
        friend std::istream & operator >>(std::istream &is, acciones & entrada);

};
std::istream & operator >>(std::istream &is, acciones & entrada);
std::ostream & operator <<(std::ostream &os, const acciones & salida);

#endif