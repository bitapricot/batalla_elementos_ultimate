#ifndef MONTANIA_H_INCLUDED
#define MONTANIA_H_INCLUDED

#include "casillero.h"

class Montania: public Casillero
{
public:
    Montania();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};

#endif // MONTANIA_H_INCLUDED
