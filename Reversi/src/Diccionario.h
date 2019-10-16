#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>
using namespace std;
typedef int Clave;
typedef int Valor;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
	vector<Clave> claves() const;
    int size() const;
	//operadores
	bool operator==(Diccionario o);
	// Union
	Diccionario operator||(Diccionario o);
	// Interseccion
	Diccionario operator&&(Diccionario o);
	
private:
	// Completar para el ejercicio 4
	struct Asociacion {
	    Clave clave;
	    Valor valor;
	};
	vector<Asociacion> _asociacion;
	
};

#endif /*__DICCIONARIO_H__*/
