#ifndef NODOLISTA_H_INCLUDED
#define NODOLISTA_H_INCLUDED

#include <stdio.h>
#include "archivo.h"

typedef struct
{
    persona cliente;
    struct nodo* sig;
    struct nodo* ant;
} nodo;

typedef struct
{
    struct nodo* inicio;
    struct nodo* fin;
} fila;

nodo* inicLista();
nodo* crearNodoLista(persona aux);
nodo* nuevoNodoLista();
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo);
nodo* buscarUltimoLista(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenTipoCliente(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenPorCantidad(nodo* lista, nodo* nuevo);
void mostrarLista(nodo* lista);
nodo* borrarNodo(nodo* lista);
nodo* borrarPrimerNodo(nodo* lista);


fila* inicFila();
fila* agregar(fila* filita, nodo* nuevo);
fila* quitar(fila* filita);
void mostrar(fila* filita);
int filaVacia(fila* filita);




#endif // NODOLISTA_H_INCLUDED
