
#include "Nodo.h"
#include <string>

Nodo::Nodo(Clave clave, Valor valor, Nodo* padre) {
    izq = nullptr;
    der = nullptr;
    this->padre = padre;
    this->clave = clave;
    this->valor = valor;
}

Clave Nodo::obtener_clave() {
    return this->clave;
}

void Nodo::asignar_clave(Clave clave) {
    this->clave = clave;
}


void Nodo::insertar_padre(Nodo* padre) {
    this->padre = padre;
}

//void Nodo::cambiar_dato(Value valor) {
//    this->valor = valor;
//}


void Nodo::insertar_izq(Nodo* izq) {
    this->izq = izq;
}

Nodo* Nodo::obtener_der() {
    return this->der;
}

void Nodo::insertar_der(Nodo* der) {
    this->der = der;
}

Nodo* Nodo::obtener_izq() {
    return this->izq;
}

Nodo* Nodo::obtener_padre() {
    return this->padre;
}

bool Nodo::es_hoja() {
    return (!this->obtener_izq() && !this->obtener_der());
}

bool Nodo::solo_hijo_der() {
    return (!this->obtener_izq() && this->obtener_der());
}

bool Nodo::solo_hijo_izq() {
    return (this->obtener_izq() && !this->obtener_der());
}

Valor Nodo::obtener_valor() {
    return valor;
}

void Nodo::copiar_nodo(Nodo* n) {
    this->izq = n->obtener_izq();
    this->der = n->obtener_izq();
    this->padre = n->obtener_padre();
    this->clave = n->obtener_clave();
    this->valor = n->obtener_valor();
}
