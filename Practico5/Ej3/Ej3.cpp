#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 3
Considere la representación para un árbol binario de búsqueda (ABB) de Naturales de la Figura 2.

Utilice la representación dada para implementar las siguientes operaciones:
(a) procedimiento insertarABB: que recibe un natural x, y un ABB b, e inserta x en b manteniendo su
cualidad de árbol binario de búsqueda. Si x pertenece al árbol la operación no tiene efecto.
(b) función perteneceABB: que recibe un natural x y un ABB b y devuelve true si y solo si x es un elemento
del árbol b.
(c) función maxABB: que recibe un ABB no vacío b y devuelve el elemento de máximo valor en b.
(d) procedimiento removerMaxABB: que recibe un ABB no vacío b y elimina el elemento de máximo valor
en b.
(e) procedimiento removerABB: que recibe un natural x y un ABB b y elimina el elemento de valor x de b,
manteniendo su cualidad de ABB.
(f) función k-esimo: que recibe un natural k y un ABB b y retorna el subárbol que tiene al k-ésimo menor
elemento de b como raíz. Si en b hay menos de k elementos o k es cero, la función debe retornar el
árbol vacío. Si k es 1, se refiere al menor elemento del árbol, si k es 2 al 2do elemento más pequeño
del árbol y así sucesivamente. La solución no puede visitar ningún nodo más de una vez.

*/

struct nodoABB {
    uint elem ;
    nodoABB * izq , * der ;
};

typedef nodoABB * ABB ;


ABB insertarABB(uint x, ABB &b) {
    if (b != NULL) {
        if (b->elem != x) {
            if (x < b->elem) {
                b->izq = insertarABB(x, b->izq);
            } else {
                b->der = insertarABB(x, b->der);
            }
        }
        return b;
    } else {
        ABB nuevo = new nodoABB;
        nuevo->elem = x;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        return nuevo;
    }
}

bool perteneceABB(uint x, ABB b) {
    if (b == NULL) {
        return false;
    }
    return b->elem == x || (perteneceABB(x, b->izq) || perteneceABB(x, b->der))
}
// no usa la magia del arbol binario, orden n;

bool perteneceABB(uint x, ABB b) {
    if (b == NULL) return false;
    if (b->elem == x) return true;
    if (x < b->elem) return perteneceABB(x, b->izq);
    else return perteneceABB(x, b->der);
}

ABB maxABB(ABB b) {
    if (b == NULL) {
        return b;
    } else {
        if (b->der != NULL) {
            return maxABB(b->der);
        } else {
            return b;
        }
    }
}

void removerMaxABB(ABB &b) {
    if (b == NULL) return; // por las dudas

    if (b->der == NULL) {
        // b es el máximo
        ABB borrar = b;
        b = b->izq; // enganchamos el hijo izquierdo (si existe)
        delete borrar;
    } else {
        removerMaxABB(b->der); // seguir bajando por la derecha
    }
}

void removerABB(uint x, ABB &b) {
    if (b == NULL) return; // por las dudas
    if perteneceABB(uint x, ABB b) {
        if (x < b->elem) {
            removerABB(x, b->izq)
        } else if (x > b->elem) {
            removerABB(x, b->der)
        } else {
            if (b->izq == NULL && b->der == NULL) {
                delete b;
                b == NULL;
            } else if (b->izq != NULL && b->der == NULL){
                ABB borrar = b;
                b = b->izq;
                delete borrar;
            } else if (b->izq == NULL && b->der != NULL){
                ABB borrar = b;
                b = b->der;
                delete borrar;
            } else {
                // usamos máximo del subárbol izquierdo
                ABB maxIzq = b->izq;
                while (maxIzq->der != NULL) maxIzq = maxIzq->der;
                b->elem = maxIzq->elem; // copiamos valor
                removerABB(maxIzq->elem, b->izq); // borramos el nodo duplicado
            }
        }
    }
}

int contarNodos(ABB b) {
    if (b == NULL) return 0;
    return 1 + contarNodos(b->izq) + contarNodos(b->der);
}

ABB k_esimo(uint k, ABB b) {
    if (b == NULL || k == 0) return NULL;

    int nIzq = contarNodos(b->izq); // número de nodos en el subárbol izquierdo

    if (k <= nIzq) {
        return k_esimo(k, b->izq);
    } else if (k == nIzq + 1) {
        return b; // la raíz es el k-ésimo
    } else {
        return k_esimo(k - nIzq - 1, b->der);
    }
}

void main() {
    
}