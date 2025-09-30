#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 4 Lista indizada (Manejo explícito de posiciones)
Una variante importante de listas son las Listas con manejo explícito de posiciones (a veces llamadas Listas
Indizadas).
En estas listas, se manipulan los elementos mediante posiciones, generalizando la idea de los arreglos
para estructuras no acotadas. La posición del primer elemento es la posición 0. Se dice que la posición p
está definida si está entre 0 y m -1, siendo m la longitud de la lista. Utilizando la representación de lista
simplemente encadenada, implemente las siguientes operaciones:
(a) estaDefinido: dados un natural p y una lista l, retorna verdadero si, y solamente si, existe un elemento
en esa posición.
(b) insertar: dados un entero x, un natural p y una lista l de longitud m, inserta a x en la lista. Si p no
esta definida, inserta a x en la posición m. En otro caso, inserta a x en la posición p y desplaza en una
posición los elementos que estuvieran en las posiciones siguientes.
(c) elemento: dados un natural p y una lista l, retorna el elemento en la posición p. Tiene como precondición
que la posición p esté definida.
(d) remover: dados un natural p y una lista l, elimina de la lista el elemento que se encuentra en la posición
p. Si la posición no está definida, la operación no tiene efecto. Si la posición está definida, elimina el
elemento en dicha posición y desplaza en una posición los elementos que estuvieran en las posiciones
posteriores a p (contrae la lista).
(e) ¿Cambia el orden del tiempo de ejecución en el peor caso de las operaciones con respecto a la implementación de la Figura 1?
*/

struct nodo {
    int elem ;
    nodo * sig;
};

typedef nodo * lista;

bool estaDefinido(lista l, int p) {
    int i;
    for (i = 0; i < p && l != NULL; i++) {
        l = l->sig;
    }
    return (i == p);
}

lista insertar(lista &l, int x, int p) {
    lista aux, nuevo = l;
    aux = l;
    nuevo = new nodo;
    nuevo->elem = x;
    if (l == NULL) {
        nuevo->sig = NULL;
        l = nuevo;
        return l;
    }
    if (p == 0) {
        nuevo->sig = aux;
        l = nuevo;
        return l;
    }
    if (estaDefinido(l, p)) {
        for (int i = 1; i < p; i++) {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    } else {
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->sig = NULL;
    }
    return l;
}

int elemento(lista l, int p) {
    for (int i = 0; i < p; i++) {
        l = l->sig;
    }
    return (l->elem);
}

lista remover(lista &l, int p) {
    lista aBorrar, aux = NULL;
    aux = l;
    if (p == 0) {
        aBorrar = aux;
        l = l->sig;
    } else {
        for (int i = 0; i < p - 1; i++) {
            aux = aux->sig;
        }
        aBorrar = aux->sig;
        aux->sig = aux->sig->sig;
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