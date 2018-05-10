#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    while(opcion != 7)
    {
        opcion = getInt("\n1. Alta\n2. Modificar\n3 .Baja\n4. Listar\n5. Informar\n6. Salir\n");
        switch(opcion)
        {

            case 1:
                printf("\nALTA\n");
                indexLugarLibre = buscarLugarLibre(listado,T);
                if(indexLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                printf("\nALTA\n");

                if (!getStringNumeros("Ingrese el codigo: ",codigoAuxStr))
                {
                    printf ("El codigo debe ser numerico\n");
                    break;
                }
                auxCodigo = atoi(codigoAuxStr);

                if(buscarProductoPorCodigo(listado,T,auxCodigo) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    break;
                }


                if (!getStringLetras("Ingrese la descripcion: ",auxDescripcion))
                {
                    printf ("La descripcion debe estar compuesta solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese la cantidad: ",cantAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxCant = atoi(cantAuxStr);

                if (!getStringNumerosFlotantes("Ingrese el valor: ",precioAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxPrecio = atof(precioAuxStr);

                listado[indexLugarLibre].codigo = auxCodigo;
                strcpy(listado[indexLugarLibre].descripcion,auxDescripcion);
                listado[indexLugarLibre].precio = auxPrecio;
                listado[indexLugarLibre].cant = auxCant;
                listado[indexLugarLibre].estado = 1;
                break;
            case 2:
                printf("\nMODIFICACION\n");
                if (!getStringNumeros("Ingrese el codigo de producto a modificar: ",codigoAuxStr))
                {
                    printf ("El codigo de producto debe ser numerico\n");
                    break;
                }
                auxCodigo = atoi(codigoAuxStr);
                indexEncontrado = buscarProductoPorCodigo(listado,T,auxCodigo);
                if(indexEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }



               if (!getStringLetras("Ingrese la descripcion: ",auxDescripcion))
                {
                    printf ("La descripcion debe estar compuesta solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese la cantidad: ",cantAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxCant = atoi(cantAuxStr);

                if (!getStringNumerosFlotantes("Ingrese el valor: ",precioAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxPrecio = atof(precioAuxStr);

                strcpy(listado[indexEncontrado].descripcion,auxDescripcion);
                listado[indexEncontrado].precio = auxPrecio;
                listado[indexEncontrado].cant = auxCant;
                listado[indexEncontrado].estado = 1;

                break;
            case 3:
                printf("\nBAJA\n");
                if (!getStringNumeros("Ingrese el codigo: ",codigoAuxStr))
                {
                    printf ("El codigo debe ser numerico\n");
                    break;
                }
                indexEncontrado = buscarPrimerOcurrencia(listado,T,atoi(codigoAuxStr));

                if(indexEncontrado == -1)
                {
                    printf("\n\nNo se encuentra ese codigo");
                    break;
                }
                listado[indexEncontrado].estado= 0;

                break;
}
