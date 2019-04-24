#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define TAM 12
#define TAMSEC 5

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    char nombre[20];
    char sexo;
    int legajo;
    float sueldo;
    int estado;
    eFecha fechaNacimiento;
    int idSector;

} eEmpleado;

typedef struct
{
    int id;
    char desc[21];
}eSector;


int menu();
void inicializarEmpleados(eEmpleado empleados[],int tam);
void mostrarEmpleado(eSector sectores[],int tam,eEmpleado emp);
void mostrarEmpleados(eEmpleado empleados[],int tam,eSector sectores[],int tamSectores);
int buscarLibre(eEmpleado empleados[],int tam);
int buscarEmpleado(eEmpleado empleados[], int tam, int legajo);
void altaEmpleado(eEmpleado empleados[], int tame,eSector sectores[],int tamSectores);
void bajaEmpleado(eEmpleado empleados[], int tam);
void modificarEmpleado(eEmpleado empleados[], int tam);
void ordenarEmpleados(eEmpleado empleados[], int tam);
int obtenerSector(eSector sectores[],int tam, int id,int desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[],int tam,eSector sectores[],int tamSectores);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores);

int main()
{
    int rta = 's';
    char confirma;

    eEmpleado lista[TAM] = {
        {"Xasd",'M',500,240.22,1,{19,04,1999},1},
        {"Walter",'F',900,540.22,1,{23,05,1990},2},
        {"Franco",'M',300,740.22,1,{05,06,1989},3},
        {"Alberto",'m',400,35000,1,{23,07,1940},1},
        {"Sonia", 'f',382,39000,1,{01,02,1930},3},
        {"Miguel", 'm',585,29700,1,{04,8,1960},4},
        {"Adrian", 'm',834,43200,1,{02,9,1950},5},
        {"Lucia", 'f',142,32300,1,{9,01,1942},2},
        {"Raston", 'm',43,29760,1,{07,10,1978},4},
        {"Diego", 'm',87,35000,1,{12,11,1924},5},
        {"Viviana", 'f',729,47000,1,{14,12,1931},3},
        {"Zustavo", 'm',99,25000,1,{31,03,1952},2}

        };
    eSector sectores[TAMSEC] =
        {
        {1,"AAA"},
        {2,"BBB"},
        {3,"CCC"},
        {4,"DDD"},
        {5,"EEE"}

        };
    //inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 2:
            bajaEmpleado(lista,TAM);
            system("pause");
            break;
        case 3:
            modificarEmpleado(lista,TAM);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(lista,TAM,sectores, TAMSEC);
            system("pause");
            break;
        case 5:
            ordenarEmpleados(lista,TAM);
            system("pause");
            break;
        case 6:
            mostrarSectoresConEmpleados(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 7:
            mostrarCantEmpleadosXSector(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 8:
            printf("Seguro desea salir? s/n \n");
            fflush(stdin);
            confirma = getch();
            if(tolower(confirma)== 's')
            {
                rta = 'n';
            }
            break;
        default:
            printf("Ingrese opcion correcta\n");
            system("pause");
        }

    }
    while(rta == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("---------------ABM EMPLEADOS--------------\n");
    printf("1.Alta\n");
    printf("2.Baja\n");
    printf("3.Modificacion\n");
    printf("4.Listar\n");
    printf("5.Ordenar\n");
    printf("6.Listar sectores con empleados\n");
    printf("7.Cantidad de empleados por sector\n");
    printf("8.Salir\n");

    opcion=getInt("Elija una opcion: ",opcion,1,8);

    return opcion;
}


void inicializarEmpleados(eEmpleado empleados[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        empleados[i].estado= 0;
    }
}

void mostrarEmpleado(eSector sectores[],int tam,eEmpleado emp)
{
    int nombreSector[20];
    int esta;
    esta = obtenerSector(sectores,tam, emp.idSector, nombreSector);

    if (!esta)
    {
        strcpy(nombreSector, "Sin definir");
    }
    printf("%5d     %10s   %4c     %.2f   %s     %d/%d/%d \n",emp.legajo,emp.nombre,emp.sexo,emp.sueldo,nombreSector,emp.fechaNacimiento);
}

void mostrarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores)
{
    int flag =0;

    printf("LEGAJO\t  NOMBRE   SEXO\t  SUELDO\tSECTOR\tNACIMIENTO\n");
    for(int i=0; i<tam; i++)
    {
        if(empleados[i].estado == 1)
        {
            mostrarEmpleado(sectores, tamSectores,empleados[i]);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY DATOS QUE MOSTRAR\n");
    }
}

int buscarLibre(eEmpleado empleados[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if (empleados[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarEmpleado(eEmpleado empleados[], int tam, int legajo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(empleados[i].estado ==1 && empleados[i].legajo == legajo)
        {
            index=i;
            break;
        }
    }

    return index;
}

void altaEmpleado(eEmpleado empleados[], int tam,eSector sectores[],int tamSectores)
{
    int index;
    int legajo;
    int esta;

    index = buscarLibre(empleados, tam);

    if(index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSectores,empleados[esta]);
        }
        else
        {
            empleados[index].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(empleados[index].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &empleados[index].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &empleados[index].sueldo );

            printf("Fecha de nacimiento\nDia:");
            scanf("%d",&empleados[index].fechaNacimiento.dia);

            printf("Mes:");
            scanf("%d",&empleados[index].fechaNacimiento.mes);

            printf("Anio:");
            scanf("%d",&empleados[index].fechaNacimiento.anio);

            printf("Ingrese sector (1 a 5)");
            scanf("%d",&empleados[index].idSector);

            empleados[index].estado = 1;

            printf("Alta empleado exitosa\n\n");
        }
    }
}

void bajaEmpleado(eEmpleado empleados[], int tam)
{
    int index;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    index = buscarEmpleado(empleados,tam,legajo);

    if(index== -1)
    {
        printf("No se encontro al empleado\n");
    }
    else
    {
        printf("Desea dar de baja al empleado?\n");
        fflush(stdin);
        confirma = getch();

        if(tolower(confirma)=='s')
        {
            empleados[index].estado =0;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("No se dio de baja al empleado\n");
        }
    }
}

void modificarEmpleado(eEmpleado empleados[], int tam)
{
    int legajo;
    int index;
    float sueldo;
    char confirma;

    printf("Ingrese legajo del empleado a modificar:\n");
    scanf("%d",&legajo);

    index = buscarEmpleado(empleados,tam,legajo);

    if(index==-1)
    {
        printf("No se encontro el empleado");
    }
    else
    {
        printf("El sueldo actual es: %.2f\n",empleados[index].sueldo);
        printf("Ingrese nuevo monto:\n");
        scanf("%f",&sueldo);

        printf("Desea modificarlo? s/n \n");
        fflush(stdin);
        confirma= getche();

        if(tolower(confirma)== 's')
        {
            empleados[index].sueldo = sueldo;
        }
    }
}

void ordenarEmpleados(eEmpleado empleados[], int tam)
{
    int i,j;
    eEmpleado aux;

    for(i=0;i<tam-1;i++)
    {
        if(empleados[i].estado==0)
        {
            continue;
        }
        for(j=i+1;j<tam;j++)
        {
            if(empleados[j].estado ==0)
            {
                continue;
            }
            if(empleados[i].legajo > empleados[j].legajo)
            {
                aux = empleados[i];
                empleados[i]= empleados[j];
                empleados[j]= aux;
            }
        }
    }
}

int obtenerSector(eSector sectores[],int tam, int idSector,int desc[])
{
    int ok=0;

    for(int i =0; i<tam;i++)
    {
        if(idSector == sectores[i].id)
        {
            strcpy(desc,sectores[i].desc);
            ok =1;
            break;
        }
    }
    return ok;
}

void mostrarSectoresConEmpleados(eEmpleado empleados[],int tam,eSector sectores[],int tamSectores)
{
    for(int i=0;i<tamSectores;i++)
    {
        printf("SECTOR: %s\n",sectores[i].desc);
        for(int j=0;j<tam;j++)
        {
            if((empleados[j].idSector == sectores[i].id) && (empleados[j].estado ==1))
            {
                mostrarEmpleado(sectores,tamSectores,empleados[j]);
            }
        }
    }
    printf("\n");
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores)
{
    int contador;

    for(int i=0; i< tamSectores; i++ )
    {
        contador = 0;
        printf("\nSector: %s\n", sectores[i].desc);

        for(int j=0; j < tam; j++)
        {
            if(sectores[i].id == empleados[j].idSector && empleados[j].estado == 1)
            {
                contador++;
            }
        }

        printf("Cantidad: %d\n", contador);
    }
}
