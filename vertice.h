#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include "casillero.h"
#include "camino.h"
#include "lago.h"
#include "montania.h"
#include "precipicio.h"
#include "vacio.h"
#include "volcan.h"
#include "coordenada.h"
#include "vector.h"

const int MAX_CANT_ARISTAS_SIN_DIAGONALES = 4;
const int MAX_CANT_ARISTAS_CON_DIAGONALES = 8;

class Arista;

class Vertice {
    private:
    Arista* vertices_ady[MAX_CANT_ARISTAS_SIN_DIAGONALES]; // la lista de adyacencia, que por lo pronto va a ser un array
    Arista* vertices_ady_y_diagonales[MAX_CANT_ARISTAS_CON_DIAGONALES];
    int cant_aristas;
    int cant_aristas_contando_diagonales;
    Casillero* casillero; // el datazo
    Coordenada coordenadas; // el ID

    public:
    Vertice(Casillero* casillero, int primera, int segunda);
    Vertice();
    void agregar_arista(Arista nueva, bool contando_diagonales);
    Coordenada obtener_coordenadas();
    int obtener_cantidad_aristas(bool contando_diagonales);
    Arista obtener_arista(int pos, bool contando_diagonales);
    Casillero* obtener_casillero();
    Arista* obtener_lista(bool contando_diagonales);
    ~Vertice();
};
#endif // VERTICE_H_INCLUDED
