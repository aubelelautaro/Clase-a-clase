#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int intAux;
    int i;

    ArrayList* lista;
    Employee* eEmpleado;
    Employee* eEmpleado2;
    Employee* eEmpleadoAux;

    lista = al_newArrayList(); //se le pide memoria al sistema operativo (malloc)

    //PARSEA EL ARCHIVO
    parserEmployee(fp, lista);

    /*
    eEmpleado = (Employee*)malloc(sizeof(Employee)); // cargar valores para empleado
    eEmpleado -> id = 4;
    strcpy(eEmpleado->name,"ZZJuan");
    strcpy(eEmpleado->lastName,"Gomez");
    eEmpleado -> isEmpty = 1;

    al_add(lista, eEmpleado);//AGREGA AL EMPLEADO


    // eEmpleadoAux = (Employee*)al_get(lista[i]); //0 para arrancar en el primer lugar
    // employee_print(eEmpleadoAux);

    eEmpleado2 = (Employee*)malloc(sizeof(Employee)); // cargar valores para empleado
    eEmpleado2 -> id = 5;
    strcpy(eEmpleado2->name,"AAPedro");
    strcpy(eEmpleado2->lastName,"Lopez");
    eEmpleado2 -> isEmpty = 2;

    al_add(lista, eEmpleado2);

    */

    intAux = al_len(lista);
    printf("cantidad de elementos: %d\n", intAux);

    for(i=0;i<intAux;i++)
    {
        eEmpleadoAux = (Employee*)al_get(lista,i); //i para arrancar en cada posicion
        employee_print(eEmpleadoAux);
    }

    printf("\nORDENADOS\n");
    al_sort(lista,employee_compare,1);
    for(i=0;i<intAux;i++)
    {
        eEmpleadoAux = (Employee*)al_get(lista,i); //i para arrancar en cada posicion
        employee_print(eEmpleadoAux);
    }

    intAux=al_len(lista);
    printf("cantidad de elementos despues de eliminar: %d\n",intAux);

    for(i=0;i<intAux;i++)
    {
        eEmpleadoAux=(Employee*)al_get(lista, i); //Casteo para guardarlo como tipo de Employee*, uso el getter que me trae la posicion i de la lista
        employee_print(eEmpleadoAux);
    }

    return 0;
}
