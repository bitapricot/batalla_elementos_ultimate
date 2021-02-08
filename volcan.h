#ifndef VOLCAN_H_INCLUDED
#define VOLCAN_H_INCLUDED

#include "casillero.h"

class Volcan: public Casillero
{
public:
    Volcan();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};


#endif // VOLCAN_H_INCLUDED
