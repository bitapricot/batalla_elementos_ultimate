#include <fstream>
#include <iostream>
#include "grafo.h"
using namespace std;

Grafo::Grafo(string nombre_archivo) {
	cargar_tablero(string nombre_archivo);
	conectar_vertices();
}


Grafo::cargar_tablero(string archivo_mapa) {
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
			
			for (j; j < dim_col-1; j++) {
				getline(archivo, casillero, ",");
				Casillero* nuevo_casillero = crear_casillero(casillero);
				Vertice* nuevo_vertice = Vertice(nuevo, i, j);
			}
		}
	}
	
	else {
		cout << "nonopepe" << endl;
		tablero = 0;
	}	
}

