#include "archivo.h"


void cargarInicialArchivoClientes(char nombre[])
{
    int i=0;
    persona aux;
    FILE* archi=fopen(nombre, "wb");
    printf("\nCargue un minimo de 30 datos de cliente: \n");
    for(i=0; i<3; i++)
    {
        aux= nuevoDatoCliente();
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
    printf("\n\nDesea ingresar mas clientes(S/N):  ");
    fflush(stdin);
    scanf("%c", &letra);
    if(letra == 's')
    {
        while(letra=='s')
        {
            aux= nuevoDatoCliente();
            fwrite(&aux, sizeof(persona), 1, archi);
            printf("-----------------------------------------------------");
            printf("\n\nDesea ingresar mas clientes(S/N):  ");
            fflush(stdin);
            scanf("%c", &letra);
        }
    }

    fclose(archi);
}

persona nuevoDatoCliente()
{
    persona aux;

    printf("\nNombre y apellido: ");
    fflush(stdin);
    gets(aux.nombreApellido);

    printf("\nCantidad de articulos: ");
    fflush(stdin);
    scanf("%d", &aux.cantArticulos);

    printf("\nTipo de cliente: ");
    printf("\n1: Embarazada");
    printf("\n2: Jubilado");
    printf("\n3: Comun\n");
    printf("\nIngrese numero: ");
    fflush(stdin);
    scanf("%d", &aux.tipo_cliente);

    while(aux.tipo_cliente > 3 || aux.tipo_cliente < 1)
    {
        printf("\n\nEse numero no es valido.\n");
        printf("\n1: Embarazada");
        printf("\n2: Jubilado");
        printf("\n3: Comun\n");
        printf("\nIngrese numero: ");
        fflush(stdin);
        scanf("%d", &aux.tipo_cliente);
    }

    printf("\nTipo de pago: ");
    printf("\n1: Efectivo");
    printf("\n2: Credito o debito\n");
    printf("\nIngrese numero: ");
    fflush(stdin);
    scanf("%d", &aux.tipo_pago);

    while(aux.tipo_pago != 1  && aux.tipo_pago != 2)
    {
        printf("\n\nEse numero no es valido.\n");
        printf("\n1: Efectivo");
        printf("\n2: Credito o debito\n");
        printf("\nIngrese numero: ");
        fflush(stdin);
        scanf("%d", &aux.tipo_pago);
    }

    aux.tiempoDeEspera=0;
    aux.tiempoProcesado=0;

    return aux;
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
    printf("\n\n-----------------------------------------------------");
    fclose(archi);
}

void inicioArchivo(char nombre[])
{
    cargarInicialArchivoClientes(nombre);
    AgregarClientes(nombre);
}
