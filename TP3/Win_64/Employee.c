#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado = (Employee*)malloc( sizeof(Employee));
    int flag = 0;

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = atoi(idStr);
        strcpy(nuevoEmpleado->nombre, nombreStr);
        nuevoEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
        if(employee_getId(nuevoEmpleado, atoi(idStr)) == 1){
            if(employee_setNombre(nuevoEmpleado, nombreStr)== 1){
                if(employee_setHorasTrabajadas(nuevoEmpleado, horasTrabajadasStr)== 1){
                    if(employee_setSueldo(nuevoEmpleado, sueldoStr)== 1)
                    {
                        flag = 1;
                    }
                }
            }
        }
        if(flag == 0)
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }

    return flag;
}

int employee_setId(Employee* this,int id)
{
    int flag = 0;

    if(this != NULL && id >0)
    {
        this->id = id;
        flag =1;
    }

    return flag;
}

int employee_getId(Employee* this,int* id)
{
    int flag = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag = 1;
    }

    return flag;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int flag = 0;

    if(this != NULL && sueldo >0 && sueldo <  100000)
    {
        this->sueldo = sueldo;
        flag =1;
    }

    return flag;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int flag = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        flag = 1;
    }

    return flag;
}

int employee_setNombre(Employee* this,char* nombre)
{

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

}
