#include "vertice.h"

class Arista {
private:
    Vertice* origen;
    Vertice* destino;
    int costo;
public:
    Arista(Vertice origen, Vertice destino, int costo);
    Vertice* obtener_destino();
    Vertice* obtener_origen();
    int obtener_costo();
    void insertar_costo(int costo);
};