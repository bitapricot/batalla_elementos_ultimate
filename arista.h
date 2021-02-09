#ifndef ARISTA_H_INCLUDED
#define ARISTA_H_INCLUDED
#include "vertice.h"

class Arista {
private:
    Vertice* origen;
    Vertice* destino;
    int costo;
public:
    Arista(Vertice* origen, Vertice* destino, int costo);
    Arista(Vertice* origen, Vertice* destino);
    Vertice* obtener_destino();
    Vertice* obtener_origen();
    int obtener_costo();
    void insertar_costo(int costo);
}; #endif // ARISTA_H_INCLUDED
