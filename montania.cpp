#include "montania.h"

Montania::Montania(): Casillero() {
}

int Montania::calcular_costo(Personaje* nuevo) {
    int nuevo_costo = 0;
    if(nuevo->de_que_elemento_soy() == ELEMENTO_AIRE) nuevo_costo = COSTO_MONTANIA*2;
    else if(nuevo->de_que_elemento_soy() == ELEMENTO_FUEGO || nuevo->de_que_elemento_soy() == ELEMENTO_AGUA) nuevo_costo = COSTO_MONTANIA;
    return nuevo_costo;
}


int Montania::obtener_costo_base() {
    return COSTO_MONTANIA;
}

string Montania::tipo_casillero() {
    return MONTANIA;
}
