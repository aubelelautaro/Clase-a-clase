#ifndef FUNCIONESPP_H_INCLUDED
#define FUNCIONESPP_H_INCLUDED
#include "productos.h"

typedef struct
{
    char nombre[50];
    char apellido[50];
    int legajo;
}ePersona;

typedef struct
{
    int idPersona;
    int idProducto;
    int estado;
}ePersona_Producto;

void inicializarPersona_Producto(ePersona_Producto personaProducto[], int T);

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
float pedirFlotante();

int esInt(char str[]);
int esChar(char str[]);
int esIntChar(char str[]);
int esTarjeta(char str[]);

int ingresarValor (int valorIngresado,int i, int T);
int maxMin();
int mostrarIndice(int numeros[],int i,int T);
int modificarIndice(int numeros[],int i,int T);

int getStringTarjeta(char mensaje[],char input[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

void inicializarPersona(ePersona listado[],int limite,int valor);
int buscarPrimerOcurrencia(ePersona listado[],int limite,int valor);

#endif // FUNCIONESPP_H_INCLUDED
