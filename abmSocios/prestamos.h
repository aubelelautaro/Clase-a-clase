#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#include "socio.h"

/** \brief
 *
 * \param ePrestamo[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void ePrestamo_init(ePrestamo[],int);

/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void ePrestamo_initDatos(ePrestamo [],int);

/** \brief
 *
 * \param ePrestamo[] array de elementos
 * \param int tamaño del array
 * \param [] eSocio array de elementos
 * \param int tamaño del array
 * \param [] eLibro array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void ePrestamo_alta(ePrestamo[],int,eSocio [],int,eLibro [], int);

/** \brief
 *
 * \param ePrestamo[] array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int ePrestamo_buscarLibre(ePrestamo[],int);

/** \brief
 *
 * \param ePrestamo[] array de elementos
 * \param int tamaño del array
 * \param int codigo del prestamo
 * \return int
 *
 */
int ePrestamo_buscar(ePrestamo[],int,int);

/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int ePrestamo_siguienteId(ePrestamo [],int);

/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int ePrestamo_cantidadPrestamos(ePrestamo [],int);

/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int ePrestamo_cantidadDias(ePrestamo [],int);

/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void mostrarPrestamos(ePrestamo [],int);

/** \brief
 *
 * \param [] ePrestamo lista del array de prestamo
 * \param tam int tamaño del array
 * \return void imprime el total general y el promedio diario
 *
 */
void ePrestamo_listarTotalYPromedioDiario(ePrestamo [], int);


/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void ePrestamo_listarCantidadDiasNoSuperanPromedio(ePrestamo [], int);

/** \brief Menu de listados
 * \return la opcion elegida
 */
int menuListar();

#endif // PRESTAMOS_H_INCLUDED
