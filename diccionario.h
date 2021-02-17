#include "nodo_diccionario.h"
#include<iostream>

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

class Diccionario
{
private:
    // attributes
    Nodo_diccionario* raiz;
    Nodo_diccionario* actual;

    // methods
    Nodo_diccionario* insertar(Nodo_diccionario* nodo, Clave clave, Valor valor);
    void imprimir_inorden(Nodo_diccionario * nodo);
    Nodo_diccionario* buscar(Nodo_diccionario* nodo, Clave clave);
    Clave buscar_min(Nodo_diccionario* nodo);
    //Clave sucesor(Nodo_diccionario* nodo);
    //Nodo_diccionario* eliminar(Nodo_diccionario* nodo, Clave clave);
    void eliminar_todos(Nodo_diccionario* nodo);
    void reiniciar();

    Nodo_diccionario* _eliminar(Nodo_diccionario* r, Clave v);


public:
    //methods

    // Creates an vacio tree
    Diccionario();

    // Adds a new nodo to the actual Diccionario. If its the tree is vacio
    // the nodo insertared will be the raiz
    void insertar(Clave clave, Valor valor);

    // Prints all the data stored in the Diccionario, sorted from the
    // smallest value to the greatest value.
    void imprimir_inorden();

    // Finds a given value in the Diccionario. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool buscar(Clave clave);

    // Finds the minimum value that exist in the Diccionario.
    //Clave buscar_min();

    // Finds the sucesor of a given data value.
    //Clave sucesor(Clave clave);

    // eliminars a given data from the Diccionario
    //void eliminar(Clave clave);

    Nodo_diccionario* obtener_raiz();

    bool vacio();

    // Deletes all the nodos in the Diccionario
    void eliminar_todos();

    Valor consulta(Clave clave);

    void claves_inorden(Nodo_diccionario* aux, string &claves);

    void eliminar(Clave borrar);

    Nodo_diccionario* minimo(Nodo_diccionario* nodo);

    Nodo_diccionario* buscar_sucesor(Nodo_diccionario* nodo);

    ~Diccionario();
};
#endif //ABB_Diccionario_H