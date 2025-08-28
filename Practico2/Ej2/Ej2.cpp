#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 2 Es Palindrome
Implemente un algoritmo recursivo que determina si un string es palíndrome. El string está representado en
un arreglo.
*/

typedef unsigned int uint;

uint indexFib;

bool esPalindrome(char* arreglo, uint inicio, uint final) {
    if (inicio >= final) {
        return true;
    }
    else {
        return (arreglo[inicio] == arreglo[final]) && esPalindrome(arreglo, inicio + 1, final - 1);
    }
}

int main() {
    char palabra[100];
    uint cantLetras;
    printf("cuantas letras tiene?: ");
    scanf("%d", &cantLetras);
    printf("q palabra es: ");
    for (uint i = 0; i < cantLetras; i++) {
        scanf(" %c", &palabra[i]);
    }
    if (esPalindrome(palabra, 0, cantLetras - 1)) {
        printf("es\n");
    } else {
        printf("no es\n");
    }
    return 0;
}
