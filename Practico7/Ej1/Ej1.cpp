#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 1 Lista
Considere el siguiente conjunto de operaciones. Las mismas especifican el TAD Lista de enteros (que
presenta el mismo comportamiento LIFO que una Pila).
(a) Dé una implementación completa (tipo y operaciones) para el TAD Lista no ordenada que garantice
que el tiempo de ejecución de las operaciones sea O(1).
(b) ¿Qué cambios realizaría si insFinal fuera parte del TAD?
*/

struct nodo {
    int elem; nodo *sig;
};

typedef nodo *LEnt;

/* Crea la lista vacia. */
LEnt crearL () {
    return NULL;
}

/* Inserta el entero x al principio de la lista . */
void insertar ( int x , LEnt & l ) {
    Lent nuevo = new nodo;
    nuevo->elem = x;
    x->sig = l;
    l = x;
}

/* Verifica si la lista est á vac ía. */
bool esVacia ( LEnt l) {
    return (l == NULL)
}

/* Devuelve el primer elemento de una lista .
Pre : ! esVacia (l) */
int primero ( LEnt l ) {
    return l->elem;
}

/* Devuelve la lista l sin su primer elemento .
Pre : ! esVacia (l) */
void resto ( LEnt & l ) {
    Lent aborrar = l;
    l = l->sig;
    delete aborrar;
}

void main() {
    
}