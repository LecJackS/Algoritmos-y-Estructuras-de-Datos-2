struct Coord { int x; int y; };

enum Jugador { Rojo, Azul };

enum Celda { FichaRoja, FichaAzul, Nada };

typedef std::vector<std::vector<Celda>> Tablero;

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

Reversi::Reversi(int n) : _dim(n) {
    for(int i=0; i<n; i++){
        _tablero.push_back(2)
        for(int j=0; j<n; j++) {
            _tablero.push_back(2)
        }
    }
}

Jugador Reversi::turno() const{
    return _nfichas%2;
};
