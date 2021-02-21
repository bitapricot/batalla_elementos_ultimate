#ifndef NODO_DICCIONARIO_H_INCLUDED
#define NODO_DICCIONARIO_H_INCLUDED

#include <string>
#include "personaje.h"

using namespace std;

typedef string Clave;
typedef Personaje* Valor;

class Nodo_diccionario
{
private:
    Clave clave;
    Valor valor;
    Nodo_diccionario* izq;
    Nodo_diccionario* der;
    //Nodo_diccionario* padre;

public:
    //Nodo_diccionario(Clave clave, Valor valor, Nodo_diccionario* padre);
    Nodo_diccionario(Clave clave, Valor valor);
    Clave obtener_clave();
    Valor obtener_valor();
    void asignar_clave(Clave nueva);
    void asignar_valor(Valor nuevo);
    void asignar_der(Nodo_diccionario* der, Nodo_diccionario* padre);
    void asignar_izq(Nodo_diccionario* izq, Nodo_diccionario* padre);
    void asignar_izq(Nodo_diccionario* izq);
    void asignar_der(Nodo_diccionario* der);
    void asignar_padre(Nodo_diccionario* padre);
    Nodo_diccionario* obtener_der();
    Nodo_diccionario* obtener_izq();
    Nodo_diccionario* obtener_padre();
    bool es_hoja();
    bool solo_hijo_der();
    bool solo_hijo_izq();

    //~Nodo_diccionario();
};
#endif //Nodo_diccionario_H