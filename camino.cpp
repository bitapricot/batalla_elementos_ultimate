#include "camino.h"

Camino::Camino(): Casillero() {
}

int Camino::calcular_costo(Personaje* nuevo) {
    return COSTO_CAMINO;
}

int Camino::costo_base() {
    return COSTO_BASE_CAMINO;
}

string Camino::tipo_casillero() {
    return CAMINO;
}
