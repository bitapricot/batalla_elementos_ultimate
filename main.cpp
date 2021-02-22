#include <iostream>
#include "menu.h"

int main() {

    Menu * menu = new Menu();
    menu->interfaz();

    delete menu;
    return 0;
}