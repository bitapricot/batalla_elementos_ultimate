#include "volcan.h"

Volcan::Volcan(): Casillero() {
}

int Volcan::calcular_costo(Personaje* nuevo) {
    int nuevo_costo = 0;
    if(nuevo->de_que_elemento_soy() == ELEMENTO_AGUA) nuevo_costo = COSTO_VOLCAN*2;
    else if(nuevo->de_que_elemento_soy() == ELEMENTO_TIERRA || nuevo->de_que_elemento_soy() == ELEMENTO_AIRE) nuevo_costo = COSTO_VOLCAN;
    return nuevo_costo;
}

string Volcan::tipo_casillero() {
    return VOLCAN;
}
