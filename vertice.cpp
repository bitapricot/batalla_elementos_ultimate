#include "vertice.h"

Vertice::Vertice(Casillero* casillero, int primera, int segunda) {
    cant_aristas = 0;
    cant_aristas_contando_diagonales = 0;
    this->casillero = casillero;
    this->coordenadas = Coordenada(primera, segunda);
}

Vertice::Vertice() {
    cant_aristas = 0;
    cant_aristas_contando_diagonales = 0;
    this->casillero = 0;
    this->coordenadas = Coordenada(0, 0);
}

void Vertice::agregar_arista(Arista nueva, bool contando_diagonales) {
    if(!contando_diagonales) {
        vertices_ady[cant_aristas] = &nueva;
        cant_aristas++;
    }
    else {
        vertices_ady_y_diagonales[cant_aristas_contando_diagonales] = &nueva;
        cant_aristas_contando_diagonales++;
    }
}

Coordenada Vertice::obtener_coordenadas() {
    return coordenadas;
}

Arista* Vertice::obtener_lista(bool contando_diagonales) {
    if(!contando_diagonales) return *vertices_ady;
    return *vertices_ady_y_diagonales;
}

Casillero* Vertice::obtener_casillero() {
    return casillero;
}

Vertice::~Vertice() {
    delete casillero;
    /*for(int i = 0; i < cant_aristas; i++) delete vertices_ady[i];
    delete vertices_ady;
    for(int i = 0; i < cant_aristas_contando_diagonales; i++) delete vertices_ady[i];
    delete vertices_ady_y_diagonales;*/
}
