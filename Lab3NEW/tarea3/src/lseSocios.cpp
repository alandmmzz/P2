
#include "../include/lseSocios.h"

struct rep_lseSocios {
	TSocio socio;
	rep_lseSocios* sig;
};

TLSESocios crearTLSESociosVacia(){
    return NULL;
}

bool esVaciaTLSESocios(TLSESocios lseSocios){
	if (lseSocios == NULL) {
		return true;
	}
	return false;
}

void imprimirTLSESocios(TLSESocios lseSocios){
	printf("Lista de Socios:\n");
	if (lseSocios != NULL) {
		imprimirTSocio(lseSocios->socio);
		while (lseSocios->sig != NULL) {
			imprimirTSocio(lseSocios->sig->socio);
			lseSocios = lseSocios->sig ;
		}
	}
}

void liberarTLSESocios(TLSESocios &lseSocios) {
    while (lseSocios != NULL) {
        TLSESocios borrar = lseSocios;
        liberarTSocio(borrar->socio);
        lseSocios = lseSocios->sig;
        delete borrar;
    }
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
	TLSESocios nuevo = new rep_lseSocios;
	nuevo->socio = socio;
	if (lseSocios != NULL) {
		if (compararTFechas(fechaAltaTSocio(socio), fechaAltaTSocio(lseSocios->socio)) == -1) {
			nuevo->sig = lseSocios;
			lseSocios = nuevo;
		} else {
			TLSESocios aux = lseSocios;
			while (aux->sig != NULL && compararTFechas(fechaAltaTSocio(socio), fechaAltaTSocio(aux->sig->socio)) > -1) {
				aux = aux->sig ;
			}
			if (aux->sig == NULL) {
				aux->sig = nuevo;
				nuevo->sig = NULL;
			} else {
				nuevo->sig = aux->sig;
				aux->sig = nuevo;
			}
		}
	} else {
		nuevo->sig = NULL;
		lseSocios = nuevo;
	}
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	if (lseSocios != NULL) {
		while (lseSocios != NULL && ciTSocio(lseSocios->socio) != ci) {
			lseSocios = lseSocios->sig ;
		}
		if (lseSocios != NULL) {
			return true;
		}
	}
	return false;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
	while (ciTSocio(lseSocios->socio) != ci) {
		lseSocios = lseSocios->sig ;
	}
	return lseSocios->socio;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n) {
    if (n <= 0) return NULL;
    int i = 1;
    while (lseSocios != NULL && i < n) {
        lseSocios = lseSocios->sig;
        i++;
    }
    if (lseSocios == NULL) {
        return NULL;
    }
    return lseSocios->socio;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	nat cantidad = 0;
	while (lseSocios != NULL) {
		lseSocios = lseSocios->sig ;
		cantidad++;
	}
	return cantidad;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
	TLSESocios borrar, aux = lseSocios;
	if (ciTSocio(lseSocios->socio) == ci) {
		borrar = lseSocios;
		lseSocios = lseSocios->sig;
	} else {
		while (aux->sig != NULL && ciTSocio(aux->sig->socio) != ci) {
			aux = aux->sig ;
		}
		borrar = aux->sig;
		aux->sig = borrar->sig;
	}
	liberarTSocio(borrar->socio);
	delete borrar;
}