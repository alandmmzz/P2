#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 1 - Árboles binarios
(a) ¿Cómo representaría al árbol vacío con dicha representación?
(b) Utilice la representación dada para implementar las siguientes operaciones:
I. función consArbol: que retorna un árbol no vacío a partir de un natural y otros dos árboles.
II. función contarElems: que recibe un árbol y retorna la cantidad de elementos del mismo.
III. función contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
subárboles son vacíos) del mismo.
IV. función altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es
0.
V. función copiar: que recibe un árbol y retorna una copia limpia (que no comparte registros de
memoria) del mismo.
VI. procedimiento liberarArbol: que recibe un árbol y elimina del mismo todos los nodos, liberando
la memoria asociada a cada uno de ellos.
(c) La estructura que devuelve su solución de consArbol, ¿comparte memoria con los parámetros? En
caso afirmativo, ¿qué problemas puede acarrear esto?
*/

struct nodoAB {
    uint elem ;
    nodoAB * izq , * der ;
};

typedef nodoAB * AB ;

AB consArbol(int n, AB arbolA, AB arbolB) {
    AB nuevo = new nodoAB;
    nuevo->elem = n;
    nuevo->izq = arbolA;
    nuevo->der = arbolB;
    return nuevo;
}

uint elemArbol(AB arbol) {
    if (arbol == NULL) {
        return 0;
    }
    return 1 + elemArbol(arbol->izq) + elemArbol(arbol->der);
}

uint contarHojas(AB arbol) {
    if (arbol == NULL) {
        return 0;
    }
    if (arbol->izq == NULL && arbol->der == NULL) {
        return 1;
    }
    return contarHojas(arbol->izq) + contarHojas(arbol->der);
}

uint altura(AB arbol) {
    if (arbol == NULL) {
        return 0;
    }
    return 1 + MAX(altura(arbol->izq), altura(arbol->der));
}

AB copiar(AB arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    AB nuevo = new nodoAB;
    nuevo->elem = arbol->elem;
    nuevo->izq = copiar(arbol->izq);
    nuevo->der = copiar(arbol->der);
    return nuevo;
}

void liberarArbol(AB &arbol) {
    if (arbol != NULL) {
        liberarArbol(arbol->izq);
        liberarArbol(arbol->der);
        delete arbol;
        arbol = NULL;
    }
}

void main() {
    
}