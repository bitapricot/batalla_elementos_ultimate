//
// Created by mdavico on 8/2/21.
//

#include "Menu.h"
#include <string>

Menu::Menu()
{
    personajes = new Diccionario();
    esta_activo = true;
    esta_activo_sub_menu = false;

    ventana_menu = new RenderWindow(VideoMode(1080, 720), TITULO);
    ventana_menu->setMouseCursorVisible(false);

    opcion_seleccionada = 0;

    cargar_personajes("../personajes.txt");
    cargar_graficos();

    interfaz_menu();
}


Menu::~Menu()
= default;

void Menu::dibujar_menu()
{

    ventana_menu->draw(spr_fondo);

    ventana_menu->draw(titulo);

    for (int i = 0; i < OPCIONES_VALIDAS_MENU; i++)
    {
        ventana_menu->draw(opciones_menu[i]);
    }
}


void Menu::dibujar_sub_menu() {

    ventana_menu->draw(spr_fondo);

    ventana_menu->draw(titulo);

    for (int i = 0; i < OPCIONES_VALIDAS_SUB_MENU; i++)
    {
        ventana_menu->draw(opciones_sub_menu[i]);
    }
}


void Menu::subir()
{
    if (opcion_seleccionada - 1 >= 0)
    {
        opciones_menu[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada--;
        opciones_menu[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}

void Menu::bajar()
{
    if (opcion_seleccionada + 1 < OPCIONES_VALIDAS_MENU)
    {
        opciones_menu[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada++;
        opciones_menu[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}


void Menu::subir_sub_menu()
{
    if (opcion_seleccionada - 1 >= 0)
    {
        opciones_sub_menu[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada--;
        opciones_sub_menu[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}

void Menu::bajar_sub_menu()
{
    if (opcion_seleccionada + 1 < OPCIONES_VALIDAS_SUB_MENU)
    {
        opciones_sub_menu[opcion_seleccionada].setFillColor(sf::Color::White);
        opcion_seleccionada++;
        opciones_sub_menu[opcion_seleccionada].setFillColor(sf::Color::Yellow);
    }
}

void Menu::interfaz_menu() {
    mensaje_bienvenida();

    while(esta_activo)
    {
        ventana_menu->clear();

        procesar_eventos();

        dibujar_menu();

        ventana_menu->display();
    }
}


void Menu::interfaz_sub_menu() {
    opcion_seleccionada = 0;
    esta_activo = false;
    esta_activo_sub_menu = true;

    while(esta_activo_sub_menu)
    {
        ventana_menu->clear();

        procesar_eventos_sub_menu();

        dibujar_sub_menu();

        ventana_menu->display();
    }
}


int Menu::obtener_opcion_seleccionada() const {
    return opcion_seleccionada;
}

void Menu::cargar_graficos() {
    fuente.loadFromFile("../Daily Hours.ttf");

    txt_fondo.loadFromFile("../fondo.jpeg");
    spr_fondo.setTexture(txt_fondo);
    spr_fondo.setScale((float)ventana_menu->getSize().x / spr_fondo.getTexture()->getSize().x , (float)ventana_menu->getSize().y / spr_fondo.getTexture()->getSize().y);
    Color color_fondo_menu(255, 255, 255, 30); //(semi transparente);
    spr_fondo.setColor(color_fondo_menu);

    titulo.setFont(fuente);
    titulo.setFillColor(Color::White);
    titulo.setString(TITULO);
    titulo.setCharacterSize(90);
    titulo.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , 10.0));
    titulo.setOrigin(titulo.getGlobalBounds().width / 2, titulo.getGlobalBounds().height / 2);

    opciones_menu[0].setString(AGREGAR_PERSONAJE);
    opciones_menu[1].setString(ELIMINAR_PERSONAJE);
    opciones_menu[2].setString(MOSTRAR_NOMBRES);
    opciones_menu[3].setString(BUSCAR_DETALLES);
    opciones_menu[4].setString(COMENZAR_JUEGO);
    opciones_menu[5].setString(SALIR);

    for(int i = 0; i < OPCIONES_VALIDAS_MENU; i++){
        opciones_menu[i].setFont(fuente);
        opciones_menu[i].setFillColor(sf::Color::White);
        opciones_menu[i].setCharacterSize(40);
        opciones_menu[i].setPosition(sf::Vector2f((float)ventana_menu->getSize().x / 2  , (float)ventana_menu->getSize().y / (OPCIONES_VALIDAS_MENU + 1) * (i + 1.0)));
        opciones_menu[i].setOrigin(opciones_menu[i].getGlobalBounds().width / 2, opciones_menu[i].getGlobalBounds().height / 2);
    }

    opciones_menu[0].setFillColor(sf::Color::Yellow);

    opciones_sub_menu[0].setString(BUSCAR_DETALLES);
    opciones_sub_menu[1].setString(MOSTRAR_NOMBRES);
    opciones_sub_menu[2].setString(SELECCIONAR_PERSONAJE);
    opciones_sub_menu[3].setString(SALIR);

    for(int i = 0; i < OPCIONES_VALIDAS_SUB_MENU; i++){
        opciones_sub_menu[i].setFont(fuente);
        opciones_sub_menu[i].setFillColor(sf::Color::White);
        opciones_sub_menu[i].setCharacterSize(40);
        opciones_sub_menu[i].setPosition(sf::Vector2f((float)ventana_menu->getSize().x / 2  , (float)ventana_menu->getSize().y / (OPCIONES_VALIDAS_SUB_MENU + 1) * (i + 1.0)));
        opciones_sub_menu[i].setOrigin(opciones_sub_menu[i].getGlobalBounds().width / 2, opciones_sub_menu[i].getGlobalBounds().height / 2);
    }

    opciones_sub_menu[0].setFillColor(sf::Color::Yellow);
}

void Menu::procesar_eventos() {
    Event evento{};

    while (ventana_menu->pollEvent(evento))
    {
        switch (evento.type)
        {
            case sf::Event::KeyReleased:
                switch (evento.key.code)
                {
                    case sf::Keyboard::Up:
                        subir();
                        break;

                    case sf::Keyboard::Down:
                        bajar();
                        break;

                    case sf::Keyboard::Enter:
                        switch (obtener_opcion_seleccionada())
                        {
                            case 0:
                                agregar_nuevo_personaje();
                                break;
                            case 1:
                                eliminar_personaje();
                                break;
                            case 2:
                                mostrar_nombres_personajes();
                                break;
                            case 3:
                                detalles_personaje();
                                break;
                            case 4:
                                interfaz_sub_menu();
                                break;
                            case 5:
                                salir();
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


void Menu::procesar_eventos_sub_menu() {
    Event evento{};

    while (ventana_menu->pollEvent(evento))
    {
        switch (evento.type)
        {
            case sf::Event::KeyReleased:
                switch (evento.key.code)
                {
                    case sf::Keyboard::Up:
                        subir_sub_menu();
                        break;

                    case sf::Keyboard::Down:
                        bajar_sub_menu();
                        break;

                    case sf::Keyboard::Enter:
                        switch (obtener_opcion_seleccionada())
                        {
                            case 0:
                                detalles_personaje();
                                break;
                            case 1:
                                mostrar_nombres_personajes();
                                break;
                            case 2:
                                //seleccionar_personaje();
                                break;
                            case 3:
                                salir();
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


void Menu::cargar_personajes(string archivo) {
    ifstream archivo_personajes;
    archivo_personajes.open(archivo);
    if(!archivo_personajes) {
        cout << ERROR_APERTURA << endl;
    } else {
        string elemento;
        string nombre;
        string escudo;
        string vida;

        while(getline(archivo_personajes, elemento, ',')) {
            getline(archivo_personajes, nombre, ',');
            getline(archivo_personajes, escudo, ',');
            getline(archivo_personajes, vida);
            cargar_personaje_segun_elemento(elemento, nombre, stoi(escudo), stoi(vida));
        }
    }
}

void Menu::cargar_personaje_segun_elemento(string elemento, string nombre, int escudo, int vida) {
    Personaje* nuevo;
    if(elemento == ELEMENTO_AGUA) nuevo = new Personaje_de_agua(nombre, escudo, vida);
    else if(elemento == ELEMENTO_AIRE) nuevo = new Personaje_de_aire(nombre, escudo, vida);
    else if(elemento == ELEMENTO_FUEGO) nuevo = new Personaje_de_fuego(nombre, escudo, vida);
    else if(elemento == ELEMENTO_TIERRA) nuevo = new Personaje_de_tierra(nombre, escudo, vida);
    personajes->insertar(nombre, nuevo);
}

void Menu::cargar_personaje_segun_elemento(string elemento, string nombre) {

    Personaje* nuevo;
    if(elemento == ELEMENTO_AGUA) nuevo = new Personaje_de_agua(nombre);
    else if(elemento == ELEMENTO_AIRE) nuevo = new Personaje_de_aire(nombre);
    else if(elemento == ELEMENTO_FUEGO) nuevo = new Personaje_de_fuego(nombre);
    else if(elemento == ELEMENTO_TIERRA) nuevo = new Personaje_de_tierra(nombre);

    personajes->insertar(nombre, nuevo);
}

void Menu::agregar_nuevo_personaje() {
    string elemento;
    while(true){
        elemento = pedir_elemento_personaje();
        if(elemento == ELEMENTO_AGUA || elemento == ELEMENTO_AIRE || elemento == ELEMENTO_FUEGO || elemento == ELEMENTO_TIERRA) break;
    }
    string nombre = pedir_nombre_personaje();
    cargar_personaje_segun_elemento(elemento, nombre);

}

void Menu::eliminar_personaje() {
    Text mensaje;
    mensaje.setFont(fuente);

    if(!personajes->vacio()) {
        string nombre = pedir_nombre_personaje();

        if (/*personajes->esta_clave(nombre)*/false) {
            //personajes->baja(nombre);
            mensaje.setString("El personaje " + nombre + " fue eliminado");
        } else{
            mensaje.setString("El personaje " + nombre + " no se encuentra en la lista");
            }
    }else {
        mensaje.setString(ERROR_DICCIONARIO_VACIO);
    }

    mensaje.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 2.0));
    mensaje.setOrigin(mensaje.getGlobalBounds().width / 2, mensaje.getGlobalBounds().height / 2);

    imprimir_mensaje(mensaje);
}

void Menu::mostrar_nombres_personajes() {
    Text mensaje;
    mensaje.setFont(fuente);

    if(!personajes->vacio()) {
        string claves = "Personajes: \n";
        personajes->claves_inorden(personajes->obtener_raiz(), claves);
        mensaje.setString(claves);
    }
    else {
        mensaje.setString(ERROR_DICCIONARIO_VACIO);
    }

    mensaje.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 2.0));
    mensaje.setOrigin(mensaje.getGlobalBounds().width / 2, mensaje.getGlobalBounds().height / 2);
    imprimir_mensaje(mensaje);
}

void Menu::detalles_personaje() {
    Text mensaje;
    mensaje.setFont(fuente);

    if(!personajes->vacio()) {
        string nombre = pedir_nombre_personaje();
        Personaje* solicitado = personajes->consulta(nombre);
        if(solicitado) {
            string detalles_pj = solicitado->mostrar_detalles();
            mensaje.setString(detalles_pj);
        } else {
            mensaje.setString("El personaje " + nombre + " no existe");
        }
    } else {
        mensaje.setString(ERROR_DICCIONARIO_VACIO);
    }

    mensaje.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 2.0));
    mensaje.setOrigin(mensaje.getGlobalBounds().width / 2, mensaje.getGlobalBounds().height / 2);

    imprimir_mensaje(mensaje);
}

void Menu::salir() {
    esta_activo_sub_menu = false;
    esta_activo = false;
    ventana_menu->close();
}

void Menu::mensaje_bienvenida() {
    Clock reloj = Clock();
    Time tiempo = Time();

    Text mensaje_bienvenida(MENSAJE_BIENVENIDA, fuente);
    mensaje_bienvenida.setCharacterSize(150);
    mensaje_bienvenida.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 3.0));
    mensaje_bienvenida.setOrigin(mensaje_bienvenida.getGlobalBounds().width / 2, mensaje_bienvenida.getGlobalBounds().height / 2);

    while(tiempo.asSeconds() < 3) {
        tiempo = reloj.getElapsedTime();
        ventana_menu->clear();
        ventana_menu->draw(spr_fondo);
        ventana_menu->draw(mensaje_bienvenida);
        ventana_menu->display();
    }
}


/*void Menu::seleccionar_personaje() {
    string nombre = pedir_nombre_personaje();
    if(!personajes->vacio()) {
        Personaje* solicitado = personajes->consulta(nombre);
        if(solicitado && !solicitado->fue_seleccionado()) {
            if(determinar_turno_seleccion() == JUGADOR_1) {
                juego.jugador_1.agregar_personaje(solicitado);
            } else {
                juego.jugador_2.agregar_personaje(solicitado);
            turno_seleccion++;
        } else {
            cout << ERROR_PERSONAJE_NO_DISPONIBLE << endl;
        }
    } else {
        cout << ERROR_DICCIONARIO_VACIO << endl;
    }
}

*/
/*void Menu::determinar_turno_seleccion() {
    if(turno_seleccion % 2 == 0) return JUGADOR_1;
    else return JUGADOR_2;
}
*/


string Menu::pedir_elemento_personaje() {
    esta_activo = false;
    string elemento;

    Text pedir_elemento("Ingrese el elemento del personaje (agua, aire, fuego o tierra): ", fuente);
    pedir_elemento.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 4.0));
    pedir_elemento.setOrigin(pedir_elemento.getGlobalBounds().width / 2, pedir_elemento.getGlobalBounds().height / 2);


    Text texto_de_entrada("", fuente);
    texto_de_entrada.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 2.0));

    Clock reloj;
    Event evento{};

    while (!esta_activo)
    {
        ventana_menu->clear();

        while (ventana_menu->pollEvent(evento))
        {
            switch (evento.type)
            {
                case sf::Event::TextEntered:
                    if (std::isprint(evento.text.unicode))
                        elemento += evento.text.unicode;

                case sf::Event::KeyReleased:
                    switch (evento.key.code)
                    {
                        case sf::Keyboard::BackSpace:
                            if (!elemento.empty())
                                elemento.pop_back();
                            break;

                        case sf::Keyboard::Enter:
                            esta_activo = true;
                            break;
                    }

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

        texto_de_entrada.setString(elemento + (mostrar_efecto ? '_' : ' '));

        ventana_menu->draw(titulo);
        ventana_menu->draw(spr_fondo);
        ventana_menu->draw(pedir_elemento);
        texto_de_entrada.setOrigin(texto_de_entrada.getGlobalBounds().width / 2, texto_de_entrada.getGlobalBounds().height / 2);
        ventana_menu->draw(texto_de_entrada);
        ventana_menu->display();
    }

    return elemento;
}

string Menu::pedir_nombre_personaje() {
    esta_activo = false;

    string nombre;

    Text pedir_nombre("Ingrese el nombre del personaje: ", fuente);
    pedir_nombre.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 4.0));
    pedir_nombre.setOrigin(pedir_nombre.getGlobalBounds().width / 2, pedir_nombre.getGlobalBounds().height / 2);

    Text texto_de_entrada("", fuente);
    texto_de_entrada.setPosition(sf::Vector2f(ventana_menu->getSize().x / 2.0  , ventana_menu->getSize().y / 2.0));

    Clock reloj;
    Event evento{};

    while (!esta_activo)
    {
        ventana_menu->clear();

        while (ventana_menu->pollEvent(evento))
        {
            switch (evento.type)
            {
                case sf::Event::TextEntered:
                    if (std::isprint(evento.text.unicode))
                        nombre += evento.text.unicode;

                case sf::Event::KeyReleased:
                    switch (evento.key.code)
                    {
                        case sf::Keyboard::BackSpace:
                            if (!nombre.empty())
                                nombre.pop_back();
                            break;

                        case sf::Keyboard::Enter:
                            esta_activo = true;
                            break;
                    }

                    break;

                case sf::Event::Closed:
                    esta_activo = false;
                    ventana_menu->close();
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

        texto_de_entrada.setString(nombre + (mostrar_efecto ? '_' : ' '));

        ventana_menu->draw(titulo);
        ventana_menu->draw(spr_fondo);
        ventana_menu->draw(pedir_nombre);
        texto_de_entrada.setOrigin(texto_de_entrada.getGlobalBounds().width / 2, texto_de_entrada.getGlobalBounds().height / 2);
        ventana_menu->draw(texto_de_entrada);
        ventana_menu->display();
    }
    return nombre;
}

void Menu::imprimir_mensaje(Text mensaje) {
    Clock reloj = Clock();
    Time tiempo = Time();

    while(tiempo.asSeconds() < 5) {
        tiempo = reloj.getElapsedTime();
        ventana_menu->clear();

        ventana_menu->draw(spr_fondo);
        ventana_menu->draw(titulo);
        ventana_menu->draw(mensaje);

        ventana_menu->display();
    }
}
