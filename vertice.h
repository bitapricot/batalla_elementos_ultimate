#include "casillero.h"
#include "coordenada.h"
#include "arista.h"

class Vertice {
    private:
    Coordenada coordenadas; // el ID
    Arista* lista_adyacencia; // la lista de adyacencia, que por lo pronto va a ser un array
    Casillero* casillero; // el datazo

    public:
    Vertice(Casillero* casillero, int primera, int segunda);
    Coordenada obtener_coordenadas();
    Casillero* obtener_casillero();
};