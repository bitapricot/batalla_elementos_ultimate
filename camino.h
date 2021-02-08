#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include "casillero.h"

class Camino: public Casillero
{
public:
    Camino();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};


#endif // CAMINO_H_INCLUDED
