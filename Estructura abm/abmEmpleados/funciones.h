#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide un entero
 * \param char mensaje a mostrar
 * \param int numero que se ingresa
 * \param int minimo
 * \param int maximo
 * \return Devuelve el numero ingresado
 */

int getInt(char mensaje[],int num,int minimo,int maximo);

/** \brief Pide un flotante
 * \param char mensaje a mostrar
 * \param float numero que se ingresa
 * \return Devuelve el numero flotante ingresado
 */

float getFloat(char mensaje[],float numero);

/** \brief Pide un caracter
 * \param char mensaje a mostrar
 * \param char caracter que se ingresa
 * \return Devuelve el char ingresado
 */

char getChar(char mensaje[],char caracter);

/** \brief Pide una cadena de caracteres
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return void
 */

void getString(char mensaje[],char cadena[]);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char mensaje[],char cadena[]);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene solo numeros
 */

int getStringNumeros(char mensaje[],char cadena[]);

/** \brief Valida un numero entre un minimo y un maximo
 * \param int dato que se le pasa
 * \param int minimo del dato
 * \param int maximo del dato
 * \return Devuelve el numero validado entre el rango de min y max
 */

int validarEntero(int dato, int minimo, int maximo, char mensaje []);

/** \brief Verifica si el valor recibido es numero
 * \param str Array a ser analizado
 * \return 1 si es numero, 0 si no lo es
 */

int esNumerico(char str[]);

/** \brief Verifica si el valor recibido es solo letras
 * \param str Array a ser analizado
 * \return 1 si son solo letras y espacios y 0 si no lo es
 */

int esSoloLetras(char str[]);

/** \brief Verifica si el valor recibido es alfa numerico
 * \param str Array a ser analizado
 * \return 1 si contiene solo espacios,letras y numeros y 0 si no lo es
 */

int esAlfaNumerico(char str[]);

/** \brief Verifica si el valor recibido es un telefono
 * \param str Array a ser analizado
 * \return 1 si contiene numeros y 0 si no lo es
 */

int esTelefono(char str[]);

#endif // FUNCIONES_H_INCLUDED
