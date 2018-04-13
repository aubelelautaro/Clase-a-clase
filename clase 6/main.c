#include <stdio.h>
#include <stdlib.h>

int contarPares(int[],int);
/** \brief determina si un caracter esta en array
 *
 * \param char[] coleccion de caracteres
 * \param int tamaño
 * \param char caracter a buscar
 * \return int  -1 si no lo encuentra o el indice del valor encontrado
 *
 */
int buscarChar (char[],int,char);

int main()
{
    int vector [5] = {9,1,3,6,4};
    int i;
    int j;
    int aux;
    for (i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(vector[i]>vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
    for (i=0;i<5;i++)
    {
        printf("%d\n", vector [i]);
    }
    return 0;
}

int main2()
{
    int vector[7] ={2,3,4,5,6,-7,1};
    char letras[4] ={'l','a','u','c'};
    int cantidad;
    int indexLetra;

    int a = 9;
    int b = 5;
    int c;

    //swap
    c = a;
    a = b;
    b = c;

    printf("a = %d -- b = %d",a,b);
    cantidad = contarPares(vector, 7); //parametros actuales
    indexLetra = buscarChar(letras, 7,'l');
    printf("\nCantidad de pares: %d", cantidad);
    printf("\nCaracter: %d",indexLetra);
    if(indexLetra==-1)
    {
        printf("No se encuentra el caracter");
    }
    else
    {
        printf("El caracter se encuentra en el array");
    }
    return 0;
}
int contarPares(int array[],int cantidad) //parametros formales
{
    int contPares = 0 ;
    int i;

    for (i=0;i<cantidad;i++)
    {
        if (array[i]%2==0)
        {
            contPares++;
        }
    }
    return contPares;
}
int buscarChar (char array[],int cantidad,char caracter)
{
    int index = -1;
    int i;
     for (i=0;i<cantidad;i++)
    {
        if (array[i] == caracter)
        {
            index = i;
            break;
        }
    }
    return index;
}
