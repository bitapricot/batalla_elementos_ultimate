#ifndef LAGO_H_INCLUDED
#define LAGO_H_INCLUDED

#include "casillero.h"

class Lago: public Casillero
{
public:
    Lago();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};


#endif // LAGO_H_INCLUDED
