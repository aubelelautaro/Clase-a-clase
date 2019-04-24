#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblotecaValidar.h"

#define QTY_CLIENTES 200

void inicializarArrayInt(int array[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(int array[],int cantidadDeElementos,int valor);

int main()
{
    char arrayNombres[QTY_CLIENTES][50];
    char arrayApellidos[QTY_CLIENTES][50];
    int arrayLegajos[QTY_CLIENTES];

    char auxNombreStr[50];
    char auxApellidoStr[50];
    char auxLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion=0;
    int i,j;

    inicializarArrayInt(arrayLegajos,QTY_CLIENTES,-1);
    while(opcion!= 6)
    {
        opcion=pedirInt("\n\n1 - ALTA  \n2 - BAJA\n3 - MODIFICACNION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n");
        switch(opcion)
        {
        case 1:
            indiceLugarLibre=buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,-1);
            if(indiceLugarLibre==-1)
            {
                printf("no quedan lugares libres\n");
                break;
            }
            printf("\nALTA\n");
            if(!getStringLetras("ingrese nombre: \n",auxNombreStr))
            {
                printf("el nombre debe estar compuesto solo por letras\n");
                break;
            }
            if(!getStringLetras("ingrese apellido: \n",auxApellidoStr))
            {
                printf("el apellido debe estar compuesto solo por letras\n");
                break;
            }
            if(!getStringNumeros("ingrese legajo: \n",auxLegajoStr))
            {
                printf("el legajo debe ser numerico.\n");
                break;
            }
            auxiliarLegajo=atoi(auxLegajoStr);
            if(buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,auxiliarLegajo)!= -1)
            {
                printf("\nel legajo ya existe\n");
                break;
            }
            strcpy(arrayNombres[indiceLugarLibre],auxNombreStr);
            strcpy(arrayApellidos[indiceLugarLibre],auxApellidoStr);
            arrayLegajos[indiceLugarLibre]=auxiliarLegajo;

            break;
        case 2:
            if(!getStringNumeros("ingrese el legajo a dar de baja_ ",auxLegajoStr))
            {
                printf("el legajo debe ser numeroco\n");
                break;
            }
            indiceResultadoBusqueda=buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,atoi(auxLegajoStr));
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nno se encuentra el legajo\n");
                break;
            }
            arrayLegajos[indiceResultadoBusqueda]=-1;
            break;
        case 3:
            if(!getStringNumeros("ingrese el legajo a dar de baja_ ",auxLegajoStr))
            {
                printf("el legajo debe ser numeroco\n");
                break;
            }
            indiceResultadoBusqueda=buscarPrimerOcurrencia(arrayLegajos,QTY_CLIENTES,atoi(auxLegajoStr));
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nno se encuentra el legajo\n");
                break;
            }
            if(!getStringLetras("ingrese el nombre: \n",auxNombreStr))
            {
                printf("el nombre debe estar compuesto solo por letras\n");
                break;
            }
            if(!getStringLetras("ingrese apellido: \n",auxApellidoStr))
            {
                printf("el apellido debe estar compuesto solo por letras\n");
                break;
            }
            strcpy(arrayNombres[indiceResultadoBusqueda],auxNombreStr);
            strcpy(arrayApellidos[indiceResultadoBusqueda],auxApellidoStr);
            break;
        case 4:
            printf("\nlISTAR\n");
            for(i=0; i<QTY_CLIENTES; i++)
            {
                if(arrayLegajos[i] !=-1)
                {
                    printf("\n%s - %s - %d\n",arrayNombres[i],arrayApellidos[i],arrayLegajos[i]);
                }
            }
            break;
        case 5:
            printf("\nORDENADO\n");
            for(i=0; i<QTY_CLIENTES; i++)
            {
                if(arrayLegajos[i]==-1)
                {
                    continue;
                }
                for(j=i+1; j<QTY_CLIENTES; j++)
                {
                    if(arrayLegajos[j]==-1)
                    {
                        continue;
                    }
                    if(strcmp(arrayApellidos[i],arrayApellidos[j]))
                    {
                        strcpy(auxNombreStr,arrayNombres[i]);
                        strcpy(arrayNombres[i],arrayNombres[j]);
                        strcpy(arrayNombres[j],auxNombreStr);

                        strcpy(auxApellidoStr,arrayApellidos[i]);
                        strcpy(arrayApellidos[i],arrayApellidos[j]);
                        strcpy(arrayApellidos[j],auxApellidoStr);

                        strcpy(auxiliarLegajo,arrayLegajos[i]);
                        strcpy(arrayLegajos[i],arrayLegajos[j]);
                        strcpy(arrayLegajos[j],auxiliarLegajo);
                    }
                }
            }
        }
    }
    return 0;
}


void inicializarArrayInt(int array[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0; i<cantidadDeElementos; i++)
    {
        array[i]=valor;
    }
}


int buscarPrimerOcurrencia(int array[],int cantidadDeElementos,int valor)
{
    int i;
    int flag=-1;

    for(i=0; i<cantidadDeElementos; i++)
    {
        if(array[i]==valor)
        {
            flag = i;
        }
    }
    return flag;
}




