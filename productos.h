#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include "Funcionespp.h"
#define clientes 20

typedef struct{
    char descripcion[51];
    int codigo;
    int cant;
    float precio;
    int estado; /**< Activo (1) o Inactivo (0)  */
}eProducto;

void establecerEstado(eProducto listado[],int tam,int valor);
int buscarLugarLibre(eProducto listado[],int tam);
int buscarProductoPorCodigo(eProducto listado[],int tam,int codigo);
float buscarMenorPrecio(eProducto listado[],int tam);
float promedioPrecio(eProducto listado[],int tam);
void ordenarPorDescripcion(eProducto listado[],int tam);
#endif // PRODUCTOS_H_INCLUDED
