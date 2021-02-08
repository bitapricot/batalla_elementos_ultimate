#ifndef VACIO_H_INCLUDED
#define VACIO_H_INCLUDED

#include "casillero.h"

class Vacio: public Casillero
{
public:
    Vacio();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};

#endif // VACIO_H_INCLUDED
