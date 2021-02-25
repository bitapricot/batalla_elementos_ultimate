#include "casillero.h"

Casillero::Casillero() {
    personaje = 0;
}

Personaje* Casillero::obtener_personaje() {
    return personaje;
}

void Casillero::posicionar_personaje(Personaje* nuevo) {
    personaje = nuevo;
}

Casillero::~Casillero() {

}

bool Casillero::hay_personaje(){
    if (personaje != nullptr){
        return true;
    }
    return false;
}

