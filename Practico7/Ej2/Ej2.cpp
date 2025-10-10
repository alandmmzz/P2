#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 2 Cola
(a) Escribir un módulo de especificación para el TAD Cola (Queue) no acotada de enteros, conteniendo un conjunto mínimo de operaciones. 
Desarrolle una especificación haciendo mayormente uso de procedimientos y no de funciones.
(b) Desarrolle una implementación completa de tal manera que el tiempo de ejecución de todas las operaciones sea O(1) en el peor caso.
(c) ¿Qué modificaría en la especificación para el TAD Cola (Queue) acotada de enteros? Desarrolle una
especificación haciendo mayormente uso de procedimientos y no de funciones.
(d) Desarrolle una implementación completa de Cola (Queue) acotada usando una estructura con manejo
estático de memoria (la memoria asignada a la estructura no debe variar en tiempo de ejecución) y otra
usando una estructura con manejo dinámico de memoria, de tal manera que el tiempo de ejecución de
todas las operaciones sea O(1) en el peor caso para ambas implementaciones. Analice las eventuales
ventajas y desventajas de ambas implementaciones.
*/

struct nodo {
    int elem; 
    nodo *sig;
};

struct headQ {
    nodo * front;
    nodo * rear;
}

typedef headQ *QEnt;

/* CREADOR */
QEnt nullQ() {
    QEnt nuevo = new headQ;
    nuevo->front = NULL;
    nuevo->rear = NULL;
    return nuevo;
}

/* PREDICADO */
bool isEmpty(QEnt q) {
    return (q->front == NULL);
}

/* DESTRUCTORA */
/* PreCond !isEmpty(q) */
void ereaseQ(QEnt &q) {
    while(q->front != NULL) {
        nodo * borrar = q->front;
        q->front = q->front->sig;
        delete borrar;
    }
    delete q;
}

/* ENCOLAR */
void enqueue(int x, QEnt &q) {
    nodo nuevo = new nodo;
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
void dequeue(int x, QEnt &q) {
     QEnt borrar = q->front;
     q->front = q->front->sig;
     delete borrar
}

/* SELECTORES *
/* PreCoond !isEmpty(q) */
int frontQ(QEnt &q) {
    return q->front->elem;
}

void main() {
    
}