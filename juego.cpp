#include "juego.h"
#include "fstream"

const char SEPARADOR_CSV = ',';
const char SALTO_DE_LINEA = '\n';

const string TIPO_AGUA = "agua";
const string TIPO_AIRE = "aire";
const string TIPO_FUEGO = "fuego";
const string TIPO_TIERRA = "tierra";

using namespace std;

Juego::Juego(string archivo_mapa, Jugador* j1, Jugador* j2) {
    tablero = new Grafo(archivo_mapa);
    ifstream save_game;
    save_game.open("juego_guardado.csv");
    if (save_game){
        save_game.close();
        cout << "Hay juego guardado. Cargando juego..." << endl; //Incoporarlo a la UI
        turno = cargar_juego(tablero);
    } else {
        determinar_primer_turno();
    }
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

int Juego::turnar() {
    if (turno % 2 == 0) return JUGADOR_1;
    return JUGADOR_2;
}

bool Juego::validar_ingreso(int valor) {
    if (!(valor >= 0 && valor < DIM_FILA)){
        cout << "Valor fuera de rango, reintentar." << endl;
        return false;
    } 
    return true;
}

Coordenada Juego::pedir_coord() {
    bool col_valida, fila_valida;
    int col_pedida, fila_pedida;
    
    do {
        cout << "Ingresa numero de fila: " << endl;
        cin >> fila_pedida;
        fila_valida = validar_ingreso(fila_pedida);
    } while (!fila_valida);
    
    do {
        cout << "Ingresa numero de columna: " << endl;
        cin >> col_pedida;
        col_valida = validar_ingreso(col_pedida);
    } while (!col_valida);
    
    Coordenada nueva = Coordenada(fila_pedida, col_pedida);
    
    return nueva;    
}

int Juego::energia_minima(string elemento, bool accion) {
    if (accion) { // atacar
    if (elemento == ELEMENTO_AGUA) return MIN_ENERGIA_ATAQUE_AGUA;
    else if (elemento == ELEMENTO_AIRE) return MIN_ENERGIA_ATAQUE_AIRE;
    else if (elemento == ELEMENTO_FUEGO) return MIN_ENERGIA_ATAQUE_FUEGO;
    else return MIN_ENERGIA_ATAQUE_TIERRA
        
    } else { // defender
    if (elemento == ELEMENTO_AGUA) return MIN_ENERGIA_DEFENSA_AGUA;
    else if (elemento == ELEMENTO_AIRE) return MIN_ENERGIA_DEFENSA_AIRE;
    else if (elemento == ELEMENTO_FUEGO) return MIN_ENERGIA_DEFENSA_FUEGO;
    else return MIN_ENERGIA_DEFENSA_TIERRA
    }
}

void Juego::atacar(int pos_personaje) {
    chequear_subturno();
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    Personaje* personaje_act = jugador_act[pos_personaje];
    Coordenada coord_act = personaje_act->obtener_coordenadas();
    
    if(personaje_act->de_que_elemento_soy() == ELEMENTO_AGUA) {
        if(personaje_act->obtener_energia() >= MIN_ENERGIA_ATAQUE_AGUA) {
            Coordenada nueva = pedir_coord();
            ataque_p_agua(nueva);
        } else cout << ENERGIA_INSUFICIENTE << endl;
    } else if(personaje_act->de_que_elemento_soy() == ELEMENTO_TIERRA) {
        if(personaje_act->obtener_energia() >= MIN_ENERGIA_ATAQUE_TIERRA) {
            Coordenada nueva = pedir_coord();
            ataque_p_tierra(coord_act, nueva);
        } else cout << ENERGIA_INSUFICIENTE << endl;
    } else if(personaje_act->de_que_elemento_soy() == ELEMENTO_FUEGO) {
        if(personaje_act->obtener_energia() >= MIN_ENERGIA_ATAQUE_FUEGO) {
            ataque_p_fuego(personaje_act);
        } else cout << ENERGIA_INSUFICIENTE << endl;
    } else {

    }
}

void Juego::ataque_p_tierra(Coordenada coord_act, Coordenada enemigo) {
    int distancia;
    int danio;
    if(tablero->acceder_tablero(enemigo)->hay_personaje()) {
        distancia = costo_camino_minimo(coord_act, enemigo);
        if(distancia <= 2) danio = 30;  // aca deberiamos poner las constantes!!!
        else if(2 < distancia <= 4) danio = 20;
        else danio = 10;
        tablero->acceder_tablero(enemigo)->obtener_personaje()->recibe_ataque(TIERRA, danio);
    } else cout << "no hay personaje en esa posicion" << endl;
}

void Juego::ataque_p_fuego(Coordenada coord_act) {
    if(turnar() == JUGADOR_1) {
        for(int i = 0; i < jugadores[JUGADOR_2]->obtener_cantidad_personajes(), i++) {
            Personaje* enemigo = jugadores[JUGADOR_2]->obtener_personaje(i);
            if(coord_act.obtener_primera == enemigo->obtener_coordenadas().obtener_primera() || coord_act.obtener_primera() + 1 == enemigo->obtener_coordenadas().obtener_primera() || coord_act.obtener_primera() - 1 == enemigo->obtener_coordenadas().obtener_primera()) {
                enemigo->obtener_coordenadas()->recibe_ataque(FUEGO, ATAQUE_BASE_FUEGO);
            }
        }
    } else {
        for(int i = 0; i < jugadores[JUGADOR_1]->obtener_cantidad_personajes(), i++) {
            Personaje* enemigo = jugadores[JUGADOR_1]->obtener_personaje(i);
            Personaje* enemigo->obtener_coordenadas() = jugadores[JUGADOR_1]->obtener_personaje(i);
            if(coord_act.obtener_primera == enemigo->obtener_coordenadas().obtener_primera() || coord_act.obtener_primera() + 1 == enemigo->obtener_coordenadas().obtener_primera() || coord_act.obtener_primera() - 1 == enemigo->obtener_coordenadas().obtener_primera()) {
                enemigo->recibe_ataque(FUEGO, ATAQUE_BASE_FUEGO);
            }
        }
    }
}

void Juego::ataque_p_agua(Coordenada enemigo) {
    if(tablero->acceder_tablero(enemigo)->obtener_casillero()->obtener_personaje()) { 
        tablero->acceder_tablero(enemigo)->obtener_casillero()->obtener_personaje()->recibe_ataque(AGUA, ATAQUE_BASE_AGUA);
    } else cout << ERROR_NO_HAY_PERSONAJE << endl;
}

void Juego::ataque_p_aire() {
    if(turnar() == JUGADOR_1) {
        for(int i = 0; i < jugadores[JUGADOR_2]->obtener_cantidad_personajes(), i++) {
            jugadores[JUGADOR_2]->obtener_personaje(i)->recibe_ataque(AIRE, ATAQUE_BASE_AIRE);
        }
    } else {
        for(int i = 0; i < jugadores[JUGADOR_1]->obtener_cantidad_personajes(), i++) {
            jugadores[JUGADOR_1]->obtener_personaje(i)->recibe_ataque(AIRE, ATAQUE_BASE_AIRE);
        }
    }
}

void Juego::defenderse() {
    chequear_subturno();
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    Personaje* personaje_act = jugador_act[pos_personaje];

    if(personaje_act->de_que_elemento_soy() == AGUA) defensa_p_agua(personaje_act);
    else if((personaje_act->de_que_elemento_soy() == AIRE) defensa_p_aire(personaje_act);
    else if((personaje_act->de_que_elemento_soy() == FUEGO) personaje_act->defender();
    else defensa_p_tierra();

}

void Juego::defensa_p_agua(Personaje* pj) {
    pj->defender();
    int id_jugador = pj->obtener_id_jugador();
    Jugador* jugador_act = jugadores[id_jugador];
    for(int i = 0; i < jugador_act; i++) {
        if(jugador_act->obtener_personaje(i) != pj) jugador_act->obtener_personaje(i)->curar(10); // cambiar por una cte
    }
}

void Juego::defensa_p_aire(Personaje* pj) {
    pj->defender();
    Coordenada nueva = pedir_coord();
    if(!tablero->acceder_tablero(nueva) {
        tablero->acceder_tablero(pj->obtener_coordenadas())->posicionar_personaje(0); 
        pj->asignar_coordenadas_pj(nueva);
        tablero->acceder_tablero(nueva)->obtener_casillero->posicionar_personaje(pj);
    }
    else cout << "ya hay un personaje en ese casillero" << endl;
}

void Juego::defensa_p_tierra(Personaje* pj) {
    pj->defender();
    pj->incrementar_escudo(true);
}

void Juego::moverse() {
    chequear_subturno();
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    Personaje* personaje_act = jugador_act[pos_personaje];
    Vertice* vertice_actual = tablero->acceder_tablero(personaje_act->obtener_coordenadas());

    Coordenada nueva = pedir_coord();

    int energia_minima = tablero->costo_camino_minimo(personaje_act, tablero->acceder_tablero(nueva));
    if(personaje_act->obtener_energia() >= energia_minima) {
        if(!tablero->acceder_tablero(nueva)->obtener_casillero()->obtener_personaje()) {
            Vertice** camino = tablero->camino_minimo(personaje_act, nueva);
            int i = 0;
            while(camino[i]) {
                vertice_actual->obtener_casillero()->posicionar_personaje(0);
                camino[i]->obtener_casillero()->posicionar_personaje(personaje_act);
                personaje_act->asignar_coordenadas_personaje(camino[i]->obtener_coordenadas());
                i++;
            }
        } else cout << "ya hay un personaje en ese casillero " << endl;
    } else cout << "el personaje no tiene suficiente energia para moverse xd " << endl; // acÃ¡ en realidad habria que indicar cuanta energia tiene y cuanta necesita etc, nico dijo eso at least :pepiga:
}

void Juego::chequear_subturno() {
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    if(pos_personaje >= jugador_act->cantidad_personajes()) pos_personaje = 0;
}

Juego::~Juego() {
    if (tablero) delete tablero;
}

Personaje * cargar_personaje_desde_archivo(string elemento, string nombre, int escudo, int vida, int energia, int fila, int columna, int jugador){
    Personaje * personaje;
    if (elemento == TIPO_AGUA){
        personaje = new Personaje_de_agua(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    else if (elemento == TIPO_FUEGO){
        personaje = new Personaje_de_fuego(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    else if (elemento == TIPO_TIERRA){
        personaje = new Personaje_de_tierra(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    else if (elemento == TIPO_AIRE){
        personaje = new Personaje_de_aire(nombre, escudo, vida, energia, fila, columna, jugador);
    }
    return personaje;
}

int Juego::cargar_juego(Grafo * grafo){
    ifstream juego_guardado;
    juego_guardado.open("juego_guardado.csv");
    string elemento, nombre_personaje, escudo, vida, energia, fila, columna, turno_jugador;
    Lista * lista_vertices = grafo->obtener_vertices();
    Vertice * vertice_actual;
    Coordenada coordenada_actual;
    Casillero * casillero_actual;
    getline(juego_guardado, turno_jugador, '\n');
    int jugador;
    int i = 0;
    while(!juego_guardado.eof()){
        getline(juego_guardado, elemento, SEPARADOR_CSV);
        getline(juego_guardado, nombre_personaje, SEPARADOR_CSV);
        getline(juego_guardado, escudo, SEPARADOR_CSV);
        getline(juego_guardado, vida, SEPARADOR_CSV);
        getline(juego_guardado, energia, SEPARADOR_CSV);
        getline(juego_guardado, fila, SEPARADOR_CSV);
        getline(juego_guardado, columna, SALTO_DE_LINEA);
        if (i < 3){
            jugador = 1;
        }
        else {
            jugador = 2;
        }
        Personaje * personaje_cargado = cargar_personaje_desde_archivo(elemento, nombre_personaje, stoi(escudo), stoi(vida), stoi(energia), stoi(fila), stoi(columna), jugador);
        while(lista_vertices->obtener_actual() != nullptr){
            vertice_actual = lista_vertices->obtener_actual();
            coordenada_actual = vertice_actual->obtener_coordenadas();
            casillero_actual = vertice_actual->obtener_casillero();
            if (coordenada_actual.obtener_primera() == stoi(fila) && coordenada_actual.obtener_segunda() == stoi(columna)){
                casillero_actual->posicionar_personaje(personaje_cargado);
            }
            lista_vertices->siguiente();
        }
        lista_vertices->reiniciar();
        i++;
    }
    juego_guardado.close();
    return stoi(turno_jugador);
}
