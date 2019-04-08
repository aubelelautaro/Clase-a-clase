#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char auxNombre[100];
    char apellido[20];
    char auxApellido[100];
    char nombreCompleto[41];
    //"Perez, Juan" poner en mayusculas la primer letra del apellido y la del nombre todo en nombrecompleto

    printf("Ingrese nombre:");
    gets(auxNombre);

    while(strlen(auxNombre)>19)
    {
        printf("error, reingrese un nombre de 19 letras");
        gets(auxNombre);
    }
    strcpy(nombre,auxNombre);

    printf("Ingrese apellido:");
    gets(auxApellido);

    while(strlen(auxApellido)>19)
    {
        printf("error, reingrese un apellido de 19 letras");
        gets(auxApellido);
    }
    strcpy(apellido,auxApellido);

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto,", ");

    strcat(nombreCompleto,nombre);
    strlwr(nombreCompleto);

    nombreCompleto[0] = toupper(nombreCompleto[0]);

    for(int i=0;i<strlen(nombreCompleto);i++)
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);

        }
    }
    printf("Nombre completo: %s",nombreCompleto);

    return 0;
}
