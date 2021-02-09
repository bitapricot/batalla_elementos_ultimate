#ifndef MONTANIA_H_INCLUDED
#define MONTANIA_H_INCLUDED

#include "casillero.h"

class Montania: public Casillero
{
public:
    Montania();
    int calcular_costo(Personaje* nuevo);
    int costo_base();
    string tipo_casillero();
};

#endif // MONTANIA_H_INCLUDED
