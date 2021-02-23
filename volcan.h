#ifndef VOLCAN_H_INCLUDED
#define VOLCAN_H_INCLUDED

#include "casillero.h"

class Volcan: public Casillero
{
public:
    Volcan();
    int calcular_costo(string elemento_pj);
    int obtener_costo_base();
    string tipo_casillero();
};


#endif // VOLCAN_H_INCLUDED
