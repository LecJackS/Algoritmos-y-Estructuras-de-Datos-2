//
// Created by jack on 9/9/19.
//

#include "reversi.h"
#include <vector>
using namespace std;

Reversi::Reversi(int n) : _dim(n) {
    for(int i=0; i<n; i++){
        //_tablero.push_back(Celda(2));
        for(int j=0; j<n; j++) {
            //_tablero.push_back(2);
        }
    }
}

Jugador Reversi::turno() const{
    //return _nfichas%2;
};
