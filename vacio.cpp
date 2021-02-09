#include "vacio.h"

Vacio::Vacio(): Casillero() {
}

int Vacio::calcular_costo(Personaje* nuevo) {
    return COSTO_VACIO;
}

int Vacio::costo_base() {
    return COSTO_VACIO;
}

string Vacio::tipo_casillero() {
    return VACIO;
}
