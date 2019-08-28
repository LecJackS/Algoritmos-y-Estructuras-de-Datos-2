//////////////
// PRELUDIO //
//////////////
#include<vector>
using namespace std;
// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO   = 1;
const Mes FEBRERO = 2;
const Mes MARZO   = 3;
const Mes ABRIL   = 4;
const Mes MAYO    = 5;
const Mes JUNIO   = 6;
const Mes JULIO   = 7;
const Mes AGOSTO  = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE    = 10;
const Mes NOVIEMBRE  = 11;
const Mes DICIEMBRE  = 12;

// Ejercicio 1: esBisiesto

/* From wikipedia:
    if (year is not divisible by 4) then (it is a common year)
    else if (year is not divisible by 100) then (it is a leap year)
    else if (year is not divisible by 400) then (it is a common year)
    else (it is a leap year)
  */
bool esBisiesto(Anio anio) {
    if (anio%4!=0) {
        return false;
    }
    if (anio%100!=0){
        return true;
    }
    if (anio%400!=0){
        return false;
    }
    return true;
}

map<Mes,int> mes_a_dias = {{ENERO,31},
                           {FEBRERO,28},
                           {MARZO,31},
                           {ABRIL,30},
                           {MAYO,31},
                           {JUNIO,30},
                           {JULIO,31},
                           {AGOSTO,31},
                           {SEPTIEMBRE,30},
                           {OCTUBRE,31},
                           {NOVIEMBRE,30},
                           {DICIEMBRE,31}
          };
// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes) {
    if (mes == FEBRERO && esBisiesto(anio)){
        return mes_a_dias[mes] + 1;
    }
    else{
        return mes_a_dias[mes];
    }
}
//

// Ejercicio 6: clase período
class Periodo {
public:
    // Constructor
    Periodo(Anio anios, Mes meses, Dia dias);
    Anio anios() const;
    Mes meses() const;
    Dia dias()  const;
private:
    Anio _anios;
    Mes _meses;
    Dia _dias;
};

Periodo::Periodo(Anio anios, Mes meses, Dia dias)
        : _anios(anios), _meses(meses), _dias(dias) {
}

Anio Periodo::anios() const {
    return _anios;
}

Mes Periodo::meses() const {
    return _meses;
}

Dia Periodo::dias() const {
    return _dias;
}

class Fecha {
    public:
        // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
        // Constructor
        Fecha(Anio anio, Mes mes, Dia dia);
        // Metodos
        Anio anio() const;
        Mes mes() const;
        Dia dia() const;
        // Operadores de comparacion
        bool operator==(Fecha o) const;
        bool operator<(Fecha o) const;
        bool operator!=(Fecha o) const;
        // Ejercicio 7: sumar período a fecha
        void sumar_periodo(Periodo p);
    private:
        Anio _anio;
        Mes _mes;
        Dia _dia;

        // Ejercicio 7: sumar a fecha
        void sumar_anios(Anio anios);
        void sumar_meses(Mes meses);
        void sumar_dias(Dia dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia)
    : _anio(anio), _mes(mes), _dia(dia) {
}

Anio Fecha::anio() const {
    return _anio;
}

Mes Fecha::mes() const {
    return _mes;
}

Dia Fecha::dia() const {
    return _dia;
}


// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    return (_anio == o.anio() &&
            _mes  == o.mes()  &&
            _dia  == o.dia());
}

// Fecha::operator<
bool Fecha::operator<(Fecha o) const {
    if (_anio < o.anio()) return true;
    if (_anio > o.anio()) return false;
    if (_mes < o.mes()) return true;
    if (_mes > o.mes()) return false;
    if (_dia < o.dia()) {
        return true;
    }
    else{
        return false;
    }
}

// Ejercicio 5: comparador distinto
bool Fecha::operator!=(Fecha o) const{
    return (_anio != o.anio() ||
            _mes  != o.mes()  ||
            _dia  != o.dia());
}

// Parte del 7
void Fecha::sumar_anios(Anio anios) {
    _anio += anios;
}

void Fecha::sumar_meses(Mes meses) {
    _mes += meses;
}

void Fecha::sumar_dias(Dia dias) {
    _dia += dias;
}

Dia diasDelMesDe(Mes mes, Anio anio){
    if (mes == FEBRERO && esBisiesto(anio)){
        return mes_a_dias[mes]+1;
    }
    else{
        return mes_a_dias[mes];
    }
}

void Fecha::sumar_periodo(Periodo p) {
    sumar_dias(p.dias());
    while(_dia > diasDelMesDe(_mes, _anio)){
        _dia -= diasDelMesDe(_mes, _anio);
        _mes += 1;
        if(_mes > 12){
            // Diciembre + 1 = Enero
            _anio += 1;
            _mes -= 12;
        }
    }
    sumar_meses(p.meses());
    while(_mes > 12){
        // Diciembre + 1 = Enero
        _anio += 1;
        _mes -= 12;
    }
    sumar_anios(p.anios());
}

// Ejercicio 8: clase Intervalo
class Intervalo{
    public:
        Intervalo(Fecha desde, Fecha hasta);
        Fecha desde() const;
        Fecha hasta() const;
        Dia enDias() const;

    private:
        Fecha _desde;
        Fecha _hasta;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta)
    : _desde(desde), _hasta(hasta) {
}

Fecha Intervalo::desde() const{
    return _desde;
}

Fecha Intervalo::hasta() const{
    return _hasta;
}

Dia fechaADias(Fecha fecha){
    Dia dias_acum = 0;
    // Sumo dias del corriente mes
    dias_acum += fecha.dia();
    // Sumo meses completados del corriente anio
    Mes aux_mes = fecha.mes();
    while(aux_mes > 1){
        aux_mes -= 1;
        dias_acum += diasDelMesDe(aux_mes, fecha.anio());
    }
    // Sumo anios completos
    Anio aux_anio = fecha.anio();
    while(aux_anio > 0){
        aux_anio -= 1;
        if (esBisiesto(aux_anio)){
            dias_acum += 366;
        }
        else{
            dias_acum += 365;
        }
    }
    return dias_acum;
}

Dia Intervalo::enDias() const {
    // Definir el operador resta en Fecha es medio muerte
    // Paso todo a dias y hago la resta:
    Dia dias_acum_desde = fechaADias(_desde);
    Dia dias_acum_hasta = fechaADias(_hasta);

    //cout << "Desde: " << dias_acum_desde << endl;
    //cout << "Hasta: " << dias_acum_hasta << endl;

    Dia diferencia = dias_acum_hasta - dias_acum_desde;
    return diferencia;
}