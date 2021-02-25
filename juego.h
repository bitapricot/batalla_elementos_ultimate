#ifndef JUEGO_H_INCLUDED
#include "grafo.h"
#include "jugador.h"

const int JUGADOR_1 = 0;
const int JUGADOR_2 = 1;
const int MAX_CANT_JUGADORES = 2;
const int DIM_FILA = 8;

class Juego {
private:
    Grafo* tablero;
    Jugador* jugadores[MAX_CANT_JUGADORES];
    int turno;
    int pos_personaje;
public:
    Juego(string archivo_mapa, Jugador* j1, Jugador* j2);
    ~Juego();
    Jugador* obtener_jugador(int jugador);
    void atacar();
    void ataque_p_agua(Coordenada enemigo);
    void ataque_p_aire();
    void ataque_p_fuego(Coordenada coord_act);
    void ataque_p_tierra(Coordenada coord_act, Coordenada enemigo);
    void defensa_p_agua(Personaje* pj);
    void defensa_p_aire(Personaje* pj);
    void defensa_p_tierra(Personaje* pj);
    void moverse();
    void chequear_subturno();
    Personaje* cargar_personaje_desde_archivo(Grafo* g);
    void cargar_partida();
    void chequear_subturno();
    bool comenzo();
    void defenderse();
    void determinar_primer_turno();
    void guardar_partida();
    void imprimir_tablero();
    void moverse();
    Jugador* obtener_jugador(int jugador);
    int turnar();
    Coordenada pedir_coord();
    bool validar_ingreso(int valor);
    int energia_minima(string elemento, bool accion);
    int cargar_juego(Grafo * grafo);
    bool validar_ingreso(int valor);
    Coordenada pedir_coord();
};
#endif // JUEGO_H_INCLUDED

