#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5

float calcularPromedio(int,int);
//void mostrarAlumnos(int[],char[][30],int[],int[],float[],int);
void mostrarAlumnos(int[],char[][30],int[],int);
int buscarInt(int[], int, int);


int main()
{
    int legajos[T]={1,2,3,4,5};
    char nombres[T][30]={"Jose", "Juan", "Maria", "Ana", "German"};
    int nota1[T]={6,4,7,9,3};
    //int nota2[T]={4,6,8,3,6};
    //float promedios[T]={};
    int i;
    int j;
    char auxNombres[30];
    int auxInt;

    /*for(i=0;i<T;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("Ingrese nota 1: ");
        scanf("%d", &nota1[i]);
        printf("Ingrese nota 2: ");
        scanf("%d", &nota2[i]);
        promedios[i]=calcularPromedio(nota1[i],nota2[i]);
    }*/

    for(i=0;i<T-1;i++)
    {
       for(j=i+1;j<T;j++)
       {
            if(strcmp(nombres[i], nombres[j])>0)
            {
                strcpy(auxNombres, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxNombres);

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;
            }
       }
    }

    //mostrarAlumnos(legajos,nombres,nota1,nota2,promedios,T);
    mostrarAlumnos(legajos,nombres,nota1,T);

    auxInt = buscarInt(legajos, T, 2);
    if(auxInt!=-1)
    {
        printf("\n%s", nombres[auxInt]);
    }
    else
    {
        printf("\nLegajo inexistente");
    }

    return 0;
}

float calcularPromedio(int nota1,int nota2)
{
    float promedio;
    promedio = (float)(nota1 + nota2)/2;
    return promedio;
}

/*void mostrarAlumnos(int legajos[],char nombres[][30],int nota1[],int nota2[],float promedios[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(legajos[i]!=0)
        {
            printf("\nLegajo: %d",legajos[i]);
            printf("\nNombre: %s",nombres[i]);
            printf("\nPrimer nota: %d",nota1[i]);
            printf("\nSegunda nota: %d",nota2[i]);
            printf("\nPromedio: %.2f \n",promedios[i]);
        }
    }
}*/
void mostrarAlumnos(int legajos[],char nombres[][30],int nota1[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(legajos[i]!=0)
        {
            printf("\nLegajo: %d",legajos[i]);
            printf("\nNombre: %s",nombres[i]);
            printf("\nNota: %d \n",nota1[i]);
        }
    }
}

int buscarInt(int enteros[], int tam, int cual)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(enteros[i]==cual)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
