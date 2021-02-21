#include "jugador.h"

Jugador::Jugador() {
    cantidad_personajes = 0;
}

Jugador::Jugador(int id) {
	this->id = id;
    cantidad_personajes = 0;
}

void Jugador::agregar_personaje(Personaje* nuevo) {
    personajes_elegidos[cantidad_personajes] = nuevo;
    cantidad_personajes++;
}

bool Jugador::eligio_max_personajes() {
    return cantidad_personajes == MAX_PERSONAJES;
}

bool Jugador::jugador_perdio() {
    for(int i = 0; i < cantidad_personajes; i++) if(!personajes_elegidos[i]->esta_vivo()) return false;
    return true;
}

int Jugador::obtener_cantidad_personajes() {
    int personajes_vivos = 0;
    for (int i = 0; i < cantidad_personajes; i++) {
        if (personajes_elegidos[i]->esta_vivo()) personajes_vivos++;
        
    return personajes_vivos;
    }
}
	
int Jugador::obtener_id() {
	return id;
}
	
Personaje* Jugador::obtener_personaje(int pos) {
	return personajes_elegidos[pos];
}

Jugador::~Jugador() {
}
