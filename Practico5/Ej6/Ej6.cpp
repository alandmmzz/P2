#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 6 Primer Parcial 2017
Defina una función recursiva copiaParcial que dados un árbol g de tipo AG y un entero positivo k, retorne
una copia de g, sin compartir memoria con éste, con todos los nodos que están en un nivel menor o igual a
k. En un árbol no vacío la raíz está en el nivel 1. Si g es vacío o k es cero, el resultado debe ser el árbol vacío.
Asuma que g->sH es NULL. No use operaciones auxiliares propias en la implementación de copiaParcial.
*/

struct nodoAG {
    int dato ;
    nodoAG * pH ;
    nodoAG * sH ;
};

typedef nodoAG * AG ;

AG copiaParcial ( AG g , uint k ) {
    if (g == NULL) return NULL;
    if (k == 0) return NULL;
    AG nuevo = new nodoAG;
    nuevo->dato = g->dato;
    nuevo->pH = copiaParcial(g->pH, k-1);
    nuevo->sH = copiaParcial(g->sH, k);
    return nuevo;
}

void main() {
    
}