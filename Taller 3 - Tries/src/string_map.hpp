#include "string_map.h"

template <typename T>
string_map<T>::string_map() : _raiz(NULL), _size(0){
    // COMPLETAR
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

//template <typename T>
//string_map<T>::Nodo::Nodo(const T& v) : definicion(NULL), siguientes(vector<int>(26, 10)){}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}

template <typename T>
void string_map<T>::insert(const pair<string, T> &tupla){
    //string* key = tupla.first;
    //const T* valor = &tupla.second;

    Nodo* n1 = _raiz;
    if (_raiz==NULL){
        n1 = new Nodo;
        _raiz = n1;
    }

    for (int l=0; l < tupla.first.length(); l++){
        //if( n1->siguientes[int(tupla.first[l])] ){
        if( n1 -> siguientes[int(tupla.first[l])] == NULL){
            Nodo* n2 = new Nodo;
            n1 -> siguientes[ int(tupla.first[l]) - int('a') ] = n2;
        }
        n1 = n1 -> siguientes[ int(tupla.first[l]) - int('a') ];
        _size += 1;
    }

    n1->definicion = new T(tupla.second);
//
//    Nodo* n2 = new Nodo(NULL);
//    n1->siguientes[int('o')] = n2;
//
//    Nodo* n3 = new Nodo(NULL);
//    n2->siguientes[int('l')] = n3;
//
//    Nodo* n4 = new Nodo(NULL);
//    n3->siguientes[int('a')] = n4;
//
//    n4->definicion = new T(NULL);


}

template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    if(_size ==0){
        return 0;
    }
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
}

template <typename T>
bool string_map<T>::empty() const{
    return _size==0;
}