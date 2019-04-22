#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 10
#define TAMSEC 5

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    int id;
    char desc[21];
}eSector;

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

int menu();
void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eSector sectores[],int tam,eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[],int tam,eSector sectores[],int tamSectores);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eSector sectores[],eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
void ordenarEmpleados(eEmpleado vec[], int tam);
int obtenerSector(eSector sectores[],int tam, int id,int desc[]);
void mostrarSectoresConEmpleados(eEmpleado vec[],int tam,eSector sectores[],int tamSectores);

int main()
{
    int rta = 's';
    int opcion;
    char confirma;

    eEmpleado lista[TAM] = {
        {"ASD",'M',500,240.22,1,{19,04,1999},1},
        {"BSD",'F',900,540.22,1,{23,05,1990},2},
        {"CSD",'M',300,740.22,1,{05,01,1929},3}
        };
    eSector sectores[5] = {
        {1,"AAA"},
        {2,"BBB"},
        {3,"CCC"},
        {4,"DDD"},
        {5,"EEE"}};
    //inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(sectores,lista,TAM);
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
    printf("6.Mostrar sectores con empleados\n");
    printf("7.Salir\n");
    printf("Elija una opcion:");
    scanf("%d",&opcion);

    return opcion;
}


void inicializarEmpleados(eEmpleado vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].estado= 0;
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

void mostrarEmpleado(eSector sectores[],int tam,eEmpleado emp)
{
    int nombreSector[20];
    int esta;
    esta = obtenerSector(sectores,tam, emp.idSector, nombreSector);

    if (!esta)
    {
        strcpy(nombreSector, "Sin definir");
    }
    printf("%10s   %4c     %5d     %.2f   %d/%d/%d  %s\n", emp.nombre,emp.sexo,emp.legajo,emp.sueldo,emp.fechaNacimiento,nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSectores)
{
    int flag =0;

    printf("NOMBRE\t\tSEXO\tLEGAJO\tSUELDO\tNACIMIENTO\tSECTOR\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarEmpleado(sectores, tam,vec[i]);
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

    for(int i=0; i<tam; i++)
    {
        if (vec[i].estado == 0)
        {
            printf("El indice vacio es: %d\n", i);
            index = i;
            break;
        }
        else if(vec[i].estado ==1)
        {
            index = -1;
        }
    }
    return index;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(vec[i].estado ==1 && vec[i].legajo == legajo)
        {
            index=i;
            break;
        }
    }

    return index;
}

void altaEmpleado(eSector sectores[],eEmpleado vec[], int tam)
{
    int index;
    int legajo;
    int esta;

    index = buscarLibre(vec, tam);

    if(index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tam,vec[esta]);
        }
        else
        {
            vec[index].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[index].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[index].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[index].sueldo );

            printf("Fecha de nacimiento\nDia:");
            scanf("%d",&vec[index].fechaNacimiento.dia);

            printf("Mes:");
            scanf("%d",&vec[index].fechaNacimiento.mes);

            printf("Anio:");
            scanf("%d",&vec[index].fechaNacimiento.anio);

            printf("Ingrese sector (1 a 5)");
            scanf("%d",&vec[index].idSector);

            vec[index].estado = 1;

            printf("Alta empleado exitosa\n\n");
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int index;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    index = buscarEmpleado(vec,tam,legajo);

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
            vec[index].estado =0;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("No se dio de baja al empleado\n");
        }
    }
}

void modificarEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    int index;
    float sueldo;
    char confirma;

    printf("Ingrese legajo del empleado a modificar:\n");
    scanf("%d",&legajo);

    index = buscarEmpleado(vec,tam,legajo);

    if(index==-1)
    {
        printf("No se encontro el empleado");
    }
    else
    {
        printf("El sueldo actual es: %f\n",vec[index].sueldo);
        printf("Ingrese nuevo monto:\n");
        scanf("%.2f",&sueldo);

        printf("Desea modificarlo? s/n \n");
        fflush(stdin);
        confirma= getche();

        if(tolower(confirma)== 's')
        {
            vec[index].sueldo = sueldo;
        }
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam)
{
    int i,j;
    eEmpleado aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;i<tam;i++)
        {
            if(vec[i].legajo > vec[j].legajo)
            {
                aux = vec[i];
                vec[i]= vec[j];
                vec[j]= aux;
            }

        }
    }
}

void mostrarSectoresConEmpleados(eEmpleado vec[],int tam,eSector sectores[],int tamSectores)
{
    for(int i=0;i<tamSectores;i++)
    {
        printf("SECTOR: %s\n",sectores[i].desc);
        for(int j=0;j<tam;j++)
        {
            if(vec[j].idSector == sectores[i].id && vec[j].estado ==1)
            {
                mostrarEmpleado(sectores,tamSectores,vec[j]);
            }
        }
    }
    printf("\n");
}
