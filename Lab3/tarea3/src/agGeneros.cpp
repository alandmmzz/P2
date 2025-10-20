
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
        } else return;
    }
    if (idGeneroPadre == -1) {
        TAGGeneros nuevoNodo = new rep_agGeneros;
        nuevoNodo->id = idGenero;
        strcpy(nuevoNodo->nombre, nombreGenero);
        nuevoNodo->sH = NULL;
        nuevoNodo->pH = arbolGeneros;
        arbolGeneros = nuevoNodo;
        return;
    } else if (idGeneroPadre == arbolGeneros->id) {
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

void imprimirTAGGeneros(TAGGeneros arbolGeneros){
}

void liberarTAGGeneros(TAGGeneros &arbolGeneros){
}

bool existeGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero){
  return false;
}

char* nombreGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero){
  return NULL;
}

nat alturaTAGGeneros(TAGGeneros arbolGeneros){
  return 0;
}

nat cantidadTAGGeneros(TAGGeneros arbolGeneros){
  return 0;
}

TAGGeneros obtenerSubarbolTAGGeneros(TAGGeneros arbolGeneros, int idGenero) {
  return NULL;
}

TConjuntoGeneros obtenerConjuntoGeneros(TAGGeneros arbolGeneros, int idGenero) {
  return NULL;
}

int obtenerMaxTAGGeneros(TAGGeneros arbolGeneros) {
  return 0;
}

void removerGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGenero){
}
