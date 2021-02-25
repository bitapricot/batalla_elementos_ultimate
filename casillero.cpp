#include "casillero.h"

Casillero::Casillero() {
    personaje = 0;
}

Personaje* Casillero::obtener_personaje() {
    return personaje;
}

void Casillero::posicionar_personaje(Personaje* nuevo, Coordenada coordenada_actual) {
    personaje = nuevo;
    nuevo->asignar_coordenadas(coordenada_actual);
}

Casillero::~Casillero() {

}

bool Casillero::hay_personaje(){
    if (personaje != nullptr){
        return true;
    }
    return false;
}

