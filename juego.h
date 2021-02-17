#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

class Juego {
private:
    Grafo* grafito;
    Jugador jugador_1;
    Jugador jugador_2;
public:
    void atacar();
    void cargar_partida();
    void cargar_tablero();
    bool comenzo();
    void defender();
    void guardar_partida();
    void imprimir_tablero();
    void moverse();
};
#endif // JUEGO_H_INCLUDED
