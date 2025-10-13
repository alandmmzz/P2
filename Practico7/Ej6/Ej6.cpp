#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 6 Dígitos (Primer Parcial 2005)
Considere la siguiente representación de números naturales mediante Listas de Dígitos en base 10:
- el número natural 1 se representa mediante la lista [1]
- el número natural 15 se representa mediante la lista [1,5]
- el número natural 123 se representa mediante la lista [1,2,3].
Considere la siguiente declaración del tipo Digito y las siguientes operaciones sobre Listas de Dígitos:

Se pide: implementar una función recursiva que calcule la suma de dos números naturales representados
mediante Listas de Dígitos, con el siguiente cabezal:
LDig suma(LDig l1, LDig l2);
Devuelve la lista de dígitos que representa al número natural resultado de sumar los dos números naturales parámetros representados mediante listas de dígitos.
La función Suma debe implementarse a partir de las operaciones presentadas arriba y no de definiciones
de tipo para LDig. Pueden utilizarse funciones auxiliares, siempre y cuando estas sean implementadas
recursivamente y, al igual que para Suma, se definan a partir de las operaciones presentadas arriba y no de
definiciones de tipo para LDig.
*/

typedef unsigned int Digito ;

/* Crea la lista de dí gitos vac ía */
LDig crear () ;

/* Inserta un elemento al principio de la lista de dí gitos */
LDig cons ( Digito x , LDig l ) ;

/* Devuelve true si y solo si la lista de dí gitos esta vac ía */
bool esVacia ( LDig l) ;

/* Devuelve el primer elemento de la lista de dí gitos. 
Precondición: la lista no es vac ía.*/
Digito primero ( LDig l ) ;

/* Devuelve la lista de dí gitos sin su primer elemento .
Precondici ón: la lista no es vac ía.*/
LDig resto ( LDig l ) ;

// función auxiliar que retorna la suma y deja el carry como parámetro por referencia
LDig sumaAux(LDig l1, LDig l2, int *carry) {
    if (esVacia(l1) && esVacia(l2)) {
        *carry = 0;
        return crear();
    }

    Digito d1 = esVacia(l1) ? 0 : primero(l1);
    Digito d2 = esVacia(l2) ? 0 : primero(l2);
    LDig r1 = esVacia(l1) ? crear() : resto(l1);
    LDig r2 = esVacia(l2) ? crear() : resto(l2);

    // recursión hacia el final
    LDig sumaRestante = sumaAux(r1, r2, carry);

    int suma = d1 + d2 + *carry;
    *carry = suma / 10;
    Digito digito = suma % 10;

    return cons(digito, sumaRestante);
}

LDig suma(LDig l1, LDig l2) {
    int carry = 0;
    LDig resultado = sumaAux(l1, l2, &carry);
    if (carry > 0)
        resultado = cons(carry, resultado);
    return resultado;
}

void main() {
    
}