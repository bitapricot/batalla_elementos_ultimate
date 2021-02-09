#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include "casillero.h"

class Camino: public Casillero
{
public:
    Camino();
    int calcular_costo(Personaje* nuevo);
    int costo_base();
    string tipo_casillero();
};


#endif // CAMINO_H_INCLUDED
