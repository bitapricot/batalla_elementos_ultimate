#include "vertice.h"

Vertice::Vertice(Casillero* casillero, int primera, int segunda) {
    this->coordenadas = Coordenada(primera, segunda);
    this->lista_adyacencia = 0;
    this->casillero = casillero;
}

Coordenada Vertice::obtener_coordenadas() {
    return coordenadas;
}

Arista* Vertice::obtener_lista() {
    return lista;
}

Casillero* Vertice::obtener_casillero() {
    return casillero;
}