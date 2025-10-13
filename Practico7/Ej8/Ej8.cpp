#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 8 Notaciones
Los siguientes son ejemplos de expresiones compuestas de operadores binarios + y *, números naturales y
paréntesis, en notación infija y en notación posfija respectivamente:
Expresión infija de entrada: 10 * 5 + 3
Expresión posfija equivalente: 10 5 * 3 +
Expresión infija de entrada: 10 * ( 5 + 3 )
Expresión posfija equivalente: 10 5 3 + *
Expresión infija de entrada: 10 + 5 * 3
Expresión posfija equivalente: 10 5 3 * +
Expresión infija de entrada: ( 10 + 5 ) * 3
Expresión posfija equivalente: 10 5 + 3 *
Expresión infija de entrada: ( 10 + 5 * 10 + 3 ) * 3
Expresión posfija equivalente: 10 5 10 * 3 + + 3 *
Dada una expresión en notación infija, compuesta de operadores binarios + y *, números naturales y paréntesis, se pide:
(a) Escribir un procedimiento que transforme la expresión a su representación en notación posfija. Para
realizar esta operación use el TAD pila de operadores en donde ir colocando los operadores (según su
orden de precedencia). La expresión de entrada es una lista de operadores y operandos representando
la expresióninfija. La expresión de salida será una lista de operadores y operandos representando la
expresión posfija. Asuma que las expresiones de entrada son sintácticamente correctas.
(b) Evaluar la expresión en notación posfija. Para realizar esta operación utilize el TAD Pila donde ir colocando los operandos. Escribir a tales efectos un procedimiento que reciba la expresión a evaluar (lista
de operadores y operandos) y retorne un número natural.
Nota: Para ambas partes deberá especificar el TAD pila de operandos.

*/

struct nodo {
    char elem; 
    nodo *sig;
};

struct headQ {
    nodo * front;
    nodo * rear;
};

typedef headQ * QChar;

/* Crea la lista de chars vacia */
QChar crear () ;

/* Inserta un elemento al final de la lista de chars */
QChar enqueue ( char x , QChar l ) ;

/* Devuelve true si y solo si la lista de chars esta vacia */
bool esVacia ( QChar l) ;

/* Devuelve el primer elemento de la lista de chars. 
Precondicion: la lista no es vacia.*/
char primero ( QChar l ) ;

/* Devuelve la lista de chars sin su primer elemento.
Precondicion: la lista no es vacia.*/
QChar dequeue ( QChar l ) ;

/* Disuelve la lista.
Precondicion: la lista no es vacia.*/
QChar clear ( QChar l ) ;

/* Imprime la lista de chars.
Precondicion: la lista no es vacia.*/
QChar print ( QChar l ) ;

// 
void readChars( QChar l1) {
    QChar qFiltrada = crear();
    while ( !esVacia(l1) ) {
        if (primero(l1) == '#') {
            l1 = dequeue(l1);
            if (!esVacia(qFiltrada)) qFiltrada = dequeue(qFiltrada);
        } else {
            if (primero(l1) == '@') {
                l1 = dequeue(l1);
                qFiltrada = clear(qFiltrada);
            } else {
                qFiltrada = enqueue(primero(l1), qFiltrada);
                l1 = dequeue(l1);
            }
        }
    }
    if (!esVacia(qFiltrada)) print(qFiltrada);
}

void main() {
    
}