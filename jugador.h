#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

//#include "diccionario.h"
#include "personaje.h"

const int MAX_PERSONAJES = 3;

class Jugador {
private:
    // Atributos
    Personaje* personajes_elegidos[MAX_PERSONAJES];
    int id;
    int cantidad_personajes;
public:
    Jugador();
    Jugador(int id);
    ~Jugador();
    void agregar_personaje(Personaje* nuevo);
    bool eligio_max_personajes();
    bool jugador_perdio();
    int obtener_cantidad_personajes();
    int obtener_id();
};


#endif // JUGADOR_H_INCLUDED
