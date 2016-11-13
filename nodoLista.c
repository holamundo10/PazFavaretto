#include "nodoLista.h"

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodoLista(persona aux)
{
    nodo* lista=(nodo*)malloc(sizeof(nodo));
    lista->cliente=aux;
    lista->ant=NULL;
    lista->sig=NULL;
    return lista;
}

nodo* nuevoNodoLista()
{
    persona p;
    printf("\n\nIngrese un nombre: ");
    fflush(stdin);
    scanf("%s", p.nombreApellido);
    printf("\nIngrese CantdeArticulos: ");
    fflush(stdin);
    scanf("%d", &p.cantArticulos);
    printf("\nTipo de Cliente: ");
    fflush(stdin);
    scanf("%d", &p.tipo_cliente);
    printf("\nTipo de Pago: ");
    fflush(stdin);
    scanf("%d", &p.tipo_pago);
    p.tiempoDeEspera=0;
    p.tiempoProcesado=0;
    nodo* a=crearNodoLista(p);
    return a;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo)
{
    if(lista)
    {
        nuevo->sig=lista;
        lista->ant=nuevo;
    }
    return nuevo;
}

nodo* buscarUltimoLista(nodo* lista)
{
    while(lista->sig)
    {
        lista=lista->sig;
    }
    return lista;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        nodo* ult=buscarUltimoLista(lista);
        ult->sig=nuevo;
        nuevo->ant=ult;
    }
    return lista;
}

nodo* agregarEnOrdenTipoCliente(nodo* lista, nodo* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        if(lista->cliente.tipo_cliente>nuevo->cliente.tipo_cliente){
            lista=agregarAlPrincipio(lista, nuevo);
        }
        else{
            nodo* ante=lista;
            nodo* seg=lista->sig;
            while((seg)&&(seg->cliente.tipo_cliente<=nuevo->cliente.tipo_cliente))
            {
                seg=seg->sig;
            }
            nuevo->sig=seg;
            ante->sig=nuevo;
            nuevo->ant=ante;
            if(seg)
            {
                seg->ant=nuevo;
            }
        }
    }
    return lista;
}

nodo* agregarEnOrdenPorCantidad(nodo* lista, nodo* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {   if(lista->cliente.cantArticulos>nuevo->cliente.cantArticulos){
            lista=agregarAlPrincipio(lista, nuevo);
        }
        else{

            nodo* ante=lista;
            nodo* seg=lista->sig;
            while((seg)&&(seg->cliente.cantArticulos<=nuevo->cliente.cantArticulos))
            {
                ante=seg;
                seg=seg->sig;
            }
            nuevo->ant= ante;
            nuevo->sig=seg;
            ante->sig=nuevo;
            if(seg)
            {
                seg->ant=nuevo;
            }
        }
    }
return lista;
}

void mostrarLista(nodo* lista)
{
    while(lista)
    {
        printf("\n\nNombre: %s\nCantidad de Articulos: %d\nTipo de Cliente: %d\nTipo de Pago: %d\n\n", lista->cliente.nombreApellido, lista->cliente.cantArticulos, lista->cliente.tipo_cliente, lista->cliente.tipo_pago);
        lista=lista->sig;
    }
    printf("\n----------------------------------------------------------------------------------------------- \n\n");
}

nodo* borrarNodo(nodo* lista)
{
    printf("\nIngrese nombre y apellido del cliente a borrar: ");
    fflush(stdin);
    char nombre[40];
    scanf("%s", nombre);
    nodo* seg=lista;
    nodo* borrar;
    while(seg)
    {
        if(strcmp(seg->cliente.nombreApellido, nombre)==0)
        {
            borrar=seg;
        }
        seg=seg->sig;
    }
    nodo* sig=borrar->sig;
    seg=borrar->ant;
    seg->sig=sig;
    sig->ant=seg;
    free(borrar);
    return lista;
}


nodo* borrarPrimerNodo(nodo* lista)
{
    nodo* borrar=lista;
    lista=lista->sig;
    lista->ant=NULL;
    free(borrar);
    return lista;
}

fila* inicFila()
{
    return NULL;
}

fila* agregar(fila* filita, nodo* nuevo)
{
    if(!filita->inicio)
    {
        filita->inicio=nuevo;
        filita->fin=nuevo;
    }
    else
    {
        nodo* aux=filita->fin;
        aux->sig=nuevo;
        nuevo->ant=aux;
        filita->fin=nuevo;
    }
    return filita;
}

fila* quitar(fila* filita)
{
    if(filita->inicio)
    {
        nodo* aux=filita->inicio;
        nodo* borrar=aux;
        aux=aux->sig;
        aux->ant=NULL;
        free(borrar);
        filita->inicio= aux;
    }
    else
    {
        printf("\n\nLa Fila ya esta vacia.\n\n");
    }
    return filita;
}

void mostrar(fila* filita)
{
    nodo* lista=filita->inicio;
    while(lista)
    {
        printf("\n\nNombre: %s\nCantidad de Articulos: %d\nTipo de Cliente: %d\nTipo de Pago: %d\n\n", lista->cliente.nombreApellido, lista->cliente.cantArticulos, lista->cliente.tipo_cliente, lista->cliente.tipo_pago);
        lista=lista->sig;
    }
    printf("\n----------------------------------------------------------------------------------------------- \n\n");
}

int filaVacia(fila* filita)
{
    int i=0;
    if(filita->inicio)
    {
        i=1;
    }
    return i;
}
