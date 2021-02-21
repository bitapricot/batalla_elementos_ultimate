#include "personaje_de_fuego.h"

Personaje_de_fuego::Personaje_de_fuego(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
}

Personaje_de_fuego::Personaje_de_fuego(string nombre): Personaje(nombre) {
}


Personaje_de_fuego::Personaje_de_fuego(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador, se_defiende) {
}

Personaje_de_fuego::Personaje_de_fuego(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador) {
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

void Personaje_de_fuego::defender() {
    if (energia >= MIN_ENERGIA_DEFENSA_FUEGO) {
        energia -= MIN_ENERGIA_DEFENSA_FUEGO;
        vidas += CURACION_PERSONAJE_FUEGO;
        se_defiende = true;
    } else {
        cout << ENERGIA_INSUFICIENTE << ". A " << nombre << " le quedan " << energia << " puntos de energia." << endl;
        se_defiende = false;
    }
}

void Personaje_de_fuego::recibe_ataque(string elemento_enemigo, int danio_recibido) {
    if (elemento_enemigo == ELEMENTO_AIRE) danio_recibido = ATAQUE_DEBIL_AIRE;
    else if (elemento_enemigo == ELEMENTO_AGUA) danio_recibido = ATAQUE_FUERTE_AGUA;
    
    aplicar_escudo(danio_recibido);
    vidas -= danio_recibido;        
}

void Personaje_de_fuego::restar_vida() {
    if (energia == 0) vidas -= 5;
