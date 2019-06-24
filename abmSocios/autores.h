#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int codigo;
    char nombre[31];
    char apellido[31];
    int estado;
}eAutor;

/** \brief
 *
 * \param eAutor[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_ordenPorApellido(eAutor[],int);

/** \brief
 *
 * \param [] eAutor array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int eAutor_buscarLibre(eAutor [],int);

/** \brief
 *
 * \param eAutor[] array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int eAutor_listar(eAutor[],int);

/** \brief
 *
 * \param eAutor elemento
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_mostrarUno(eAutor , int);

/** \brief Menu abm de autores
 * \return la opcion elegida
 */
int menuAutores();

/** \brief
 *
 * \return int
 *
 */
int eAutor_menuModificacion();

/** \brief
 *
 * \param eAutor[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_init(eAutor[], int);

/** \brief
 *
 * \param [] eAutor array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_initDatos(eAutor [],int);

/** \brief
 *
 * \param [] eAutor array de elementos
 * \param int tamaño del array
 * \param int codigo de autor
 * \return int
 *
 */
int eAutor_buscar(eAutor [], int ,int);

/** \brief
 *
 * \param eAutor[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_alta(eAutor[], int);

/** \brief
 *
 * \param eAutor[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_modificacion(eAutor[], int);

/** \brief
 *
 * \param eAutor[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eAutor_baja(eAutor[], int);

/** \brief
 *
 * \param [] eAutor array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int eAutor_siguienteId(eAutor [],int );

#endif // AUTORES_H_INCLUDED
