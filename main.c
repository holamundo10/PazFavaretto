#include <stdio.h>///Fecha de entrega 22/11
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombreApellido[40];
    int cantArticulos;
    int tiempoDeEspera;
    int tiempoProcesado;
    int tipo_cliente;
    int tipo_pago;
} persona;

void cargarInicialArchivoClientes(char nombre[])
{
    int i=0;
    persona aux;
    FILE* archi=fopen(nombre, "wb");
    printf("\nCargue un minimo de 30 datos de cliente: \n");
    for(i=0; i<3; i++)
    {
        printf("\nNombre y apellido: ");
        fflush(stdin);
        gets(aux.nombreApellido);
        printf("\nCantidad de articulos: ");
        fflush(stdin);
        scanf("%d", &aux.cantArticulos);
        printf("\nTipo de cliente: ");
        fflush(stdin);
        scanf("%d", &aux.tipo_cliente);
        printf("\nTipo de pago: ");
        fflush(stdin);
        scanf("%d", &aux.tipo_pago);
        aux.tiempoDeEspera=0;
        aux.tiempoProcesado=0;
        fwrite(&aux, sizeof(persona), 1, archi);
        printf("-----------------------------------------------------");
    }
    fclose(archi);
}

void AgregarClientes(char nombre[])
{
    char letra='s';
    persona aux;
    FILE* archi=fopen(nombre, "ab");
    while(letra=='s')
    {
        printf("\nNombre y apellido: ");
        fflush(stdin);
        gets(aux.nombreApellido);
        printf("\nCantidad de articulos: ");
        fflush(stdin);
        scanf("%d", &aux.cantArticulos);
        printf("\nTipo de cliente: ");
        fflush(stdin);
        scanf("%d", &aux.tipo_cliente);
        printf("\nTipo de pago: ");
        fflush(stdin);
        scanf("%d", &aux.tipo_pago);
        aux.tiempoDeEspera=0;
        aux.tiempoProcesado=0;
        fwrite(&aux, sizeof(persona), 1, archi);
        printf("-----------------------------------------------------");
        printf("\n\nDesea ingresar mas clientes(S/N):  ");
        fflush(stdin);
        scanf("%c", &letra);
    }
    fclose(archi);
}

void MostrarClientes(char nombre[])
{
    persona aux;
    FILE* archi=fopen(nombre, "rb");
    if(archi)
    {
        while(fread(&aux, sizeof(persona), 1, archi)>0)
        {
            printf("\n\n\nNombre y Apellido: %s\nCantidad de Articulos: %d\nTipo de Cliente: %d\nTipo de Pago: %d", aux.nombreApellido, aux.cantArticulos, aux.tipo_cliente, aux.tipo_pago);
        }
    }
    printf("-----------------------------------------------------");
    fclose(archi);
}




int main()
{
    char nombre[40]= "archivoClientes.dat";
    cargarInicialArchivoClientes(nombre);
    MostrarClientes(nombre);
    AgregarClientes(nombre);
    MostrarClientes(nombre);

    return 0;
}
