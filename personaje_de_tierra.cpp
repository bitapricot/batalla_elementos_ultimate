#include "personaje_de_tierra.h"

Personaje_de_tierra::Personaje_de_tierra(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
}

Personaje_de_tierra::Personaje_de_tierra(string nombre): Personaje(nombre) {
}


Personaje_de_tierra::Personaje_de_tierra(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende): Personaje(nombre, escudo, vidas, energia, fila, columna, id_jugador, se_defiende) {
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
    if (incrementar) this->escudo += PUNTOS_EXTRA_ESCUDO;
    else this->escudo -= PUNTOS_EXTRA_ESCUDO;
}


void Personaje_de_tierra::defender() {
    if (energia >= MIN_ENERGIA_DEFENSA) {
        incrementar_escudo(true);
        se_defiende = true;        
    }
    else {
        cout << ENERGIA_INSUFICIENTE << ". A " << nombre << " le quedan " << energia << " puntos de energia." << endl;
        se_defiende = false;
    }
}

void Personaje_de_tierra::recibe_ataque(string elemento_enemigo) {
    int danio_recibido;
    if (elemento_enemigo == AIRE) danio_recibido = ATAQUE_FUERTE;
    else if (elemento_enemigo == AGUA) danio_recibido = ATAQUE_DEBIL;
    else danio_recibido = ATAQUE_BASE_FUEGO;
    
    vida -= danio_recibido;
}
    


    
    
    
