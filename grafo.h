#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "lista.h"
#include "vertice.h"
const Coordenada ARRIBA = Coordenada(-1,0);
const Coordenada ABAJO= Coordenada(1,0);
const Coordenada IZQUIERDA= Coordenada(0,-1);
const Coordenada DERECHA= Coordenada(0,1);

class Grafo {
	private:
		Lista* vertices;
		Vertice* tablero;
	
	public:
		Grafo(string nombre_archivo);
		void conectar_vertice(Vertice* vertice, Coordenada direccion);
		
	private:
		void buscar_vertices_adyacentes(Vertice* nuevo);
		void cargar_tablero(string archivo);
		Casillero* crear_casillero(string casillero);
		void crear_y_agregar_arista(Vertice* origen, Vertice* destino);
		void destruir_matriz(); // para el destructor
		// tambien hay que destruir el grafo: aristas, lista de aristas, vertices, lista de vertices
		// falta pensar un metodo para eso
		Vertice* obtener_vertice_ady(Vertice vertice, Coordenada direccion); // ALERTA ALERTA ALERTA VER .CPP
		~Grafo();


};
#endif // GRAFO_H_INCLUDED
