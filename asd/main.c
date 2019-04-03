#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 5

void ordenarAscendente(int vecc[]);
void ordenarDescendente(int vec[]);

int main()
{
    char nombre[10];
    getString(nombre);

    int vec[CANT]={7,5,6,2,8};

    //ordenarAscendente(vec[CANT]);
    //ordenarDescendente(vec[CANT]);

    return 0;
}
//VER LAS MANERAS DE ORDENAR PARA HACERLAS FUNCION
void ordenarAscendente(int vecc[])
{
    int i;
    int auxx;

    for(i=0;i<CANT-1;i++)
    {
        for(int j=i+1;j<CANT;j++)
        {
            if(vecc[i]>vecc[j])
            {
                auxx=vecc[i];
                vecc[i]=vecc[j];
                vecc[j]=auxx;
            }
        }
    }
    for(i=0;i<CANT;i++)
    {
        printf("ASCENDENTE:%d\n", vecc[i]);
    }
}

void ordenarDescendente(int vec[])
{
    int i;
    int aux;

    for(i=0;i<CANT-1;i++)
    {
        for(int j=i+1;j<CANT;j++)
        {
            if(vec[i]<vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
    for(i=0;i<CANT;i++)
    {
        printf("DESCENDENTE:%d\n", vec[i]);
    }

}

void getString()
{
    char buffer[64];
    int cantidad;
    fflush(stdin);
    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);

    cantidad = strlen(buffer);

    buffer[cantidad-1] = '\0';

    printf("NOMBRE: %s", buffer);

}
