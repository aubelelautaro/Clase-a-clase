#include <stdio.h>
#include <stdlib.h>
#include "propietario.h"
#define T 20

int main()
{
    ePropietario listado[T];
    ePropietario auxProd;

    char auxDescripcion[51];
    int auxid;
    int auxCant;
    float auxPrecio;

    char codigoAuxStr[50];
    char cantAuxStr[50];
    char precioAuxStr[50];

    int indexLugarLibre;
    int indexEncontrado;
    int opcion = 0;

    int i,j;

    establecerEstado(listado,T,0);

    while(opcion != 8)
    {
        opcion = getInt("\n1. Alta\n2. Modificar\n3 .Baja\n4. Ingreso automovil\n5. Egreso automovil\n6. Recaudacion total\n7.Recaudacion total por marca\n8.Salir\n");
        switch(opcion)
        {
            case 1:
                printf("\nALTA\n");
                break;
            case 2:
                printf("\nMODIFICACION\n");
                break;
            case 3:
                printf("\nBAJA\n");
                break;
            case 4:
                printf("\nINGRESO AUTOMOVIL\n");
                break;
            case 5:
                printf("\nEGRESO AUTOMOVIL\n");
                break;
            case 6:
                printf("\nRECAUDACION TOTAL\n");
                break;
            case 7:
                printf("\nRECAUDACION TOTAL POR MARCA\n");
                break;
            case 8:
                break;
        }
    }
    return 0;
}
