#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 3
Se quiere implementar una función que cuente la cantidad de veces que una letra aparece en una frase.
La frase se representa como un arreglo de caracteres, y dado que se conoce que el largo máximo de
una frase es de 100 caracteres, la frase se implementa como char frase[100]. Usando esta representación
escriba una función Ocurrencias que recibe una frase, un natural llamado largo que representa el número
de caracteres en la frase, y el caracter a buscar (almacenado en la variable letra), y devuelve el número de
ocurrencias del carácter letra en el arreglo frase.*/

// funcion q va a determinar cuantas veces aparece una letra en una frase
int Ocurrencias(char frase[100], int largo, char letra) {
    int contador = 0;
    for (int i = 0; i < largo; i++) {
        if (frase[i] == letra) {
            contador++;
		}
    }
    
    return contador;
}

int main() {
    char frase[100];
	int largo;
    char letra;

    printf("Ingrese la cantidad de caracteres y la letra a buscar:\n");
    scanf("%d %c", &largo, &letra);
    printf("Ingrese la frase:\n");
    for (int i = 0; i < largo; i++) {
		scanf(" %c", &frase[i]);
    }

	int ocurrencias = Ocurrencias(frase, largo, letra);

    printf("La letra %c aparece %d veces en la frase:\n", letra, ocurrencias);
    for (int i = 0; i < largo; i++) {
        printf("%c", frase[i]);
    }
    return 0;
}