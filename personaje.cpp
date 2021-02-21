#include "personaje.h"

Personaje::Personaje(string nombre, int escudo, int vidas) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vidas = vidas;
    srand(time(NULL));
    this->energia = rand() % (VALOR_MAX_ENERGIA - VALOR_MIN_ENERGIA + 1) + VALOR_MIN_ENERGIA;
    this->id_jugador = NO_ELEGIDO;
}

Personaje::Personaje(string nombre) {
    this->nombre = nombre;
    srand(time(NULL));
    this->escudo = rand() % (VALOR_MAX_ESCUDO - VALOR_MIN_ESCUDO + 1) + VALOR_MIN_ESCUDO;
    this->vidas = rand() % (VALOR_MAX_VIDA - VALOR_MIN_VIDA + 1) + VALOR_MIN_VIDA;
    this->energia = rand() % (VALOR_MAX_ENERGIA - VALOR_MIN_ENERGIA + 1) + VALOR_MIN_ENERGIA;
    this->id_jugador = NO_ELEGIDO;
}

Personaje::Personaje(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vidas = vidas;
    this->energia = energia;
    this->coord_personaje = Coordenada(fila, columna);
    this->id_jugador = id_jugador;
    this->se_defiende = se_defiende;
}

Personaje::~Personaje() {
}

void Personaje::asignar_coordenadas_pj(int fila, int columna) {
    coord_personaje = Coordenada(fila,columna);
}

void Personaje::elegir(int id_jugador) {
    this->id_jugador = id_jugador;
}

string Personaje::nombre_personaje() {
    return nombre;
}

bool Personaje::se_defiende() { // chequear si esto funca
    return se_defiende;

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
    
int aplicar_escudo(int danio_recibido) {
    if (VALOR_MIN_ESCUDO < escudo < VALOR_MAX_ESCUDO) danio_recibido -= danio_recibido*0.1;
    else if (escudo == VALOR_MAX_ESCUDO) danio_recibido -= danio_recibido*0.2;
    else if (escudo > VALOR_MAX_ESCUDO) danio_recibido -= danio_recibido*0.8;
    return danio_recibido;
}

void Personaje::mover(int fila, int columna, int energia_minima) {
    if(energia >= energia_min) {
        coord_personaje->cambiar_primera(fila);
        coord_personaje->cambiar_segunda(columna);
        energia -= energia_min;
    } else cout << ENERGIA_INSUFICIENTE << endl;
}

int Personaje::obtener_energia(){
    return energia;
}

int Personaje::obtener_vida(){
    return vidas;
}

int Personaje::obtener_escudo(){
    return escudo;
}