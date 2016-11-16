#include <stdio.h> ///Fecha de entrega 22/11
#include <stdlib.h>
#include <string.h>
#include "nodoLista.h"
#include "nodoArbol.h"
#include "archivo.h"
#include "ADF.h"



int main()
{
    char nombre[40]= "archivoClientes.dat";
    MostrarClientes(nombre);
    nodoArbol* arbol= inicArbol();
    arbol= pasarDeArchivoAUnArbol(nombre, arbol);
    mostrarArbol(arbol, MododeUso());

    caja a[8];
    int valido=agregarCaja(a, 0);
    int i=elegirCaja();
    int abrirOcerrarCaja(a, i);

    return 0;
}
