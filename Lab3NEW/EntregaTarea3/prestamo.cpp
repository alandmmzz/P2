
#include "../include/prestamo.h"

struct rep_prestamo {
    TSocio socio;
    TLibro libro;
    TFecha fechaRetiro;
    TFecha fechaDevolucion;
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro){
  TPrestamo nuevoPrestamo = new rep_prestamo;
  nuevoPrestamo->socio = socio;
  nuevoPrestamo->libro = libro;
  nuevoPrestamo->fechaRetiro = fechaRetiro;
  nuevoPrestamo->fechaDevolucion = NULL; 
  return nuevoPrestamo;
}
 
void imprimirTPrestamo(TPrestamo prestamo){
  printf("Préstamo de libro %s a %s %s.\n", tituloTLibro(libroTPrestamo(prestamo)), nombreTSocio(socioTPrestamo(prestamo)), apellidoTSocio(socioTPrestamo(prestamo)));
  imprimirTFecha(fechaRetiroTPrestamo(prestamo));
  if(fueRetornadoTPrestamo(prestamo)){
      imprimirTFecha(fechaDevolucionTPrestamo(prestamo));
  } else {
      printf("No retornado\n");
  }
}

void liberarTPrestamo(TPrestamo &prestamo){
  liberarTSocio(prestamo->socio);
  liberarTLibro(prestamo->libro);
  liberarTFecha(prestamo->fechaRetiro);
  if(prestamo->fechaDevolucion != NULL){
      liberarTFecha(prestamo->fechaDevolucion);
  }
  delete prestamo;
  prestamo = NULL;
}

TSocio socioTPrestamo(TPrestamo prestamo){
  return prestamo->socio;
}
 
TFecha fechaRetiroTPrestamo(TPrestamo prestamo){
  return prestamo->fechaRetiro;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo){
  return prestamo->fechaDevolucion;
}

TLibro libroTPrestamo(TPrestamo prestamo){
  return prestamo->libro;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo){
  if(prestamo->fechaDevolucion != NULL){
      return true;
  }
  return false;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion){
  if(prestamo->fechaDevolucion != NULL){
      liberarTFecha(prestamo->fechaDevolucion);
  }
  prestamo->fechaDevolucion = fechaDevolucion;
}

TPrestamo copiarTPrestamo(TPrestamo prestamo){
  TPrestamo nuevoPrestamo = new rep_prestamo;
  nuevoPrestamo->socio = copiarTSocio(socioTPrestamo(prestamo));
  nuevoPrestamo->libro = copiarTLibro(libroTPrestamo(prestamo));
  nuevoPrestamo->fechaRetiro = copiarTFecha(fechaRetiroTPrestamo(prestamo));
  if (fueRetornadoTPrestamo(prestamo)){
      nuevoPrestamo->fechaDevolucion = copiarTFecha(fechaDevolucionTPrestamo(prestamo));
  }
  else {
      nuevoPrestamo->fechaDevolucion = NULL;
  }
  return nuevoPrestamo;
}

/* FUNCIONES TAREA 3 */

void liberarTPrestamoSoloEstructura(TPrestamo &prestamo) {
  liberarTFecha(prestamo->fechaRetiro);
  if(prestamo->fechaDevolucion != NULL){
      liberarTFecha(prestamo->fechaDevolucion);
  }
  delete prestamo;
  prestamo = NULL;
}