#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include "casillero.h"

class Camino: public Casillero {
public:
    Camino();
    int calcular_costo(Personaje* nuevo);
    int obtener_costo_base();
    string tipo_casillero();
    virtual ~Camino(){};
};


#endif // CAMINO_H_INCLUDED
