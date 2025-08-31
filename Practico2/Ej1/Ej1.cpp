#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 1 Sucesión de Fibonacci
Implemente de forma recursiva la función fib que permite calcular los valores de la sucesión de Fibonacci
(0, 1, 1, 2, 3, 5, 8, 13, 21....). Esta sucesión se representa mediante la fórmula Fn = Fn−1 + Fn−2. Es decir,
cada elemento es la suma de los dos anteriores, siendo el primer elemento F0 = 0, y el segundo F1 = 1.
Por lo tanto F2 = 1 + 0, F3 = 1 + 1, F4 = 2 + 1, F5 = 3 + 2 y así sucesivamente.
*/

typedef unsigned int uint;

uint indexFib;

uint fib(uint index) {
    if (index <= 1) {
        return 1;
    }
    else {
        return fib(index - 1) + fib(index - 2);
    }
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
