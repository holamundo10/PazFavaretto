#include "ADF.h"

int agregarCaja(caja a[], int v)
{
    if(v>7)
    {
        printf("\n\nYa no se pueden agregar mas cajas. ");
    }
    else
    {
        char letra='s';
        while(v<8&&letra=='s')
        {
            printf("\n\nIngrese el numero de la caja: ");
            fflush(stdin);
            scanf("%d", &a[v].nro_de_caja);

            printf("\n Ingrese el nombre del cajero: ");
            fflush(stdin);
            gets(a[v].nombreCajero);

            printf("\nIngrese el tipo de pago aceptado en esta caja (1/2/3): ");
            fflush(stdin);
            scanf("%d", &a[v].tipo_pago);

            printf("\nEsta caja estara abierta(1) o cerrada(2): ");
            fflush(stdin);
            scanf("%d", &a[v].abiertaOcerrada);

            int op=0;
            while(op<1||op>4)
            {
                printf("\nSelecciones el algoritmo de ordenacion a utilizar en esta caja: ");
                printf("\n\nFIFO: 1\nSJF no apropiativo: 2\nPrioridades apropiativo: 3\nRound Robin: 4\n\nOpcion: ");
                fflush(stdin);
                scanf("%d", &op);
                if(op<1||op>4)
                {
                    printf("\nOpcion inexistente. Seleccione nuevamente.");
                }
            }
            char algoritmo[30]="FIFO";
            char algoritmo1[30]="SJFnoApropiativo";
            char algoritmo2[30]="PrioridadesApropiativo";
            char algoritmo3[30]="RoundRobin";
            if(op==1)
            {
                strcpy(a[v].algoritmoPlanificacion, algoritmo);
            }
            else if(op==2)
            {
                strcpy(a[v].algoritmoPlanificacion, algoritmo1);
            }
            else if(op==3)
            {
                strcpy(a[v].algoritmoPlanificacion, algoritmo2);
            }
            else if(op==4)
            {
                strcpy(a[v].algoritmoPlanificacion, algoritmo3);
            }


            v++;
            if(v<8)
            {
                printf("\n\nDesea agregar mas cajas(s/n): ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        }
    }
    return v;
}

int elegirCaja(){
    int i=0;
    while(i<1||i>8){
        printf("\n\n¿Que caja desea modificar?(1-8)\n ");
        fflush(stdin);
        scanf("%d", &i);

        if(i<1|| i>8){
            printf("\n\nEsa caja no existe. Seleccione nuevamente.");
        }
    }
return i-1;
}

int abrirOcerrarCaja(caja a[], int i){
    int b;
    nodo* aux= &a[i].filita;
    if(a[i].abiertaOcerrada==1 && aux!=NULL){
        a[i].abiertaOcerrada=0;
        b=0;
        printf("\n\nLa caja %d ahora esta cerrada.", i+1);
    }
    else if(a[i].abiertaOcerrada==0){
        a[i].abiertaOcerrada=1;
        b=1;
        printf("\n\nLa caja %d ahora esta abierta.", i+1);
    }
    if(aux==NULL){
        printf("\n\nLa caja no puede cerrarse por que todavia tiene clientes. ");
    }
return b;
}

