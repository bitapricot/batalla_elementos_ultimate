#include "vertice.h"

Vertice::Vertice(Casillero* casillero, int primera, int segunda) {
    aristas = new Vector(MIN_CANT_ARISTAS);
    cant_aristas = 0;
    this->casillero = casillero;
    this->coordenadas = Coordenada(primera, segunda);
}

void Vertice::agregar_arista(Arista* nueva) {
    if(cant_aristas == aristas->obtener_longitud()) {
        cant_aristas++;
        aristas->redimensionar(cant_aristas);
        aristas->asignar(nueva, cant_aristas);
    }
    else {
        aristas->asignar(nueva, cant_aristas);
        cant_aristas++;
    }
}

Coordenada Vertice::obtener_coordenadas() {
    return coordenadas;
}

Vector* Vertice::obtener_lista() {
    return aristas;
}

Casillero* Vertice::obtener_casillero() {
    return casillero;
}

Vertice::~Vertice() {
    delete casillero;
    while(aristas->obtener_longitud() > 0) {

    }
}
