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

int ultimo(lista l) { // Orden n
    while (l->sig != NULL) {
        l = l->sig;
    }
    return l->elem;
}

float promedio(lista l) { // Orden n
    int contador = 0;
    int suma = 0;
    while (l != NULL) {
        contador ++;
        suma += l->elem;
        l = l->sig;
    }
    return suma/contador;
}

lista insOrden(lista &l, int x) { // Orden n
    printf("insOrden: agregando %d\n", x);
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

lista insFinal(lista &l, int x) { // Orden n   
    printf("insFinal: agregando %d\n", x);
    lista nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;
    lista aux = l;
    if (aux == NULL) {
        l = nuevo;
        return l;
    } else {
        while (aux->sig != NULL) {
            aux  = aux->sig;
        }
    }
    aux->sig = nuevo;
    return l;
}

void removerOcurrencias(lista &l, int x) { // Orden n
    lista nodoBorrar = l;
    while (l != NULL && l->elem == x) {
        lista nodoBorrar = l;
        l = l->sig;
        delete nodoBorrar;
    }
    lista aux = l;
    while (aux != NULL && aux->sig != NULL) {
        if (aux->sig->elem == x) {
            nodoBorrar = aux->sig;
            aux->sig = aux->sig->sig;
            delete nodoBorrar;
        } else {
            aux = aux->sig;
        }
    }
}

bool esSubLista(lista l, lista p) { // Orden n*m
    if (l == NULL) {
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

void imprimirLista(lista l) {
    while(l) {
        printf("%d ", l->elem);
        l = l->sig;
    }
    printf("\n");
}

int main() {
    lista lista1 = nullptr;

    printf("--- Probando insFinal ---\n");
    lista1 = insFinal(lista1, 5);
    lista1 = insFinal(lista1, 10);
    lista1 = insFinal(lista1, 15);
    imprimirLista(lista1); // 5 10 15

    printf("--- Probando ultimo ---\n");
    printf("Ultimo: %d\n", ultimo(lista1)); // 15

    printf("--- Probando promedio ---\n");
    printf("Promedio: %.2f\n", promedio(lista1)); // 10.00

    printf("--- Probando insOrden ---\n");
    lista1 = insOrden(lista1, 12);
    lista1 = insOrden(lista1, 3);
    imprimirLista(lista1); // 3 5 10 12 15

    printf("--- Probando removerOcurrencias ---\n");
    removerOcurrencias(lista1, 10);
    imprimirLista(lista1); // 3 5 12 15

    printf("--- Probando esSubLista ---\n");
    lista sub = nullptr;
    sub = insFinal(sub, 5);
    sub = insFinal(sub, 12);
    if (esSubLista(sub, lista1)) {
        printf("sub está incluida en lista\n");
    } else {
        printf("sub NO está incluida en lista\n");
    }

    return 0;
}