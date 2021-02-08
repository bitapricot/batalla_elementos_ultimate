#include "precipicio.h"

Precipicio::Precipicio(): Casillero() {
}

int Precipicio::calcular_costo(Personaje* nuevo) {
    int nuevo_costo = 0;
    if(nuevo->de_que_elemento_soy() == ELEMENTO_TIERRA) nuevo_costo = COSTO_PRECIPICIO*2;
    else if(nuevo->de_que_elemento_soy() == ELEMENTO_FUEGO || nuevo->de_que_elemento_soy() == ELEMENTO_AGUA) nuevo_costo = COSTO_PRECIPICIO;
    return nuevo_costo;
}

string Precipicio::tipo_casillero() {
    return PRECIPICIO;
}
