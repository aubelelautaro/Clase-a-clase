#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 3

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    int id;
    char desc[31];
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
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
void ordenarEmpleados(eEmpleado vec[], int tam);

int main()
{
    int rta = 's';
    int opcion;
    char confirma;

    eEmpleado lista[TAM]= {{"ASD",'M',100,240.22,1,19,04,1999},{"BSD",'F',200,540.22,1,23,04,1999},{"CSD",'M',300,740.22,0,05,04,1999}};
    //inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(lista,TAM);
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
            mostrarEmpleados(lista,TAM);
            system("pause");
            break;
        case 5:

            system("pause");
            break;
        case 6:
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
    printf("6.Salir\n");
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

void mostrarEmpleado(eEmpleado emp)
{
    printf("%10s   %4c     %5d     %.2f   %d/%d/%d \n", emp.nombre,emp.sexo,emp.legajo,emp.sueldo,emp.fechaNacimiento.dia,emp.fechaNacimiento.mes,emp.fechaNacimiento.anio);
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int flag =0;

    printf("NOMBRE\t\tSEXO\tLEGAJO\tSUELDO\tNACIMIENTO\n");
    for(int i=0; i<tam; i++)
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

void altaEmpleado(eEmpleado vec[], int tam)
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
            mostrarEmpleado(vec[esta]);
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
            if(vec[i].legajo > vec[i].legajo)
            {
                aux.nombre = vec[i].nombre;
                vec[i].nombre = vec[j].nombre;
                vec[j].nombre= aux.nombre;

                aux.sexo = vec[i].sexo;
                vec[i].sexo = vec[j].sexo;
                vec[j].sexo= aux.sexo;

                aux.legajo = vec[i].legajo;
                vec[i].legajo = vec[j].legajo;
                vec[j].legajo = aux.legajo;

                aux.sueldo = vec[i].sueldo;
                vec[i].sueldo = vec[j].sueldo;
                vec[j].sueldo = aux.sueldo;

                aux.idSector = vec[i].idSector;
                vec[i].idSector = vec[j].idSector;
                vec[j].idSector = aux.idSector;

            }

        }
    }

}
