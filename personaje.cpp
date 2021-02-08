#include "personaje.h"

Personaje::Personaje(string nombre, int escudo, int vidas) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vidas = vidas;
    srand(time(NULL));
    this->energia = rand() % (VALOR_MAX_ENERGIA - VALOR_MIN_ENERGIA + 1) + VALOR_MIN_ENERGIA;
}

Personaje::Personaje(string nombre) {
    this->nombre = nombre;
    srand(time(NULL));
    this->escudo = rand() % (VALOR_MAX_ESCUDO - VALOR_MIN_ESCUDO + 1) + VALOR_MIN_ESCUDO;
    this->vidas = rand() % (VALOR_MAX_VIDA - VALOR_MIN_VIDA + 1) + VALOR_MIN_VIDA;
    this->energia = rand() % (VALOR_MAX_ENERGIA - VALOR_MIN_ENERGIA + 1) + VALOR_MIN_ENERGIA;
}

Personaje::~Personaje() {
}

string Personaje::nombre_personaje() {
    return nombre;
}

void Personaje::mostrar_detalles() {
    cout << "Nombre: " << nombre << endl;
    cout << "Elemento: " << de_que_elemento_soy() << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Vidas: " << vidas << endl;
    cout << "Energia: " << energia << endl;
}

bool Personaje::esta_vivo() {
    return vidas > 0;
}

void Personaje::restar_energia(int costo_energia) {
    energia -= costo_energia;
}
