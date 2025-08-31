#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 4 Es Palíndrome
Considere ahora que la frase se representa como un arreglo de caracteres implementado como char
*frase.
(a) ¿Qué diferencias hay entre esta representación y la que utilizó en el Ejercicio 3?
(b) Escriba una función EsPalindrome que recibe una frase representada como un puntero a char y devuelve TRUE si la misma es un palíndrome, FALSE en otro caso.*/

int largoCadena(char* p) {
    int len = 0;
    while (*(p + len) != '\0') {
        len++;
    }
    return len;
}

// funcion q va a determinar si una frase es palíndromo
bool esPalindrome(char *frase) {
    int i = 0;
    int j = largoCadena(frase) - 1;
    while (i < j) {
        if (frase[i] != frase[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char* frase = nullptr;
    int capacidad = 1;
    int i = 0;
    char c;

    frase = new char[capacidad];

    printf("Ingrese una frase (termina con '.'): ");

    while (true) {
		scanf(" %c", &c); // lee un caracter, ignorando espacios
        if (c == '.') {
            break;
        }

        // agrandar si hace falta
        if (i >= capacidad) {
            int nuevaCap = capacidad * 2;
            char* nuevaFrase = new char[nuevaCap];
            for (int j = 0; j < capacidad; j++) {
                nuevaFrase[j] = frase[j];
            }
            delete[] frase;
            frase = nuevaFrase;
            capacidad = nuevaCap;
        }

        frase[i] = c;
        i++;
    }

    // terminamos la cadena con '\0'
    if (i >= capacidad) { // si no hay espacio para '\0', agrandamos
        char* nuevaFrase = new char[capacidad + 1];
        for (int j = 0; j < capacidad; j++) {
            nuevaFrase[j] = frase[j];
        }
        delete[] frase;
        frase = nuevaFrase;
        capacidad = capacidad + 1;
    }
    frase[i] = '\0';

    printf("La frase ingresada es: %s\n", frase);

    if (esPalindrome(frase)) {
        printf("Es palindromo.\n");
    }
    else {
        printf("No es palindromo.\n");
    }

    delete[] frase;  // liberá la memoria solo después de usarla
    return 0;
}