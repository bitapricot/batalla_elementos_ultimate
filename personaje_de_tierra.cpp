#include "personaje_de_tierra.h"

Personaje_de_tierra::Personaje_de_tierra(string nombre, int escudo, int vidas): Personaje(nombre, escudo, vidas) {
}

Personaje_de_tierra::Personaje_de_tierra(string nombre): Personaje(nombre) {
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
