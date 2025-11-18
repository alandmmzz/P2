#include "../include/tablaReserva.h"

// Se debe implementar mediante una tabla de dispersión abierta (hash)

struct nodoTablaReserva {
    TLibro libro;
    TColaDePrioridadReservas cp;
    nodoTablaReserva *sig;
};

struct rep_tablaTablaReserva {
    nodoTablaReserva **tabla;  
    nat capacidad;
    nat capacidadCola;
};

TTablaReserva crearTTablaReserva(int max, int N) {
    TTablaReserva t = new rep_tablaTablaReserva;

    t->capacidad = max;
    t->capacidadCola = N;

    t->tabla = new nodoTablaReserva*[max];

    for (int i = 0; i < max; i++)
        t->tabla[i] = NULL;

    return t;
}

void insertarTTablaReserva(TTablaReserva &tabla, int isbn, TReserva reserva) {
    if (tabla == NULL) return;

    nat pos = (nat)isbn % tabla->capacidad;

    nodoTablaReserva *p = tabla->tabla[pos];

    while (p != NULL && isbnTLibro(p->libro) != isbn) {
        p = p->sig;
    }

    if (p == NULL) {
        p = new nodoTablaReserva;
        p->libro = libroTReserva(reserva);
        p->cp = crearTColaDePrioridadReservas(tabla->capacidadCola);
        p->sig = tabla->tabla[pos];
        tabla->tabla[pos] = p;
    }

    insertarTColaDePrioridadReservas(p->cp, reserva);
}

bool perteneceTTablaReserva(TTablaReserva tabla, int ciSocio, int isbnLibro) {
    if (tabla == NULL) return false;

    nat pos = (nat)isbnLibro % tabla->capacidad;

    nodoTablaReserva *p = tabla->tabla[pos];

    while (p != NULL && isbnTLibro(p->libro) != isbnLibro) {
        p = p->sig;
    }

    if (p == NULL) {
        return false;
    }

    return estaTColaDePrioridadReservas(p->cp, ciSocio, isbnLibro);
}


TColaDePrioridadReservas obtenerReservaTTablaReserva(TTablaReserva tabla, int isbn) {
    if (tabla == NULL) return NULL;

    nat pos = (nat)isbn % tabla->capacidad;

    nodoTablaReserva *p = tabla->tabla[pos];

    while (p != NULL && isbnTLibro(p->libro) != isbn) {
        p = p->sig;
    }

    if (p == NULL) return NULL;

    return p->cp;
}

TReserva obtenerSigReservaTTablaReserva(TTablaReserva tabla, int isbn) {
    if (tabla == NULL) return NULL;

    nat pos = (nat)isbn % tabla->capacidad;

    nodoTablaReserva *p = tabla->tabla[pos];

    while (p != NULL && isbnTLibro(p->libro) != isbn) {
        p = p->sig;
    }

    if (p == NULL) return NULL;

    return prioritarioTColaDePrioridadReservas(p->cp);
}

void liberarTTablaReserva(TTablaReserva &tabla){
    if (tabla == NULL) return;

    for (nat i = 0; i < tabla->capacidad; i++) {
        nodoTablaReserva* p = tabla->tabla[i];

        while (p != NULL) {
            nodoTablaReserva* borrar = p;
            p = p->sig;

            liberarTColaDePrioridadReservas(borrar->cp);

            delete borrar;
        }
    }

    delete[] tabla->tabla;

    delete tabla;
    tabla = NULL;
}
