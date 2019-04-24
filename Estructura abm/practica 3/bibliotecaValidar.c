#include <stdio.h>
#include <stdlib.h>
#include "biblotecaValidar.h"

float pedirFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int pedirInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%i",&auxiliar);
    //auxiliar= validarEntero(numero,min,max,mensaje);
    return auxiliar;
}

char pedirChar(char mensaje[])
{
    char auxiliarChar;
    printf("%s",mensaje);
    fflush(stdin);//-standar imput que borra la basura.
    scanf("%c",&auxiliarChar);
    return auxiliarChar;
}






int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
        {
        if(str[i]< '0' || str[i]> '9')
            return 0;
        i++;
        }
    return 1;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
        {
        if((str[i] != ' ')&&(str[i] < 'a'|| str[i] > 'z')&&(str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
        }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
        while(str[i] != '\0')
            {
            if((str[i] != ' ')&&(str[i] < 'a'|| str[i] > 'z')&&(str[i] < 'A' || str[i] > 'Z')&&(str[i]< '0' || str[i]> '9'))
                return 0;
            i++;
        }
    return 1;
}


void getString(char mensaje[],char imput[])
{
    printf("%s",mensaje);
    scanf("%s",imput);
}


int getStringLetras(char mensaje[],char imput[])
{
    char aux[300];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
        {
            strcpy(imput,aux);
            return 1;
        }
        return 0;
}

int getStringNumeros(char mensaje[],char imput[])
{
    char aux[300];
    getString(mensaje,aux);
    if(esNumerico(aux))
        {
            strcpy(imput,aux);
            return 1;
        }
        return 0;
}









