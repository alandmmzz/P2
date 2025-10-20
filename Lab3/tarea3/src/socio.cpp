#include "../include/socio.h"

struct rep_socio {
    unsigned int ci;
    char nombre[MAX_NOMBRE_SOCIO];
    char apellido[MAX_APELLIDO_SOCIO];
    TFecha fechaAlta;
    int generosFavoritos[MAX_GENEROS_FAVORITOS];
    int generosTope;
};
 
TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta){
    TSocio nuevoSocio = new rep_socio;
    nuevoSocio->ci = ci;
    strcpy(nuevoSocio->nombre, nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);
    nuevoSocio->generosTope = 0;
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio){
    printf("Socio %d: %s %s\n", ciTSocio(socio), nombreTSocio(socio), apellidoTSocio(socio));
    printf("Fecha de alta: ");
    imprimirTFecha(fechaAltaTSocio(socio));
    printf("Géneros favoritos: ");
    for (int i = 0; i < cantidadGenerosFavoritosTSocio(socio); i++) {
        printf("%d ", socio->generosFavoritos[i]);
    }
    printf("\n");
}

void liberarTSocio(TSocio &socio){
    liberarTFecha(socio->fechaAlta);
    delete socio;
    socio = NULL;
}

int ciTSocio(TSocio socio){
    return socio->ci;
}

char* nombreTSocio(TSocio socio){
    return socio->nombre;
}

char* apellidoTSocio(TSocio socio){
    return socio->apellido;
}

TFecha fechaAltaTSocio(TSocio socio){
    return socio->fechaAlta;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
    if(cantidadGenerosFavoritosTSocio(socio) < MAX_GENEROS_FAVORITOS){
        socio->generosFavoritos[cantidadGenerosFavoritosTSocio(socio)] = idGenero;
        socio->generosTope++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    int i;
    for(i = 0; i < cantidadGenerosFavoritosTSocio(socio) && socio->generosFavoritos[i] != idGenero; i++){}
    if(i == cantidadGenerosFavoritosTSocio(socio)){
        return false;
    }
    return true;
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    return socio->generosTope;
}

TSocio copiarTSocio(TSocio socio){
    TSocio nuevoSocio = new rep_socio;
    nuevoSocio->ci = ciTSocio(socio);
    strcpy(nuevoSocio->nombre, nombreTSocio(socio));
    strcpy(nuevoSocio->apellido, apellidoTSocio(socio));
    nuevoSocio->fechaAlta = copiarTFecha(fechaAltaTSocio(socio));
    for(int i = 0; i < cantidadGenerosFavoritosTSocio(socio); i++){
        nuevoSocio->generosFavoritos[i] = socio->generosFavoritos[i];
    }
    nuevoSocio->generosTope = cantidadGenerosFavoritosTSocio(socio);
    return nuevoSocio;
}
