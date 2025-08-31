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

lista intercalarConDummy(lista l, lista p) {
    if (l == NULL && p == NULL) { // Dummy->sig da null, se puede sacar
        return NULL;
    } else {
        lista nuevaLista, aux, dummy;
        dummy = new nodo;
        aux = dummy;
        while (l != NULL && p != NULL) {
            aux->sig = new nodo;
            aux = aux->sig;
            if (l->elem < p->elem) {
                aux->elem = l->elem;
                l = l->sig;
            } else {
                aux->elem = p->elem;
                p = p->sig;
            }
        }
        while (l != NULL) {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->elem = l->elem;
            l = l->sig;
        }
        while (p != NULL) {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->elem = p->elem;
            p = p->sig;
        }
        aux->sig = NULL;
        nuevaLista = dummy->sig;
        delete dummy;
        return nuevaLista;
    }
}

lista concatenar(lista l, lista p) {
    if (l == NULL && p == NULL) {
        return NULL;
    } else {
        lista nuevaLista, aux;
        nuevaLista = new nodo;
        if (l != NULL) {
            nuevaLista->elem = l->elem;
            l = l->sig;
            aux = nuevaLista;
            while (l != NULL) {
                aux->sig = new nodo;
                aux = aux->sig;
                aux->elem = l->elem;
                l = l->sig;
            }
        } else {
            nuevaLista->elem = p->elem;
            p = p->sig;
            aux = nuevaLista;
        }
        while (p != NULL) {
            aux->sig = new nodo;
            aux = aux->sig;
            aux->elem = p->elem;
            p = p->sig;
        }
        aux->sig = NULL;
        return nuevaLista;
    }
}

lista concatenarConDummy(lista l, lista p) {
    lista dummy = new nodo;
    lista aux = dummy;

    while (l != NULL) {
        aux->sig = new nodo;
        aux = aux->sig;
        aux->elem = l->elem;
        l = l->sig;
    }

    while (p != NULL) {
        aux->sig = new nodo;
        aux = aux->sig;
        aux->elem = p->elem;
        p = p->sig;
    }

    aux->sig = NULL;
    lista nuevaLista = dummy->sig;
    delete dummy;
    return nuevaLista;
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