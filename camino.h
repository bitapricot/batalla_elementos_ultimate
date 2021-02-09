#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include "casillero.h"

class Camino: public Casillero
{
public:
    Camino();
    int costo_base();
    int calcular_costo(Personaje* nuevo);
    string tipo_casillero();
};


#endif // CAMINO_H_INCLUDED
