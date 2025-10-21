
#include "../include/abbLibros.h"

struct rep_abbLibros {
    TLibro libro;
    rep_abbLibros* izq;
    rep_abbLibros* der;
};

TABBLibros crearTABBLibrosVacio(){
    return NULL;
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro){
	if (abbLibros != NULL) {
        if (isbnTLibro(libro) < isbnTLibro(abbLibros->libro)) {
            insertarLibroTABBLibros(abbLibros->izq, libro);
        } else {
            insertarLibroTABBLibros(abbLibros->der, libro);
        }
	} else {
        TABBLibros nuevo = new rep_abbLibros;
        nuevo->libro = libro;
        nuevo->izq = NULL;
        nuevo->der = NULL;
		abbLibros = nuevo;
	}
}

void imprimirTABBLibros(TABBLibros abbLibros){
    if (abbLibros != NULL) {
        imprimirTABBLibros(abbLibros->izq);
        imprimirTLibro(abbLibros->libro);
        imprimirTABBLibros(abbLibros->der);
    }
}

void liberarTABBLibros(TABBLibros &abbLibros){
    if (abbLibros != NULL) {
        liberarTABBLibros(abbLibros->izq);
        liberarTABBLibros(abbLibros->der);
        liberarTLibro(abbLibros->libro);
        delete abbLibros;
        abbLibros = NULL;
    }
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (abbLibros != NULL) {
        if (isbn == isbnTLibro(abbLibros->libro)) {
            return true;
        } else if (isbn < isbnTLibro(abbLibros->libro)) {
            return existeLibroTABBLibros(abbLibros->izq, isbn);
        } else {
            return existeLibroTABBLibros(abbLibros->der, isbn);
        }
    }
    return false;
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (abbLibros != NULL) {
        if (isbn == isbnTLibro(abbLibros->libro)) {
            return abbLibros->libro;
        } else if (isbn < isbnTLibro(abbLibros->libro)) {
            return obtenerLibroTABBLibros(abbLibros->izq, isbn);
        } else {
            return obtenerLibroTABBLibros(abbLibros->der, isbn);
        }
    }
    return NULL;
}

nat alturaTABBLibros(TABBLibros abbLibros){
    if (abbLibros != NULL) {
        nat alturaIzq = alturaTABBLibros(abbLibros->izq);
        nat alturaDer = alturaTABBLibros(abbLibros->der);
        if (alturaIzq > alturaDer) {
            return alturaIzq + 1;
        } else {
            return alturaDer + 1;
        }
    }
    return 0;
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros){
    if (abbLibros->der != NULL) {
        return maxISBNLibroTABBLibros(abbLibros->der);
    }
    return abbLibros->libro;
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn) {
    if (abbLibros == NULL) return;

    if (isbn < isbnTLibro(abbLibros->libro)) {
        removerLibroTABBLibros(abbLibros->izq, isbn);
    } else if (isbn > isbnTLibro(abbLibros->libro)) {
        removerLibroTABBLibros(abbLibros->der, isbn);
    } else {
        if (abbLibros->izq == NULL && abbLibros->der == NULL) {
            liberarTLibro(abbLibros->libro);
            delete abbLibros;
            abbLibros = NULL;
        }
        else if (abbLibros->izq == NULL) {
            TABBLibros borrar = abbLibros;
            abbLibros = abbLibros->der;
            liberarTLibro(borrar->libro);
            delete borrar;
        }
        else if (abbLibros->der == NULL) {
            TABBLibros borrar = abbLibros;
            abbLibros = abbLibros->izq;
            liberarTLibro(borrar->libro);
            delete borrar;
        }
        else {
            TABBLibros nodoMax = abbLibros->izq;
            while (nodoMax->der != NULL) {
                nodoMax = nodoMax->der;
            }
            TLibro tempLibro = abbLibros->libro;
            abbLibros->libro = nodoMax->libro;
            nodoMax->libro = tempLibro;
            removerLibroTABBLibros(abbLibros->izq, isbnTLibro(tempLibro));
        }
    }
}


int cantidadTABBLibros(TABBLibros abbLibros){
    if (abbLibros != NULL) {
        return 1 + cantidadTABBLibros(abbLibros->izq) + cantidadTABBLibros(abbLibros->der);
    }
    return 0;
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res){
    if (abbLibros != NULL && res == NULL) {
        obtenerNesimoLibroTABBLibrosAux(abbLibros->izq, n, k, res);
        k++;
        if (k == n) {
            res = abbLibros->libro;
            return;
        }
        obtenerNesimoLibroTABBLibrosAux(abbLibros->der, n, k, res);
    }
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n){
    int k = 0;
    TLibro res = NULL;
    obtenerNesimoLibroTABBLibrosAux(abbLibros, n, k, res);
    return res;
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    if (abbLibros == NULL) {
        return NULL;
    }
    TABBLibros izqFiltrado = filtradoPorGeneroTABBLibros(abbLibros->izq, genero);
    TABBLibros derFiltrado = filtradoPorGeneroTABBLibros(abbLibros->der, genero);

    if (idGeneroTLibro(abbLibros->libro) == genero) {
        TABBLibros nuevo = new rep_abbLibros;
        nuevo->libro = copiarTLibro(abbLibros->libro);
        nuevo->izq = izqFiltrado;
        nuevo->der = derFiltrado;
        return nuevo;
    } else {
        if (izqFiltrado != NULL && derFiltrado != NULL) {
            TABBLibros aux = izqFiltrado;
            while (aux->der != NULL) {
                aux = aux->der;
            }
            aux->der = derFiltrado;
            return izqFiltrado;
        }
        if (izqFiltrado != NULL) {
            return izqFiltrado;
        } else {
            return derFiltrado;
        }
    }
}
