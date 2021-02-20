#include "personaje_de_aire.h"

Personaje_de_aire::Personaje_de_aire(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
}

Personaje_de_aire::Personaje_de_aire(string nombre): Personaje(nombre) {
}


Personaje_de_aire::Personaje_de_aire(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador, se_defiende) {
}

void Personaje_de_aire::alimentar() {
    cout << ALIMENTO_P_AIRE << endl;
}

string Personaje_de_aire::de_que_elemento_soy() {
    return ELEMENTO_AIRE;
}

void Personaje_de_aire::defender() {
    if (energia >= 15) {
        energia -= 15;
        se_defiende = true;
    } else {
        cout << ENERGIA_INSUFICIENTE << ". A " << nombre << " le quedan " << energia << " puntos de energia." << endl;
        se_defiende = false;
    }
}

void Personaje_de_aire::recibe_ataque(string elemento_enemigo, int danio_recibido) {
    if (elemento_enemigo == TIERRA) danio_recibido = ATAQUE_DEBIL_TIERRA;
    else if (elemento_enemigo == FUEGO) danio_recibido = ATAQUE_FUERTE_FUEGO;
    else danio_recibido = ATAQUE_BASE_AGUA;
    
    aplicar_escudo(danio_recibido);
    vida -= danio_recibido;
}

void Personaje_de_aire::cambiar_turno() {
    energia += 5;
}
