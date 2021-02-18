#include "jugador.h"

Jugador::Jugador(bool tiene_primer_turno) {
    personajes_elegidos = new Personaje[MAX_PERSONAJES];
    cantidad_personajes = 0;
    this->tiene_primer_turno = tiene_primer_turno;
}

void Jugador::agregar_personaje(Personaje* nuevo) {
    personajes_elegidos[cantidad_personajes] = nuevo;
    cantidad_personajes++;
}

bool Jugador::eligio_max_personajes() {
    return cantidad_personajes == MAX_PERSONAJES;
}

bool Jugador::jugador_perdio() {
    for(int i = 0; i < cantidad_personajes; i++) if(!personajes_elegidos[i]->esta_muerto()) return false;
    return true;
}