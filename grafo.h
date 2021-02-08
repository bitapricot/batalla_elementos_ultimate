#include "vertice.h"


class Grafo {
	private:
		Lista* aristas;
		Vertice* tablero;
	
	public:
		Grafo(string nombre_archivo);
		void conectar_vertices(); 
		
	private:
		void buscar_vertices_adyacentes(Vertice* nuevo);
		void cargar_tablero(string archivo_mapa);
		void crear_casillero(string casillero);

};
