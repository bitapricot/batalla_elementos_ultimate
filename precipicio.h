#ifndef PRECIPICIO_H_INCLUDED
#define PRECIPICIO_H_INCLUDED

#include "casillero.h"

class Precipicio: public Casillero
{
public:
    Precipicio();
    int calcular_costo(string elemento_pj);
    int obtener_costo_base();
    string tipo_casillero();
};

#endif // PRECIPICIO_H_INCLUDED
