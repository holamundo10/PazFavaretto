#include "nodoArbol.h"
#include <string.h>

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(persona aux)
{
    nodoArbol* nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->p=aux;
    nuevo->der=NULL;
    nuevo->izq=NULL;

    return nuevo;
}

nodoArbol* insertarNodoArbol(nodoArbol* arbol, nodoArbol* nuevo)
{

    if(!arbol)
    {
        arbol=nuevo;
    }
    else
    {
        if(strcmp(arbol->p.nombreApellido, nuevo->p.nombreApellido) < 0)
        {
            arbol->izq=insertarNodoArbol(arbol->izq, nuevo);
        }
        else
        {
            arbol->der=insertarNodoArbol(arbol->der, nuevo);
        }
    }

    return arbol;
}

int seleccionModoRecorrido()
{
    int modo=0;
    printf("\nSeleccione modo de recorrido: \ninOrder: 1");
    printf("\npostOrder: 2");
    printf("\npreOrder: 3");
    fflush(stdin);
    scanf("%d", &modo);
    while(modo==0||modo>3)
    {
        printf("\n\nEsa opcion es incorrecta. Escoja un numero indicado: ");
        fflush(stdin);
        scanf("%d", &modo);
    }
    return modo;
}

int MododeUso(){
    int m=0;
    while(m<1||m>3){
        printf("\n\nSeleccione modo de ordenacion deseado: ");
        printf("\nInorder: 1\nPostOrder: 2\nPreOrder: 3\nOpcion: ");
        fflush(stdin);
        scanf("%d", &m);
        if(m<1||m>3){
            printf("\n\nEsa opcion no existe.\nElija otra opcion.\n");
        }

    }
return m;
}

void mostrarArbol(nodoArbol* arbol, int modo)
{
    if(modo==1)
    {
        if(arbol)
        {
            mostrarArbol(arbol->izq, modo);
            printf("\n\n\nNombre y Apellido: %s\nCantidad de Articulos: %d\nTipo de Cliente: %d\nTipo de Pago: %d", arbol->p.nombreApellido, arbol->p.cantArticulos, arbol->p.tipo_cliente, arbol->p.tipo_pago);
            mostrarArbol(arbol->der, modo);

        }
    }
    else if(modo==2)
    {
        if(arbol)
        {
            mostrarArbol(arbol->izq, modo);
            mostrarArbol(arbol->der, modo);
            printf("\n\n\nNombre y Apellido: %s\nCantidad de Articulos: %d\nTipo de Cliente: %d\nTipo de Pago: %d", arbol->p.nombreApellido, arbol->p.cantArticulos, arbol->p.tipo_cliente, arbol->p.tipo_pago);

        }
    }
    else if(modo==3)
    {
        if(arbol)
        {
            printf("\n\n\nNombre y Apellido: %s\nCantidad de Articulos: %d\nTipo de Cliente: %d\nTipo de Pago: %d", arbol->p.nombreApellido, arbol->p.cantArticulos, arbol->p.tipo_cliente, arbol->p.tipo_pago);
            mostrarArbol(arbol->izq, modo);
            mostrarArbol(arbol->der, modo);
        }
    }
}

nodoArbol* pasarDeArchivoAUnArbol(char nombre[], nodoArbol* arbol)
{
    nodoArbol* nuevo;
    persona aux;

    FILE* archi=fopen(nombre, "rb");

    while(fread(&aux, sizeof(persona), 1, archi) > 0)
    {
        nuevo= crearNodoArbol(aux);
        arbol= insertarNodoArbol(arbol, nuevo);
    }

    fclose(archi);

    return arbol;
}
