#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 5 Josefo
El libro The Art of Programming Vol. 1, Donald Knuth plantea un problema matemático conocido como el
problema de Josefo. El mismo lleva el nombre del historiador judío Flavio Josefo y se basa en un relato de
lo ocurrido en el sitio de Yodfat donde él y sus camaradas decidieron suicidarse antes de caer en manos de
los romanos. Se ubicaron en un círculo, eligieron una posición de inicio y comenzaron a suicidarse en orden
(sentido horario), cada 7 personas. Se numeran empeando en 1 y a quien le corresponde el número 7 se
suicida. La secuencia vuelve a 1 con el siguiente del que se suicida. El proceso de eliminación de personas
del círculo continúa hasta que mueren todos. Según cuenta la leyenda, Josefo (que también era un gran
matemático) logró ubicarse en la posición del último en tener que suicidarse, y que en lugar de hacerlo se
pasó al lado romano y salvó su vida.
El problema consiste entonces en, dados dos enteros no negativos, n, que representa la cantidad de personas, y k, que indica la cantidad de pasos hasta llegar a la persona que debe suicidarse, determinar cuál es
la posición dentro del círculo que ocupará el último sobreviviente.
Para esto es necesario calcular toda la secuencia de ejecuciones.
Por ejemplo, si n = 8 y k = 2, tendremos un círculo con 8 personas identificadas desde la persona 1 a
la persona 8. Las personas que se suicidan según su posición son: 2, 4, 6, 8, 3, 7 y 5, siendo la persona
ubicada en la posición 1 la última en suicidarse.
Se pide: implementar una función Posiciones que dados un número de personas n y un k devuelva, en
O(n × k), una lista de enteros con la secuencia de posiciones que resuelve el problema de Josefo.
Se sugiere utilizar el TAD Cola de Naturales para representar las posiciones alrededor del círculo.
LNat posiciones (unsigned int n, unsigned int k);
/* Retorna la lista de dígitos que representa la secuencia de posiciones que resuelven el problema de Josefo
*/

LNat posiciones (unsigned int n, unsigned int k) {
    q = nullQ();
    posiciones = nullQ();
    int x;
    for(int i = 1; i <= n; i++) {
        queue(i, q);
    }
    while (!isEmpty(q)) {
        for(int i = 0; i < k - 1; i++) {
            x = dequeue(q);
            enqueue(x, q);
        }
        enqueue(dequeue(q), posiciones);
    }
    return posiciones;
}

void main() {
    
}