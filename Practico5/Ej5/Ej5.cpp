#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 5
Se quieren implementar las siguientes operaciones sobre árboles generales de enteros (representados con
la semántica primer hijo, siguiente hermano) no vacíos y sin elementos repetidos:
(a) arbolHoja: Dado un entero x retorna un árbol que sólo contiene a x (como una hoja).
(b) esArbolHoja: Dado un árbol, retorna true si y solo si el árbol es un árbol hoja (tiene un solo elemento).
(c) pertenece: Dados un árbol y un entero x, retorna true si y solo si x pertenece al árbol.
(d) insertar: Dados un árbol y dos enteros h y p, inserta a h como el primer hijo de p en el árbol (hijo más
a la izquierda) si p pertenece al árbol y h no pertenece al árbol. En caso contrario la operación no tiene
efecto.
(e) borrar: Dados un árbol y un entero x, elimina a x del árbol si es una hoja del árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se debe liberar la
memoria asignada a él.
(f) borrarSub: Dados un árbol y un entero x, elimina a x del árbol, si pertenece al árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se deberá liberar la
memoria asignada a los elementos que están en el subárbol dependiente de éste.
*/

struct nodoAG {
    int dato ;
    nodoAG * pH ;
    nodoAG * sH ;
};

typedef nodoAG * AG ;

AG arbolHoja(uint x) {
    AG nuevo = new nodoAG;
    nuevo->dato = x;
    nuevo->sH = NULL;
    nuevo->pH = NULL;
    return nuevo;
}

bool esArbolHoja(AG g) {
    return (g != NULL && g->sH == NULL && g->pH == NULL);
}

bool pertenece(AG g, uint x) {
    if (g == NULL) return false;
    if (g->dato == x) return true;
    return pertenece(g->pH, x) || pertenece(g->sH, x);
}

void insertar(AG g, uint h, uint p) {
    if (g == NULL) return;
    if (g->dato == p) {
        AG nuevo = new nodoAG;
        nuevo->dato = h;
        nuevo->pH = NULL;
        if (g->pH == NULL) {
            nuevo->sH = NULL;
        } else {
            AG aux = g->pH;
            nuevo->sH = aux;
        }
        g->pH = nuevo;
    } else {
        if pertenece(g->pH, p) {
            insertar(g->pH, h, p);
        } else {
            insertar(g->sH, h, p);
        }
    }
}

void borrar(AG &g, uint x) {
    if (g == NULL) return;
    if (g->dato == x && esArbolHoja(g)) {
        AG borrar = g;
        g = g->sH;
        delete borrar;
    } else {
        borrar(g->pH, x);
        borrar(g->sH, x);
    }
}

void borrarSubAux(AG &g, uint x) {
    if (g == NULL) return;
    if (g->dato == x) {
        borrarSubAux(g->pH, g->pH->dato);
        borrarSubAux(g->sH, g->sH->dato);
        AG borrar = g;
        g = g->sH;
        delete borrar;
    } else {
        borrarSubAux(g->pH, x);
        borrarSubAux(g->sH, x);
    }
}

void borrarSub(AG &g, uint x) {
    if (g == NULL) return;
    if (esArbolHoja(g)) return;
    borrarSubAux(g, x);
}

void main() {
    
}