#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcionespp.h"

/** \brief solicitan algo al usuario dependiendo de la funcion y devuelve el resultado
 * \param mensaje Es el que va a ser mostrado
 * \return Lo ingresado por usuario
 *
 */

float getFloat(char mensaje[])
{
    float aux;
    printf("%s", mensaje);
    scanf("%f", &aux);
    return aux;
}
int getInt(char mensaje[])
{
    int aux;
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}
char getChar(char mensaje[])
{
    char aux;
    printf(mensaje);
    gets(aux);
    return aux;
}
float pedirFlotante()
{
    float aux;
    printf("Ingrese un numero con coma:");
    scanf("%f",&aux);
    return aux;
}

int ingresarValor (int valorIngresado,int i, int T)
{
    int numeros[T];

    for (i=0;i<T;i++)
    {
        valorIngresado = getInt("Ingrese valor: \n");
        numeros[i] = valorIngresado;
    }
}
// MINIMO MAXIMO Y PROMEDIO DE UN ENTERO
int maxMin()
{
    int max;
    int min;
    int acum;
    int auxInt;
    int i;

    //solicita primer numero y se inicializa el max y el min como el primer num acumulado
    printf("Ingrese x");
    scanf("%d",&auxInt);
    max = auxInt;
    min = auxInt;
    acum = auxInt;
    //se piden los demas numeros

    for(i=0;i<10;i++)
    {
        printf("Ingrese x");
        scanf("%d",&auxInt);
        acum = acum + auxInt;

        if (auxInt> max)
        {
            max = auxInt;
        }
        if (auxInt < min)
        {
            min = auxInt;
        }
    }
    printf("Maximo: %d \nMinimo: %d \nPromedio: %d",max,min,acum /10);
    return 0;
}

int mostrarIndice(int numeros[],int i,int T)
{
    printf("\n\nINDICE - VALOR\n");
    for (i = 0;i<T;i++)
    {
        printf ("%d %d\n",i,numeros[i]);
    }
}

/** \brief verifica si es numerico el valor recibido
 * \param   str array con la cadena a ser analizada
 * \return  1 si es numerico y 0 si no lo es
 *
 */

int esInt(char str[])
{
    int i=0;
    while(str[i] != '\0' )
    {
        if(str[i] < '0'|| str [i] >'9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief verifica si es solo letras y espacios el valor recibido
 * \param   str array con la cadena a ser analizada
 * \return  1 si es solo letras o espacio y 0 si no lo es
 *
 */

int esChar(char str[])
{
    int i=0;
    while(str[i] != '\0' )
    {
        if((str[i] !=' ') && (str[i] < 'a' || str[i] > 'z') &&(str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief verifica si son letras y numeros el valor recibido
 * \param   str array con la cadena a ser analizada
 * \return  1 si son solo letras y numeros y 0 si no lo es
 *
 */

int esIntChar(char str[])
{
    int i=0;
    while(str[i] != '\0' )
    {
        if((str[i] !=' ') && (str[i] < 'a' || str[i] > 'z') &&(str[i] < 'A' || str[i] > 'Z') && (str[i] < '0'|| str [i] >'9'))
            return 0;
        i++;
    }
    return 1;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
 int esFloat(char str[])
 {
   int i = 0;
   int cantComas = 0;
   while(str[i] !='\0')
   {
       if (i ==0 && str[i] =='-')
       {
           i++;
           continue;

       }
       if (str[i] =='.' && cantComas ==0)
       {
           cantComas++;
           i++;
           continue;

       }
       if(str[i] <'0' || str[i] >'9')
           return 0;
       i++;
   }
   return 1;
}

/** \brief solicita el texto al usuario
 * \param mensaje mensaje a mostrar
 * \param input donde se carga el texto ingresado
 * \return void
 *
 */
int esTarjeta(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==2) // debe tener un guion
        return 1;

    return 0;
}
 int getStringTarjeta(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esTarjeta(aux))
       {
            strcpy(input,aux);
            return 1;
       }
    return 0;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf("%s", input);
}

/** \brief solicita el texto al usuario y lo devuelve
 * \param mensaje mensaje a mostrar
 * \param input donde se carga el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */

 int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esChar(aux))
       {
            strcpy(input,aux);
            return 1;
       }
    return 0;
}

/** \brief solicita el texto numerico al usuario y lo devuelve
 * \param mensaje mensaje a mostrar
 * \param input donde se carga el texto ingresado
 * \return 1 si el texto contiene solo numeros
 *
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esInt(aux))
       {
            strcpy(input,aux);
            return 1;
       }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int modificarIndice(int numeros[],int i,int T)
{
    int valorIngresado;
    i= getInt("\nIngrese el indice a modificar: ");
    if (i>=0 && i<T)
    {
        valorIngresado = getInt("Ingrese el valor: \n");
        numeros[i] = valorIngresado;
    }
    else
    {
        printf("\nNo se encuentra el indice");
    }

    return valorIngresado;
}

void inicializarPersona(ePersona listado[],int limite,int valor)
{
    int i;
    for(i=0;i<limite; i++)
    {
        listado[i].legajo = valor;
    }
}

int buscarPrimerOcurrencia(ePersona listado[],int limite,int valor)
{
    int i;
    for(i=0;i<limite; i++)
    {
        if(listado[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}


void inicializarPersona_Producto(ePersona_Producto personaProducto[], int T)
{
     int i;

    for(i=0; i<T; i++)
    {
        personaProducto[i].estado = 0;
    }
}

void mostrarPersona_Producto (ePersona_Producto personaProducto[], int cantPersona, eSerie serie[], int cantidadSeries, int usuarioIngresado, eUsuario_Serie usuarioSerie[], int cantidadUSerie)
{
    int i;
    int j;
    int auxUsuario;
    auxUsuario = usuarioIngresado;

    for(int i=0;i<cantPersona;i++) // usuario
    {
        if(usuarios[i].estado == 1)
        {

        for(int j=0;j<cantidadSeries;j++) // serie
          {

            if(serie[j].estado == 1 && usuarioSerie[i].idSerie == serie[j].idSerie) // verifico que estado de serie no sea 0, tenga datos
            {
                printf("%s", serie[j].nombre);
                break;//mostrar datos serie
            }
          }
          printf("\n");
        }
    }

}
