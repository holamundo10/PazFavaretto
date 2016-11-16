#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED
#include <stdio.h>
#include "archivo.h"
#include "nodoLista.h"

typedef struct
{
    persona p;
    struct nodoArbol* izq;
    struct nodoArbol* der;
} nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(persona aux);
nodoArbol* insertarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo);
int seleccionModoRecorrido();
int MododeUso();
void mostrarArbol(nodoArbol* arbol, int modo);
nodoArbol* borrarUnNodoArbol(nodoArbol* arbol);

nodoArbol* pasarDeArchivoAUnArbol(char nombre[], nodoArbol* arbol);




#endif // NODOARBOL_H_INCLUDED
