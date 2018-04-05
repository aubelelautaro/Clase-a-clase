#include <stdio.h>
#include <stdlib.h>

int pedirEntero (char [], int , int);
int validarEntero(int, int , int, char []);

int main()
{
    int edad;
    int legajo;
    int nota;

    edad = pedirEntero("Edad: ", 18, 60);

    legajo = pedirEntero("Legajo: ", 1 , 1000);

    nota = pedirEntero("Nota: ", 1,10);

    printf("Edad : %d \nLegajo: %d \nNota: %d ", edad,legajo,nota);

    return 0;
}

int pedirEntero(char mensaje[] , int min , int max)
{
    int numero;

    printf("%s", mensaje);
    scanf ("%d", &numero);

    numero = validarEntero(numero,min,max,mensaje);

    return numero;
}

int validarEntero(int dato, int min , int max, char mensaje [])
{

    while (dato<min || dato>max)
    {
        printf("Error, reingrese %s", mensaje);
        scanf("%d", &dato);
    }
    return dato;
}
