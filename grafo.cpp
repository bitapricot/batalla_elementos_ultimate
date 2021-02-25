#include <fstream>
#include <iostream>
#include <string>
#include "grafo.h"
#include "camino.h"
#include "lago.h"
#include "montania.h"
#include "precipicio.h"
#include "vacio.h"
#include "volcan.h"
#include "lista.h"
using namespace std;

Grafo::Grafo(string nombre_archivo) {
    vertices = new Lista;
    int dim_fil = 0;
    int dim_col = 0;
	cargar_mapa(nombre_archivo);
	cargar_tablero();
	conectar_vertices();
	floyd_warshall(ELEMENTO_AGUA, distancias_p_agua, recorridos_p_agua);
	floyd_warshall(ELEMENTO_AIRE, distancias_p_aire, recorridos_p_aire);
	floyd_warshall(ELEMENTO_TIERRA, distancias_p_tierra, recorridos_p_tierra);
	floyd_warshall(ELEMENTO_FUEGO, distancias_p_fuego, recorridos_p_fuego);
	floyd_warshall();
}

Lista* Grafo::obtener_vertices() {
    return vertices;
}

/*void Grafo::buscar_vertices_adyacentes(Vertice* vertice) {
    if(obtener_vertice_arriba(vertice)) {
        Vertice* destino = obtener_vertice_arriba(vertice);
        crear_y_agregar_arista(vertice, destino);
    }
    if(obtener_vertice_abajo(vertice)) {
        Vertice* destino = obtener_vertice_abajo(vertice);
        crear_y_agregar_arista(vertice, destino);
    }
    if(obtener_vertice_izq(vertice)) {
        Vertice* destino = obtener_vertice_izq(vertice);
        crear_y_agregar_arista(vertice, destino);
    }
    if(obtener_vertice_der(vertice)) {
        Vertice* destino = obtener_vertice_der(vertice);
        crear_y_agregar_arista(vertice, destino);
    }
}*/


void Grafo::cargar_mapa(string archivo) {
	ifstream archivo_mapa;
	archivo_mapa.open(archivo);

	if (archivo_mapa) {

		int i = 0, j = 0;
		string casillero, dim;

		getline(archivo_mapa, dim, ',');
		dim_fil = stoi(dim);
		getline(archivo_mapa, dim);
		dim_col = stoi(dim);

		for (i; i < dim_fil; i++) {
			for (j; j < dim_col; j++) {
				getline(archivo_mapa, casillero, ',');
				Casillero* nuevo = crear_casillero(casillero);
				Vertice* nuevo_vertice = new Vertice(nuevo, i, j);
				vertices->alta(nuevo_vertice);
			}
			j = 0;
		}
	}

	else {
		cout << "nonopepe" << endl;
		tablero = 0;
	}
}


void Grafo::buscar_vertices_adyacentes(Vertice* vertice) {
    conectar_vertice(vertice, ARRIBA, false);
    conectar_vertice(vertice, ABAJO, false);
    conectar_vertice(vertice, IZQUIERDA, false);
    conectar_vertice(vertice, DERECHA, false);
    conectar_vertice(vertice, ARRIBA_IZQ, true);
    conectar_vertice(vertice, ARRIBA_DER, true);
    conectar_vertice(vertice, ABAJO_IZQ, true);
    conectar_vertice(vertice, ABAJO_DER, true);
}


void Grafo::conectar_vertice(Vertice* vertice, Coordenada direccion, bool es_diagonal) {
    Coordenada nueva = vertice->obtener_coordenadas() + direccion;
    Vertice* vertice_ady = vertices->consulta(nueva);
    if(vertice_ady) crear_y_agregar_arista(vertice, vertice_ady, es_diagonal);
}

void Grafo::conectar_vertices() {
    vertices->reiniciar();
	while (vertices->hay_siguiente()) {
		buscar_vertices_adyacentes(vertices->consulta(vertices->obtener_indice_actual()));
		vertices->siguiente();
	}
} // Guia para arturo


Casillero* Grafo::crear_casillero(string casillero) {

    Casillero* nuevo_casillero;

	if (casillero == CAMINO) nuevo_casillero = new Camino();
	else if (casillero == LAGO) nuevo_casillero = new Lago();
	else if (casillero == MONTANIA) nuevo_casillero = new Montania();
	else if (casillero == PRECIPICIO) nuevo_casillero = new Precipicio();
	else if (casillero == VACIO) nuevo_casillero = new Vacio();
	else nuevo_casillero = new Volcan();

	return nuevo_casillero;
}

void Grafo::crear_y_agregar_arista(Vertice* origen, Vertice* destino, bool es_diagonal) {
    Arista nueva;
    if(es_diagonal) nueva = Arista(origen, destino, 1);
    else nueva = Arista(origen, destino);
    origen->agregar_arista(nueva, es_diagonal);
}


/*
 * La idea aca entonces es implementar un operator+ y un operator=. Las constantes
 * de direccion van a guardar datos de tipo Coordenada, por ej, ARRIBA va a guardar
 * la coordenada (1,0). Y con el operator+ vamos a sumar eso a la posicion del
 * vertice en cuestion. Falta agregar las constantes estas.
 * No se si lo escribi muy entendible pero bueno me quiero ri a dormir slausos
 */
/*Vertice* Grafo::obtener_vertice_ady(Vertice* vertice, Coordenada direccion) {
    int i = vertice->obtener_coordenadas()->obtener_primera();
    int j = vertice->obtener_coordenadas()->obtener_segunda();

    Coordenada coord_ady;
    Vertice* vertice_ady = 0;

    if (direccion == ARRIBA) Coordenada coord_ady = Coordenada(i-1,j);
    else if (direccion == ABAJO) Coordenada coord_ady = Coordenada(i+1,j);
    else if (direccion == DERECHA) Coordenada coord_ady = Coordenada(i,j+1);
    else Coordenada coord_ady = Coordenada(i,j-1); // direccion == IZQUIERDA

    if(vertices->consulta(coord_ady)) vertice_ady = vertices->consulta(coord_ady);
    return vertice_ady;
}*/

void Grafo::cargar_tablero() {
    tablero = new Vertice**[dim_fil];
    for(int i = 0; i < dim_fil; i++) tablero[i] = new Vertice*[dim_col];
    int fila, columna;
    vertices->reiniciar();
    while(vertices->hay_siguiente()) {
        fila = vertices->consulta(vertices->obtener_indice_actual())->obtener_coordenadas().obtener_primera();
        columna = vertices->consulta(vertices->obtener_indice_actual())->obtener_coordenadas().obtener_segunda();
        tablero[fila][columna] = vertices->consulta(vertices->obtener_indice_actual());
        vertices->siguiente();
    }
}

Vertice* Grafo::acceder_tablero(Coordenada coordenada) {
    int f = coordenada.obtener_primera();
    int c = coordenada.obtener_segunda();
    return tablero[f][c];
}

void Grafo::floyd_warshall(string elemento, int** distancias, Vertice*** recorridos) { // este va en el constructor de grafo, le pasas todas las matrices atributo y su respectivo elemento para que las inicialice

    for(int i = 0; i < vertices->obtener_cantidad(); i++) {
        for(int j = 0; j < vertices->obtener_cantidad(); j++) {
            if(i == j) distancias[i][j] = 0;
            else distancias[i][j] = INFINITO;
        }
    }

    for(int i = 0; i < vertices->obtener_cantidad(); i++) {
        for(int j = 0; j < vertices->obtener_cantidad(); j++) {
            if(i == j) recorridos[j][i] = 0;
            else recorridos[j][i] = vertices->consulta(i);
        }
    }

    for(i = 0; i < vertices->obtener_cantidad(); i++) {
        for(int j = 0; j < vertices->consulta(i)->obtener_cantidad_aristas(); j++) {
            if(i != j && vertices->consulta(i)->hay_arista(vertices->consulta(j)), false) {
                Arista arista_act = vertices->consulta(i)->obtener_arista(j, false);
                int costo_act = arista_act.obtener_destino()->obtener_casillero()->calcular_costo(elemento);
                distancias[i][j] = costo_act;
            }
        }
    }

    for(int k = 0; k < vertices->obtener_cantidad(); k++) {
        for(i = 0; i < vertices->obtener_cantidad(); i++) {
            for(j = 0; j < vertices->obtener_cantidad(); j++) {
                if(distancias[i][j] > distancias[i][k] + distancias[k][j]) {
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                    recorridos[i][j] = recorridos[i][k];
                }
            }
        }
    }
}

Vertice** Grafo::camino_minimo(Personaje* pj, Coordenada nueva) {

    Vertice** camino[vertices->obtener_cantidad()];

    Coordenada actual = pj->obtener_coordenadas();
    Vertice* origen = vertices->consulta(actual);
    Vertice* destino = vertices->consulta(nueva);

    int numero_origen = dim_fila*origen->obtener_coordenadas().obtener_primera() + origen->obtener_coordenadas().segunda() + 1;
    int numero_destino = dim_fila*destino->obtener_coordenadas().obtener_primera() + destino->obtener_coordenadas().segunda() + 1;
    int i = 0;

    if(pj->de_que_elemento_soy() == AGUA) {
        while(destino != origen) {
            camino[i] = recorridos_p_agua[numero_origen][numero_destino];
            i++;
            destino = recorridos_p_agua[numero_vertice][numero_vertice];
            numero_destino = dim_fila*destino->obtener_coordenadas().obtener_primera() + destino->obtener_coordenadas().segunda() + 1;
        }
    } else if(pj->de_que_elemento_soy() == AIRE) {
        while(destino != origen) {
            camino[i] = recorridos_p_agua[numero_origen][numero_destino];
            i++;
            destino = recorridos_p_agua[numero_origen][numero_destino];
            numero_destino = dim_fila*destino->obtener_coordenadas().obtener_primera() + destino->obtener_coordenadas().segunda() + 1;
        }
    } else if(pj->de_que_elemento_soy() == FUEGO) {
        while(destino != origen) {
            camino[i] = recorridos_p_agua[numero_origen][numero_destino];
            i++;
            destino = recorridos_p_agua[numero_origen][numero_destino];
            numero_destino = dim_fila*destino->obtener_coordenadas().obtener_primera() + destino->obtener_coordenadas().segunda() + 1;
        }
    } else {
        while(origen != destino) {
            camino[i] = recorridos_p_agua[numero_origen][numero_destino];
            i++;
            destino = recorridos_p_agua[numero_origen][numero_destino];
            numero_destino = dim_fila*destino->obtener_coordenadas().obtener_primera() + destino->obtener_coordenadas().segunda() + 1;
        }
    }

    camino[i] = 0;

    return caminos;
}

int Grafo::costo_camino_minimo(Vertice* origen, Vertice* destino) {
    int costo = 0;

    int numero_origen = dim_fila*origen->obtener_coordenadas().obtener_primera() + origen->obtener_coordenadas().segunda() + 1;
    int numero_destino = dim_fila*destino->obtener_coordenadas().obtener_primera() + destino->obtener_coordenadas().segunda() + 1;

    costo = distancias[numero_origen][numero_destino];

    return costo;

}

void Grafo::floyd_warshall() { // sobrecarga de floyd warshall, simplemente arma la matriz de costos de distancias (en unidad casillero = 1) de cada vertice, contando diagonales

    for(int i = 0; i < vertices->obtener_cantidad(); i++) {
        for(int j = 0; j < vertices->obtener_cantidad(); j++) {
            if(i == j) distancias[i][j] = 0;
            else distancias[i][j] = INFINITO;
        }
    }

    for(i = 0; i < vertices->obtener_cantidad(); i++) {
        for(int j = 0; j < vertices->consulta(i)->obtener_cantidad_aristas(); j++) {
            if(i != j && vertices->consulta(i)->hay_arista(vertices->consulta(j)), true) {
                Arista arista_act = vertices->consulta(i)->obtener_arista(j, true);
                distancias[i][j] = 1; // el costo en unidad de casillero, digamos como la distancia es 1, el costo es 1
            }
        }
    }

    for(int k = 0; k < vertices->obtener_cantidad(); k++) {
        for(i = 0; i < vertices->obtener_cantidad(); i++) {
            for(j = 0; j < vertices->obtener_cantidad(); j++) {
                if(distancias[i][j] > distancias[i][k] + distancias[k][j]) {
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                }
            }
        }
    }
}

Grafo::~Grafo() {
    while(!vertices->vacia()) {
        Vertice* eliminar = vertices->baja_y_devuelve(0);
        delete eliminar;
    }
    delete vertices;
    for(int i = 0; i < dim_fil; i++) {
        delete [] tablero[i];
    }
    delete [] tablero;
}
