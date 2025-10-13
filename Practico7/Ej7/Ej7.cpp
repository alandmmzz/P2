#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Ejercicio 7 Editor de textos
Usualmente los editores de texto incluyen algún carácter especial (por ejemplo "backspace") que tiene la
funcionalidad de borrar el carácter previo no borrado. Por ejemplo, si # es este carácter, entonces el string
abc#d##e es en realidad ae. Los editores de texto también incluyen, por lo general, un carácter de borrado
de línea. Dicho carácter permite eliminar todos los caracteres previos de la línea de texto. A este carácter lo
denotaremos con el símbolo @.
Utilizando el TAD lista de caracteres, escribir un procedimiento que lea y luego imprima una lista de caracteres, que puede contener ocurrencias de los caracteres de borrado arriba descriptos.
Nota: Deberá definir el TAD lista de caracteres
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