#include <stdio.h>
#include <stdlib.h>
#define T 6

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
void altaAlumno(int[], char[][20], int[], int[], float[], int);
void modificarAlumno(int[], char[][20], int[], int[], float[], int);
void bajaAlumno(int[], char[][20], int[], int[], float[], int);

int main()
{
    char respuesta = "s";
    int legajo[T]= {1,2,3,4,5};
    char nombre[T][20]={"Federico", "Daniel", "Andrea", "Laura", "Lautaro"};
    int nota1[T]={10,7,9,3,5};
    int nota2[T]={8,5,4,6,8};
    float promedio[T];
    int opcion;
    calcularPromedio(nota1[T],nota2[T]);
    do
    {
        printf("\n1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n6.ORDENAR (por )\n7.ORDENAR (por )\n8.ORDENAR (por )\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            altaAlumno(legajo,nombre,nota1,nota2,promedio,T);
            break;
        case 2:
            mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,T);
            break;
        case 3:
            modificarAlumno(legajo,nombre,nota1,nota2,promedio,T);
            break;
        case 4:
            bajaAlumno(legajo,nombre,nota1,nota2,promedio,T);
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        break;
        }

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int legajos[], int tam)
{
    int index=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(legajos[i]==0)
        {
            index=i;
            break;
        }
    }

    return index;
}

void altaAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index;
    index = buscarLibre(legajos, tam);
        if(index!=-1)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &legajos[index]);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombres[index]);
            printf("Ingrese nota 1: ");
            scanf("%d", &nota1[index]);
            printf("Ingrese nota 2: ");
            scanf("%d", &nota2[index]);
            promedio[index]=calcularPromedio(nota1[index],nota2[index]);
        }
        else
        {
            printf("No hay cupos disponibles");
        }

    return index;
}

float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(legajos[i]!=0)
        {
            printf("%d %s %d %d %.2f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i]);
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
void modificarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int numeroLegajo;
    int i;
    int opcionModificar;
    int flag = 0;

    printf("\nIngrese legajo a modificar: ");
    scanf("%d", &numeroLegajo);
    for (i=0;i<tam;i++)
    {
        if(legajos[i]==numeroLegajo)
        {
            flag = 1;
            printf("1. Modificar legajo\n");
            printf("2. Modificar nombre\n");
            printf("3. Modificar nota 1\n");
            printf("4. Modificar nota 2\n");
            scanf("%d", &opcionModificar);

            switch(opcionModificar)
            {
                case 1:
                    scanf("%d", &legajos[i]);
                    break;
                case 2:
                    gets(nombres[i]);
                    fflush(stdin);
                    break;
                case 3:
                    scanf("%d", &nota1[i]);
                    break;
                case 4:
                    scanf("%d", &nota2[i]);
                    break;
            }
            promedio[i]=calcularPromedio(nota1[i],nota2[i]);
        }
    }
    if (flag == 0)
    {
        printf("Legajo no encontrado\n");
    }
}

void bajaAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int borrarLegajo;
    int i;

    printf("Ingrese legajo a dar de baja: ");
    scanf("%d", &borrarLegajo);

    for(i=0;i<tam;i++)
    {
        if(legajo[i]== borrarLegajo)
        {
        legajo[i]=0;
        strcpy(nombre[i],"");
        nota1[i]=0;
        nota2[i]=0;
        promedio[i]=0;
        break;
        }
        if (i==tam)
        {
            printf("No existe este legajo");
        }
    }
}
