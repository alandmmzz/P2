#include "../include/fecha.h"

struct rep_fecha {
    nat dia, mes, anio;
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;

    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    delete fecha;
    fecha = NULL;
}
void imprimirTFecha(TFecha fecha) {
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
}

TFecha copiarTFecha(TFecha fecha) {
    TFecha copia = new rep_fecha;
    copia->dia = fecha->dia;
    copia->mes = fecha->mes;
    copia->anio = fecha->anio;
    return copia;
}

// Función para obtener la cantidad de días de un mes en un año dado
static nat diasMes(nat mes, nat anio) {
    if (mes == 2) {
        // Calculamos años bisiestos
        if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return 30;
        } else {
            return 31;
        }
    }
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}


int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    if (fecha1->anio > fecha2->anio) {
        res = 1;
    } else {
        if (fecha1->anio < fecha2->anio) {
            res = -1;
        } else {
            if (fecha1->mes > fecha2->mes) {
                res = 1;
            } else {
                if (fecha1->mes < fecha2->mes) {
                    res = -1;
                } else {
                    if (fecha1->dia > fecha2->dia) {
                        res = 1;
                    } else {
                        if (fecha1->dia < fecha2->dia) {
                            res = -1;
                        }
                    }
                }
            }
        }
    }
    return res;
}
