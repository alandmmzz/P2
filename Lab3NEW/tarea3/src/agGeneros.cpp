
#include "../include/agGeneros.h"
#include <assert.h>


struct rep_agGeneros {
    int id;
    char nombre[MAX_NOMBRE];
    rep_agGeneros * sH;
    rep_agGeneros * pH;
};

TAGGeneros crearTAGGeneros(){
    return NULL;
}

void insertarGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE] ){
    if (arbolGeneros == NULL) {
        if (idGeneroPadre == -1) {
            TAGGeneros nuevoNodo = new rep_agGeneros;
            nuevoNodo->id = idGenero;
            strcpy(nuevoNodo->nombre, nombreGenero);
            nuevoNodo->sH = NULL;
            nuevoNodo->pH = NULL;
            arbolGeneros = nuevoNodo; 
        } 
        return;
    }
    if (idGeneroPadre == arbolGeneros->id) {
        TAGGeneros nuevoNodo = new rep_agGeneros;
        nuevoNodo->id = idGenero;
        strcpy(nuevoNodo->nombre, nombreGenero);
        nuevoNodo->pH = NULL;
        if (arbolGeneros->pH != NULL) {
            TAGGeneros aux = arbolGeneros->pH;
            nuevoNodo->sH = aux;
        } else {
            nuevoNodo->sH = NULL;
        }
        arbolGeneros->pH = nuevoNodo;
        return;
    } else {
        insertarGeneroTAGGeneros(arbolGeneros->pH, idGeneroPadre, idGenero, nombreGenero );
        insertarGeneroTAGGeneros(arbolGeneros->sH, idGeneroPadre, idGenero, nombreGenero );
    }
}

void imprimirTAGGenerosAux(TAGGeneros arbol, int nivel) {
    if (arbol == NULL) return;
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%d - %s\n", arbol->id, arbol->nombre);
    imprimirTAGGenerosAux(arbol->pH, nivel + 1);
    imprimirTAGGenerosAux(arbol->sH, nivel);
}

void imprimirTAGGeneros(TAGGeneros arbolGeneros) {
    printf("Árbol de géneros:\n");
    imprimirTAGGenerosAux(arbolGeneros, 0);
}

void liberarTAGGeneros(TAGGeneros &arbolGeneros){
    if (arbolGeneros == NULL) return;
    liberarTAGGeneros(arbolGeneros->pH);
    liberarTAGGeneros(arbolGeneros->sH);
    delete arbolGeneros;
    arbolGeneros = NULL;
}

bool existeGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero){
    if (arbolGeneros == NULL ) return false;
    return (arbolGeneros->id == idGenero) || 
           existeGeneroTAGGeneros(arbolGeneros->pH, idGenero) || 
           existeGeneroTAGGeneros(arbolGeneros->sH, idGenero);
}

char* nombreGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero){
    if (arbolGeneros == NULL ) return NULL;
    if (arbolGeneros->id == idGenero) {
        return arbolGeneros->nombre;
    }
    char* nombreHijo = nombreGeneroTAGGeneros(arbolGeneros->pH, idGenero);
    if (nombreHijo != NULL) {
        return nombreHijo;
    }
    char* nombreHermano = nombreGeneroTAGGeneros(arbolGeneros->sH, idGenero);
    if (nombreHermano != NULL) {
        return nombreHermano;
    }
  return NULL;
}

nat alturaTAGGeneros(TAGGeneros arbolGeneros){
    if (arbolGeneros == NULL ) return 0;
    nat alturaHermano = alturaTAGGeneros(arbolGeneros->sH);
    nat alturaHijo = alturaTAGGeneros(arbolGeneros->pH);
    if (alturaHermano > alturaHijo) {
        return alturaHermano;
    } else {
        return 1 + alturaHijo;
    }
}

nat cantidadTAGGeneros(TAGGeneros arbolGeneros){
    if (arbolGeneros == NULL ) return 0;
    return 1 + cantidadTAGGeneros(arbolGeneros->pH) + cantidadTAGGeneros(arbolGeneros->sH);
}

TAGGeneros obtenerSubarbolTAGGeneros(TAGGeneros arbolGeneros, int idGenero) {
    if (arbolGeneros == NULL ) return NULL;
    if (arbolGeneros->id == idGenero) {
        return arbolGeneros;
    }
    TAGGeneros subarbolHijo = obtenerSubarbolTAGGeneros(arbolGeneros->pH, idGenero);
    if (subarbolHijo != NULL) {
        return subarbolHijo;
    }
    TAGGeneros subarbolHermano = obtenerSubarbolTAGGeneros(arbolGeneros->sH, idGenero);
    if (subarbolHermano != NULL) {
        return subarbolHermano;
    }
    return NULL;
}

TConjuntoGeneros obtenerConjuntoGeneros(TAGGeneros arbol, int idGenero) {
    if (!arbol) return crearTConjuntoGeneros(0);

    if (arbol->id == idGenero) {
        TConjuntoGeneros conjunto = crearTConjuntoGeneros(obtenerMaxTAGGeneros(arbol));
        // Insertar el nodo actual
        insertarTConjuntoGeneros(conjunto, arbol->id);

        // Recorrer todos los hijos
        TAGGeneros hijo = arbol->pH;
        while (hijo) {
            TConjuntoGeneros subConjunto = obtenerConjuntoGeneros(hijo, hijo->id);
            TConjuntoGeneros tmp = unionTConjuntoGeneros(conjunto, subConjunto);
            liberarTConjuntoGeneros(conjunto);
            liberarTConjuntoGeneros(subConjunto);
            conjunto = tmp;
            hijo = hijo->sH;
        }
        return conjunto;
    }

    // Buscar en subárbol de hijos
    TConjuntoGeneros res = obtenerConjuntoGeneros(arbol->pH, idGenero);
    if (cardinalTConjuntoGeneros(res) > 0) return res;

    // Buscar en hermanos
    return obtenerConjuntoGeneros(arbol->sH, idGenero);
}



int obtenerMaxTAGGeneros(TAGGeneros arbolGeneros) {
    if (arbolGeneros == NULL ) return 0;
    int maxHijo = obtenerMaxTAGGeneros(arbolGeneros->pH);
    int maxHermano = obtenerMaxTAGGeneros(arbolGeneros->sH);
    int maxActual = arbolGeneros->id;
    if (maxHijo > maxActual) {
        maxActual = maxHijo;
    }
    if (maxHermano > maxActual) {
        maxActual = maxHermano;
    }
    return maxActual;
}


void removerGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGenero){
    if (arbolGeneros == NULL) return;
    if (arbolGeneros->id == idGenero) {
        if (arbolGeneros->pH != NULL) {
            liberarTAGGeneros(arbolGeneros->pH);
        }
        TAGGeneros aBorrar = arbolGeneros;
        arbolGeneros = arbolGeneros->sH;
        delete aBorrar;
    } else {
        removerGeneroTAGGeneros(arbolGeneros->pH, idGenero);
        removerGeneroTAGGeneros(arbolGeneros->sH, idGenero);
    }
}
