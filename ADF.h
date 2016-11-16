#ifndef ADF_H_INCLUDED
#define ADF_H_INCLUDED
#include "nodoLista.h"
#include "archivo.h"
#include "nodoArbol.h"
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


int agregarCaja(caja a[], int validos);
int elegirCaja();
int abrirOcerrarCaja(caja a[], int i);
int buscarCaja(caja a[], int tipo_pago);
void mostrarCaja(caja a[], int nro_caja);
void agregarClienteACaja(caja a[], nodo* nuevo);
void agregarClienteACajaEnTiempoDeterminado(caja a[], nodo* nuevo, int tiempo);
int atenderClientes(caja a[]);

nodo* pasarDeArbolALineaDeCajas(nodoArbol* arbol, nodo* listaCajas);




#endif // ADF_H_INCLUDED
