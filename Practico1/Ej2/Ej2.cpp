#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "punto.h"

/* Ejercicio 2 Punto
Un punto en un plano cartesiano se representa como un par ordenado de números, de forma que el primer
número corresponde a la coordenada horizontal x y el segundo número a la coordenada vertical y.
La siguiente es la especificación del módulo Punto.
*/

int main() {
	float x, y;
	Punto colPuntos[3];
	for (int i = 0; i < 3; i++) {
		printf("Ingrese las coordenadas del punto %d (x y): ", i + 1);
		scanf("%f %f", &x, &y);
		colPuntos[i] = crearPunto(x, y);
	}

	double distancia = calcularDistancia(colPuntos[0], colPuntos[1]);
	printf("La distancia entre los puntos 1 y 2 es: %.2f\n", distancia);
	distancia = calcularDistancia(colPuntos[1], colPuntos[2]);
	printf("La distancia entre los puntos 2 y 3 es: %.2f\n", distancia);
	distancia = calcularDistancia(colPuntos[0], colPuntos[2]);
	printf("La distancia entre los puntos 1 y 3 es: %.2f\n", distancia);
	return 0;
}