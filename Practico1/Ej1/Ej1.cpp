#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Ejercicio 1 Fecha
(a)
Dada la siguiente representación de fecha:
Registro con dia d, mes m y año a
struct rep_fecha {
unsigned int d ;
unsigned int m ;
unsigned int a ;
};
Implemente una función main() que inicialice un arreglo de fechas (por ejemplo, con las fechas 10/10/2022,
15/5/2022 y 20/11/1992), lo ordene e imprima el resultado.
(b)
Considere ahora la siguiente representación de fecha:
struct rep_fecha {
unsigned int f ; // AAAAMMDD
}
Modifique el main() implementado en la parte (a) de manera que se adecúe a la nueva representación.
(c)
Considere ahora que cuenta con la siguiente interfaz del tipo de datos TFecha:
typedef struct rep_fecha * TFecha ;
Devuelve un 'TFecha ' con dia d, mes m y año a
TFecha crearFecha(unsigned int d, unsigned int m, unsigned int a);
Devuelve true si f1 es anterior a f2 , false en otro caso 
bool esAnterior(TFecha f1, TFecha f2);
Devuelve el día correspondiente a fecha
unsigned int dia(TFecha fecha);
Devuelve el mes correspondiente a fecha 
unsigned int mes(TFecha fecha);
Devuelve el año correspondiente a fecha
unsigned int anio(TFecha fecha);
Implemente la interfaz utilizando la representación de fecha dada en la parte(a).Reescriba la función
main() haciendo uso de las operaciones implementadas en la interfaz y sin acceder a la representación.
(d)
Implemente la interfaz utilizando ambas representaciones de fecha.
¿Es necesario realizar cambios en la función main() ?
*/

typedef struct rep_fecha {
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

typedef struct rep_fecha* TFecha;

typedef struct rep_colFechas {
    int capacidad;
    int cantidad;
    TFecha* arregloFechas;
} ColFechas;

/* Devuelve un 'TFecha ' con dia d, mes m y año a */
TFecha crearFecha(unsigned int d, unsigned int m, unsigned int a);

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool esAnterior(TFecha f1, TFecha f2);

/* Devuelve el día correspondiente a fecha */
unsigned int dia(TFecha fecha);

/* Devuelve el mes correspondiente a fecha */
unsigned int mes(TFecha fecha);

/* Devuelve el año correspondiente a fecha */
unsigned int anio(TFecha fecha);

ColFechas ordenarFechas(ColFechas coleccion) {
    // Implementación de un algoritmo de ordenamiento simple, como burbuja
    for (int i = 0; i < coleccion.cantidad - 1; i++) {
        for (int j = 0; j < coleccion.cantidad - i - 1; j++) {
            if (esAnterior(coleccion.arregloFechas[j], coleccion.arregloFechas[j+1])) {
                // Intercambiar fechas
                TFecha temp = coleccion.arregloFechas[j];
                coleccion.arregloFechas[j] = coleccion.arregloFechas[j + 1];
                coleccion.arregloFechas[j + 1] = temp;
            }
        }
    }
    return coleccion;
}

int main() {
    crearFecha(11, 9, 2002);
    // creamos coleccion de fechas
    ColFechas coleccion;
    // pedimos datos para inicializar la coleccion
    printf("Decime cuantas fechas pensas agregar (minimo 3 papi):");
    scanf("%d", &coleccion.cantidad);
    coleccion.capacidad = coleccion.cantidad + 1;
    // creamos el arreglo de fechas
    coleccion.arregloFechas = new TFecha[coleccion.capacidad];
    // pedimos las fechas al usuario
    int d, m, a;
    for (int i = 0; i < coleccion.cantidad; i++) {
        printf("Ingrese dia de la fecha %d: ", i + 1);
        scanf("%d", &d);
        printf("Ingrese mes de la fecha %d: ", i + 1);
        scanf("%d", &m);
        printf("Ingrese anio de la fecha %d: ", i + 1);
        scanf("%d", &a);
		coleccion.arregloFechas[i] = crearFecha(d, m, a);
    }
	coleccion.arregloFechas = ordenarFechas(coleccion).arregloFechas;
    for (int i = 0; i < coleccion.cantidad; i++) {
        printf("Fecha %d: (%d/%d/%d)\n", i + 1, dia(coleccion.arregloFechas[i]), mes(coleccion.arregloFechas[i]), anio(coleccion.arregloFechas[i]));
        /* Parte (a)
        printf("Fecha %d: %d\n", i + 1, coleccion.arregloFechas[i].f); */
    }
    return 0;
}

TFecha crearFecha(unsigned int d, unsigned int m, unsigned int a) {
    TFecha nuevaFecha = new rep_fecha;
	nuevaFecha->d = d;
	nuevaFecha->m = m;
	nuevaFecha->a = a;
    return nuevaFecha;
}

bool esAnterior(TFecha f1, TFecha f2) {
    if (f1->a > f2->a ||
       (f1->a == f2->a &&
        f1->m > f2->m) ||
       (f1->a == f2->a &&
        f1->m == f2->m &&
        f1->d > f2->d)) {
        return true;
    } else {
        return false;
    }
}

unsigned int dia(TFecha fecha) {
    return fecha->d;
}

unsigned int mes(TFecha fecha) {
    return fecha->m;
}

unsigned int anio(TFecha fecha) {
    return fecha->a;
}