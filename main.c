#include <stdio.h>///Fecha de entrega 22/11
#include <stdlib.h>
#include <string.h>
#include "nodoLista.h"
#include "nodoArbol.h"
#include "archivo.h"




int main()
{
    /*char nombre[40]= "archivoClientes.dat";
    /*MostrarClientes(nombre);
    nodoArbol* arbol= inicArbol();
    arbol= pasarDeArchivoAUnArbol(nombre, arbol);
    mostrarArbol(arbol, MododeUso());*/

    nodo* lista=inicLista();
    lista=agregarEnOrdenPorCantidad(lista, nuevoNodoLista());
    mostrarLista(lista);
    lista=agregarEnOrdenPorCantidad(lista, nuevoNodoLista());
    mostrarLista(lista);
    lista=agregarEnOrdenPorCantidad(lista, nuevoNodoLista());
    mostrarLista(lista);


    return 0;
}
