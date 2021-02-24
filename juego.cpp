#include "juego.h"

Juego::Juego(){
    tablero = new Grafo("../mapa.csv");

    Jugador* j1 = new Jugador();
    Jugador* j2 = new Jugador();

    determinar_primer_turno();

    jugadores[JUGADOR_1] = j1;
    jugadores[JUGADOR_2] = j2; // a chequear jaja malisimo bro que hacia
    pos_personaje = 0;

    termino = false;
    opcion_seleccionada = 0;
    esta_activo_menu_juego = true;
    esta_activo_sub_menu_juego = false;
}


bool Juego::comenzo() {
    return obtener_jugador(JUGADOR_1)->eligio_max_personajes() && obtener_jugador(JUGADOR_2)->eligio_max_personajes();
}


void Juego::jugar() {
    ventana_juego = new RenderWindow(VideoMode(1152, 864), TITULO);
    ventana_juego->setMouseCursorVisible(false);
    cargar_graficos();

    posicionar_personajes();

    while(!termino && !obtener_jugador(JUGADOR_1)->jugador_perdio() && !obtener_jugador(JUGADOR_2)->jugador_perdio()){

        interfaz_menu_juego();

    }
}


Jugador* Juego::obtener_jugador(int jugador) {
    if(jugador == JUGADOR_1 || jugador == JUGADOR_2) return jugadores[jugador];
    return nullptr;
}


Juego::~Juego() {
    if (tablero) delete tablero;
}


void Juego::determinar_primer_turno() {
    turno = rand() % 1 + 0;
}


int Juego::turnar() {
    if (turno % 2 == 0) return JUGADOR_1;
    return JUGADOR_2;
}


void Juego::chequear_subturno() {
    int turno_act = turnar();
    Jugador* jugador_act = jugadores[turno_act];
    if(pos_personaje >= jugador_act->obtener_cantidad_personajes()) {
        pos_personaje = 0;
        turno++;
    }
}


void Juego::posicionar_personajes() {
    Text mensaje;
    mensaje.setFont(fuente);

    int personajes_posicionados = 0;

    while(personajes_posicionados < 6){
        Coordenada coordenada = coordenada_valida();

        tablero->obtener_vertices()->consulta(coordenada)->obtener_casillero()->posicionar_personaje(jugadores[turnar()]->obtener_personaje(pos_personaje), coordenada);

        turno++;

        if(personajes_posicionados % 2 != 0) pos_personaje++;

        chequear_subturno();

        personajes_posicionados++;
    }

}


void Juego::alimentarse() {

}


void Juego::moverse() {

}


void Juego::defenderse() {

}


void Juego::atacar() {

}


void Juego::pasar_opcion() {

    if(esta_activo_menu_juego){
        opciones_menu_juego[opcion_seleccionada].setFillColor(Color::White);
        opciones_menu_juego[0].setFillColor(Color::Yellow);
        interfaz_sub_menu_juego();
    }

    if(esta_activo_sub_menu_juego){
        opciones_sub_menu_juego[opcion_seleccionada].setFillColor(Color::White);
        opciones_sub_menu_juego[0].setFillColor(Color::Yellow);
        pos_personaje++;
        chequear_subturno();
        interfaz_menu_juego();
    }
}


void Juego::cargar_graficos() {
    fuente.loadFromFile("../Daily Hours.ttf");

    txt_fondo.loadFromFile("../fondo.jpeg");
    spr_fondo.setTexture(txt_fondo);
    spr_fondo.setScale((float)ventana_juego->getSize().x / spr_fondo.getTexture()->getSize().x , (float)ventana_juego->getSize().y / spr_fondo.getTexture()->getSize().y);
    Color color_fondo(255, 255, 255, 30); //(semi transparente);
    spr_fondo.setColor(color_fondo);

    titulo.setFont(fuente);
    titulo.setFillColor(Color::White);
    titulo.setString(TITULO);
    titulo.setCharacterSize(90);
    titulo.setPosition(sf::Vector2f(ventana_juego->getSize().x / 2.0  , 10.0));
    titulo.setOrigin(titulo.getGlobalBounds().width / 2, titulo.getGlobalBounds().height / 2);

    for (int i = 0; i < MAX_PERSONAJES; i++){
        spr_personajes_jugador_1[i] = jugadores[JUGADOR_1]->obtener_personaje(i)->obtener_sprite();
        spr_personajes_jugador_1[i].setPosition(200.f, 350.f + (float)(175 * i));

        spr_personajes_jugador_2[i] = jugadores[JUGADOR_2]->obtener_personaje(i)->obtener_sprite();
        spr_personajes_jugador_2[i].setPosition(972.f - 32.f, 350.f + (float)(175 * i));
    }

    cargar_graficos_turno();

    cargar_graficos_detalles_personajes();

    cargar_graficos_menu_juego();

    cargar_graficos_sub_menu_juego();

}


void Juego::cargar_graficos_menu_juego() {
    opciones_menu_juego[0].setString(ALIMENTARSE);
    opciones_menu_juego[1].setString(MOVERSE);
    opciones_menu_juego[2].setString(PASAR_OPCION);

    for(int i = 0; i < OPCIONES_VALIDAS_MENU_JUEGO; i++){
        opciones_menu_juego[i].setFont(fuente);
        opciones_menu_juego[i].setFillColor(sf::Color::White);
        opciones_menu_juego[i].setCharacterSize(22);
        opciones_menu_juego[i].setPosition(sf::Vector2f((float)ventana_juego->getSize().x / 2  , 90 + (i * 20.0)));
        opciones_menu_juego[i].setOrigin(opciones_menu_juego[i].getGlobalBounds().width / 2, opciones_menu_juego[i].getGlobalBounds().height / 2);
    }

    opciones_menu_juego[0].setFillColor(sf::Color::Yellow);
}


void Juego::cargar_graficos_sub_menu_juego() {
    opciones_sub_menu_juego[0].setString(DEFENDERSE);
    opciones_sub_menu_juego[1].setString(ATACAR);
    opciones_sub_menu_juego[2].setString(PASAR_OPCION);

    for(int i = 0; i < OPCIONES_VALIDAS_SUB_MENU_JUEGO; i++){
        opciones_sub_menu_juego[i].setFont(fuente);
        opciones_sub_menu_juego[i].setFillColor(sf::Color::White);
        opciones_sub_menu_juego[i].setCharacterSize(22);
        opciones_sub_menu_juego[i].setPosition(sf::Vector2f((float)ventana_juego->getSize().x / 2  , 90 + (i * 20.0)));
        opciones_sub_menu_juego[i].setOrigin(opciones_sub_menu_juego[i].getGlobalBounds().width / 2, opciones_sub_menu_juego[i].getGlobalBounds().height / 2);
    }

    opciones_sub_menu_juego[0].setFillColor(sf::Color::Yellow);
}


void Juego::cargar_graficos_detalles_personajes() {
    detalles_personajes_jugador_1.setString("PERSONAJES\nJUGADOR 1: \n\n" + obtener_jugador(0)->detalles_personajes());
    detalles_personajes_jugador_1.setFont(fuente);
    detalles_personajes_jugador_1.setFillColor(Color::White);
    detalles_personajes_jugador_1.setCharacterSize(22);
    detalles_personajes_jugador_1.setOrigin(detalles_personajes_jugador_1.getGlobalBounds().width / 2, detalles_personajes_jugador_1.getGlobalBounds().height / 2);
    detalles_personajes_jugador_1.setPosition(10 + detalles_personajes_jugador_1.getGlobalBounds().width / 2, 70 + (float)ventana_juego->getSize().y / 2);

    detalles_personajes_jugador_2.setString("PERSONAJES\nJUGADOR 2: \n\n" + obtener_jugador(1)->detalles_personajes());
    detalles_personajes_jugador_2.setFont(fuente);
    detalles_personajes_jugador_2.setFillColor(Color::White);
    detalles_personajes_jugador_2.setCharacterSize(22);
    detalles_personajes_jugador_2.setOrigin(detalles_personajes_jugador_2.getGlobalBounds().width / 2, detalles_personajes_jugador_2.getGlobalBounds().height / 2);
    detalles_personajes_jugador_2.setPosition((float)ventana_juego->getSize().x - 10 - detalles_personajes_jugador_2.getGlobalBounds().width / 2, 70 + (float)ventana_juego->getSize().y / 2);
}


void Juego::cargar_graficos_turno() {
    turno_actual.setFont(fuente);
    turno_actual.setFillColor(Color::Cyan);
    turno_actual.setString("Turno JUGADOR: " + to_string(turnar() + 1) + "  PERSONAJE: " + jugadores[turnar()]->obtener_personaje(pos_personaje)->nombre_personaje());
    turno_actual.setOrigin(turno_actual.getGlobalBounds().width / 2, turno_actual.getGlobalBounds().height / 2);
    turno_actual.setPosition((float)ventana_juego->getSize().x / 2, (float)ventana_juego->getSize().y - (float )turno_actual.getCharacterSize() - 10.f);
}


void Juego::dibujar_juego() {
    ventana_juego->draw(spr_fondo);
    ventana_juego->draw(titulo);

    cargar_graficos_detalles_personajes(); //OBS: se carga cada vez que se dibuja el juego, ya que los datos se van modificando
    ventana_juego->draw(detalles_personajes_jugador_1);
    ventana_juego->draw(detalles_personajes_jugador_2);

    for(int i = 0; i < MAX_PERSONAJES; i++){
        ventana_juego->draw(spr_personajes_jugador_1[i]);
        ventana_juego->draw(spr_personajes_jugador_2[i]);
    }

    cargar_graficos_turno(); //OBS: se carga cada vez que se dibuja el juego, ya que los datos se van modificando
    ventana_juego->draw(turno_actual);

    dibujar_tablero();
    dibujar_personajes();
}


void Juego::dibujar_tablero() {
    tablero->obtener_vertices()->reiniciar();

    Lista * vertices = tablero->obtener_vertices();

    while(vertices->hay_siguiente()){

        ventana_juego->draw(vertices->obtener_actual()->obtener_casillero()->obtener_sprite());

        vertices->siguiente();
    }
}

//OBS: Si bien es la misma logica que dibujar_tablero(), si dibujo ambas cosas al mismo tiempo se van pisando (cosas de SFML);
void Juego::dibujar_personajes() {
    tablero->obtener_vertices()->reiniciar();

    Lista * vertices = tablero->obtener_vertices();

    while(vertices->hay_siguiente()){

        if(vertices->obtener_actual()->obtener_casillero()->hay_personaje()){
            ventana_juego->draw(vertices->obtener_actual()->obtener_casillero()->obtener_personaje()->obtener_sprite());
        }

        vertices->siguiente();
    }
}


void Juego::dibujar_menu_juego() {
    for (int i = 0; i < OPCIONES_VALIDAS_MENU_JUEGO; i++)
    {
        ventana_juego->draw(opciones_menu_juego[i]);
    }
}


void Juego::dibujar_sub_menu_juego() {
    for (int i = 0; i < OPCIONES_VALIDAS_SUB_MENU_JUEGO; i++)
    {
        ventana_juego->draw(opciones_sub_menu_juego[i]);
    }
}


void Juego::interfaz_menu_juego() {
    opcion_seleccionada = 0;

    esta_activo_sub_menu_juego = false;
    esta_activo_menu_juego = true;

    while(esta_activo_menu_juego)
    {
        ventana_juego->clear();

        dibujar_juego();
        dibujar_menu_juego();
        procesar_eventos_menu_juego();

        ventana_juego->display();
    }
}


void Juego::interfaz_sub_menu_juego() {
    opcion_seleccionada = 0;
    esta_activo_menu_juego = false;
    esta_activo_sub_menu_juego = true;

    while(esta_activo_sub_menu_juego)
    {
        ventana_juego->clear();

        dibujar_juego();
        dibujar_sub_menu_juego();
        procesar_eventos_sub_menu_juego();

        ventana_juego->display();
    }
}


void Juego::procesar_eventos_menu_juego() {
    Event evento{};

    while (ventana_juego->pollEvent(evento))
    {
        switch (evento.type)
        {
            case sf::Event::KeyReleased:
                switch (evento.key.code)
                {
                    case sf::Keyboard::Up:
                        subir_menu_juego();
                        break;

                    case sf::Keyboard::Down:
                       bajar_menu_juego();
                        break;

                    case sf::Keyboard::Enter:
                        switch (obtener_opcion_seleccionada())
                        {
                            case 0: {
                                //alimentar();
                                break;
                            }
                            case 1:
                                //mover();
                                break;
                            case 2:
                                pasar_opcion();
                                break;
                        }
                        break;
                }

                break;

            case sf::Event::Closed:
                salir();
                break;
        }
    }
}


void Juego::procesar_eventos_sub_menu_juego() {
    Event evento{};

    while (ventana_juego->pollEvent(evento))
    {
        switch (evento.type)
        {
            case sf::Event::KeyReleased:
                switch (evento.key.code)
                {
                    case sf::Keyboard::Up:
                        subir_sub_menu_juego();
                        break;

                    case sf::Keyboard::Down:
                        bajar_sub_menu_juego();
                        break;

                    case sf::Keyboard::Enter:
                        switch (obtener_opcion_seleccionada())
                        {
                            case 0:
                                //defender();
                                break;
                            case 1:
                                //atacar();
                                break;
                            case 2:
                                pasar_opcion();
                                break;
                        }
                        break;
                }
                break;

            case sf::Event::Closed:
                salir();
                break;
        }
    }
}


void Juego::subir_menu_juego() {
    if (opcion_seleccionada - 1 >= 0)
    {
        opciones_menu_juego[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada--;
        opciones_menu_juego[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}


void Juego::bajar_menu_juego() {
    if (opcion_seleccionada + 1 < OPCIONES_VALIDAS_MENU_JUEGO)
    {
        opciones_menu_juego[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada++;
        opciones_menu_juego[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}


void Juego::subir_sub_menu_juego() {
    if (opcion_seleccionada - 1 >= 0)
    {
        opciones_sub_menu_juego[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada--;
        opciones_sub_menu_juego[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}


void Juego::bajar_sub_menu_juego() {
    if (opcion_seleccionada + 1 < OPCIONES_VALIDAS_SUB_MENU_JUEGO)
    {
        opciones_sub_menu_juego[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada++;
        opciones_sub_menu_juego[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}


int Juego::obtener_opcion_seleccionada() const {
    return opcion_seleccionada;
}


void Juego::imprimir_mensaje(Text mensaje) {
    Clock reloj = Clock();
    Time tiempo = Time();

    mensaje.setOrigin(mensaje.getGlobalBounds().width / 2, mensaje.getGlobalBounds().height / 2);
    mensaje.setPosition((float)ventana_juego->getSize().x / 2, opciones_menu_juego[1].getPosition().y);

    while(tiempo.asSeconds() < 1.5) {
        ventana_juego->clear();

        tiempo = reloj.getElapsedTime();

        dibujar_juego();
        ventana_juego->draw(mensaje);

        ventana_juego->display();
    }
}


string Juego::pedir_coordenadas() {
    esta_activo_menu_juego = false;

    string coordenada;

    Text pedir_coordenada("Ingrese la posicion (0 <= FILA <= 7, 0 <= COLUMNA <= 7) : ", fuente);
    pedir_coordenada.setPosition(sf::Vector2f(ventana_juego->getSize().x / 2.0  , opciones_menu_juego[0].getPosition().y));
    pedir_coordenada.setOrigin(pedir_coordenada.getGlobalBounds().width / 2, pedir_coordenada.getGlobalBounds().height / 2);

    Text texto_de_entrada("", fuente);
    texto_de_entrada.setPosition(sf::Vector2f(ventana_juego->getSize().x / 2.0  , opciones_menu_juego[2].getPosition().y));

    Clock reloj;
    Event evento{};

    while (!esta_activo_menu_juego)
    {
        ventana_juego->clear();

        while (ventana_juego->pollEvent(evento))
        {
            switch (evento.type)
            {
                case sf::Event::TextEntered:
                    if (std::isprint(evento.text.unicode))
                        coordenada += evento.text.unicode;

                case sf::Event::KeyReleased:
                    switch (evento.key.code)
                    {
                        case sf::Keyboard::BackSpace:
                            if (!coordenada.empty())
                                coordenada.pop_back();
                            break;

                        case sf::Keyboard::Enter:
                            esta_activo_menu_juego = true;
                            break;
                    }

                    break;

                case sf::Event::Closed:
                    salir();
                    break;
            }
        }

        static sf::Time efecto_texto;
        static bool mostrar_efecto;

        efecto_texto += reloj.restart();

        if (efecto_texto >= sf::seconds(0.5f))
        {
            mostrar_efecto = !mostrar_efecto;
            efecto_texto = sf::Time::Zero;
        }

        texto_de_entrada.setString(coordenada + (mostrar_efecto ? '_' : ' '));

        dibujar_juego();
        texto_de_entrada.setOrigin(texto_de_entrada.getGlobalBounds().width / 2, texto_de_entrada.getGlobalBounds().height / 2);
        ventana_juego->draw(pedir_coordenada);
        ventana_juego->draw(texto_de_entrada);
        ventana_juego->display();
    }

    return coordenada;
}


Coordenada Juego::coordenada_valida() {
    Text mensaje;
    mensaje.setFont(fuente);

    int fila, columna;
    Coordenada coordenada;
    bool coordenada_valida = false;

    while(!coordenada_valida) {
        string posicion_personaje = pedir_coordenadas();
        while (posicion_personaje.length() != 3 || !isdigit(posicion_personaje[0]) || !isdigit(posicion_personaje[2])){
            mensaje.setString("La coordenada ingresada no es valida!");
            imprimir_mensaje(mensaje);
            posicion_personaje = pedir_coordenadas();
        }

        char primera_coord[2];
        primera_coord[0] = posicion_personaje[0];
        primera_coord[1] = '\0';
        char segunda_coord[2];
        segunda_coord[0] = posicion_personaje[2];
        segunda_coord[1] = '\0';

        fila = atoi(primera_coord);
        columna = atoi(segunda_coord);

        if(0 <= columna && columna <= 7 && 0 <= fila &&  fila <= 7) {

            coordenada = Coordenada(fila, columna);

            if(!tablero->obtener_vertices()->consulta(coordenada)->obtener_casillero()->hay_personaje()){
                coordenada_valida = true;
            }else{
                mensaje.setString("La posicion (" + to_string(coordenada.obtener_primera()) + ", " + to_string(coordenada.obtener_segunda()) +  ") esta ocupada!");
                imprimir_mensaje(mensaje);
            }
        }else {
            mensaje.setString("La coordenada ingresada no es valida!");
            imprimir_mensaje(mensaje);
        }
    }

    return coordenada;
}


void Juego::salir() {
    termino = true;
    esta_activo_menu_juego = false;
    esta_activo_sub_menu_juego = false;
    ventana_juego->close();
}

