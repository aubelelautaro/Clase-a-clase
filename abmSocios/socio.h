#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

typedef struct
{
    int dia,mes,anio;
}eFecha;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha fechaAsociado;
    int estado;

}eSocio;

typedef struct
{
    int codigo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPrestamo;
    int estado;
}ePrestamo;

typedef struct
{
    int codigo;
    char titulo[51];
    int codigoAutor;
    int estado;
}eLibro;

/** \brief Menu principal
 * \return la opcion elegida
 */
int menu();

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eSocio_init(eSocio[],int);

/** \brief
 *
 * \param [] eSocio array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eSocio_initDatos(eSocio [],int);

/** \brief
 *
 * \return int opcion
 *
 */
int eSocio_menuModificacion();

/** \brief
 *
 * \param eSocio elemento
 * \param int tamaño del array
 * \return void
 *
 */
void eSocio_mostrarUno(eSocio,int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int tamaño del array
 * \return int
 *
 */
int eSocio_mostrarTodos(eSocio[],int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eSocio_alta(eSocio[], int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eSocio_baja(eSocio[], int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int tamaño del array
 * \return void
 *
 */
void eSocio_modificarCampo(eSocio[], int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int
 * \return int
 *
 */
int eSocio_buscarLibre(eSocio[],int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int
 * \param int
 * \return int
 *
 */
int eSocio_buscar(eSocio[], int, int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int
 * \return void
 *
 */
void eSocio_listar(eSocio[],int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int
 * \return void
 *
 */
void eSocio_ordenarPorApellido(eSocio[],int);

/** \brief
 *
 * \param eSocio[] array de elementos
 * \param int
 * \return void
 *
 */
void eSocio_insertionSort(eSocio[], int);

/** \brief
 *
 * \param [] eSocio array de elementos
 * \param int
 * \param [] ePrestamo array de elementos
 * \param int
 * \return void
 *
 */
void eSocio_socioConAlgunPrestamo(eSocio [], int ,ePrestamo [], int);

/** \brief
 *
 * \param [] eSocio array de elementos
 * \param int
 * \param [] ePrestamo array de elementos
 * \param int
 * \return void
 *
 */
void eSocio_socioConMasPrestamos(eSocio [], int ,ePrestamo [], int);

/** \brief
 *
 * \param [] eSocio array de elementos
 * \param int
 * \param [] eLibro array de elementos
 * \param int
 * \param [] ePrestamo array de elementos
 * \param int
 * \return void
 *
 */
void eSocio_solicitaronUnLibro(eSocio [], int,eLibro [], int,ePrestamo [],int);

#endif // SOCIO_H_INCLUDED
