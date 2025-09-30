#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 2 Funciones que no comparten memoria
Utilizando la representación para Lista Encadenada de Enteros de la Figura 1, implemente las siguientes
funciones en forma iterativa y sin usar procedimientos auxiliares. Las soluciones retornadas no deben
compartir memoria con los parámetros.
(a) obtenerPrimeros: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i
elementos de l.
(b) sinPrimeros: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de l.
(c) intercalar: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas
listas.
(d) concatenar: dadas dos listas l y p, retorna una lista que contiene a los elementos de l y luego a los
elementos de p, en el mismo orden. Comparar con la solución recursiva.
*/

struct nodo {
    int elem; nodo *sig;
};

typedef nodo *lista;

lista obtenerPrimeros(lista l, int i) {
    lista nuevaLista, aux = NULL;
    if (l == NULL || i < 1) {
        aux = NULL;
        nuevaLista = aux;
    } else {
        aux = new nodo;
        aux->elem = l->elem;
        nuevaLista = aux;
        for (int j = 1; j < i; j++) {
            if (l->sig != NULL) {
                aux->sig = new nodo;
                aux->sig->elem = l->sig->elem;
                l = l->sig;
                aux = aux->sig;
            }
        }
        aux->sig = NULL;
    }
    return nuevaLista;
}

lista sinPrimeros(lista l, int i) {
    lista nuevaLista, aux = NULL;
    for (int j = 0; j < i && l != NULL; j++) {
        l = l->sig;
    }
    if (l == NULL) {
        return NULL;
    } else {
        aux = new nodo;
        aux->elem = l->elem;
        nuevaLista = aux;
        while ( l->sig != NULL) {
            aux->sig = new nodo;
            aux->sig->elem = l->sig->elem;
            l = l->sig;
            aux = aux->sig;
        }
        aux->sig = NULL;
    }
    return nuevaLista;
}

lista intercalar(lista l, lista p) {
    if (l == NULL && p == NULL) {
        return NULL;
    } else {
        lista nuevaLista, aux;
        nuevaLista = new nodo;
        if (l != NULL && p != NULL) {
            if (l->elem < p->elem) {
                nuevaLista->elem = l->elem;
                l = l->sig;
            } else {
                nuevaLista->elem = p->elem;
                p = p->sig;
            }
        } else {
            if (l == NULL) {
                nuevaLista->elem = p->elem;
                p = p->sig;
            } else {
                nuevaLista->elem = l->elem;
                l = l->sig;
            }
        }
        aux = nuevaLista;
        if (l != NULL || p != NULL) {
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
            while (l != NULL && p == NULL) {
                aux->sig = new nodo;
                aux = aux->sig;
                aux->elem = l->elem;
                l = l->sig;
            }
            while (l == NULL && p != NULL) {
                aux->sig = new nodo;
                aux = aux->sig;
                aux->elem = p->elem;
                p = p->sig;
            }
        }
        aux->sig = NULL; 
        return nuevaLista;
    }
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