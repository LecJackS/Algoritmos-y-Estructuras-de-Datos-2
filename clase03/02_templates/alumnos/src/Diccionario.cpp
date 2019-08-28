#include <vector>
#include "Diccionario.h"

// Constructor
Diccionario::Diccionario() {}

void Diccionario::definir(Clave k, Valor v) {
    if(!def(k)){
        Asociacion nuevo_kv = {k,v};
        _asociacion.push_back(nuevo_kv);
    }
    else{
        for (int i=0; i < _asociacion.size(); i++){
            // Loop over every key-value pair
            Clave key = _asociacion[i].clave;
            if (k == key){
                // Sobreescribe valor anterior
                _asociacion[i].valor = v;
            }
        }
    }
}

bool Diccionario::def(Clave k) const {
    for (Asociacion kv_pair : _asociacion){
        // Loop over every key-value pair
        Clave key = kv_pair.clave;
        if (k == key){
            return true;
        }
    }
    return false;
}

Valor Diccionario::obtener(Clave k) const {
    for (Asociacion kv_pair : _asociacion){
        // Loop over every key-value pair
        Clave key = kv_pair.clave;
        if (k == key){
            return kv_pair.valor;
        }
    }
    return 0;
}
//5
void Diccionario::borrar(Clave k) {
    for (int i=0; i < _asociacion.size(); i++){
        // Loop over every key-value pair
        Clave key = _asociacion[i].clave;
        if (k == key){
            // Pisa el valor con el ultimo y borra el ultimo del vector
            _asociacion[i] = _asociacion[_asociacion.size()-1];
            _asociacion.pop_back();
        }
    }
}
//6
vector<Clave> Diccionario::claves() const {
    vector<Clave> claves;
    for (int i=0; i < _asociacion.size(); i++){
        // Loop over every key-value pair
        Clave key = _asociacion[i].clave;
        claves.push_back(key);
    }
    return claves;
}

//7
int Diccionario::size() const {
    return _asociacion.size();
}

bool Diccionario::operator==(Diccionario o) {
    // Check same size
    if(_asociacion.size() != o.size()){
        return false;
    }
    // (Elementos unicos y misma cantidad) => (solo hace falta
    // verificar pertenencia en una direccion (no doble inclusion))
    for(int i=0; i<_asociacion.size();i++){
        Clave key   = _asociacion[i].clave;
        Valor value = _asociacion[i].valor;
        if(!o.def(key) || value != o.obtener(key)){
            return false;
        }
    }
    return true;
}
// Ej8

Diccionario Diccionario::operator||(Diccionario o) {
    // Agrego los segundos
    vector<Clave> lista_claves = o.claves();
    Diccionario union_d;
    for(Clave key : lista_claves) {
        union_d.definir(key, o.obtener(key));
    }

    // Piso los repetidos con el primero
    for(int i=0; i<_asociacion.size();i++){
        Clave key   = _asociacion[i].clave;
        Valor value = _asociacion[i].valor;
        union_d.definir(key, value);
    }
    return union_d;
}

Diccionario Diccionario::operator&&(Diccionario o) {
    // Agrego los segundos
    vector<Clave> lista_claves = o.claves();
    Diccionario union_d;
    for(Clave key : lista_claves) {
        if(def(key)){
            // existe en ambos dicts
            union_d.definir(key, obtener(key));
        }
    }
    return union_d;
}