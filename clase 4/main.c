#include <stdio.h>
#include <stdlib.h>

//prototipos
void sumar1 (void);
void sumar2 (int,int);
void sumar3 ();

int main()
{
    sumar1();
    sumar2(2,5);
    int resultado;
    resultado = sumar3();
    return 0;
}

void sumar1(void)
{
    int n1;
    int n2;
    int suma;

    n1 = pedirEntero("Ingrese un numero:",1,1000);
    n2 = pedirEntero("Ingrese un numero:",1,1000);
    suma = n1 + n2;

    printf("Suma: %d", suma);
}

void sumar2(int n1, int n2)
{

}
