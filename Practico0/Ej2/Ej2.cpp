#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Ejercicio 2 Primos
// Escriba un procedimiento que calcule e imprima en pantalla todos los números primos entre dos enteros positivos A y B cualesquiera.

// funcion q va a determinar si un numero es primo ono
bool esPrimo(int n) {
    if (n <= 1) return false;  // 0, 1 y negativos no son primos
    if (n == 2) return true;   // 2 es el único primo par

    if (n % 2 == 0) return false; // descartamos pares > 2
    for (int i = 3; i <= n/2; i += 2) {
        if (n % i == 0) {
            return false; // si se divide, no es primo
        }
    }
    return true; // si no se divide por ninguno, es primo
}

int main() {
	int a, b;
    int primos[100];

    printf("Ingrese los numeros entre los que desea calcular los numeros primos:\n");
	scanf("%d %d", &a, &b);

    int contador = 0;
    for (int i = a; i < b; i++) {
        if (esPrimo(i)) {
            primos[contador] = i;
            contador++;
        }
    }

    printf("Los numeros primos entre %d y %d son:\n", a, b);
        for (int i = 0; i < contador; i++){
            printf("%d, ", primos[i]);
        }
    return 0;
}