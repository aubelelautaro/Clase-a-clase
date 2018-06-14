#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int retorno;
    int l;
    int a,b,c,d;

    pFile=fopen("data.csv", "r");

    if(pFile == NULL)
    {
        printf("Archivo inexiste");
        retorno= -1;
    }
    do
    {
        al_add(ArrayList* pList,void* pElement);
        l=fscanf(pFile,"%d,%s,%s,%d\n",&a,&b,&c,&d);

        if(r==4)
        {
           printf("Lee: %d %s %s %d\n",a,b,c,d);
        }else
        {
            break;
        }

    }while(!feof(pFile));

    fclose(pFile);

    return retorno;
}
