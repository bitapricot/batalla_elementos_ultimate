#include "juego.h"

Juego::Juego(string archivo_mapa, Jugador* j1, Jugador* j2) {
    tablero = new Grafo(archivo_mapa);
    determinar_primer_turno();
    jugadores[JUGADOR_1] = j1;
    jugadores[JUGADOR_2] = j2; // a chequear jaja malisimo bro que hacia
    pos_personaje = 0;
}


Jugador* Juego::obtener_jugador(int jugador) {
    if(jugador == JUGADOR_1 || jugador == JUGADOR_2) return jugadores[jugador];
    return 0;
}

void Juego::determinar_primer_turno() {
    turno = rand() % 2;
}

/*void Juego::atacar(int pos_personaje) {
    chequear_subturno();
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    Personaje* personaje_act = jugador_act[pos_personaje];
    if(personaje_act->de_que_elemento_soy() == AGUA) {
        if(personaje_act->obtener_energia() >= MIN_ENERGIA_PJ_AGUA) {
            Coordenada nueva = pedir_coord_ataque();
            if(tablero->acceder_tablero(nueva->obtener_primera(), nueva->obtener_segunda())->obtener_casillero()->obtener_personaje()) {
                tablero->acceder_tablero(nueva->obtener_primera(), nueva->obtener_segunda())->obtener_casillero()->obtener_personaje()->recibe_ataque(personaje_act->de_que_elemento_soy());
            } else cout << ERROR_NO_HAY_PERSONAJE << endl;
        } else cout << ERROR_ENERGIA_INSUFICIENTE << endl;
    } else if(personaje_act->de_que_elemento_soy() == TIERRA) {
        Coordenada coord_act = personaje_act->obtener_coordenadas();
        ataque_pj_tierra(coord_act); // ubicar las coordenadas de los pj enemigos y calcular el daño en base a la distancia

    }
}*/

/*void Juego::chequear_subturno() {
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    if(pos_personaje >= jugador_act->cantidad_personajes()) pos_personaje = 0;
}*/

Juego::~Juego() {
    if (tablero) delete tablero;
}
