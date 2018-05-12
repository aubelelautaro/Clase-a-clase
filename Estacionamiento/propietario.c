#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "propietario.h"
#define T 20

/**
        PARCIAL A RECUPERAR
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

        ----------------------------------------------------------------------------------------
                        AGRUPAR BIEN TODAS LAS FUNCIONES ASI LAS PUEDO USAR

    Para poder usar una estructura dentro de la otra,leer lo de primarykey y lo de foreign key
    Ej:
    prov        prod
    pk idprov   idprod
                idProv (fk)

    buscarid, recorrer prod --> matchar y recien ahi recorrer proveedores

    Clase del sabado despues del parcial, valide la baja del tp 2

    for(i=0;i<T;i++) //funcion mostrar listado
    {
        if(lista[i].estado==1)
        {
           printf("Nombre: %s - Edad: %d - DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
           flag=1;
        }
    }

    if(flag == 1)
    {
        printf("Ingrese dni a dar de baja: ");
        scanf("%d",&dni);
        index = buscarDni(lista, dni,T);

        if(index!=-1)
        {
            printf("Desea realizar la baja? (S/N)");
            fflush(stdin);
            scanf("%c",&confirmarBaja);
            if (confirmarBaja == 's')
            {
                lista[index].estado=0;
                strcpy(lista[index].nombre,"");
                lista[index].edad=0;
                lista[index].dni=0;
                printf("Baja realizada\n");
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
        else
        {
            printf("La persona seleccionada no esta registrada\n");
        }
    }
    else
    {
        printf("No hay datos cargados en el sistema\n");
    }
*/

