#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 3 Deque
Una Deque es una cola con dos extremos, donde las inserciones y las supresiones pueden efectuarse en
cualquiera de ellos.
(a) Escribir un módulo de definición del TAD Deque no acotada de enteros que incluya procedimientos
para:
I. Crear una Deque vacía.
II. Realizar las inserciones y bajas permitidas.
III. Obtener los elementos situados en los extremos.
IV. Determinar si una Deque es vacía o no.
(b) Desarrolle una implementación completa de tal manera que el tiempo de ejecución de todas las operaciones seaO(1) en el peor caso.

*/

struct nodo {
    int elem; 
    nodo *sig;
};

struct headDQ {
    nodo * front;
    nodo * rear;
};

typedef headDQ *DQEnt;

/* CREADOR */
DQEnt nullDQ() {
    DQEnt nuevo = new headDQ;
    nuevo->front = NULL;
    nuevo->rear = NULL;
    return nuevo;
}

/* PREDICADO */
bool isEmpty(DQEnt q) {
    return (q->front == NULL);
}

/* DESTRUCTORA */
/* PreCond !isEmpty(q) */
void ereaseDQ(DQEnt &q) {
    while(q->front != NULL) {
        nodo * borrar = q->front;
        q->front = q->front->sig;
        delete borrar;
    }
    delete q;
}

/* ENCOLAR */
void enqueueFront(int x, DQEnt &q) {
    nodo * nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;
    if (q->front == NULL) {
        q->front = nuevo;
        q->rear = nuevo;
    } else {
        nuevo->sig = q->front;
        q->front = nuevo;
    }
}

void enqueueRear(int x, DQEnt &q) {
    nodo * nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;
    if (q->front == NULL) {
        q->front = nuevo;
    } else {
        q->rear->sig = nuevo;
    }
    q->rear = nuevo;
}

/* DESENCOLAR */
/* PreCoond !isEmpty(q) */
void dequeueFront(DQEnt &q) {
    nodo * borrar = q->front;
    q->front = q->front->sig;
    delete borrar;
}

void dequeueRear(DQEnt &q) {
    nodo * aux = q->front, borrar = q->rear;
    if (aux->sig == NULL) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        while (aux->sig->sig != NULL) {
            aux = aux->sig;
        }
        q->rear = aux;
    }
    delete borrar;
}

/* SELECTORES */
/* PreCoond !isEmpty(q) */
int frontDQ(DQEnt &q) {
    return q->front->elem;
}

int rearDQ(DQEnt &q) {
    return q->rear->elem;
}

void main() {
    
}