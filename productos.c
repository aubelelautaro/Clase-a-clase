#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"

void establecerEstado(eProducto listado[],int tam,int valor)
{
    int i;
    for(i=0;i<tam;i++)
    {
        listado[i].estado = valor;
    }
}

int buscarLugarLibre(eProducto listado[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(listado[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

int buscarProductoPorCodigo(eProducto listado[],int tam,int codigo)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(listado[i].codigo == codigo && listado[i].estado == 1)
        {
            return i;
        }
    }
    return -1;
}

float buscarMenorPrecio(eProducto listado[],int tam)
{
    int i;
    float  precioBarato = -1;

    for(i=0;i<tam;i++)
    {
        if (listado[i].estado == 1)
        {
            precioBarato = listado[i].precio;
            break;
        }
    }

    if (precioBarato == -1)/** si se cumple es porque no existen productos en el array*/
    {
        printf("No hay productos en el sistema todavia");
        return -1;
    }

    for(i=0;i<tam;i++)
    {
        if (precioBarato > listado[i].precio && listado[i].estado == 1)
        {
            precioBarato = listado[i].precio;
            break;
        }
    }
    return precioBarato;
}

float promedioPrecio(eProducto listado[],int tam)
{
    int i;
    float precioTotal = 0;
    int productosActivos = 0;
    int promedio=0;

    for(i=0;i<tam;i++)
    {
        if (listado[i].estado == 1)
        {
            precioTotal = precioTotal + listado[i].precio;
            productosActivos++;
        }
    }

    if (productosActivos == 0)/** si se cumple es porque no existen productos en el array*/
    {
        printf("No hay productos en el sistema todavia");
        return -1;
    }
    promedio = (precioTotal / (float)productosActivos);
    return promedio;
}

void ordenarPorDescripcion(eProducto listado[],int tam)
{
    eProducto auxProducto;
    int i,j;
    for(i=0; i < clientes - 1; i++)
    {
        if(listado[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j < clientes; j++)
        {
            if(listado[j].estado == 0)
            {
                continue;
            }
            if(strcmp(listado[j].descripcion,listado[i].descripcion) > 0)
            {
                auxProducto = listado[j];
                listado[j] = listado[i];
                listado[i] = auxProducto;
            }
            else if (strcmp(listado[j].descripcion,listado[i].descripcion) == 0)
            {
                if (listado[i].cant > listado[j].cant)
                {
                    auxProducto = listado[j];
                    listado[j] = listado[i];
                    listado[i] = auxProducto;
                }



            }

        }
    }
}
