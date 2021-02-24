#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;

#include "personaje.h"
#include "personaje_de_fuego.h"
#include "personaje_de_agua.h"
#include "personaje_de_aire.h"
#include "personaje_de_tierra.h"

const string CAMINO = "camino";
const string LAGO = "lago";
const string MONTANIA = "montaña";
const string PRECIPICIO = "precipicio";
const string VACIO = "vacio";
const string VOLCAN = "volcan";

const int COSTO_CAMINO = 1;
const int COSTO_LAGO = 1;
const int COSTO_MONTANIA = 1;
const int COSTO_PRECIPICIO = 1;
const int COSTO_VACIO = 15;
const int COSTO_VOLCAN = 1;


class Casillero {
protected:
    Personaje* personaje;
    Casillero();

    Texture txt_casillero;
    Sprite spr_casillero;

public:
    void posicionar_personaje(Personaje* nuevo, Coordenada coordenada);
    bool hay_personaje();
    Personaje* obtener_personaje();
    virtual int calcular_costo(string elemento_pj) = 0;
    virtual int obtener_costo_base() = 0;
    virtual string tipo_casillero() = 0;
    virtual ~Casillero();

    Sprite obtener_sprite();
    void cargar_graficos();
    void asignar_posicion(int x, int y);
};


#endif // CASILLERO_H_INCLUDED
