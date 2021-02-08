#include "vertice.h"

class Grafo {
	private:
		Lista* aristas;
		Casillero* tablero;
	
	public:
		Grafo(string nombre_archivo);
		void conectar_vertices(Casillero* nuevo, int primero, int segundo); 
		
	private:
		void buscar_vertices_adyacentes(Vertice* nuevo);

};
