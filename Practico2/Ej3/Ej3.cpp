#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 3 Rayuela
En una hilera de una calle con adoquines unos niños juegan a la rayuela. Para esto numeran los adoquines
como se indica en la Figura 1. Los movimientos permitidos del juego son:
Al principio del juego los niños se ubican en el adoquín 0.
De un adoquín numerado i se puede saltar al adoquín numerado i + 1.
De un adoquín numerado i se puede saltar al adoquín numerado i + 2 (sin pasar por el adoquín i + 1).
Implemente un algoritmo recursivo que calcule el número de caminos posibles para alcanzar un adoquín
objetivo numerado con n (mayor que cero). Asuma que la cantidad de caminos para llegar al adoquin 0 es 1.
Por ejemplo, el número de caminos posibles para n=3 es 3 y son los siguientes: (0,1,2,3), (0,2,3) y (0,1,3).
Figura 1: Esquema de adoquines
Calcule la cantidad de caminos para n desde 1 hasta 10.

*/

typedef unsigned int uint;

int caminosPosibles(int casilla) {
    if (casilla < 2) {
        return 1;
    }
    else {
        return caminosPosibles(casilla - 1) + caminosPosibles(casilla - 2);
    }
}

int indexEscalones;

int main() {
    printf("cuantos escalones queres calcular:");
    scanf("%d", &indexEscalones);
    printf("Tenes %d caminos posibles.\n", caminosPosibles(indexEscalones));
    return 0;
}