#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "socio.h"
#include "funciones.h"
#include "libros.h"
#include "prestamos.h"

void ePrestamo_alta(ePrestamo prestamos[], int tam,eSocio socios[],int tamSocios,eLibro libros[], int tamLibros)
{
    int index;
    int indexSocio;
    int indexLibro;
    int auxCodigo;
    int dia,mes,anio;
    char auxDia[3],auxMes[3],auxAnio[5];
    int auxCodigoLibro,auxCodigoSocio;

    index = ePrestamo_buscarLibre(prestamos,tam);

    //VALIDAR  SI NO HAY LIBROS Y TAMPOCO AUTORES
    if(index == -1)
    {
        printf("\nNo hay prestamos disponibles\n");
    }
    else if(eLibro_listar(libros,tamLibros))
    {
        auxCodigo= ePrestamo_siguienteId(prestamos,tam);
        printf("Codigo de prestamo: %d\n",auxCodigo);

        printf("Ingrese codigo del libro: ");
        scanf("%d",&auxCodigoLibro);
        indexLibro = eLibro_buscar(libros,tamLibros,auxCodigoLibro);

        if(indexLibro==-1)
        {
            printf("No se encontro el libro\n");
        }
        else if(eSocio_mostrarTodos(socios,tamSocios))
        {
            printf("Ingrese codigo del socio: ");
            scanf("%d",&auxCodigoSocio);
            indexSocio = eSocio_buscar(socios,tamSocios,auxCodigoSocio);

            if(indexSocio==-1)
            {
                printf("No se encontro el socio\n");
            }else
            {
                do
                {
                    getStringNumeros("Ingrese dia entre 1 y 31: ",auxDia);
                    dia =atoi(auxDia);
                }while(dia>31 || dia <1);
                prestamos[index].fechaPrestamo.dia = dia;

                do
                {
                    getStringNumeros("Ingrese mes entre 1 y 12: ",auxMes);
                    mes =atoi(auxMes);
                }while(mes>12 || mes <1);
                prestamos[index].fechaPrestamo.mes = mes;

                do
                {
                    getStringNumeros("Ingrese anio entre 2016 y 2020: ",auxAnio);
                    anio =atoi(auxAnio);
                }while(anio>2020 || anio <2016);

                prestamos[index].codigo = auxCodigo;
                prestamos[index].codigoSocio = auxCodigoSocio;
                prestamos[index].codigoLibro = auxCodigoLibro;
                prestamos[index].fechaPrestamo.anio = anio;
                prestamos[index].estado = 1;
                printf("Alta de prestamo exitosa.\nCodigo: %d  Codigo de Socio: %d  Codigo de libro: %d  Fecha de prestamo: %d/%d/%d\n",auxCodigo,prestamos[index].codigoSocio,prestamos[index].codigoLibro,prestamos[index].fechaPrestamo.dia,prestamos[index].fechaPrestamo.mes,prestamos[index].fechaPrestamo.anio);
                auxCodigo++;
            }
        }
    }
}

int ePrestamo_buscarLibre(ePrestamo prestamos[],int tam)
{
    int index = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if (prestamos[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int ePrestamo_siguienteId(ePrestamo prestamos[],int tam)
{
    int retorno = 0;
    int i;

        for(i=0; i<tam; i++)
        {
            if(prestamos[i].codigo>retorno)
            {
                 retorno=prestamos[i].codigo;
            }
        }

    return retorno+1;
}

void ePrestamo_init(ePrestamo prestamos[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        prestamos[i].codigo = 0;
        prestamos[i].estado = 0;
    }
}

void ePrestamo_initDatos(ePrestamo prestamos[],int tam)
{
    int i;
    ePrestamo auxPrest[] ={
    {1,2,10,{5,4,2018},1}, //ID PRESTAMO ,LIBRO, SOCIO
    {2,1,2,{5,4,2018},1},
    {4,1,1,{5,4,2019},1},
    {3,3,5,{5,4,2019},1},
    {8,3,6,{18,9,2018},1},
    {6,3,5,{18,9,2018},1},
    {7,4,5,{11,9,2017},1},
    {5,4,6,{11,9,2015},1},
    {9,5,6,{5,4,2016},1},
    {10,5,2,{5,4,2016},1}};

    for(i=0;i<tam;i++)
    {
        prestamos[i]=auxPrest[i];
    }
}
int menuListar()
{
    char opcion = '.';

    printf("\n----MENU LISTAR----\n");
    printf("A.Total general y promedio diario\n");
    printf("B.Cantidad de dias que no superan el promedio del item anterior\n");
    printf("C.Socios que solicitaron un prestamo de un libro determinado\n");
    printf("D.Libros solicitados a prestamo por un socio determinado\n");
    printf("E.Libros menos solicitados en prestamo\n");
    printf("F.Socio(s) que realizaron mas solicitudes a prestamo\n");
    printf("G.Libros solicitados a prestamo en una fecha determinada\n");
    printf("H.Socios que realizaron al menos una solicitud a prestamo en una fecha determinada\n");
    printf("I.Libros ordenados por titulo descendente\n");
    printf("J.Socios ordenados por apellido\n");
    printf("K.Salir\n");

    opcion=getChar("Elija una opcion: \n",opcion);
    opcion = toupper(opcion);

    return opcion;
}

int ePrestamo_cantidadPrestamos(ePrestamo prestamos[], int tam)
{
    int contador=0;
    int i;

    for (i=0;i<tam; i++)
    {
        if(prestamos[i].estado)
        {
            contador++;
        }
    }
    return contador;
}

int ePrestamo_cantidadDias(ePrestamo prestamos[],int tam)
{
    int fechas=1;
    int i,j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if((prestamos[i].estado && prestamos[j].estado)&& (prestamos[i].fechaPrestamo.dia!=prestamos[j].fechaPrestamo.dia || prestamos[i].fechaPrestamo.mes!=prestamos[j].fechaPrestamo.mes || prestamos[i].fechaPrestamo.anio!=prestamos[j].fechaPrestamo.anio))
            {
                i=j;
                fechas++;
            }
        }
    }
    return fechas;
}

void ePrestamo_mostrarPrestamos(ePrestamo prestamos[], int tam)
{
    int i;
    int flag=0;

    printf("Codigo  Codigo de Socio Codigo de Libro Fecha\n");
    for (i=0; i<tam; i++)
    {
        if(prestamos[i].estado)
        {
            printf("%d\t%d\t%d\t%d/%d/%d\n",prestamos[i].codigo,prestamos[i].codigoSocio,prestamos[i].codigoLibro,prestamos[i].fechaPrestamo.dia,prestamos[i].fechaPrestamo.mes,prestamos[i].fechaPrestamo.anio);
            flag =1;
        }
    }
    if(!flag)
    {
        printf("No hay prestamos");
    }
}

void ePrestamo_listarTotalYPromedioDiario(ePrestamo prestamos[], int tam)
{
    float promedio;
    int contador=ePrestamo_cantidadPrestamos(prestamos,tam);
    int fechas=ePrestamo_cantidadDias(prestamos,tam);

    ePrestamo_mostrarPrestamos(prestamos,tam);

    promedio=(float)contador/fechas;

    if (contador == 0) //si se cumple no existen prestamos activos en el array
	{
	  printf("No hay prestamos en el sistema");
	  promedio =-1;
	}else
	{
	    printf("El total general de prestamos es: %d\n",contador);
        printf("El promedio diario de prestamos es: %.2f\n",promedio);
	}
}

void ePrestamo_listarCantidadDiasNoSuperanPromedio(ePrestamo prestamos[], int tam)
{

    int contador=ePrestamo_cantidadPrestamos(prestamos,tam);
    int fechas= ePrestamo_cantidadDias(prestamos,tam);

    int i,j;
    int fechasIguales=1;
    int noSuperan=0;
    float promedio =(float)contador/fechas;

    if(contador ==0)
    {
        printf("No hay prestamos.\n");
    }else
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(prestamos[i].estado && prestamos[j].estado)
                {
                    if(prestamos[i].fechaPrestamo.dia==prestamos[j].fechaPrestamo.dia && prestamos[i].fechaPrestamo.mes==prestamos[j].fechaPrestamo.mes && prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio)
                    {
                        fechasIguales++;
                    }else
                    {
                        i=j;
                        if(fechasIguales<promedio)
                        {
                            noSuperan++;
                        }
                        fechasIguales=1;
                    }
                }
            }
        }
        if(promedio == 1)
        {
            noSuperan=contador;
        }
        printf("Cantidad de dias que no superan el promedio: %d\n",noSuperan);
    }
}

