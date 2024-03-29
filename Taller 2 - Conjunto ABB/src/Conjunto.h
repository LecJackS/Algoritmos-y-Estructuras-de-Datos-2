#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

        // Mostrar Inorder
        void mostrar_inorder();

    private:
        /*** Completar con lo que sea necesario... ***/
        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v) : valor(v), parent(NULL), izq(NULL), der(NULL) {};
            // El elemento al que representa el nodo.
            T valor;
            // Puntero al nodo padre
            Nodo* parent; // parent
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der;
        };
        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;
        // AGREGO:
        // Cantidad de nodos en el conjunto
        int _cardinal;
        // busca un valor y devuelve un puntero al nodo del conjunto.
        // si no existe, devuelve NULL
        Nodo* buscar(const T&) const;
        //
        void transplantar(Nodo* u, Nodo* v);
        //
        void inorder_tree_walk_search_next(Nodo* nodo, const T& clave);
        T _elQueSigue;
        // Para mostrar
        void inorder_tree_walk(Nodo* nodo);
        // Para borrar
        void inorder_tree_destruction(Nodo* nodo);
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
