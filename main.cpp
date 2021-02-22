#include <iostream>
#include "casillero.h"
#include "camino.h"
#include "lago.h"
#include "montania.h"
#include "precipicio.h"
#include "vacio.h"
#include "volcan.h"

#include "personaje.h"
#include "personaje_de_fuego.h"

int main() {

    Casillero* ccamino = new Camino();
    Casillero* clago = new Lago();
    Casillero* cmontania = new Montania();
    Casillero* cprecipicio = new Precipicio();
    Casillero* cvacio = new Vacio();
    Casillero* cvolcan = new Volcan();

    Personaje* pfuego = new Personaje_de_fuego("RAUL");

    cout << "COSTO BASE CAMINO: " << ccamino->obtener_costo_base() << endl;
    cout << "COSTO BASE LAGO: " << clago->obtener_costo_base() << endl;
    cout << "COSTO BASE MONTANIA: " << cmontania->obtener_costo_base() << endl;
    cout << "COSTO BASE PRECIPICIO: " << cprecipicio->obtener_costo_base() << endl;
    cout << "COSTO BASE VACIO: " << cvacio->obtener_costo_base() << endl;
    cout << "COSTO BASE VOLCAN: " << cvolcan->obtener_costo_base() << endl;

    clago->posicionar_personaje(pfuego);
    Personaje* personaje_actual = clago->obtener_personaje();
    cout << "PERSONAJE POSICIONADO EN CASILLERO LAGO: " << personaje_actual->nombre_personaje() <<
    " COSTO: " << clago->calcular_costo(pfuego) << endl;

    delete ccamino;
    delete clago;
    delete cmontania;
    delete cprecipicio;
    delete cvacio;
    delete cvolcan;
    delete pfuego;


    return 0;
}