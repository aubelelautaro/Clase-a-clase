#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nomYApe[40];
    char direccion[40];
    int tarjeta;
    int estado; /**< Activo (1) o Inactivo (0)  */
}ePropietario;

void establecerEstado(ePropietario listado[],int tam,int valor);
int buscarLugarLibre(ePropietario listado[],int tam);
int buscarProductoPorCodigo(ePropietario listado[],int tam,int codigo);
