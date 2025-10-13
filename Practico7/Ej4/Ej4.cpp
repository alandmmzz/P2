#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 4 Ejercicio de examen Diciembre 2018
Se desea saber si una pila y una cola tienen exactamente los mismos elementos y fueron insertados en ellas
exactamente en el mismo orden. Para esto implemente la función mismosElementos usando las operaciones
de los TADs Pila y Cola. Al terminar, p y c deben quedar vacías. Los elementos de Pila y Cola son de un
tipo genérico que admite los usuales operadores de comparación.
bool mismosElementos ( Pila &p , Cola & c) ;
No se deben hacer comparaciones innecesarias. No se pueden usar funciones auxiliares.


PILA LIFO pop saca el primer elemento insertado
3 -> lo que devuelve pop 
2
1 -> primer elemento insertado

COLA FIFO dequeue saca el ultimo elemento insertado
3
2
1 -> primer elemento insertado // lo que devuelve dequeue

*/

bool mismosElementos ( Pila &p , Cola &c) {
    if (isEmptyP(p) && isEmptyC(c)) return true;
    if (isEmptyP(p) || isEmptyC(c)) return false;
    int primerP = pop(p);
    return (mismosElementos(p,c) && primerP == dequeue(c));
};

void main() {
    
}