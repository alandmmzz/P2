#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 5
Implemente un algoritmo recursivo que calcule el máximo común divisor de dos enteros positivos */

typedef unsigned int uint;

uint maxComunDenominador(uint n, uint m) {
    if (m == 0) {
        return n;
    }
    else {
        return maxComunDenominador(m, n % m);
    }
};

uint num1, num2;

int main() {
    printf("dame dos num:");
    scanf("%d %d", &num1, &num2);
    printf("El maximo comun divisor es: %d\n", maxComunDenominador(num1, num2));
    return 0;
}
