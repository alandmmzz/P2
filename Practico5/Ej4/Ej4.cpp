#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 4 Filtrado
Sea ABB un tipo que representa árboles binarios de búsqueda cuyos elementos son del tipo EstInfo.
EstInfo representa a un estudiante a partir de una identificación (ci) y la nota obtenida en un curso (nota).
Los nodos de ABB están ordenados según el campo ci. En la figura siguiente se presenta a continuación
la estructura de EstInfo y de ABB.
Se dispone de las operaciones maxABB y removerMaxABB definidas en el ejercicio anterior.
Se debe implementar la función filtrado, sin definir procedimientos auxiliares, para obtener un nuevo árbol
solo con los estudiantes que superen una determinada nota:
*/

struct EstInfo {
    uint nota ; // dato
    int ci ; // clave
};

struct nodoABB {
    EstInfo info ;
    nodoABB * izq , * der;
};

typedef nodoABB * ABB;

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

/* Devuelve un arbol con los elementos de 'b' en los que " nota " es mayor que " cota ". */
ABB filtrado(ABB b, uint cota) {
    if (b == NULL) return NULL;
    if (b->info->nota >= cota) {
        ABB nuevo = new nodoABB;
        nuevo->info = new EstInfo;
        nuevo->info->ci = b->info->ci;
        nuevo->info->nota = b->info->nota;
        nuevo->izq = filtrado(b->izq, cota);
        nuevo->der = filtrado(b->der, cota);
        return nuevo;
    } else {
        if (b->info.nota < cota) {
            ABB izqFiltrado = filtrado(b->izq, cota);
            ABB derFiltrado = filtrado(b->der, cota);

            if (izqFiltrado == NULL) return derFiltrado;
            if (derFiltrado == NULL) return izqFiltrado;

            // Ambos existen → tomamos el máximo de izq como nueva raíz
            ABB nuevaRaiz = maxABB(izqFiltrado);
            removerMaxABB(izqFiltrado); // lo quitamos del subárbol izquierdo
            nuevaRaiz->izq = izqFiltrado;
            nuevaRaiz->der = derFiltrado;
            return nuevaRaiz;
        }
    } 
}

void main() {
    
}