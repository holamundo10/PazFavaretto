#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include <stdio.h>
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


void cargarInicialArchivoClientes(char nombre[]);
void AgregarClientes(char nombre[]);
void MostrarClientes(char nombre[]);

void inicioArchivo(char nombre[]);
persona nuevoDatoCliente();



#endif // ARCHIVO_H_INCLUDED
