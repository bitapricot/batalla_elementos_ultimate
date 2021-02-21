#include <iostream>
#include "juego.h"
#include "jugador.h"

using namespace std;

int main() {

    string archivo_mapa = "../mapa.csv";
    Jugador* jugador_one = new Jugador(0);
    Jugador* jugador_two = new Jugador(1);

    Juego* test = new Juego(archivo_mapa, jugador_one, jugador_two);

    cout << "jugador 1: " << test->obtener_jugador(0)->obtener_id() << endl;
    cout << "jugador 2: " << test->obtener_jugador(1)->obtener_id() << endl;

    return 0;
}