#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>
#include "personaje.h"

using namespace std;

typedef string Clave;
typedef Personaje* Valor;

class Nodo {
private:
    Valor valor;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
    Clave clave;
public:
    Nodo(Clave clave, Valor valor, Nodo* padre);
    void copiar_nodo(Nodo* n);
    bool es_hoja();
    void insertar_der(Nodo* der);
    void insertar_izq(Nodo* izq);
    void insertar_padre(Nodo* padre);
    Clave obtener_clave();
    Nodo* obtener_der();
    Nodo* obtener_izq();
    Nodo* obtener_padre();
    Valor obtener_valor();
    bool solo_hijo_der();
    bool solo_hijo_izq();
    void asignar_clave(Clave clave);

};


#endif // NODO_H_INCLUDED
