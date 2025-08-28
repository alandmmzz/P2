#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 4 */

typedef unsigned int uint;

/* Ordena A[1.. n] de manera creciente . */
void ordenar(float* A, uint n);

/* Inserta e en A [1.. n +1] de manera ordenada .
Precondicion: n >=0. Si n >=1 -> A [1.. n] está ordenado de manera ←-
creciente . A[n+1] es indeterminado .
Postcondicion: A [1.. n+1] queda ordenado de manera creciente . */
void insertarOrdenado(float* A, uint n, float e);


uint cantArreglo;

float arreglo[100];

int main() {
    printf("cuantos numeros me vas a agregar:");
    scanf("%d", &cantArreglo);
    printf("aber decime el arreglo: \n");
    for (uint i = 0; i < cantArreglo; i++) {
        scanf("%f", &arreglo[i]);
    }
    ordenar(arreglo, cantArreglo - 1);
    for (uint i = 0; i < cantArreglo; i++) {
        printf("%f ", arreglo[i]);
    }
    return 0;
}

void ordenar(float* A, uint n) {
    if (n > 0) {
        ordenar(A, n - 1);
        insertarOrdenado(A, n - 1, A[n]);
    }
};

void insertarOrdenado(float* A, uint n, float e) {
    float temp;
    /* no es recursivo :(
    for (int i = n; A[i] > e && i >= 0 ; i--) {
        temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
    }*/

    if (A[n] > e) {
        temp = A[n];
        A[n] = A[n + 1];
        A[n + 1] = temp;
        if (n != 0) {
            insertarOrdenado(A, n - 1, e);
        }
    }
}

