#include "../include/colaReservas.h"

struct nodo_colaReservas {
    TReserva reserva; 
    nodo_colaReservas * sig;
};

struct rep_colaReservas {
    nodo_colaReservas * front;
    nodo_colaReservas * rear;
};

TColaReservas crearTColaReservas(){
    TColaReservas nuevo = new rep_colaReservas;
    nuevo->front = NULL;
    nuevo->rear = NULL;
    return nuevo;
}

void liberarTColaReservasSoloEstructura(TColaReservas &colaReservas) {
    if (colaReservas == NULL) return;
    nodo_colaReservas * borrar;
    while (colaReservas->front != NULL) {
        borrar = colaReservas->front;
        colaReservas->front = colaReservas->front->sig;
        liberarTReservaSoloEstructura(borrar->reserva);
        delete borrar;
    }
    delete colaReservas;
    colaReservas = NULL;
}

void encolarTColaReservas(TColaReservas &colaReservas, TReserva reserva){
    if (colaReservas->rear == NULL) {
        nodo_colaReservas * nuevoNodo = new nodo_colaReservas;
        nuevoNodo->reserva = reserva;
        nuevoNodo->sig = NULL;
        colaReservas->front = nuevoNodo;
        colaReservas->rear = nuevoNodo;
    } else {
        nodo_colaReservas * nuevoNodo = new nodo_colaReservas;
        nuevoNodo->reserva = reserva;
        nuevoNodo->sig = NULL;
        colaReservas->rear->sig = nuevoNodo;
        colaReservas->rear = nuevoNodo;
    }
}

void desencolarTColaReservas(TColaReservas &colaReservas) {
    nodo_colaReservas * borrar = colaReservas->front;
    colaReservas->front = colaReservas->front->sig;
    if (colaReservas->front == NULL) {
        colaReservas->rear = NULL;
    }
    liberarTReserva(borrar->reserva);
    delete borrar;
}

TReserva frenteTColaReservas(TColaReservas colaReservas) {
    if (colaReservas == NULL) return NULL;
    return colaReservas->front->reserva;
}

nat cantidadTColaReservas(TColaReservas colaReservas){
    if (colaReservas == NULL) return 0;
    nat contador = 0;
    nodo_colaReservas * actual = colaReservas->front;
    while (actual != NULL) {
        contador++;
        actual = actual->sig;
    }
    return contador;
}

void imprimirTColaReservas(TColaReservas colaReservas){
    printf("Cola de Reservas:\n");
    nodo_colaReservas * actual = colaReservas->front;
    while (actual != NULL) {
        imprimirTReserva(actual->reserva);
        actual = actual->sig;
    }
}

void liberarTColaReservas(TColaReservas &colaReservas){
    if (colaReservas == NULL) return;
    nodo_colaReservas * borrar;
    while (colaReservas->front != NULL) {
        borrar = colaReservas->front;
        colaReservas->front = colaReservas->front->sig;
        liberarTReserva(borrar->reserva);
        delete borrar;
    }
    delete colaReservas;
    colaReservas = NULL;
}

TReserva extraerFrenteTColaReservas(TColaReservas &colaReservas) {
    if (colaReservas == NULL || colaReservas->front == NULL) return NULL;
    nodo_colaReservas * borrar = colaReservas->front;
    TReserva reservaExtraida = borrar->reserva;
    colaReservas->front = colaReservas->front->sig;
    if (colaReservas->front == NULL) {
        colaReservas->rear = NULL;
    }
    delete borrar;
    return reservaExtraida;
}
