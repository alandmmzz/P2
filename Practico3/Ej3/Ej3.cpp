#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 3 Lista doblemente encadenada
Una variante de listas encadenadas es la llamada Lista Doblemente Encadenada. En dicha implementación cada elemento de la lista referencia al siguiente elemento y al elemento anterior. La Figura 2 presenta
una representación para esta variante.
(a) ¿Qué ventajas y desventajas presenta esta representación respecto a la presentada en la Figura 1?
(b) Implementar las siguientes operaciones utilizando la representación presentada en la Figura 2:
I. listaVacia: retorna una lista vacia.
II. insPrincipio: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.
III. esVacia: dada una lista l, verifica si l esta vacia.
IV. esElemento: dados un entero x y una lista l, verifica si x pertenece a l.
V. removerOcurrencias: dados un entero x y una lista l, retorna el resultado de eliminar todas las
ocurrencias de x de l.
VI. insOrd: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.
VII. remomverUltimo: dada una lista l ordenada, retorna el resultado de eliminar el último elemento de
l. Analice el orden del tiempo de ejecución. Proponga una representación con la que el orden del
tiempo de ejecución sea O(1).

*/

struct nodo_doble {
    int elem ;
    nodo_doble * sig;
    nodo_doble * ant;
};

typedef nodo_doble * lista;

lista listaVacia() {
    lista nuevaLista = NULL;
    return nuevaLista;
}

lista insPrincipio(lista &l, int x) {
    lista nuevo = new nodo_doble;
    nuevo->elem = x;
    nuevo->ant = NULL;
    nuevo->sig = l;
    if (l != NULL) {
        l->ant = nuevo;
    }
    l = nuevo;
    return l;
}

bool esElemento(lista l, int x) {
    while (l != NULL && l->elem != x) {
        l = l->sig;
    }
    return (l != NULL);
}

lista removerOcurrencias(lista &l, int x) {
    lista aBorrar, aux = NULL;
    aux = l;
    while (aux != NULL) {
        if (aux->elem == x) {
            aBorrar = aux;
            if (aux->ant != NULL) {
                aux->ant->sig = aux->sig;
            } else {
                l = aux->sig;
            }
            if (aux->sig != NULL) {
                aux->sig->ant = aux->ant;
            }
            aux = aux->sig;
            delete aBorrar;
        } else {
            aux = aux->sig;
        }
    }
    return l;
}

lista insOrd(lista &l, int x) {
    lista nuevo, aux = NULL;
    aux = l;
    nuevo = new nodo_doble;
    nuevo->elem = x;
    if (aux == NULL ) {
        nuevo->ant = NULL;
        nuevo->sig = NULL;
        l = nuevo;
        return l;
    }
    if (aux->elem > x ) {
        nuevo->ant = NULL;
        nuevo->sig = aux;
        aux->ant = nuevo;
        l = nuevo;
        return l;
    }
    while (aux->sig != NULL && aux->sig->elem < x) {
        aux = aux->sig;
    }
    if (aux->sig != NULL) {
        aux->sig->ant = nuevo;
        nuevo->ant = aux;
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    } else {
        nuevo->sig = NULL;
        nuevo->ant = aux;
        aux->sig = nuevo;
    }
    return l;
}

lista remomverUltimo(lista &l) {
    lista aBorrar, aux = NULL;
    aux = l;
    if (l == NULL) {
        return NULL;
    }
    while (aux->sig != NULL ) {
        aux = aux->sig;
    }
    aBorrar = aux;
    if (aux->ant != NULL) {
        aux->ant->sig = aux->sig;
    }
    delete aBorrar;
    return l;
}


void imprimirLista(lista l) {
    while(l) {
        printf("%d ", l->elem);
        l = l->sig;
    }
    printf("\n");
}

int main() {
    
}