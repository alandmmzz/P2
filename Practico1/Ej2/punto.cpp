#include "punto.h"
#include <math.h>

struct rep_punto {
	double x;
	double y;
};

Punto crearPunto(double x, double y) {
	Punto nuevoPunto = new rep_punto;
	nuevoPunto->x = x;
	nuevoPunto->y = y;
	return nuevoPunto;
}

double coordX(Punto punto) {
	return punto->x;
}

double coordY(Punto punto) {
	return punto->y;
}

double calcularDistancia(Punto pto1, Punto pto2) {
	double distancia = sqrt(pow(coordX(pto1) - coordX(pto2), 2) + pow(coordY(pto1) - coordY(pto2), 2));
	return distancia;
}