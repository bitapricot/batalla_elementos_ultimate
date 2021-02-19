#ifndef PERSONAJE_DE_TIERRA_H_INCLUDED
#define PERSONAJE_DE_TIERRA_H_INCLUDED

#include "personaje.h"

const int ATAQUE_BASE_DEBIL = 10;
const int ATAQUE_BASE_MEDIO = 20;
const int ATAQUE_BASE_FUERTE = 30;
const int MIN_ENERGIA_DEFENSA = 5;
const int PUNTOS_EXTRA_ESCUDO = 2;

class Personaje_de_tierra: public Personaje
{
private:
    /*
    Devuelve el elemento del personaje
    */
    string de_que_elemento_soy();

public:
    /*
    Constructor
    PRE: 0 <= escudo <= 2, 10 <= vidas <= 100
    POS: crea un personaje de tierra con nombre = nombre, escudo = escudo, vidas = vidas y con un valor de energia inicial aleatorio entre 0 y 20
    */
    Personaje_de_tierra(string nombre, int escudo, int vidas);

    /*
    Constructor
    PRE: -
    POS: crea un personaje de tierra con nombre = nombre, escudo con valores aleatorios entre 0 y 2, vida con valores aleatorios entre 10 y 100 y energia entre 0 y 20
    */
    Personaje_de_tierra(string nombre);
    
    
    Personaje_de_tierra(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende);

    /*
    Incrementa la energia segun la energia recuperada determinada en personaje.h
    */
    void alimentar();
    
    void defender();
    
    void incrementar_escudo(bool incrementar);
    
    void recibe_ataque(string elemento_enemigo);

};

#endif // PERSONAJE_DE_TIERRA_H_INCLUDED
