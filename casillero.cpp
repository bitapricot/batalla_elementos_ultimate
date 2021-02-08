#include "casillero.h"

Casillero::Casillero() {
    personaje = 0;
}

Casillero::~Casillero() {
}

bool Casillero::hay_personaje() {
    return personaje != 0;
}

void Casillero::posicionar_personaje(Personaje* nuevo) {
    personaje = nuevo;
}

