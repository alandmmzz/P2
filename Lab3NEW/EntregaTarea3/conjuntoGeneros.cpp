#include "../include/conjuntoGeneros.h"

struct rep_conjuntogeneros{
    bool* elementos;
    int cantidad;
    int capacidad;
};

TConjuntoGeneros crearTConjuntoGeneros(int cantMax){
    TConjuntoGeneros nuevoConjunto = new rep_conjuntogeneros;
    nuevoConjunto->elementos = new bool[cantMax];
    for(int i = 0; i < cantMax; i++){
        nuevoConjunto->elementos[i] = false;
    }
    nuevoConjunto->cantidad = 0;
    nuevoConjunto->capacidad = cantMax;
    return nuevoConjunto;
}

bool esVacioTConjuntoGeneros(TConjuntoGeneros c){
    return (c == NULL || c->cantidad == 0);
}

void insertarTConjuntoGeneros(TConjuntoGeneros &c, int id){
    if (c != NULL && id < c->capacidad && !(c->elementos[id])) {
        c->elementos[id] = true;
        c->cantidad++;
    }
}

void borrarDeTConjuntoGeneros(TConjuntoGeneros &c, int id){
    if (c != NULL && id < c->capacidad && c->elementos[id]) {
        c->elementos[id] = false;
        c->cantidad--;
    }
}

bool perteneceTConjuntoGeneros(TConjuntoGeneros c, int id){
    return (id < c->capacidad && c->elementos[id]);
}

int cardinalTConjuntoGeneros(TConjuntoGeneros c){
    return (c->cantidad);
}

int cantMaxTConjuntoGeneros(TConjuntoGeneros c){
    return (c->capacidad);
}

void imprimirTConjuntoGeneros(TConjuntoGeneros c){
    bool yaImprimio = false;
    for (int i = 0; i < cantMaxTConjuntoGeneros(c); i++) {
        if (c->elementos[i]) {
            if (yaImprimio) {
                printf(" %d", i);
            } else {
                printf("%d", i);
                yaImprimio = true;
            }
        }
    }
    printf("\n");
}

void liberarTConjuntoGeneros(TConjuntoGeneros &c){
    if (c != NULL) {
        delete[] c->elementos;
        delete c;
        c = NULL;
    }
}

TConjuntoGeneros unionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2){
    TConjuntoGeneros nuevoConjunto = crearTConjuntoGeneros(cantMaxTConjuntoGeneros(c1));
    for (int i = 0; i < cantMaxTConjuntoGeneros(c1); i++) {
        if (c1->elementos[i] || c2->elementos[i]) {
            nuevoConjunto->elementos[i] = true;
            nuevoConjunto->cantidad++;
        }
    }
    return nuevoConjunto;
}

TConjuntoGeneros interseccionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2){
    TConjuntoGeneros nuevoConjunto = crearTConjuntoGeneros(cantMaxTConjuntoGeneros(c1));
    for (int i = 0; i < cantMaxTConjuntoGeneros(c1); i++) {
        if (c1->elementos[i] && c2->elementos[i]) {
            nuevoConjunto->elementos[i] = true;
            nuevoConjunto->cantidad++;
        }
    }
    return nuevoConjunto;
}

TConjuntoGeneros diferenciaTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2){
    TConjuntoGeneros nuevoConjunto = crearTConjuntoGeneros(cantMaxTConjuntoGeneros(c1));
    for (int i = 0; i < cantMaxTConjuntoGeneros(c1); i++) {
        if (c1->elementos[i] && !(c2->elementos[i])) {
            nuevoConjunto->elementos[i] = true;
            nuevoConjunto->cantidad++;
        }
    }
    return nuevoConjunto;
}
