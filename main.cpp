#include <iostream>
#include "menu.h"
#include "personaje.h"
#include "personaje_de_agua.h"
#include "personaje_de_aire.h"
#include "personaje_de_fuego.h"
#include "personaje_de_tierra.h"

using namespace std;

int main()
{
    /*Menu nuevo_menu;
    nuevo_menu.cargar_personajes("personajes.csv");
    nuevo_menu.interfaz();*/
    Diccionario* nuevo = new Diccionario;
    Personaje* p1 = new Personaje_de_agua("a");
    Personaje* p2 = new Personaje_de_fuego("frank");
    Personaje* p3 = new Personaje_de_tierra("cami");
    nuevo->alta("frank", p2);
    nuevo->alta("a", p1);
    nuevo->alta("cami", p3);
    nuevo->imprimir_inorden(nuevo->obtener_raiz());
    Nodo* minimo = nuevo->buscar_min(nuevo->obtener_raiz());
    cout << "el minimo es " << minimo->obtener_clave() << endl;
    nuevo->baja("a");
    nuevo->baja("cami");
    nuevo->baja("frank");
    delete p1;
    delete p2;
    delete p3;
    delete nuevo; // ac se produce el segdault MAURIIIIIII
}
