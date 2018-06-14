#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno;

    Employee* empleado1 = (Employee*)pEmployeeA;
    Employee* empleado2 = (Employee*)pEmployeeB;

    retorno = strcmp(empleado1->name,empleado2->name);

    return retorno;
}


void employee_print(Employee* this)
{
    printf("%d  -  %s  -  %s\n",this->id, this->name, this->lastName);
}


Employee* employee_new(void)
{
    Employee* returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;

    if(this!=NULL && id >0)
    {
        retorno = 1;
        this->id = id;
    }
    return retorno;
}

int employee_getId(Employee* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->id;
    }

    return retorno;
}


