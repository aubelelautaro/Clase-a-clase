#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas[5];
    int acum = 0;
    float prom;

    for (int i=0;i<5;i++)
    {
        printf("num:");
        scanf("%d", &notas[i]);
        acum+=notas;
    }
     for (int i = 0;i<5;i++)
    {
        printf("num ingresado: %d\n", notas[i]);
    }
    return 0;
}
