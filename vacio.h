#ifndef VACIO_H_INCLUDED
#define VACIO_H_INCLUDED

#include "casillero.h"

class Vacio: public Casillero
{
public:
    Vacio();
    int calcular_costo(Personaje* nuevo);
    int obtener_costo_base();
    string tipo_casillero();
    virtual ~Vacio(){};
};

#endif // VACIO_H_INCLUDED
