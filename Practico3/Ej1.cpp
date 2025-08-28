#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 1
(a) Utilizando la representación de la Figura 1, implemente las siguientes funciones
 o procedimientos en forma iterativa y sin usar procedimientos auxiliares. En el 
 caso de inserciones o eliminaciones se debe modificar los parámetros de entrada 
 y compartir memoria con los mismos. 
 I. ultimo: dada una lista no vacia, retorna su ultimo elemento.
 II. promedio: dada una lista no vacia, retorna el promedio de sus elementos.
 III. insOrden: dados un entero x y una lista l ordenada: inserta x en l 
 ordenadamente. Comparar con la solución recursiva.
 IV. insFinal: dados un entero x y una lista l, inserta x al final de l.
 V. removerOcurrencias: dados un entero x y una lista l, remueve todas las 
 ocurrencias de x en l.
 VI. esSubLista: dadas dos listas l y p, verifica si l esta incluida en p. 
 Una lista l1 está incluida en l2 si y sólo sí existen dos listas, l3 y l4, tal 
 que cumplen que l2 = l3l1l4. 
 Tenga en cuenta que las listas li, con i ∈ {1,...,4} pueden ser vacías. 
(b) Analice las operaciones anteriores indicando cuáles son totales y cuáles 
parciales. ¿Es posible en cada caso pensar en ambas variantes (total y parcial)?. 
(c) Calcule el orden del tiempo de ejecución en el peor caso de las operaciones 
de la parte a
*/

struct nodo {
    int elem; nodo *sig;
};

typedef nodo *lista;

int ultimo(lista l) {
    while (l->sig != NULL) {
        l = l->sig;
    }
    return l->elem;
}

float promedio(lista l) {
    int contador = 0;
    int suma = 0;
    while (l != NULL) {
        contador ++;
        suma += l->elem;
        l = l->sig;
    }
    return suma/contador;
}

lista insOrden(int x, lista &l) {
    lista nuevo = new nodo;
    lista aux = l;
    nuevo->elem = x;
    if (aux->elem > x) {
        nuevo->sig = aux;
        l = nuevo;
    } else {
        while (aux->sig != NULL && aux->sig->elem < x) {
            aux  = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
    return l;
}

lista insFinal(int x, lista l) {
    lista nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;
    lista aux = l;
    while (aux->sig != NULL) {
        aux  = aux->sig;
    }
    aux->sig = nuevo;
    return l;
}

void removerOcurrencias(int x, lista &l) {
    lista nodoBorrar = l;
    lista aux = l;
    while (l != NULL && l->elem == x) {
        lista nodoBorrar = l;
        l = l->sig;
        delete nodoBorrar;
    }
    while (aux != NULL && aux->sig != NULL) {
        if (aux->sig->elem = x) {
            nodoBorrar = aux->sig;
            aux->sig = aux->sig->sig;
            delete nodoBorrar;
        } else {
            aux = aux->sig;
        }
    }
}

bool esSubLista(lista l, lista p) {
    if (l = NULL) {
        return false;
    }
    while (p != NULL) {
        if (l->elem == p->elem) {
            lista auxp = p;
            lista auxl = l;
            while (auxp != NULL && auxl != NULL && auxl->elem == auxp->elem) {
                auxl = auxl->sig;
                auxp = auxp->sig;
            }
            if (auxl == NULL) {
                return true;
            } 
        }
        p = p->sig;
    }
    return false;
}

int main() {
    //pedimos datos para inicializar la sucesion
    printf("cuantos num de la suc. fib. queres:");
    scanf("%d", &indexFib);
    uint arregloFib[100];
    for (uint i = 0; i < indexFib; i++){
        arregloFib[i] = fib(i);
    }
    printf("Tu sucesion es:");
    for (int i = 0; i < indexFib; i++) {
        printf(" %d", arregloFib[i]);
    }
    return 0;
}
