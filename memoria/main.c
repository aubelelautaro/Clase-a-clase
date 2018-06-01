#include <stdio.h>
#include <stdlib.h>
#define tam 5
int main()
{
    int* pVector;
    int* aux;
    int i;

    pVector = (int*) malloc(sizeof(int)* tam);

    if(pVector!=NULL)
    {
        for (i=0; i<tam; i++)
        {
            *(pVector +i) = i+1;
        }
        for (i=0; i<tam; i++)
        {
            printf("%d\n",*(pVector +i));
        }

        aux = (int*) realloc(pVector, sizeof(int)* tam*2); //REASIGNA ESPACIO EN MEMORIA, SI NO ENCUENTRA LUGAR LO ASIGNA A OTRAS MEMORIAS, SI NO ENCUENTRA OTRAS MEMORIAS PARA ASIGNAR DEVUELVE NULO
        if (aux!=NULL)
        {
            pVector = aux;
            for (i=tam; i<tam*2; i++)
            {
                *(pVector +i) = i+1;
            }
            for (i=0; i<tam*2; i++)
            {
                printf("REALLOC: %d\n",*(pVector +i));
            }
        }
        if (aux!=NULL)
        {
            pVector = aux;
            for (i=tam; i<4; i++)
            {
                *(pVector +i) = i+1;
            }
            for (i=0; i<4; i++)
            {
                printf("REALLOC por menos: %d\n",*(pVector +i));
            }
        }
        free(aux);
    }
    return 0;
}

