#include "../include/colaDePrioridadReservas.h"

// La cola de prioridad debe implementarse con un HEAP.

// NOTA IMPORTANTE: Para evitar diferencias con las salidas esperadas de los tests:
// * El filtrado ascendente debe parar cuando se encuentra un elemento igual o más prioritario que el elemento filtrado.
// * El filtrado descendente debe parar cuando los hijos del elemento filtrado sean igual o menos prioritarios que el.
// * Si se dan empates de prioridad entre los hijos durante el filtrado descendente y corresponde continuar filtrando,
// se debe seguir el filtrado hacia la rama izquierda.

struct rep_colaDePrioridadReservas {
    TReserva *heap;  // índices 1..tope
    nat cantidad;    // cuántos elementos hay
    nat tope;        // N del crearTColaDePrioridadReservas
    bool invertida;  // por si la letra pide invertir prioridad
};

TColaDePrioridadReservas crearTColaDePrioridadReservas(nat N) {
    TColaDePrioridadReservas nuevo = new rep_colaDePrioridadReservas;
    nuevo->cantidad = 0;
    nuevo->tope = N;
    nuevo->invertida = false;
    nuevo->heap = new TReserva[N + 1]; // usamos 1..N
    return nuevo;
}

void invertirPrioridadTColaDePrioridadReservas(TColaDePrioridadReservas &cp) {
    if (cp == NULL || cp->cantidad == 0) {
        return;
    }
    cp->invertida = !cp->invertida;
    nat cant = cp->cantidad;
    TReserva *aux = new TReserva[cant + 1]; // usamos 1..cant
    for (nat i = 1; i <= cant; i++) {
        aux[i] = cp->heap[i];
    }
    cp->cantidad = 0;
    for (nat i = 1; i <= cant; i++) {
        insertarTColaDePrioridadReservas(cp, aux[i]);
    }
    delete[] aux;
}



void liberarTColaDePrioridadReservas(TColaDePrioridadReservas &cp) {
    if (cp != NULL) {
        for (nat i = 1; i <= cp->cantidad; i++) {
            liberarTReserva(cp->heap[i]);
        }
        delete[] cp->heap;
        delete cp;
        cp = NULL;
    }
}

bool esMasPrioritario(TColaDePrioridadReservas cp, TReserva a, TReserva b) {
    nat ra = rangoTSocio(socioTReserva(a));
    nat rb = rangoTSocio(socioTReserva(b));

    if (!cp->invertida) {
        // normal: menor rango = más prioridad
        return ra < rb;
    } else {
        // invertida: mayor rango = más prioridad
        return ra > rb;
    }
}

void insertarTColaDePrioridadReservas(TColaDePrioridadReservas &cp, TReserva reserva) {
    // asumimos que no está lleno: cp->cantidad < cp->tope
    cp->cantidad++;
    nat i = cp->cantidad;
    cp->heap[i] = reserva; // lo ponés al final

    // filtrado ascendente (sift up)
    while (i > 1) {
        nat padre = i / 2;

        // si el padre es igual o más prioritario, cortamos (tal cual dice la letra)
        if (!esMasPrioritario(cp, cp->heap[i], cp->heap[padre]))
            break;

        // sino, swap hijo ↔ padre
        TReserva tmp = cp->heap[i];
        cp->heap[i] = cp->heap[padre];
        cp->heap[padre] = tmp;

        i = padre;
    }
}

bool estaVaciaTColaDePrioridadReservas(TColaDePrioridadReservas cp) {
    return (cp == NULL || cp->cantidad == 0);
}

TReserva prioritarioTColaDePrioridadReservas(TColaDePrioridadReservas cp) {
    return cp->heap[1];
}

void eliminarPrioritarioTColaDePrioridadReservas(TColaDePrioridadReservas &cp) {
    if (!estaVaciaTColaDePrioridadReservas(cp)) {

        // guardo la reserva a borrar (la raíz)
        TReserva borrar = cp->heap[1];

        // traigo el último a la raíz y reduzco cantidad
        cp->heap[1] = cp->heap[cp->cantidad];
        cp->cantidad--;

        // filtrado descendente (sift down) desde la raíz
        nat i = 1;
        while (true) {
            nat izq = 2 * i;
            nat der = 2 * i + 1;

            // si no tiene hijo izquierdo, no tiene hijos
            if (izq > cp->cantidad)
                break;

            // por defecto, asumimos que el hijo prioritario es el izquierdo
            nat hijoPrioritario = izq;

            // si tiene hijo derecho, vemos si es MÁS prioritario que el izquierdo
            // (si no lo es, en empate nos quedamos con el izquierdo)
            if (der <= cp->cantidad &&
                esMasPrioritario(cp, cp->heap[der], cp->heap[izq])) {
                hijoPrioritario = der;
            }

            // si el hijo prioritario NO es más prioritario que el actual, cortamos
            // (hijos igual o menos prioritarios → condición de parada de la letra)
            if (!esMasPrioritario(cp, cp->heap[hijoPrioritario], cp->heap[i]))
                break;

            // sino, swap actual ↔ hijo prioritario
            TReserva tmp = cp->heap[i];
            cp->heap[i] = cp->heap[hijoPrioritario];
            cp->heap[hijoPrioritario] = tmp;

            i = hijoPrioritario;
        }

        // ahora sí, liberamos la reserva que estaba en la raíz originalmente
        liberarTReserva(borrar);
    }
}


bool estaTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro) {
    for (nat i = 1; i <= cp->cantidad; i++) {
        TReserva res = cp->heap[i];
        TSocio soc = socioTReserva(res);
        TLibro lib = libroTReserva(res);
        if (ciSocio == ciTSocio(soc) && isbnLibro == isbnTLibro(lib)) {
            return true;
        }
    }
    return false;
}

nat prioridadTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro) {
    for (nat i = 1; i <= cp->cantidad; i++) {
        TReserva res = cp->heap[i];
        TSocio soc = socioTReserva(res);
        TLibro lib = libroTReserva(res);
        if (ciSocio == ciTSocio(soc) && isbnLibro == isbnTLibro(lib)) {
            return rangoTSocio(soc);
        }
    }
    return 0;
}

TColaDePrioridadReservas copiarTColaDePrioridadReservas(TColaDePrioridadReservas cp) {
    TColaDePrioridadReservas copia = crearTColaDePrioridadReservas(cp->tope);
    copia->invertida = cp->invertida;
    for (nat i = 1; i <= cp->cantidad; i++) {
        // Asumimos que insertar hace una copia profunda de la reserva
        TReserva copiaReserva = copiarTReserva(cp->heap[i]);
        insertarTColaDePrioridadReservas(copia, copiaReserva);
    }
    return copia;
}

void imprimirTColaDePrioridad(TColaDePrioridadReservas cp) {
    TColaDePrioridadReservas copia = copiarTColaDePrioridadReservas(cp);
    while (!estaVaciaTColaDePrioridadReservas(copia)) {
        imprimirTReserva(prioritarioTColaDePrioridadReservas(copia));
        eliminarPrioritarioTColaDePrioridadReservas(copia);
    }
    liberarTColaDePrioridadReservas(copia);
}