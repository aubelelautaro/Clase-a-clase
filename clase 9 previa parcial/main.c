#include <stdio.h>
#include <stdlib.h>
#define T 3
void mostarAlumnos()
{
    int i;
    for(i=0; i<T; i++)
    {
        eAlumno[i].legajo=legajo[i];
        eAlumno[i].nombre=nombre[i];
    }
}
typedef struct
{
    char calle[50];
    int numero;
    int cp;
}eDomicilio;

typedef struct
{
    int legajo;
    char nombre [50];
    eDomicilio domicilio;

}eAlumno;

int main()
{
    eAlumno miAlumno;

    int i;

    for (i=0; i<T; i++)
    {
        printf("Nombre:",miAlumno.nombre);
        fflush(stdin);
        gets(miAlumno.nombre);
        printf("Numero:", miAlumno.legajo);
        scanf ("%d", &miAlumno.legajo);
    }

    mostrarAlumnos(eAlumno.miAlumno);
    return 0;
}
