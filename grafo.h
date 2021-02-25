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
	
		int** distancias_p_agua[dim_fil*dim_col][dim_fil*dim_col];
		Vertice*** recorrido_p_agua[dim_fil*dim_col][dim_fil*dim_col];
	
		int** distancias_p_aire[dim_fil*dim_col][dim_fil*dim_col];
		Vertice*** recorrido_p_aire[dim_fil*dim_col][dim_fil*dim_col];
	
		int** distancias_p_fuego[dim_fil*dim_col][dim_fil*dim_col];
		Vertice*** recorrido_p_fuego[dim_fil*dim_col][dim_fil*dim_col];
	
		int** distancias_p_tierra[dim_fil*dim_col][dim_fil*dim_col];
		Vertice*** recorrido_p_tierra[dim_fil*dim_col][dim_fil*dim_col];
	
		int** distancias_ataque_tierra[dim_fil*dim_col][dim_fil*dim_col];

	public:
		Grafo(string nombre_archivo);
		void conectar_vertice(Vertice* vertice, Coordenada direccion, bool es_diagonal);
		void conectar_vertices();
		Lista* obtener_vertices();
		Vertice* acceder_tablero(Coordenada coordenada);
        ~Grafo();
	private:
		void buscar_vertices_adyacentes(Vertice* v);
		void cargar_mapa(string archivo);
		void cargar_tablero();
		Casillero* crear_casillero(string casillero);
		void crear_y_agregar_arista(Vertice* origen, Vertice* destino, bool es_diagonal);
		void destruir_matriz();
		Vertice* acceder_tablero(Coordenada coord);
		void floyd_warshall(string elemento, int** distancias, Vertice*** recorridos);
		void floyd_warshall();
		Vertice** camino_minimo(Personaje* pj, Coordenada nueva);
		int costo_camino_minimo(Vertice* origen, Vertice* destino);
		
		
		


};
#endif // GRAFO_H_INCLUDED
