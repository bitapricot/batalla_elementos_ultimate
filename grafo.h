#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "lista.h"
#include "vertice.h"

const int MIN_CANT_ARISTAS = 2;

const Coordenada ARRIBA = Coordenada(-1,0);
const Coordenada ABAJO= Coordenada(1,0);
const Coordenada IZQUIERDA= Coordenada(0,-1);
const Coordenada DERECHA= Coordenada(0,1);

const Coordenada ARRIBA_IZQ = Coordenada(-1,-1);
const Coordenada ABAJO_IZQ = Coordenada(1,-1);
const Coordenada ARRIBA_DER = Coordenada(-1,1);
const Coordenada ABAJO_DER = Coordenada(1,1);

class Grafo {
	private:
		Lista* vertices;
		int dim_fil;
		int dim_col;
		Vertice*** tablero;

	public:
		Grafo(string nombre_archivo);
		void conectar_vertice(Vertice* vertice, Coordenada direccion, bool es_diagonal);
		void conectar_vertices();
		Lista* obtener_vertices();
		Vertice* acceder_tablero(int f, int c);
        ~Grafo();
	private:
		void buscar_vertices_adyacentes(Vertice* nuevo);
		void cargar_mapa(string archivo);
		void cargar_tablero();
		Casillero* crear_casillero(string casillero);
		void crear_y_agregar_arista(Vertice* origen, Vertice* destino, bool es_diagonal);
		void destruir_matriz(); // para el destructor
		// tambien hay que destruir el grafo: aristas, lista de aristas, vertices, lista de vertices
		// falta pensar un metodo para eso
		Vertice* obtener_vertice_ady(Vertice vertice, Coordenada direccion); // AGREGAR DIAGONALES


};
#endif // GRAFO_H_INCLUDED
