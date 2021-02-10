cmake_minimum_required(VERSION 3.17)
project(batalla_elementos_pt2)

set(CMAKE_CXX_STANDARD 14)

add_executable(batalla_elementos_pt2 main.cpp arista.cpp arista.h camino.cpp camino.h coordenada.cpp
        coordenada.h casillero.cpp casillero.h diccionario.cpp diccionario.h grafo.cpp grafo.h
        juego.h lago.cpp lago.h lista.cpp lista.h menu.cpp menu.h montania.cpp montania.h nodo.cpp
        nodo.h nodo_diccionario.cpp nodo_diccionario.h personaje.cpp personaje.h personaje_de_agua.cpp
        personaje_de_agua.h personaje_de_aire.cpp personaje_de_aire.h personaje_de_fuego.cpp
        personaje_de_fuego.h personaje_de_tierra.cpp personaje_de_tierra.h precipicio.cpp precipicio.h
        vacio.cpp vacio.h vertice.cpp vertice.h volcan.cpp volcan.h)