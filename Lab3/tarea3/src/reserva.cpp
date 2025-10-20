
#include "../include/reserva.h"

struct rep_reserva {
    TSocio socio;
    TLibro libro;
};

TReserva crearTReserva(TSocio socio, TLibro libro){
    TReserva nuevaReserva = new rep_reserva;
    nuevaReserva->socio = socio;
    nuevaReserva->libro = libro;
    return nuevaReserva;
}

void imprimirTReserva(TReserva reserva){
    printf("Reserva de libro %s por %s %s.\n", tituloTLibro(libroTReserva(reserva)), nombreTSocio(socioTReserva(reserva)), apellidoTSocio(socioTReserva(reserva)));
}

void liberarTReserva(TReserva &reserva){
    liberarTSocio(reserva->socio);
    liberarTLibro(reserva->libro);
    delete reserva;
    reserva = NULL;
}

TSocio socioTReserva(TReserva reserva){
    return reserva->socio;
}

TLibro libroTReserva(TReserva reserva){
    return reserva->libro;
}

TReserva copiarTReserva(TReserva reserva){
    TReserva nuevaReserva = new rep_reserva;
    nuevaReserva->socio = copiarTSocio(reserva->socio);
    nuevaReserva->libro = copiarTLibro(reserva->libro);
    return nuevaReserva;
}

void liberarTReservaSoloEstructura(TReserva &reserva) {
    delete reserva;
    reserva = NULL;
}
