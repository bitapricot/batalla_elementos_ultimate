#include "personaje_de_tierra.h"

Personaje_de_tierra::Personaje_de_tierra(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
    srand(time(nullptr));
    cargar_graficos();
}

Personaje_de_tierra::Personaje_de_tierra(string nombre): Personaje(nombre) {
    srand(time(nullptr));
    cargar_graficos();
}

Personaje_de_tierra::Personaje_de_tierra(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador, se_defiende) {
}

Personaje_de_tierra::Personaje_de_tierra(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador) {
}

void Personaje_de_tierra::alimentar() {
    int energia_anterior = energia;
    if(energia >= VALOR_MIN_ENERGIA && energia <= VALOR_MAX_ENERGIA) energia += ENERGIA_RECUPERADA_P_TIERRA;
    if(energia > VALOR_MAX_ENERGIA) energia = VALOR_MAX_ENERGIA;
    cout << "El personaje " << nombre << " fue alimentado con " << ALIMENTO_P_TIERRA << " y recupero " << energia - energia_anterior << " punto(s) de energia" << endl;
}

string Personaje_de_tierra::de_que_elemento_soy(){
    return ELEMENTO_TIERRA;
}

void Personaje_de_tierra::incrementar_escudo(bool incrementar) {
    if (incrementar) this->escudo += PUNTOS_EXTRA_ESCUDO_TIERRA;
    else this->escudo -= PUNTOS_EXTRA_ESCUDO_TIERRA;
}

void Personaje_de_tierra::defender() {
    if (energia >= MIN_ENERGIA_DEFENSA_TIERRA) {
        energia -= MIN_ENERGIA_DEFENSA_TIERRA;
        incrementar_escudo(true);
        se_defiende = true;
    } else {
        cout << ENERGIA_INSUFICIENTE << ". A " << nombre << " le quedan " << energia << " puntos de energia." << endl;
        se_defiende = false;
    }
}

void Personaje_de_tierra::recibe_ataque(string elemento_enemigo, int danio_recibido) {
    if (elemento_enemigo == ELEMENTO_AIRE) danio_recibido = ATAQUE_FUERTE_AIRE;
    else if (elemento_enemigo == ELEMENTO_AGUA) danio_recibido = ATAQUE_DEBIL_AGUA;
    else danio_recibido = ATAQUE_BASE_FUEGO;

    aplicar_escudo(danio_recibido);
    vidas -= danio_recibido;
}

int Personaje_de_tierra::calcular_danio_segun_distancia(int distancia) {
    int danio;
    if (0 < distancia <= 2) danio = 30;
    else if (2 < distancia <= 4) danio = 20;
    else danio = 10;

    return danio;
}