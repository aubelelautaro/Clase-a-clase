#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct datosPersonales
{

    char nombre[20];
    char apellido[20];
    char direccion[20];
    int numero;
    int cp;

};


int main()
{
    struct datosPersonales agenda[3];

    int i=0;

    for(i=0; i<3; i++)
    {
        setbuf(stdin, NULL); //fflush en windows
        printf("Nombre: ");
        gets(agenda[i].nombre);
        printf("Apellido: ");
        gets(agenda[i].apellido);
        printf("Direccion: ");
        gets(agenda[i].direccion);

        printf("Numero: ");
        scanf("%d",&agenda[i].numero);
        printf("Codigo postal: ");
        scanf("%d",&agenda[i].cp);

    }
        printf("NOMBRE\t\tAPELLIDO\tDIRECCION\tNUMERO\t\tCODIGO POSTAL\n");
        for(i=0; i<3; i++)
    {
        printf("%s\t%s\t%s\t%d\t%d\n",agenda[i].nombre,agenda[i].apellido,agenda[i].direccion,agenda[i].numero,agenda[i].cp);
    }

    return 0;
}
