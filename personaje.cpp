#include "personaje.h"

Personaje::Personaje(string nombre, int escudo, int vidas) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vidas = vidas;
    srand(time(nullptr));
    this->energia = rand() % (VALOR_MAX_ENERGIA - VALOR_MIN_ENERGIA + 1) + VALOR_MIN_ENERGIA;
}

Personaje::Personaje(string nombre) {
    this->nombre = nombre;
    srand(time(nullptr));
    this->escudo = rand() % (VALOR_MAX_ESCUDO - VALOR_MIN_ESCUDO + 1) + VALOR_MIN_ESCUDO;
    this->vidas = rand() % (VALOR_MAX_VIDA - VALOR_MIN_VIDA + 1) + VALOR_MIN_VIDA;
    this->energia = rand() % (VALOR_MAX_ENERGIA - VALOR_MIN_ENERGIA + 1) + VALOR_MIN_ENERGIA;
}

Personaje::~Personaje() {
}

string Personaje::nombre_personaje() {
    return nombre;
}

string Personaje::mostrar_detalles() {
   string detalles = "Nombre: " + nombre + '\n' +
           "Elemento: " + de_que_elemento_soy() + '\n' +
           "Escudo: " + to_string(escudo) + '\n' +
           "Vidas: " + to_string(vidas) + '\n' +
           "Energia: " + to_string(energia) + '\n';

    return detalles;
}

bool Personaje::esta_vivo() {
    return vidas > 0;
}

void Personaje::restar_energia(int costo_energia) {
    energia -= costo_energia;
}
