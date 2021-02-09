#include <fstream>
#include <iostream>
#include "grafo.h"
using namespace std;

Grafo::Grafo(string nombre_archivo) {
	cargar_tablero(string nombre_archivo);
	conectar_vertices();
}


void Grafo::buscar_vertices_adyacentes(Vertice* vertice) {
	
}


void Grafo::cargar_tablero(string archivo_mapa) {
	ifstream archivo_mapa;
	archivo_mapa.open(nombre_archivo);
	
	if (archivo_mapa) {
		
		int dim_fila, dim_col;
		int i = 0, j = 0;
		string casillero, dim;

		getline(archivo, dim, ",");
		dim_fila = stoi(dim);
		getline(archivo, dim);
		dim_col = stoi(dim);
		
		for (i; i < dim_fila; i++) {
			getline(archivo, casillero);
			crear_casillero(casillero);
			Vertice* nuevo_vertice = Vertice(nuevo, i, j);

			
			for (j; j < dim_col-1; j++) {
				getline(archivo, casillero, ",");
				Casillero* nuevo_casillero = crear_casillero(casillero);
				Vertice* nuevo_vertice = Vertice(nuevo, i, j);
				vertices->alta(nuevo_vertice);
			}
		}
	}
	
	else {
		cout << "nonopepe" << endl;
		tablero = 0;
	}	
}


void Grafo::conectar_vertices() {
	while (vertices->hay_siguiente()) {
		buscar_vertices_adyacentes(vertices->obtener_actual());
		vertices->siguiente();
	}
}


Casillero* Grafo::crear_casillero(string casillero) {
	
	if (casillero == CAMINO) nuevo_casillero = new Camino();
	else if (casillero == LAGO) nuevo_casillero = new Lago();
	else if (casillero == MONTANIA) nuevo_casillero = new Montania();
	else if (casillero == PRECIPICIO) nuevo_casillero = new Precipicio();
	else if (casillero == VACIO) nuevo_casillero = new Vacio();
	else nuevo_casillero = new Volcan();
	
	return nuevo_casillero;
}
