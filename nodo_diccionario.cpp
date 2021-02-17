#include "nodo_diccionario.h"

/*Nodo_diccionario::Nodo_diccionario(Clave clave, Valor valor, Nodo_diccionario* padre) {
    this->clave = clave;
    this->valor = valor;
    this->izq = NULL;
    this->der = NULL;
    this->padre = padre;
}*/

Nodo_diccionario::Nodo_diccionario(Clave clave, Valor valor) {
    this->clave = clave;
    this->valor = valor;
    this->izq = NULL;
    this->der = NULL;
    //this->padre = NULL;
}

Clave Nodo_diccionario::obtener_clave() {
    return this->clave;
}

Valor Nodo_diccionario::obtener_valor() {
    return this->valor;
}


/*void Nodo_diccionario::asignar_der(Nodo_diccionario* der, Nodo_diccionario* padre) {
    this->der = der;
    this->padre = padre;
}*/

void Nodo_diccionario::asignar_der(Nodo_diccionario* der) {
    this->der = der;
}

/*void Nodo_diccionario::asignar_izq(Nodo_diccionario* izq, Nodo_diccionario* padre) {
    this->izq = izq;
    this->padre = padre;
}*/

/*void Nodo_diccionario::asignar_padre(Nodo_diccionario *padre) {
    this->padre = padre;
}*/

void Nodo_diccionario::asignar_clave(Clave nueva) {
    this->clave = nueva;
}

void Nodo_diccionario::asignar_valor(Valor nuevo) {
    this->valor = nuevo;
}


void Nodo_diccionario::asignar_izq(Nodo_diccionario* izq) {
    this->izq = izq;
}

Nodo_diccionario* Nodo_diccionario::obtener_der() {
    return this->der;
}

Nodo_diccionario* Nodo_diccionario::obtener_izq() {
    return this->izq;
}

/*Nodo_diccionario* Nodo_diccionario::obtener_padre() {
    return this->padre;
}*/

bool Nodo_diccionario::es_hoja() {
    return (!this->obtener_izq() && !this->obtener_der());
}

bool Nodo_diccionario::solo_hijo_der() {
    return (!this->obtener_izq() && this->obtener_der());
}

bool Nodo_diccionario::solo_hijo_izq() {
    return (this->obtener_izq() && !this->obtener_der());
}


/*Nodo_diccionario::~Nodo_diccionario() {
    if(valor) delete valor;
}*/