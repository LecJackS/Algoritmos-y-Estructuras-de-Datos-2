#include "SistemaDeMensajes.h"
#include <iostream>

using namespace std;
// Completar...
SistemaDeMensajes::SistemaDeMensajes() : _conns({NULL,NULL,NULL,NULL}) {
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    cout << "registrarJugador:" << endl;
    (_conns[id]) = new ConexionJugador(ip);

}

bool SistemaDeMensajes::registrado(int id) const {
    cout << "registrado:" << endl;
    if (_conns[id] == NULL) {
        return false;
    }
    else{
        return true;
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {

}

string SistemaDeMensajes::ipJugador(int id) const {
    return (*_conns[id]).ip();
}