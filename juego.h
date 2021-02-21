#ifndef JUEGO_H_INCLUDED
#include "grafo.h"
#include "jugador.h"

const int JUGADOR_1 = 0;
const int JUGADOR_2 = 1;
const int MAX_CANT_JUGADORES = 2;


class Juego {
private:
    Grafo* tablero;
    Jugador* jugadores[MAX_CANT_JUGADORES];
    int turno;
    int pos_personaje;
public:
    Juego(string archivo_mapa, Jugador* j1, Jugador* j2);
    ~Juego();
    void atacar();
    void cargar_partida();
    bool comenzo();
    void defender();
    void determinar_primer_turno();
    void guardar_partida();
    void imprimir_tablero();
    void moverse();
    Jugador* obtener_jugador(int jugador);
    void turnar();
};
#endif // JUEGO_H_INCLUDED
