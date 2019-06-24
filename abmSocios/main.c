#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "socio.h"
#include "autores.h"
#include "libros.h"
#include "prestamos.h"

#define TAMSOCIOS 10
#define TAMLIBROS 5
#define TAMAUTORES 5
#define TAMPRESTAMOS 10

int main()
{
    char rta = 'S';
    char rtaLibros = 'S';
    char rtaAutores = 'S';
    char rtaListar = 'S';

    eSocio listaSocios[TAMSOCIOS];
    eLibro listaLibros[TAMLIBROS];
    eAutor listaAut[TAMAUTORES];
    ePrestamo listaPrest[TAMPRESTAMOS];

    eLibro_initDatos(listaLibros,TAMLIBROS);
    eAutor_initDatos(listaAut,TAMAUTORES);
    ePrestamo_initDatos(listaPrest,TAMPRESTAMOS);
    eSocio_initDatos(listaSocios,TAMSOCIOS);

    //eLibro_init(listaLibros,TAMLIBROS);
    //eAutor_init(listaAut,TAMAUTORES);
    //ePrestamo_init(listaPrest,TAMPRESTAMOS);
    //eSocio_init(listaSocios,TAMSOCIOS);

    //EL PRESTAMO SIGUE ESTANDO DADO DE ALTA AUNQUE EL LIBRO SE HAYA DADO DE BAJA, DUDA PARA PREGUNTARLE AL PROFESOR
    do
    {
        switch(menu())
        {
        case 'A':
            eSocio_alta(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'B':
            eSocio_modificarCampo(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'C':
            eSocio_baja(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'D':
            eSocio_listar(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'E':
            do
            {
                switch(menuLibros())
                {
                case 'A':
                    eLibro_alta(listaLibros,TAMLIBROS,listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'B':
                    eLibro_modificarCampo(listaLibros,TAMLIBROS,listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'C':
                    eLibro_baja(listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'D':
                    eLibro_ordenPorTitulo(listaLibros,TAMLIBROS);
                    eLibro_listar(listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'E':
                    rtaLibros='N';
                    break;
                default:
                    printf("Ingrese opcion correcta\n");
                    system("pause");
                }
            }while(rtaLibros == 'S');
            system("pause");
            break;
        case 'F':
            do
            {
                switch(menuAutores())
                {
                case 'A':
                    eAutor_alta(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'B':
                    eAutor_modificacion(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'C':
                    eAutor_baja(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'D':
                    eAutor_listar(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'E':
                    rtaAutores='N';
                    break;
                default:
                    printf("Ingrese opcion correcta\n");
                    system("pause");
                }
            }while(rtaAutores == 'S');
            break;
        case 'G':
            ePrestamo_alta(listaPrest,TAMPRESTAMOS,listaSocios,TAMSOCIOS,listaLibros,TAMLIBROS);
            system("pause");
            break;
        case 'H':
            do
            {
                switch(menuListar())
                {
                case 'A':
                    ePrestamo_listarTotalYPromedioDiario(listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'B':
                    ePrestamo_listarCantidadDiasNoSuperanPromedio(listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'C':
                    eSocio_solicitaronUnLibro(listaSocios,TAMSOCIOS,listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'D':
                    eLibro_solicitadoPorUnSocio(listaSocios,TAMSOCIOS,listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'E':
                    eLibro_menosSolicitado(listaPrest,TAMPRESTAMOS,listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'F':
                    eSocio_socioConMasPrestamos(listaSocios,TAMSOCIOS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'G':
                    eLibro_fechaDeterminada(listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'H':
                    eSocio_socioConAlgunPrestamo(listaSocios,TAMSOCIOS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'I':
                    eLibro_listarDescendiente(listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'J':
                    eSocio_insertionSort(listaSocios,TAMSOCIOS);
                    system("pause");
                    break;
                case 'K':
                    rtaListar = 'N';
                    break;
                default:
                    printf("Ingrese opcion correcta\n");
                    system("pause");
                }
            }while(rtaListar == 'S');
            break;
        case 'I':
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Ingrese opcion correcta\n");
            system("pause");
        }
    }while(rta == 'S');

    return 0;
}
