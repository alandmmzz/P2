#include "../include/biblioteca.h"
#include <assert.h>

struct rep_biblioteca {
    TABBLibros arbolLibros;
    TLSESocios listaSocios;
    TLDEPrestamos listaPrestamos;
    TAGGeneros arbolGeneros;
    TColaReservas colaReservas;
};

TBiblioteca crearTBiblioteca(){
    TBiblioteca nuevaBiblioteca = new rep_biblioteca;
    nuevaBiblioteca->arbolLibros = crearTABBLibrosVacio();
    nuevaBiblioteca->listaSocios = crearTLSESociosVacia();
    nuevaBiblioteca->listaPrestamos = crearTLDEPrestamosVacia();
    nuevaBiblioteca->arbolGeneros = crearTAGGeneros();
    nuevaBiblioteca->colaReservas = crearTColaReservas();
    return nuevaBiblioteca;
}

void agregarLibroTBiblioteca(TBiblioteca biblioteca, TLibro libro){
    insertarLibroTABBLibros(biblioteca->arbolLibros, libro);
}

void agregarSocioTBiblioteca(TBiblioteca biblioteca, TSocio socio){
    insertarTLSESocios(biblioteca->listaSocios, socio);
}

void prestarLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro, TFecha fechaPrestamo){
    TSocio socio = obtenerSocioTLSESocios(biblioteca->listaSocios, ciSocio);
    TLibro libro = obtenerLibroTABBLibros(biblioteca->arbolLibros, isbnLibro);
    TPrestamo nuevoPrestamo = crearTPrestamo(socio, libro, fechaPrestamo);
    insertarTLDEPrestamos(biblioteca->listaPrestamos, nuevoPrestamo);
}

bool existePrestamoActivoDeLibroTLDEPrestamos(TBiblioteca biblioteca, int isbnLibro) {
    bool resultado = false;
    TLDEPrestamos prestamos = filtrarPrestamosTLDEPrestamos(biblioteca->listaPrestamos, 1);
    nat cantidad = cantidadTLDEPrestamos(prestamos);
    for (nat i = 1; i <= cantidad && resultado == false; i++) {
        TPrestamo prestamo = obtenerNesimoTLDEPrestamos(prestamos, i);
        TLibro libroPrestamo = libroTPrestamo(prestamo);
        if (isbnTLibro(libroPrestamo) == isbnLibro) {
            resultado = true;
        }
    }
    liberarTLDEPrestamos(prestamos);
    return resultado;
}

bool disponibleLibroTBiblioteca(TBiblioteca biblioteca, int isbnLibro){
    return ( existeLibroTABBLibros(biblioteca->arbolLibros, isbnLibro) && 
             !existePrestamoActivoDeLibroTLDEPrestamos(biblioteca, isbnLibro) );
}

void reservarLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro){
    TSocio socio = obtenerSocioTLSESocios(biblioteca->listaSocios, ciSocio);
    TLibro libro = obtenerLibroTABBLibros(biblioteca->arbolLibros, isbnLibro);
    TReserva nuevaReserva = crearTReserva(socio, libro);
    encolarTColaReservas(biblioteca->colaReservas, nuevaReserva);
}

void devolverLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro, TFecha fechaPrestamo, TFecha fechaDevolucion){
    nat cantidad = cantidadTLDEPrestamos(biblioteca->listaPrestamos);
    TPrestamo prestamo = obtenerPrimeroTLDEPrestamos(biblioteca->listaPrestamos);
    TLibro libroPrestamo = libroTPrestamo(prestamo);
    TSocio socioPrestamo = socioTPrestamo(prestamo);
    TFecha fechaRetiroPrestamo = fechaRetiroTPrestamo(prestamo);
    for (nat i = 1;
        i <= cantidad &&
        (isbnTLibro(libroPrestamo) != isbnLibro) &&
        (ciTSocio(socioPrestamo) != ciSocio) &&
        compararTFechas(fechaRetiroPrestamo, fechaPrestamo) != 0;
        i++) {
        prestamo = obtenerNesimoTLDEPrestamos(biblioteca->listaPrestamos, i);
        libroPrestamo = libroTPrestamo(prestamo);
        socioPrestamo = socioTPrestamo(prestamo);
        fechaRetiroPrestamo = fechaRetiroTPrestamo(prestamo);
    }
    actualizarFechaDevolucionTPrestamo(prestamo, fechaDevolucion);
}

void imprimirSociosTBiblioteca(TBiblioteca biblioteca){
    imprimirTLSESocios(biblioteca->listaSocios);
}

void imprimirLibrosTBiblioteca(TBiblioteca biblioteca){
    imprimirTABBLibros(biblioteca->arbolLibros);
}

void imprimirReservasTBiblioteca(TBiblioteca biblioteca){
    imprimirTColaReservas(biblioteca->colaReservas);
}

void imprimirPrestamosTBiblioteca(TBiblioteca biblioteca){
    imprimirTLDEPrestamos(biblioteca->listaPrestamos);
}

void agregarGeneroABiblioteca(TBiblioteca biblioteca, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE]) {
    insertarGeneroTAGGeneros(biblioteca->arbolGeneros, idGeneroPadre, idGenero, nombreGenero);
}


TABBLibros obtenerLibrosDeGenero(TBiblioteca biblioteca, int idGenero) {
    TConjuntoGeneros conjunto = obtenerConjuntoGeneros(biblioteca->arbolGeneros, idGenero);
    TABBLibros resultado = crearTABBLibrosVacio();

    int total = cantidadTABBLibros(biblioteca->arbolLibros);
    for (int i = 1; i <= total; i++) {
        TLibro libro = obtenerNesimoLibroTABBLibros(biblioteca->arbolLibros, i);
        int generoLibro = idGeneroTLibro(libro);

        // 4️⃣ Si el género del libro pertenece al conjunto, agregarlo
        if (perteneceTConjuntoGeneros(conjunto, generoLibro)) {
            TLibro copia = copiarTLibro(libro);
            insertarLibroTABBLibros(resultado, copia);
        }
    }

    // 5️⃣ Liberar el conjunto
    liberarTConjuntoGeneros(conjunto);

    return resultado;
}



void liberarTBiblioteca(TBiblioteca &biblioteca) {
    if (biblioteca == NULL) return;
    liberarTColaReservasSoloEstructura(biblioteca->colaReservas);
    liberarTLDEPrestamosSoloEstructura(biblioteca->listaPrestamos);
    liberarTABBLibros(biblioteca->arbolLibros);
    liberarTLSESocios(biblioteca->listaSocios);
    liberarTAGGeneros(biblioteca->arbolGeneros);
    delete biblioteca;
    biblioteca = NULL;
}
