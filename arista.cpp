#include "arista.h"

Arista::Arista(Vertice* origen, Vertice* destino, int costo) {
    this->origen = origen;
    this->destino = destino;
    this->costo = costo;
}

void Arista::insertar_costo(int costo) {
    this->costo = costo;
}

int Arista::obtener_costo() {
    return costo;
}

Vertice* Arista::obtener_destino() {
    return destino;
}

Vertice* Arista::obtener_origen() {
    return origen;
}