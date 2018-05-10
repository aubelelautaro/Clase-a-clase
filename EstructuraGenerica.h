#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int idUsuario;
    int estado;
    int calificacion;
}eUsuario;

typedef struct
{
    char nombre[50];
    int idProducto;
    int idUsuario;
    char nombreProducto[50];
    float precio;
    int stock;
    int cantidadVentas;
    int cantidadVentasPromedio;
    int estado;
}eProducto;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

/** \brief Inicializa los usuarios en estado 0 (libre). Además inicializa las calificaciones y el id en 0.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param int El largo del array que contiene los usuarios.
 * \return void
 *
 */
void eUser_init(eUsuario[],int);

/** \brief Inicializa los productros en estado 0 (libre). Además inicializa la cantidad de ventas y el id en 0.
 *
 * \param eProducto[]  El array que contiene a los productos.
 * \param int El largo del array que contiene los usuarios.
 * \return void
 *
 */
void eProducto_init(eProducto[],int);

/** \brief Recorre el vector de usuarios buscando el primero que tenga estado libre y devuelve su índice.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param int El largo del array que contiene los usuarios.
 * \return int Devuelve la posición del vector en la que se encontró el primer usuario libre, de no encontrarlo
 * devuelve -1 o -2 (error).
 */
int eUser_buscarLugarLibre(eUsuario listado[],int limite);

/** \brief Recorre el vector de usuarios buscando el ultimo que tenga estado ocupado y devuelve el ID del siguiente.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \return int El ID del usuario siguiente al ultimo ocupado, si no devuelve 0.
 *
 */
int eUser_siguienteId(eUsuario[] ,int limite);

/** \brief Recibe un id, recorre el vector de usuarios buscando a que posicion corresponde ese ID.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \param id int El ID a buscar
 * \return int La posicion que coincide con el ID, si no coincide devuelve -1.
 *
 */
int eUser_buscarPorId(eUsuario[] ,int limite, int id);

/** \brief Permite el alta de usuarios.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \return int En caso de haber lugar para usuarios nuevos devuelve 0 y de no haber devuelve -2 o -3.
 *
 */
int eUser_alta(eUsuario[] ,int limite);

/** \brief Valida que solo se ingresen letras.
 *
 * \param nombre Una copia del nombre ingresado por el usuario.
 * \return int Devuelve 0 en caso de error y un 1 si esta bien.
 *
 */
int validarNombre(char nombre[]);

/** \brief Valida que solo se ingresen numeros
 *
 * \param numero int Una copia del numero ingresado por el usuario.
 * \return int Devuelve 0 en caso de error y un 1 si esta bien.
 *
 */
int validarNumero(char numero[]);

/** \brief Permite modificar el nombre del usuario elegido.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \return void
 *
 */
void eUser_modificacion(eUsuario[] ,int limite);

/** \brief Permite dar de baja al usuario elegido (poner usuarios y productos en estado BORRADO).
 *
* \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \param listadoProductos[] El array que contiene los productos.
 * \param limiteProductos int El largo del array que contiene los productos.
 * \return void
 *
 */
void eUser_baja(eUsuario[] ,int limite, eProducto listadoProductos[],int limiteProductos);

/** \brief Muestra nombre e ID de un solo usuario.
 *
 * \param parametro eUsuario Los parametros de un solo usuario.
 * \return void
 *
 */
void eUser_mostrarUno(eUsuario parametro);

/** \brief Muestra el listado de todos los usuarios con estado OCUPADO.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene a los usuarios.
 * \return void
 *
 */
void eUser_mostrarListado(eUsuario[] ,int limite);

int eProducto_altaPublicacion(eUsuario[], eProducto[], int, int);

int eProducto_buscarLugarLibre(eProducto[],int limite);

int eProducto_siguienteId(eProducto[],int limite);

int eProducto_modificarPublicacion(eUsuario[], eProducto[], int, int);

void eProducto_mostrarProductosPorIdUsuario(eProducto[], eUsuario[], int, int, int);

void eProducto_borrarProductosPorIdUsuario(eProducto[], eUsuario[], int, int, int);

void eProducto_mostrarUno(eProducto parametro);

int eProducto_mostrarListado(eProducto[],int);



int eProducto_cancelarPublicacion(eUsuario[], eProducto[], int, int);

int eProducto_comprarProducto(eUsuario[], eProducto[], int, int);

int eUser_listarPublicacionesUsuario(eUsuario[],int,eProducto[],int);

float promedioCalificaciones(eUsuario[], int, eProducto[], int);
