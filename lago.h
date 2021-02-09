#ifndef LAGO_H_INCLUDED
#define LAGO_H_INCLUDED

#include "casillero.h"

class Lago: public Casillero
{
public:
    Lago();
    int calcular_costo(Personaje* nuevo);
    int costo_base();
    string tipo_casillero();
};

#endif // LAGO_H_INCLUDED
