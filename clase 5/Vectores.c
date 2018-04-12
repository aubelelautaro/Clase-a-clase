#include "Vectores.h"

void cargarVectores (int vector[],int i,int TAM)
{
    for (i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }
}
void mostrarVector (int vec[], int tamanio)
{
    int i;
    for (i=0; i<tamanio; i++)
    {
        printf("%d -- %d\n",i,vec[i]);
    }
}
int maximoValor(int vec[], int tam)
{
    int maximo;
    int i;
    int flag = 0;

    for(i=0; i<tam; i++)
    {
        if (flag == 0 || vec[i]> maximo)
        {
            maximo = vec[i];
            flag = 1;
        }
    }
    printf("\nEl vector mayor es: %d", maximo);
    return maximo;
}

int buscarValor(int vec[], int tam, int valor)
{
    int index = -1;
    int i;

    for (i=0; i<tam; i++)
    {
        if (valor == vec[i])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("\nEl indice no lo encontro");
    }
    else
    {
        printf("\nEncontro el indice: %d", index);
    }
    return index;
}
