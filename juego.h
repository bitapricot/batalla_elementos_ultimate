#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

class Juego {
private:
    // Atributos
    Casillero* tablero;
    Jugador jugador_1;
    Jugador jugador_2;
public:
    void cargar_tablero();
    void imprimir_tablero();
    bool comenzo();


};


#endif // JUEGO_H_INCLUDED
