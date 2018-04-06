#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

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
