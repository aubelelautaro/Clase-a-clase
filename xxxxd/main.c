#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[40];
    char sexo;
    int sueldo;
}eEmpleado;

int main()
{
    eEmpleado* pemp = (eEmpleado*) malloc(sizeof(eEmpleado));

    /*int* pnum = (int*) malloc(sizeof(int)* 5);
    int i,j;

    if (pnum==NULL)
    {
        printf("No se consiguio memoria");
        exit(1); // SOLO SE USA EXIT EN LA FUNCION MAIN
    }
    for(i=0;i<5;i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", pnum+i);
    }
    for(j=0;j<5;j++)
    {
       printf("NUMERO: %d\n",*(pnum +j));
    }

    int* paux = (int*) realloc(pnum,sizeof(int)* 10);
    if(paux!=NULL)
    {
        pnum=paux;
    }else
    {
        exit(1);
    }
    for(i=5;i<10;i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", pnum+i);
    }
    printf("ARRAY AGRANDADO:\n");
   for(j=0;j<10;j++)
   {
       printf("NUMERO: %d\n",*(pnum +j));
   }
   pnum = (int*) realloc(pnum,sizeof(int)* 5);
   printf("ACHICADO NUEVAMENTE:\n");
   for(j=0;j<10;j++)
   {
       printf("NUMERO: %d\n",*(pnum +j));
   }*/

   if (pemp==NULL)
    {
        printf("No se consiguio memoria");
        exit(1); // SOLO SE USA EXIT EN LA FUNCION MAIN
    }
    printf("INGRESE LEGAJO");
    scanf("%d",&pemp->legajo);

    printf("INGRESE NOMBRE");
    fflush(stdin);
    gets(pemp->nombre);

    printf("INGRESE SEXO");
    scanf("%c",&pemp->sexo);

    printf("INGRESE SUELDO");
    scanf("%d",&pemp->sueldo);

    printf("LEGAJO: %d - NOMBRE: %s - SEXO: %c - SUELDO: %d",pemp->legajo,pemp->nombre,pemp->sexo,pemp->sueldo);
    free(pemp);
    return 0;
}
