#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include "autores.h"
#include "socio.h"

/** \brief Menu abm de libros
 * \return int  opcion elegida
 */
int menuLibros();

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array
 * \return int 1 si hay libros, 0 si no hay
 *
 */
int eLibro_listar(eLibro[],int);

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eLibro_init(eLibro[], int);

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eLibro_initDatos(eLibro [], int);

/** \brief
 *
 * \param eLibro[] array de elementos
 * \param int tamaño del array
 * \return int indice libre
 *
 */
int eLibro_buscarLibre(eLibro[],int);

/** \brief
 *
 * \param eLibro[] array de elementos
 * \param int tamaño del array de libros
 * \param [] eAutor array de elementos
 * \param int tamaño del array de autores
 * \return void
 *
 */
void eLibro_alta(eLibro[], int, eAutor [], int);

/** \brief
 *
 * \param eLibro[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eLibro_baja(eLibro[], int);

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array
 * \return int siguiente posicion del array
 *
 */
int eLibro_siguienteId(eLibro [],int );

/** \brief
 *
 * \param eLibro elemento
 * \param int tamaño del array
 * \return void
 *
 */
void eLibro_mostrarUno(eLibro,int);

/** \brief
 *
 * \param eLibro[] array de elementos
 * \param int tamaño del array
 * \param int codigo del libro a buscar
 * \return int -1 si no encontro el indice o el indice
 *
 */
int eLibro_buscar(eLibro[], int,int);

/** \brief
 *
 * \param eLibro[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eLibro_ordenPorTitulo(eLibro[],int);

/** \brief
 *
 * \param eLibro[] array de elementos
 * \param int tamaño del array de libros
 * \param eAutor[]  array de elementos
 * \param int tamaño del array de autores
 * \return void
 *
 */
void eLibro_mostrarConAutor(eLibro[],int,eAutor[],int);

/** \brief
 *
 * \return int opcion elegida
 *
 */
int eLibro_menuModificacion();

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array de libros
 * \param [] eAutor array de elementos
 * \param int tamaño del array de autores
 * \return void
 *
 */
void eLibro_modificarCampo(eLibro [], int,eAutor [],int);

/** \brief
 *
 * \param [] eSocio array de elementos
 * \param int tamaño del array de socios
 * \param [] eLibro array de elementos
 * \param int tamaño del array de libros
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array de prestamos
 * \return void
 *
 */
void eLibro_solicitadoPorUnSocio(eSocio [],int,eLibro [],int,ePrestamo [],int);

/** \brief
 *
 * \param [] ePrestamo array de elementos
 * \param int tamaño del array de prestamos
 * \param [] eLibro array de elementos
 * \param int tamaño del array de libros
 * \return void
 *
 */
void eLibro_menosSolicitado(ePrestamo [],int,eLibro [],int);

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array de libros
 * \return void
 *
 */
void eLibro_listarDescendiente(eLibro [], int);

/** \brief
 *
 * \param [] eLibro array de elementos
 * \param int tamaño del array
 * \param ePrestamo[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eLibro_fechaDeterminada(eLibro [], int, ePrestamo[], int);

#endif // LIBROS_H_INCLUDED
