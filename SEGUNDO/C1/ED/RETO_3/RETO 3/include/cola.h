/**
 * @file cola.h
 *@author Daniel Monjas Miguélez
 *@author Manuel Horacio Torres Cañero
 */

#ifndef COLA_H
#define COLA_H

#include<stack>

using namespace std;

template <class T>
class cola {
    private:
        stack<T> pila;
        
    public:
        /**
         * @brief Constructor por defecto
         */
        cola(){ };
        
        /**
         * @brief Constructor de copia
         * @param c El objeto que se copia en el constructor
         */
        cola(const cola<T> & c);
        
        /**
         * @brief Comprueba si la cola está vacía o no
         * @return true si está vacía o false si contiene algún dato
         */
        bool empty() const;
        
        /**
         * @brief Limpia la cola y la deja vacía
         */
        void clear();
        
        /**
         * @brief Devuelve el primer elemento de la cola
         * @return Primer elemento de la cola
         */
        T front();
        
        /**
         * @brief Consulta el primer elemento de la cola (constante)
         * @return Primer elemento de la cola
         */
        const T & front() const;
        
        /**
         * @brief Inserta un elemento al final de la cola
         * @param elem
         */
        void push_back(const T & elem);
        
        /**
         * @brief Elimina el primer elemento de la cola
         */
        void pop_front();
        
        /**
         * @brief Consulta el tamaño de la cola
         * @return Tamaño de la cola
         */
        unsigned int size() const;
        
        /**
         * @brief Se intercambia el contenido de dos colas
         * @param c
         */
        void swap(cola <T> & c);
        
        /**
         * @brief Destructor de la clase cola
         */
        ~cola(){ };
};

#include "cola.cpp"
#endif