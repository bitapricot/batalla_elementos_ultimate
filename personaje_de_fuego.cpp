#include "personaje_de_fuego.h"

Personaje_de_fuego::Personaje_de_fuego(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
}

Personaje_de_fuego::Personaje_de_fuego(string nombre): Personaje(nombre) {
}

void Personaje_de_fuego::alimentar() {
    int vida_anterior = vidas;
    if(vidas >= VALOR_MIN_VIDA && vidas <= VALOR_MAX_VIDA) vidas += VIDA_RECUPERADA_P_FUEGO;
    if(vidas > VALOR_MAX_VIDA) vidas = VALOR_MAX_VIDA;
    cout << "El personaje " << nombre << " fue alimentado con " << ALIMENTO_P_FUEGO << " y recupero " << vidas - vida_anterior << " punto(s) de vida" << endl;
}

string Personaje_de_fuego::de_que_elemento_soy() {
    return ELEMENTO_FUEGO;
}
