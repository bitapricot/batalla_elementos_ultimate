#ifndef PERSONAJE_DE_AIRE_H_INCLUDED
#define PERSONAJE_DE_AIRE_H_INCLUDED

#include "personaje.h"

class Personaje_de_aire: public Personaje
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
    POS: crea un personaje de aire con nombre = nombre, escudo = escudo, vidas = vidas y con un valor de energia inicial aleatorio entre 0 y 20
    */
    Personaje_de_aire(string nombre, int escudo, int vidas);

    /*
    Constructor
    PRE: -
    POS: crea un personaje de aire con nombre = nombre, escudo con valores aleatorios entre 0 y 2, vida con valores aleatorios entre 10 y 100 y energia entre 0 y 20
    */
    Personaje_de_aire(string nombre);

    /*
    Como este personaje no necesita alimentarse, este metodo se encarga de recordarselo al usuario
    */
    void alimentar();

};


#endif // PERSONAJE_DE_AIRE_H_INCLUDED
