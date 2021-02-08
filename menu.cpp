#include "menu.h"

Menu::Menu() {
    personajes = 0;
    esta_activo = false;
}

/*Menu::~Menu() {
    while(!personajes->vacio()) {
        Personaje* eliminado = personajes->baja();
        delete eliminado;
    }
    delete personajes;
}*/

Menu::~Menu() {}

void Menu::cargar_personajes(string archivo) {
    personajes = new Diccionario();
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
    personajes->alta(nombre, nuevo);
}

void Menu::cargar_personaje_segun_elemento(string elemento, string nombre) {
    Personaje* nuevo;
    if(elemento == ELEMENTO_AGUA) nuevo = new Personaje_de_agua(nombre);
    else if(elemento == ELEMENTO_AIRE) nuevo = new Personaje_de_aire(nombre);
    else if(elemento == ELEMENTO_FUEGO) nuevo = new Personaje_de_fuego(nombre);
    else if(elemento == ELEMENTO_TIERRA) nuevo = new Personaje_de_tierra(nombre);
    personajes->alta(nombre, nuevo);
}

void Menu::agregar_nuevo_personaje() {
    string elemento = pedir_elemento_personaje();
    string nombre = pedir_nombre_personaje();
    cargar_personaje_segun_elemento(elemento, nombre);
}

/*void Menu::eliminar_personaje() {
    if(!personajes->vacio()) {
        string nombre = pedir_nombre_personaje();
        Personaje* eliminado = personajes->baja(nombre);
        if(eliminado) {
            delete eliminado;
            cout << "El personaje " << nombre << " fue eliminado" << endl;
        } else cout << "El personaje " << nombre << " no se encuentra en la lista" << endl;
    } else {
        cout << ERROR_DICCIONARIO_VACIO << endl;
    }
}*/

void Menu::mostrar_nombres_personajes() {
    if(!personajes->vacio())
        personajes->imprimir_inorden(personajes->obtener_raiz());
    else cout << ERROR_DICCIONARIO_VACIO << endl;
}

void Menu::detalles_personaje() {
    if(!personajes->vacio()) {
        string nombre = pedir_nombre_personaje();
        Personaje* solicitado = personajes->consulta(nombre);
        if(solicitado) {
            solicitado->mostrar_detalles();
        } else {
            cout << "El personaje " << nombre << " no existe" << endl;
        }
    } else {
        cout << ERROR_DICCIONARIO_VACIO << endl;
    }
}

void Menu::alimentar_personaje() {
    if(!personajes->vacio()) {
        string nombre = pedir_nombre_personaje();
        Personaje* solicitado = personajes->consulta(nombre);
        if(solicitado) {
            solicitado->alimentar();
        } else cout << "El personaje " << nombre << " no existe" << endl;
    } else {
        cout << ERROR_DICCIONARIO_VACIO << endl;
    }
}

void Menu::salir() {
    esta_activo = false;
}

void Menu::mensaje_bienvenida() {
    cout << MENSAJE_BIENVENIDA << endl;
}

void Menu::interfaz() {
    mensaje_bienvenida();
    esta_activo = true;
    while(esta_activo){
        mostrar_opciones();
        int opcion = pedir_opcion();
        switch(opcion)
        {
            case 1:
                agregar_nuevo_personaje();
                break;
            /*case 2:
                eliminar_personaje();
                break;*/
            case 3:
                mostrar_nombres_personajes();
                break;
            case 4:
                detalles_personaje();
                break;
            /*case 5:
                comenzar_juego();
                break;*/
            case 6:
                salir();
                break;
        }
    }
}

/*void Menu::comenzar_juego() {
    while(esta_activo && !juego.comenzo()){
        mostrar_opciones_submenu();
        int opcion = pedir_opcion();
        switch(opcion)
        {
            case 1:
                detalles_personaje();
                break;
            case 2:
                mostrar_nombres_personajes();
                break;
            case 3:
                seleccionar_personaje();
                break;
            case 4:
                salir();
                break;
        }
    }
    if(juego.comenzo()) menu_juego.jugar();
}
*/
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


void Menu::mostrar_opciones() {
    cout << "Elija una opcion (ingrese el numero): " << endl;
    cout << "1. " << AGREGAR_PERSONAJE << endl;
    cout << "2. " << ELIMINAR_PERSONAJE << endl;
    cout << "3. " << MOSTRAR_NOMBRES << endl;
    cout << "4. " << BUSCAR_DETALLES << endl;
    cout << "5. " << COMENZAR_JUEGO << endl;
    cout << "6. " << SALIR << endl;
}


void Menu::mostrar_opciones_submenu() {
    cout << "Elija una opcion (ingrese el numero): " << endl;
    cout << "1. " << BUSCAR_DETALLES << endl;
    cout << "2. " << MOSTRAR_NOMBRES << endl;
    cout << "3. " << SELECCIONAR_PERSONAJE << endl;
    cout << "4. " << SALIR << endl;
}

int Menu::pedir_opcion() {
    int opcion;
    while(true) {
        cin >> opcion;
        if(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6) return opcion;
        }
}

string Menu::pedir_elemento_personaje() {
    string elemento;
    while(true) {
        cout << "Ingrese el elemento del personaje (agua, aire, fuego o tierra): ";
        cin >> elemento;
        if(elemento == ELEMENTO_AGUA || elemento == ELEMENTO_AIRE || elemento == ELEMENTO_FUEGO || elemento == ELEMENTO_TIERRA) return elemento;
    }
}

string Menu::pedir_nombre_personaje() {
    string nombre;
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    return nombre;
}
