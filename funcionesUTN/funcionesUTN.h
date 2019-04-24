/**
 * \brief Funcion para ordenamiento de un array con metodo burbuja
 * \param recibe un dato char* y muestra el vector ordando alfab�ticamente.
 * \return no retorna.
 *  libreias usadas : #include <stdio.h> #include <string.h>
 *
 */
void metodoBurbujeo(char vector[]);

/**
 * \brief verifica si el valor es solo contiene solo letras(a,b,c,D,E...)
 * \param str array con la cadena a ser analizada
 * \return 1 si es solo letras y 0 si no lo es.
 *
 */
int esSoloLetras(char cadena[]);

/**
 * \brief verifica si el valor es numerico(1,2,3,4...)
 * \param str array con la cadena a ser analizada
 * \return 1 si es solo nuemros y 0 si no lo es.
 *
 */
int esNumerico(char cadena[]);

/**
 * \brief verifica si el valor es alfanumerico( aBCd123 )
 * \param str array con la cadena a ser analizada
 * \return 1 si es alfanumerico y 0 si no lo es.
 *
 */
int esAlfanumerico(char cadena[]);

/**
 * \brief verifica si el valor es Telefono ( 4244-4444 )
 * \param str array con la cadena a ser analizada
 * \return 1 si es Telelfono y 0 si no lo es.
 *
 */
int esTelefono(char cadena[]);
/** \brief toma un vector de enteros y devuelve el numero mayor
 *
 * \param Ingresar el vector de enteros y el tama�o del mismo
 * \param
 * \return retorna el numero mayor del array
 *
 */
 int numeroMayor(int vector[], int tam);

 /** \brief toma un vector de enteros y devuelve el numero menor
 *
 * \param Ingresar el vector de enteros y el tama�o del mismo
 * \param
 * \return retorna el numero menor del array
 *
 */
 int numeroMenor(int vector[], int tam);

  /** \brief toma un vector de enteros y devuelve el promedio de ellos
 *
 * \param Ingresar el vector de enteros y el tama�o del mismo
 * \param
 * \return retorna un flotante con el resultado del promdio del array
 *
 */
 float promedioArray(int vector[], int tam);


