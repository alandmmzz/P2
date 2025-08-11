#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 5 Insertar Punto
Un punto en un plano cartesiano se representa como un par ordenado de números, de forma que el primer
número corresponde a la coordenada horizontal x y el segundo número a la coordenada vertical y.
Los siguientes tipos definen los conceptos punto y colección de puntos. La colección se representa con un
arreglo con tope.

typedef struct rep_punto {
    int coordX, coordY;
} Punto;

typedef struct rep_colPuntos {
    int capacidad;
    int cantidad;
    Punto* arregloPuntos;
} ColPuntos;

(a) Implemente una función que inserte un punto al final de una colección de puntos:
void insertarPunto ( ColPuntos & colPtos , Punto pto ) ;
Si la cantidad de puntos es igual a la capacidad del arreglo la operación no tiene efecto.
(b) Defina e implemente una función que dada una colección de puntos devuelva el valor de la menor
coordenada x de sus puntos.
(c) Defina e implemente una función que dados dos puntos devuelva el punto medio del segmento determinado por ambos.*/

typedef struct rep_punto {
    int coordX, coordY;
} Punto;

typedef struct rep_colPuntos {
    int capacidad;
    int cantidad;
    Punto* arregloPuntos;
} ColPuntos;

void insertarPunto(ColPuntos &colPtos, Punto pto) {
   /* Si la cantidad de puntos es igual a la capacidad del arreglo la operación no tiene efecto.
    if (colPtos.cantidad == colPtos.capacidad) {
	   int nuevaCapacidad = colPtos.capacidad * 2;
	   Punto* nuevoArregloMasGrande = new Punto[nuevaCapacidad];
       for (int i = 0; i < colPtos.cantidad; i++) {
           nuevoArregloMasGrande[i] = colPtos.arregloPuntos[i];
	   }
       delete[] colPtos.arregloPuntos;
       colPtos.arregloPuntos = nuevoArregloMasGrande;
       colPtos.capacidad = nuevaCapacidad;
   }*/
    if (colPtos.cantidad < colPtos.capacidad) {
        colPtos.arregloPuntos[colPtos.cantidad] = pto;
        colPtos.cantidad++;
    }
}

int menorCoordenadaX(ColPuntos colPtos) {
    if (colPtos.cantidad == 0) {
        return -1; // Indica que no hay puntos
    }
    int menor = colPtos.arregloPuntos[0].coordX;
    for (int i = 1; i < colPtos.cantidad; i++) {
        if (colPtos.arregloPuntos[i].coordX < menor) {
            menor = colPtos.arregloPuntos[i].coordX;
        }
    }
    return menor;
}

Punto puntoMedio(Punto pto1, Punto pto2) {
	Punto puntoMedio;

	puntoMedio.coordX = (pto1.coordX + pto2.coordX) / 2;
    puntoMedio.coordY = (pto1.coordY + pto2.coordY) / 2;
    
    return puntoMedio;
}

int main() {
	//creamos coleccion de puntos
    ColPuntos coleccion;
	//pedimos datos para inicializar la coleccion
	printf("Decime cuantos puntos pensas agregar (minimo 2 papi):");
	scanf("%d", &coleccion.cantidad);
    coleccion.capacidad = coleccion.cantidad + 1;
	//creamos el arreglo de puntos
    coleccion.arregloPuntos = new Punto[coleccion.capacidad];
	//pedimos los puntos al usuario
    for (int i = 0; i < coleccion.cantidad; i++) {
        printf("Ingrese coordenada X del punto %d: ", i + 1);
        scanf("%d", &coleccion.arregloPuntos[i].coordX);
        printf("Ingrese coordenada Y del punto %d: ", i + 1);
        scanf("%d", &coleccion.arregloPuntos[i].coordY);
	}
    for (int i = 0; i < coleccion.cantidad; i++) {
        printf("Punto %d: (%d, %d)\n", i + 1, coleccion.arregloPuntos[i].coordX, coleccion.arregloPuntos[i].coordY);
	}
    insertarPunto(coleccion, puntoMedio(coleccion.arregloPuntos[0], coleccion.arregloPuntos[1]));
    for (int i = 0; i < coleccion.cantidad; i++) {
        printf("Punto %d: (%d, %d)\n", i + 1, coleccion.arregloPuntos[i].coordX, coleccion.arregloPuntos[i].coordY);
    }
    return 0;
}