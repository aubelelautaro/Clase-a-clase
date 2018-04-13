#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*tarea
* char nombre[?]
char apellido[?]
char apellidoynombre[?];

*************
ingr apellido
ingr nombre

apellido y nombre = "Scarafilo, German" hacer todo sobre apellidoynombre no tocar las varialbes apellido o nombre
*/
int main()
{
    char palabra1[10];
    char palabra2[12];
    char buffer[1024];
    int i;
    int cant;
    int comp;
    printf("Palabra:");
    fflush(stdin);
    gets(buffer);

    while (strlen(buffer)>14)
    {
        printf("Reingrese palabra: ");
        fflush(stdin);
        gets(buffer);
    }

    //strcpy(palabra1,buffer); copia las palabras
    //strcpy(palabra2,palabra1);

    strupr(palabra1);
    strlwr(palabra2);

    comp=strcmp(palabra2,palabra1); // strcmp al compararlas las transforma en minuscula las dos
    strcat(buffer, palabra2); //concatena
    strcat(buffer, palabra1);

    printf("\nResultado de la comparacion: %d", comp);

    printf("%s y %s\nCantidad de caracteres: %d\nBienvenido %s", palabra1,palabra2,cant, buffer);


    return 0;
}
