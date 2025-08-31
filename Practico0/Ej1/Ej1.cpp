#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm> // Para sort, aunque con stdio es más clásico usar arrays y ordenar a mano

// Prototipo de función
float PromClase(float c1, float c2, float c3, float c4, float c5);

int main() {
    float calificaciones[5];

    printf("Ingrese las 5 calificaciones:\n");

    for (int i = 0; i < 5; i++) {
        printf("Calificacion %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
    }

    float promedio = PromClase(calificaciones[0], calificaciones[1], calificaciones[2], calificaciones[3], calificaciones[4]);

    printf("\nEl promedio de las 4 mejores calificaciones es: %.2f\n", promedio);

    return 0;
}

float PromClase(float c1, float c2, float c3, float c4, float c5) {
    float notas[5] = { c1, c2, c3, c4, c5 };

    // Ordenar notas (vamos a hacer un simple bubble sort para no depender de std::sort)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (notas[j] > notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    float suma = 0;
    for (int i = 1; i < 5; i++) { // sumamos las 4 más altas
        suma += notas[i];
    }

    return suma / 4;
}
