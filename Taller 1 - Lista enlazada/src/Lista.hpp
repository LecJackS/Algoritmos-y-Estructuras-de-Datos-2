#include "Lista.h"

template <typename T>
Lista<T>::Lista() : _length(0), _head(NULL), _last(NULL) {
    // Completar
}

template <typename T>
Lista<T>::Nodo::Nodo(const T &elem) : data(elem), next(NULL), prev(NULL) {}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    if(_head == NULL){
        delete(_head);
    }
    else{
        // Itero sobre cada uno de los elementos de la lista para destruirlos
        // El destructor es llamado con el primer elemento
        Nodo* temp = _head->next;
        while(temp != NULL){
            temp = temp->next;
            delete(_head);
            _head = temp;
        }
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    // Completar
    while(_length > 0){
        // Borro cada elemento
        // uso la funcion agregarAtras de la misma clase
        this->eliminar(0);
    }
    for(int i=0; i<aCopiar._length; i++){
        // Itero sobre todos los elementos a copiar
        // uso la funcion agregarAtras de la misma clase
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    // Completar
    Nodo* nuevo = new Nodo(elem);
    if(_head != NULL){
        _head->prev = nuevo;
    }

    nuevo->next = _head;
    _head = nuevo;
    if(_length == 0){
        // If first added elem, head and last are the same
        _last = nuevo;
    }
    _length++;

}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    // Completar
    Nodo* nuevo = new Nodo(elem);
    if(_last != NULL){
        _last->next = nuevo;
    }
    nuevo->prev = _last;
    _last = nuevo;
    if(_length == 0){
        // If first added elem, head and last are the same
        _head = nuevo;
    }
    _length++;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    // Completar
    if(i > _length-1){
        cout << i << "-esimo no existe! Max len:" << _length << endl;
        return;
    }
    if(_length == 1){
        // Elimino ultimo elemento. Explicito valores por defecto.
        _head = NULL;
        _last = NULL;
        _length = 0;
        return;
    }
    if(i==0){
        // Eliminar primero
        _head = _head->next;
        _head->prev = NULL;
    }
    else if(i == _length-1){
        // Eliminar ultimo
        _last = _last->prev;
        _last->next = NULL;
    }
    else{
        // Eliminar alguno del medio
        Nodo* to_del = _head;
        for(int j=0; j<i; j++){
            to_del = to_del->next;
        }
        Nodo* prev_del = to_del->prev;
        Nodo* next_del = to_del->next;
        to_del->prev->next = next_del;
        to_del->next->prev = prev_del;
    }
    _length--;
}

template <typename T>
int Lista<T>::longitud() const {
    // Completar

    return _length;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
    if(i > _length-1){
        cout << i << "-esimo no existe! Max len:" << _length << endl;
        return _head->data;
    }
    int count = 0;
    Nodo* nodo = _head;
    while (count < i){
        nodo = nodo->next;
        count++;
    }
    return nodo->data;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar
    int j = _length;
    if(i > _length-1){
        cout << i << "-esimo no existe! Max len:" << _length << endl;
        return _head->data;
    }
    int count = 0;
    Nodo* nodo = _head;
    while (count < i){
        nodo = nodo->next;
        count++;
    }
    return nodo->data;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}