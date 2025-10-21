#include "../include/ldePrestamos.h"

struct nodoDoble{
    TPrestamo prestamo;
    nodoDoble* sig;
    nodoDoble* ant;
};

struct rep_ldePrestamos {
    nodoDoble* inicial;
    nodoDoble* final;
};

TLDEPrestamos crearTLDEPrestamosVacia(){
    TLDEPrestamos ldePrestamos = new rep_ldePrestamos;
    ldePrestamos->inicial = NULL;
    ldePrestamos->final = NULL;
    return ldePrestamos;
}

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo){
    nodoDoble* nuevo = new nodoDoble;
	nuevo->prestamo = prestamo;
	if (ldePrestamos->inicial != NULL) {
		if (compararTFechas(fechaRetiroTPrestamo(prestamo), fechaRetiroTPrestamo(ldePrestamos->inicial->prestamo)) == -1) {
			nuevo->sig = ldePrestamos->inicial;
            nuevo->ant = NULL;
            ldePrestamos->inicial->ant = nuevo;
            ldePrestamos->inicial = nuevo;
		} else {
			nodoDoble* aux = ldePrestamos->inicial;
			while (aux->sig != NULL && compararTFechas(fechaRetiroTPrestamo(prestamo), fechaRetiroTPrestamo(aux->prestamo)) > -1) {
				aux = aux->sig ;
			}
			if (aux->sig == NULL) {
				aux->sig = nuevo;
				nuevo->sig = NULL;
                nuevo->ant = aux;
                ldePrestamos->final = nuevo;
			} else {
				nuevo->sig = aux->sig;
				aux->sig = nuevo;
                nuevo->ant = aux;
                nuevo->sig->ant = nuevo;
			}
		}
	} else {
		nuevo->sig = NULL;
		nuevo->ant = NULL;
		ldePrestamos->inicial = nuevo;
        ldePrestamos->final = nuevo;
	}
}

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos){
    nodoDoble *borrar, *aux = ldePrestamos->inicial;
    while (aux != NULL) {
        borrar = aux;
        liberarTPrestamo(borrar->prestamo);
        aux = aux->sig;
        delete borrar;
    }
    delete ldePrestamos;
    ldePrestamos = NULL;
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos){
    nodoDoble* aux = ldePrestamos->inicial;
    printf("LDE Préstamos:\n");
    while (aux != NULL) {
        imprimirTPrestamo(aux->prestamo);
        aux = aux->sig ;
    }
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    nodoDoble* aux = ldePrestamos->final;
    printf("LDE Préstamos:\n");
    while (aux != NULL) {
        imprimirTPrestamo(aux->prestamo);
        aux = aux->ant ;
    }
}

nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos){
    nat cantidad = 0;
    nodoDoble* aux = ldePrestamos->inicial;
    while (aux != NULL) {
        aux = aux->sig ;
        cantidad++;
    }
    return cantidad;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return ldePrestamos->inicial->prestamo;
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return ldePrestamos->final->prestamo;
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n){
    if (n <= 0) return NULL;
    int i = 1;
    nodoDoble* aux = ldePrestamos->inicial;
    while (aux != NULL && i < n) {
        aux = aux->sig;
        i++;
    }
    if (aux == NULL) {
        return NULL;
    }
    return aux->prestamo;
}

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio){
    TLDEPrestamos filtrada = crearTLDEPrestamosVacia();
    nodoDoble* aux = ldePrestamos->inicial;
    while (aux != NULL) {       
        if ((criterio == 0 && fueRetornadoTPrestamo(aux->prestamo)) || (criterio == 1 && !fueRetornadoTPrestamo(aux->prestamo))) {
            insertarTLDEPrestamos(filtrada, copiarTPrestamo(aux->prestamo));
        }
        aux = aux->sig;
    }
    return filtrada;
}

/* FUNCIONES TAREA 3 */

void liberarTLDEPrestamosSoloEstructura(TLDEPrestamos &ldePrestamos) {
    nodoDoble *borrar, *aux = ldePrestamos->inicial;
    while (aux != NULL) {
        borrar = aux;
        aux = aux->sig;
        liberarTPrestamoSoloEstructura(borrar->prestamo);
        delete borrar;
    }
    delete ldePrestamos;
    ldePrestamos = NULL;
}