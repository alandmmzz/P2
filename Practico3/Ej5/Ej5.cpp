#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 5 Lista circular
Otra variante para listas encadenadas es la llamada Lista Encadenada Circular. En esta implementación,
la gran diferencia radica en que el último elemento de la lista referencia al primero.
(a) Esta parte será resuelta utilizando la representación presentada en la Figura 1.
I. listaVacia: retorna una lista vacia.
II. esVacia: dada una lista l, verifica si l esta vacia.
III. resto: dada una lista l no vacia, retorna la lista sin su primer elemento.
IV. ultimo: dada una lista l no vacia, retorna su ultimo elemento.
V. insOrden: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.
(b) ¿ Qué alternativas de representación (diferente a la de las Figuras 1 y 2) pueden ser utilizadas para
representar listas circulares?
(c) Calcular y comparar los órdenes de las operaciones de la parte a en base a las representaciones de la
parte b.
(d) ¿Qué ventajas y desventajas presentan dichas alternativas respecto a las presentadas en las Figuras 1
y 2?
*/

struct nodo {
    int elem ;
    nodo * sig;
};

typedef nodo * lista;

lista listaVacia() {
    return NULL;
}

bool esVacia(lista l) {
    return (l == NULL);
}

lista resto(lista &l) {
    lista aBorrar, aux = l;
    aBorrar = l;
    l = l->sig;
    if (aux->sig == l) {
        return NULL;
    }
    while (aux->sig != aBorrar) {
        aux = aux->sig;
    }
    delete aBorrar;
    aux->sig = l;
    return l;
}

int ultimo(lista l) {
    lista aux = l;
    while (aux->sig != l) {
        aux = aux->sig;
    }
    return (aux->elem);
}

lista insOrden(lista &l, int x) {
    lista nuevo, aux = NULL;
    nuevo = new nodo;
    nuevo->elem = x;
    aux = l;
    if (l == NULL) {
        nuevo->sig = nuevo;
        l = nuevo;
        return l;
    }
    if (aux->elem > x) {
        nuevo->sig = l;
        l = nuevo;
    } else {
        while (aux->sig != l && aux->sig->elem < x) {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
    while (aux->sig != l) {
        aux = aux->sig;
    }
    aux->sig = l;
    return l;
}

void imprimirLista(lista l) {
    if (l == NULL) return;  // lista vacía
    lista aux = l;
    do {
        printf("%d ", aux->elem);
        aux = aux->sig;
    } while (aux != l);  // cuando volvemos al head, terminamos
    printf("\n");
}

int main() {
    
}