/*
 * Biblioteca.h
 *      Author: Marcos
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @brief Pide un entero y lo valida.
///
/// @param char[] - El primer mensaje a mostrar.
/// @param char[] - El mensaje a mostrar en la validaci�n.
/// @param int - El par�metro de m�nimo de la validaci�n.
/// @param int - El par�metro de m�ximo de la validaci�n.
/// @return int - El entero recibido.
int PedirEntero(char[], char[], int, int);

/// @brief Pide la opci�n a seleccionar del men� y la muestra en la consola.
///
/// @param float - Primer floatante ingresado, para mostrarlo en el men�.
/// @param float - Segundo floatante ingresado, para mostrarlo en el men�.
/// @param int - Una bandera para determinar si se ingres� o no el primer n�mero a mostrar.
/// @param int - Una bandera para determinar si se ingres� o no el segundo n�mero a mostrar.
/// @return int - El n�mero de la opci�n elegida.
int PedirOpcion(float, float, int, int);

// Resultados------------------------------------------------

/// @brief Muestra en consola el mensaje de resultado de suma.
///
/// @param float - El primer n�mero de la operaci�n a mostrar.
/// @param float - El segundo n�mero de la operaci�n a mostrar.
/// @param float - El resultado de la operaci�n a mostrar.
void ResultadoSuma(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de resta.
///
/// @param float - El primer n�mero de la operaci�n a mostrar.
/// @param float - El segundo n�mero de la operaci�n a mostrar.
/// @param float - El resultado de la operaci�n a mostrar.
void ResultadoResta(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de divisi�n.
///
/// @param float - El primer n�mero de la operaci�n a mostrar.
/// @param float - El segundo n�mero de la operaci�n a mostrar.
/// @param float - El resultado de la operaci�n a mostrar.
void ResultadoDivision(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de divisi�n si es posible, sino, muestra mensaje de error.
///
/// @param float - El primer n�mero de la operaci�n a mostrar.
/// @param float - El segundo n�mero de la operaci�n a mostrar.
/// @param float - El resultado o error de la operaci�n a mostrar.
void ResultadoMultiplicacion(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de factorial si es posible, sino, muestra mensaje de error.
///
/// @param float - El n�mero de la operaci�n a mostrar.
/// @param float - El resultado de la operaci�n a mostrar.
void ResultadoFactorial(float, float);

#endif /* BIBLIOTECA_H_ */
