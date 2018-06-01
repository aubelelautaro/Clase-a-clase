#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[50];
}ePersona;

int ePersona_setId(ePersona*,int);
int ePersona_setNombre(ePersona*,char*);

int ePersona_getId(ePersona*);
char ePersona_getNombre(ePersona*);
//getters/setter ENCAPSULAMIENTO DE LOS DATOS
int main()
{

    /*
        stack/pila (es estatica, va variando cuando termina el marco de la funcion) pPersona  (punteros)
            |
            |
            V
        head/monton (reserva espacio en memoria y lo libera segun lo necesita) miPersona (DATOS)
    */

    ePersona* pPersona;
    int id;
    char nombre[20];
    pPersona = (ePersona*) malloc(sizeof(ePersona)); //reserva el espacio en memoria, y dependiendo del dato se pasa el dato(int*,float* o char *) adelante del malloc

    if (pPersona!=NULL)
    {
        printf("Ingrese id:");
        scanf("%d",&id);
        if(ePersona_setId(pPersona,id)==-1)
        {
            printf("ID INCORRECTO");
        }
        else
        {
            printf("Ingrese nombre:");
            scanf("%s",nombre);
            if(ePersona_setNombre(pPersona,nombre)==-1)
            {
                printf("NOMBRE INCORRECTO!");
            }else
            {
                printf("%d -- %s",ePersona_getId(pPersona), ePersona_getNombre(pPersona));
            }
        }
    }
    return 0;
}

int ePersona_setId(ePersona* this,int id)
{
    int ret=-1;
    if(id>0 && this != NULL)
    {
        ret = 1;
        this->id = id;
    }
    return ret;
}

int ePersona_setNombre(ePersona* this,char* nombre)
{
    int ret=-1;
    if(nombre != NULL && (strlen(nombre)>3) && this != NULL)
    {
        ret = 1;
        strcpy(this->nombre, nombre);
    }
    return ret;
}

int ePersona_getId(ePersona* this)
{
    int ret =-1;
    if(this != NULL)
    {
        ret = this->id;
    }
    return ret;
}

char ePersona_getNombre(ePersona* this)
{
    char ret = NULL;

    if (this!=NULL)
    {
        ret = this->nombre;
    }

    return ret;
}
