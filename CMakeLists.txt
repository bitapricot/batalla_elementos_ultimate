cmake_minimum_required(VERSION 3.13)
project(tp3)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "SFML-2.5.1/lib")
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(tp3 main.cpp Menu.cpp Menu.h diccionario.cpp diccionario.h nodo_diccionario.cpp nodo_diccionario.h personaje.cpp personaje.h
        personaje_de_tierra.h personaje_de_tierra.cpp personaje_de_fuego.h personaje_de_fuego.cpp personaje_de_aire.h personaje_de_aire.cpp
        personaje_de_agua.h personaje_de_agua.cpp jugador.cpp jugador.h juego.cpp casillero.cpp casillero.h precipicio.cpp precipicio.h
        vacio.cpp vacio.h volcan.cpp volcan.h montania.cpp montania.h lago.cpp lago.h camino.cpp camino.h juego.cpp juego.h grafo.cpp grafo.h
        vertice.cpp vertice.h coordenada.cpp coordenada.h arista.cpp arista.h lista.cpp lista.h nodo.cpp nodo.h main.cpp)

target_link_libraries (tp3 sfml-graphics sfml-window sfml-system sfml-audio)