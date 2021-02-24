#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "coordenada.h"
#include "jugador.h"
using namespace std;

const string ELEMENTO_AIRE = "aire";
const string ELEMENTO_FUEGO = "fuego";
const string ELEMENTO_AGUA = "agua";
const string ELEMENTO_TIERRA = "tierra";

const string ALIMENTO_P_AGUA = "plancton";
const string ALIMENTO_P_TIERRA = "hierbas";
const string ALIMENTO_P_FUEGO = "madera";
const string ALIMENTO_P_AIRE = "Este personaje no necesita alimentarse ";

const int ATAQUE_BASE_AGUA = 20;
const int ATAQUE_BASE_AIRE = 15;
const int ATAQUE_BASE_FUEGO = 20;
const int ATAQUE_BASE_TIERRA_DEBIL = 10;
const int ATAQUE_BASE_TIERRA_MEDIO = 20;
const int ATAQUE_BASE_TIERRA_FUERTE = 30;

const int ATAQUE_FUERTE_AGUA = 30;
const int ATAQUE_DEBIL_AGUA = 10;
const int ATAQUE_FUERTE_AIRE = 20;
const int ATAQUE_DEBIL_AIRE = 10;
const int ATAQUE_FUERTE_FUEGO = 30;
const int ATAQUE_DEBIL_FUEGO = 10;
const int ATAQUE_FUERTE_TIERRA = 20; // +20
const int ATAQUE_DEBIL_TIERRA = 10;

const int MIN_ENERGIA_ATAQUE_AGUA = 5;
const int MIN_ENERGIA_ATAQUE_AIRE = 8;
const int MIN_ENERGIA_ATAQUE_FUEGO = 5;
const int MIN_ENERGIA_ATAQUE_TIERRA = 6;

const int MIN_ENERGIA_DEFENSA_AGUA = 12;
const int MIN_ENERGIA_DEFENSA_AIRE = 15;
const int MIN_ENERGIA_DEFENSA_FUEGO = 10;
const int MIN_ENERGIA_DEFENSA_TIERRA = 5;

const int VALOR_MIN_VIDA = 10;
const int VALOR_MAX_VIDA = 100;
const int VALOR_MIN_ESCUDO = 0;
const int VALOR_MAX_ESCUDO = 2;
const int VALOR_MIN_ENERGIA = 0;
const int VALOR_MAX_ENERGIA = 20;

const int ENERGIA_RECUPERADA_P_AGUA = 10;
const int ENERGIA_RECUPERADA_P_TIERRA = 8;
const int VIDA_RECUPERADA_P_FUEGO = 15;

const int CURACION_ALIADOS_PERSONAJE_AGUA = 10;
const int CURACION_PERSONAJE_AGUA = 50;
const int CURACION_PERSONAJE_FUEGO = 10;
const int MAX_VECES_ALIMENTADO_P_AGUA = 3;
const int PUNTOS_EXTRA_ESCUDO_TIERRA = 2;

const string ENERGIA_INSUFICIENTE = "Energia insuficiente.";
const string ERROR_NO_HAY_PERSONAJE = "No hay personaje para el ataque";

const int NO_ELEGIDO = -1;

class Personaje {
protected:
    // Atributos
    string nombre;
    int escudo;
    int vidas;
    int energia;
    Coordenada coord_personaje;
    int id_jugador;
    bool se_defiende;

    // Constructores
    /*
    PRE: -
    POS: crea un personaje de tierra con nombre = nombre, escudo = escudo, vidas = vidas y energia con valores aleatorios entre 0 y 20
    */
    Personaje(string nombre, int escudo, int vidas);

    /*
    PRE: -
    POS: crea un personaje de tierra con nombre = nombre escudo con valores aleatorios entre 0 y 2, vida con valores aleatorios entre 10 y 100 y energia entre 0 y 20
    */
    Personaje(string nombre);

    /*
    PRE: - 
    POS: crea un personaje con los valores ingresados. Vamos a utilizar este método al cargar la partida.
    */
    Personaje(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador);

    Personaje(string nombre, int escudo, int vidas, int energia, int fila, int columna, int id_jugador, bool se_defiende);

public:

    /*
    Destructor
    */
    virtual ~Personaje();

    /*
    Crea una nueva coordenada para el personaje con los valores de fila y columna recibidos por parametro
    */
    void asignar_coordenadas_pj(int fila, int columna);

    /*
    Devuelve el nombre del personaje
    */
    string nombre_personaje();

    /*
    Imprime por pantalla los detalles del personaje (nombre, elemento, escudo, vidas y energia)
    */
    void mostrar_detalles();

    /*
    Alimenta al personaje, incrementando la energia segun el elemento del cual sea el personaje
    Para el personaje de aire, dado que no necesita alimentarse, este metodo se encarga de recordarselo al usuario
    */
    virtual void alimentar() = 0;

    bool esta_vivo();

    void restar_energia(int costo_energia);

    /*
    Devuelve el elemento del personaje
    */
    virtual string de_que_elemento_soy() = 0;

    
    void elegir(int id_jugador);
    
    bool obtener_se_defiende(); 
    
    int aplicar_escudo(int danio_recibido);
    
    virtual void defender() = 0;
    
    virtual void recibe_ataque(string elemento_enemigo, int danio_recibido) = 0;
 
    void mover(int fila, int columna, int energia_minima);
    
    int obtener_id_jugador();

    int obtener_vida();

    int obtener_energia();

    int obtener_escudo();

    Coordenada obtener_coordenadas();

};

#endif // PERSONAJE_H_INCLUDED
