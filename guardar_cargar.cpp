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

Personaje * cargar_personaje_desde_archivo(string elemento, string nombre, int escudo, int vida, int energia, int fila, int columna, int jugador){
    Personaje * personaje;
    if (elemento == TIPO_AGUA){
        personaje = new Personaje_de_agua(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    else if (elemento == TIPO_FUEGO){
        personaje = new Personaje_de_fuego(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    else if (elemento == TIPO_TIERRA){
        personaje = new Personaje_de_tierra(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    else if (elemento == TIPO_AIRE){
        personaje = new Personaje_de_aire(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    return personaje;
}

int Juego::cargar_juego(Grafo * grafo){
    ifstream juego_guardado;
    juego_guardado.open("juego_guardado.csv");
    string elemento, nombre_personaje, escudo, vida, energia, fila, columna, turno_jugador;
    Lista * lista_vertices = grafo->obtener_vertices();
    Vertice * vertice_actual;
    Coordenada coordenada_actual;
    Casillero * casillero_actual;
    getline(juego_guardado, turno_jugador, '\n');
    int jugador;
    int i = 0;
    while(!juego_guardado.eof()){
        getline(juego_guardado, elemento, SEPARADOR_CSV);
        getline(juego_guardado, nombre_personaje, SEPARADOR_CSV);
        getline(juego_guardado, escudo, SEPARADOR_CSV);
        getline(juego_guardado, vida, SEPARADOR_CSV);
        getline(juego_guardado, energia, SEPARADOR_CSV);
        getline(juego_guardado, fila, SEPARADOR_CSV);
        getline(juego_guardado, columna, SALTO_DE_LINEA);
        if (i < 3){
            jugador = 1;
        }
        else {
            jugador = 2;
        }
        Personaje * personaje_cargado = cargar_personaje_desde_archivo(elemento, nombre_personaje, stoi(escudo), stoi(vida), stoi(energia), stoi(fila), stoi(columna), jugador);
        while(lista_vertices->obtener_actual() != nullptr){
            vertice_actual = lista_vertices->obtener_actual();
            coordenada_actual = vertice_actual->obtener_coordenadas();
            casillero_actual = vertice_actual->obtener_casillero();
            if (coordenada_actual.obtener_primera() == stoi(fila) && coordenada_actual.obtener_segunda() == stoi(columna)){
                casillero_actual->posicionar_personaje(personaje_cargado);
            }
            lista_vertices->siguiente();
        }
        lista_vertices->reiniciar();
        i++;
    }
    juego_guardado.close();
    return stoi(turno_jugador);
}
