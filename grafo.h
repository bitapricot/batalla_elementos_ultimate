#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "vertice.h"

class Grafo {
	private:
		Lista* vertices;
		Vertice* tablero;
	
	public:
		Grafo(string nombre_archivo);
		void conectar_vertices();
		
	private:
		void buscar_vertices_adyacentes(Vertice* nuevo);
		void cargar_tablero(string archivo_mapa);
		Casillero* crear_casillero(string casillero);
		void crear_y_agregar_arista(Vertice origen, Vertice destino);
		void destruir_matriz(); // para el destructor
		// tambien hay que destruir el grafo: aristas, lista de aristas, vertices, lista de vertices
		// falta pensar un metodo para eso
		~Grafo();


};
#endif // GRAFO_H_INCLUDED
