#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "grafo.h"
#include "jugador.h"

const int PRIMER_TURNO_J1 = 1;
const int PRIMER_TURNO_J2 = 2;

class Juego {
private:
    Grafo* grafito;
    Jugador jugador_1;
    Jugador jugador_2;
    int primer_turno;
public:
    Grafo();
    ~Grafo();
    void atacar();
    void cargar_partida();
    void cargar_tablero();
    bool comenzo();
    void defender();
    void guardar_partida();
    void imprimir_tablero();
    void moverse();
    void determinar_primer_turno();
    void turnar();
};
#endif // JUEGO_H_INCLUDED
