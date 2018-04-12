#include <stdio.h>
#include <stdlib.h>
#include "Vectores.h"
#define TAM 6

int main()
{
    int vector [TAM];
    int i;
    int mayor;
    int index;

    cargarVectores(vector,i,TAM);
    mostrarVector(vector, TAM);
    mayor = maximoValor(vector, TAM);
    index = buscarValor(vector, TAM, 14);
    return 0;
}
