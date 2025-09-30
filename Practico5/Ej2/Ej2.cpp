#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 2
Considere la representación para árbol binario de Naturales de la Figura 1 y la siguiente representación de
Lista de Naturales:

(a) Utilícelas para implementar las siguientes funciones:
I. enOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
recorrida en orden de b.
II. preOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
recorrida en pre orden de b.
III. postOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
recorrida en post orden de b.
IV. esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino
desde la raíz a un hoja de b.
V. caminoMasLargo: que recibe un árbol b y retorna una lista con los elementos del camino más
largo de b (desde la raíz a una hoja). En caso de haber más de un camino de igual longitud a la del
camino más largo, retorna cualquiera de ellos.
(b) Se dice que un árbol es perfecto si todas las hojas están en el mismo nivel y todos los nodos internos
tiene dos subárboles no vacíos, o sea, si todos los niveles están completos. ¿Cuántos nodos tiene un
árbol binario perfecto de altura h? Escriba una función booleana que dados un árbol binario b y un
natural h, retorne TRUE si y solo si b es un árbol perfecto de altura h. Implemente dicha función sin usar
operaciones auxiliares para calcular la cantidad de nodos o la altura de un árbol. Cada nodo se puede
visitar a lo sumo una vez y no se deben visitar nodos innecesarios.
(c) ¿Cuántos nodos tiene como mínimo y cómo máximo el camino más largo desde la raíz a una hoja,
para un árbol binario de n nodos? Justifique.
(d) Se dice que un árbol es completo si todos los niveles están completos, excepto tal vez el más profundo
al que le pueden faltar nodos a la derecha. Escriba una función booleana que dados un árbol binario b
y un natural h, retorne TRUE si y solo si b es un árbol completo de altura h. Cada nodo se puede visitar
a lo sumo una vez y no se deben visitar nodos innecesarios.
*/

struct nodoAB {
    uint elem ;
    nodoAB * izq , * der ;
};

typedef nodoAB * AB ;

struct nodoLista {
    uint elem ;
    nodoLista * sig ;
};

typedef nodoLista * lista ;

lista concatenar(lista l, lista p) {
   lista dummy = new nodo;
    lista aux = dummy;

    while (l != NULL) {
        aux->sig = new nodo;
        aux = aux->sig;
        aux->elem = l->elem;
        l = l->sig;
    }

    while (p != NULL) {
        aux->sig = new nodo;
        aux = aux->sig;
        aux->elem = p->elem;
        p = p->sig;
    }

    aux->sig = NULL;
    lista nuevaLista = dummy->sig;
    delete dummy;
    return nuevaLista;
}

Lista enOrden(AB b) {
    if (b == NULL) {
        return NULL;
    }
    Lista listaIzq = enOrden(b->izq);
    Lista nuevo = new nodoLista;
    nuevo->elem = b-> elem;
    nuevo->sig = NULL;
    Lista listaDer = enOrden(b->der);
    return concatenar(concatenar(listaIzq, nuevo), listaDer);
}
//mucho mejor seria agregar al final de listaIzq el elemento nuevo y concatenar las dos listas

Lista preOrden(AB b) {
    if (b == NULL) return NULL;

    Lista nuevo = new nodoLista;
    nuevo->elem = b->elem;
    nuevo->sig = NULL;

    Lista listaIzq = preOrden(b->izq);
    Lista listaDer = preOrden(b->der);

    return concatenar(nuevo, concatenar(listaIzq, listaDer));
}

Lista postOrden(AB b) {
    if (b == NULL) return NULL;

    Lista listaIzq = postOrden(b->izq);
    Lista listaDer = postOrden(b->der);

    Lista nuevo = new nodoLista;
    nuevo->elem = b->elem;
    nuevo->sig = NULL;

    return concatenar(concatenar(listaIzq, listaDer), nuevo);
}

bool esCamino(AB b, Lista l) {
    if (b == NULL) {
        return (l == NULL); // si no hay árbol, el camino debe ser vacío
    }
    if (l == NULL) {
        return false; // si el árbol sigue pero la lista se terminó, no es válido
    }
    if (b->elem != l->elem) {
        return false; // valores distintos -> no hay match
    }
    // Si estamos en una hoja, el camino solo es válido si la lista también termina acá
    if (b->izq == NULL && b->der == NULL) {
        return (l->sig == NULL);
    }
    // Si no es hoja, seguimos bajando por izq o der
    return esCamino(b->izq, l->sig) || esCamino(b->der, l->sig);
}

uint altura(AB arbol) {
    if (arbol == NULL) {
        return 0;
    }
    return 1 + MAX(altura(arbol->izq), altura(arbol->der));
}

Lista caminoMasLargo(AB b) {
    if (b == NULL) { 
        return NULL;
    }
    Lista nuevo = new nodoLista;
    nuevo->elem = b->elem;
    if (altura(b->izq) > altura(b->der)) {
        nuevo->sig = caminoMasLargo(b->izq);
    } else {
        nuevo->sig = caminoMasLargo(b->der);
    }
    return nuevo;
}

bool esPerfecto(AB b, uint h) {
    if (b == NULL) {
        return (h == 0);
    } else if (h == 1) {
        return (b->izq == NULL && b->der == NULL);
    } else return (esPerfecto(b->izq, h-1) && esPerfecto(b->der, h-1));
}

bool esCompleto(AB b, uint h) {
    if (b == NULL) {
        return (h == 0);
    }
    if (h == 1) {
        // último nivel, nodo puede ser hoja o tener solo izquierdo
        return true;
    }
    if (b->izq == NULL) {
        return false; // en niveles intermedios siempre debe haber hijo izquierdo
    }
    if (b->der == NULL) {
        // derecha falta: entonces todo el subárbol izquierdo debe ser perfecto de altura h-1
        return esPerfecto(b->izq, h-1);
    }
    // ambos hijos existen → seguimos recursivamente
    return esCompleto(b->izq, h-1) && esCompleto(b->der, h-1);
}


void main() {
    
}