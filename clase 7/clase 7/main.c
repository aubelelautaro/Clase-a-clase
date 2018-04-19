#include <stdio.h>
#include <stdlib.h>
#define T 3
float calcularPromedio(int,int);
void mostrarAlumnos(char[][22],int[],int[],int[],float[],int);
int main()
{
    char nombre[T][22];
    int legajo[T];
    int nota1[T];
    int nota2[T];
    float promedio[T];
    int i;

    for (i=0;i<T;i++)
    {
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre[i]);
        printf("Ingrese Legajo: ");
        scanf ("%d", &legajo[i]);
        printf("Ingrese nota 1: ");
        scanf ("%d", &nota1[i]);
        printf("Ingrese nota 2: ");
        scanf ("%d", &nota2[i]);
        promedio[i] =(calcularPromedio(nota1[i],nota2[i]));
    }

    mostrarAlumnos(nombre,legajo,nota1,nota2,promedio,T);
    return 0;
}

float calcularPromedio (int num1, int num2)
{
    float promedio;
    promedio = (float)num1+num2/2;

    return promedio;
}
void mostrarAlumnos(char nombre[i][22], int legajo[i], int nota1[i],int nota2[i],float promedio[i],int T)
{
    int i;
    for (i=0;i<T;i++)
    {
        printf("\nNombre: %s\nLegajo: %d\nNota 1: %d\nNota 2: %d\nPromedio: %.2f",nombre[i],legajo[i],nota1[i],nota2[i],promedio[i], T);
    }
}
