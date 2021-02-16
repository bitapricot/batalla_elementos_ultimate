#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include "arista.h"
#include "casillero.h"
#include "coordenada.h"
#include "vector.h"

class Arista;
class Vector;

class Vertice {
    private:
    Vector* aristas; // la lista de adyacencia, que por lo pronto va a ser un array
    int cant_aristas;
    Casillero* casillero; // el datazo
    Coordenada coordenadas; // el ID

    public:
    Vertice(Casillero* casillero, int primera, int segunda);
    void agregar_arista(Arista* nueva);
    Coordenada obtener_coordenadas();
    Casillero* obtener_casillero();
    Vector* obtener_lista();
    ~Vertice();
};
#endif // VERTICE_H_INCLUDED
