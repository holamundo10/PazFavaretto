#ifndef ADF_H_INCLUDED
#define ADF_H_INCLUDED

#include <stdio.h>

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];
    fila filita;
} caja;

/* funciones a crear

agregarCaja;

abrirOcerrarCaja;

buscarCaja;

mostrarCaja;

agregarClienteACaja;

agregarClienteACajaEnTiempoDeterminado;

atenderClientes;

*/


#endif // ADF_H_INCLUDED
