#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 3


typedef struct
{
    char nombre[20];
    char sexo;
    int legajo;
    float sueldo;
    int estado;
}eEmpleado;

void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);

int main()
{
    int rta = 's';
    int opcion;
    char confirma;

    eEmpleado lista[TAM]={{"ASD",'M',100,240.22,1},{"BSD",'F',200,540.22,1},{"CSD",'M',300,740.22,1}};
    //inicializarEmpleados(lista,TAM);

    do
    {
        printf("---------------ABM EMPLEADOS--------------\n");
        printf("1.Alta\n");
        printf("2.Baja\n");
        printf("3.Modificacion\n");
        printf("4.Listar\n");
        printf("5.Ordenar\n");
        printf("6.Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            mostrarEmpleados(lista,TAM);
            break;
        case 5:
            break;
        case 6:
            printf("Seguro desea salir? s/n \n");
            fflush(stdin);
            confirma = getch();
            if(tolower(rta)== 's')
            {
                rta == 'n';
            }
            break;
        default:
            printf("Ingrese opcion correcta\n");
        }

    }
    while(opcion!=6);
    return 0;
}

void inicializarEmpleados(eEmpleado vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].estado= 0;
    }
}

void mostrarEmpleado(eEmpleado emp)
{
    printf("%10s   %4c     %5d     %.2f\n", emp.nombre,emp.sexo,emp.legajo,emp.sueldo);
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int flag =0;

    printf("NOMBRE\t\tSEXO\tLEGAJO\tSUELDO\n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarEmpleado(vec[i]);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY DATOS QUE MOSTRAR\n");
    }
}

int buscarLibre(eEmpleado vec[],int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if (vec[i].estado ==0)
        {
            printf("El indice vacio es: %d", vec[i]);
        }
        else if(vec[i].estado ==1)
        {
            index = -1;
        }
    }
    return index;
}
