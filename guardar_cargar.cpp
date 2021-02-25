//
// Created by santiago on 20/2/21.
//

#include "iostream"
#include "fstream"
#include "personaje.h"
#include "grafo.h"
#include "lista.h"

using namespace std;

const char SEPARADOR_CSV = ',';
const char SALTO_DE_LINEA = '\n';

const string TIPO_AGUA = "agua";
const string TIPO_AIRE = "aire";
const string TIPO_FUEGO = "fuego";
const string TIPO_TIERRA = "tierra";

void guardar_juego(int jugador_que_guardo, Grafo * grafo){
    ofstream juego_guardado;
    juego_guardado.open("juego_guardado.csv");
    juego_guardado << jugador_que_guardo << endl;
    Lista * lista_vertices = grafo->obtener_vertices();
    Vertice * vertice_actual;
    Coordenada coordenada_actual;
    Casillero * casillero_actual;
    Personaje * personaje_actual;
    string elemento, nombre_personaje;
    int escudo, vida, energia, fila, columna;
    while(lista_vertices->obtener_actual() != nullptr){
        vertice_actual = lista_vertices->obtener_actual();
        casillero_actual = vertice_actual->obtener_casillero();
        coordenada_actual = vertice_actual->obtener_coordenadas();
        personaje_actual = casillero_actual->obtener_personaje();
        if (personaje_actual != nullptr){
            fila = coordenada_actual.obtener_primera();
            columna = coordenada_actual.obtener_segunda();
            elemento = personaje_actual->de_que_elemento_soy();
            nombre_personaje = personaje_actual->nombre_personaje();
            escudo = personaje_actual->obtener_escudo();
            vida = personaje_actual->obtener_vida();
            energia = personaje_actual->obtener_energia();
            juego_guardado << elemento << ',' << nombre_personaje << ',' << escudo << ',' << vida << ',' << energia
                           << ',' << fila << ',' << columna << endl;
        }
        lista_vertices->siguiente();
    }
    juego_guardado.close();
}