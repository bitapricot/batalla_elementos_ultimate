#ifndef PERSONAJE_DE_FUEGO_H_INCLUDED
#define PERSONAJE_DE_FUEGO_H_INCLUDED

#include "personaje.h"

class Personaje_de_fuego: public Personaje
{
private:
    /*
    Devuelve el elemento del personaje
    */
    string de_que_elemento_soy();
    
    void restar_vida();

public:
    /*
    Constructor
    PRE: 0 <= escudo <= 2, 10 <= vidas <= 100
    POS: crea un personaje de fuego con nombre = nombre, escudo = escudo, vidas = vidas y con un valor de energia inicial aleatorio entre 0 y 20
    */
    Personaje_de_fuego(string nombre, int escudo, int vidas);

    /*
    Constructor
    PRE: -
    POS: crea un personaje de fuego con nombre = nombre, y sus valores de escudo, vida y energia aleatorios entre las cotas definidas en personaje.h
    */
    Personaje_de_fuego(string nombre);
    
    
    Personaje_de_fuego(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende);

    Personaje_de_fuego(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador);

    /*
    Incrementa la vida segun la vida recuperada determinada en personaje.h
    */
    void alimentar();
    
    void defender();
    
    void recibe_ataque(string elemento_enemigo, int danio_recibido);

};


#endif // PERSONAJE_DE_FUEGO_H_INCLUDED
