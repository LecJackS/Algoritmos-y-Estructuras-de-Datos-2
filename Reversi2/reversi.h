//
// Created by jack on 9/9/19.
//

#ifndef REVERSI2_REVERSI_H
#define REVERSI2_REVERSI_H

#include <vector>
using namespace std;

struct Coord { int x; int y; };

enum Jugador { Rojo, Azul };

enum Celda { FichaRoja, FichaAzul, Nada };

typedef vector<vector<Celda>> Tablero;

class Reversi {
public:
    Reversi(int n);
    Jugador turno() const;
    void jugar(Coord c);
    int puntaje(Jugador j) const;
    void mostrar(Tablero& t) const;
private:
    int _dim;
    Tablero _tablero;
    int _nfichas;
};



#endif //REVERSI2_REVERSI_H
