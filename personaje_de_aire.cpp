#include "personaje_de_aire.h"

Personaje_de_aire::Personaje_de_aire(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
}

Personaje_de_aire::Personaje_de_aire(string nombre): Personaje(nombre) {
}


Personaje_de_aire::Personaje_de_aire(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador) {
}

void Personaje_de_aire::alimentar() {
    cout << ALIMENTO_P_AIRE << endl;
}

string Personaje_de_aire::de_que_elemento_soy() {
    return ELEMENTO_AIRE;
}
