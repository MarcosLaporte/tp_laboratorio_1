/*
 * Operaciones.h
 *      Author: Marcos
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/// @brief Solicita un flotante.
///
/// @param char[] - El mensaje que muestra la funci�n.
/// @return float - El flotante ingresado.
float PedirFlotante(char[]);

/// @brief Suma dos flotantes.
///
/// @param float - El primer flotante ingresado.
/// @param float - El segundo flotante ingresado.
/// @return float - La suma de esos flotantes.
float SumarNumeros(float, float);

/// @brief Resta dos flotantes.
///
/// @param float - El primer flotante ingresado.
/// @param float - El segundo flotante ingresado.
/// @return float - La resta de esos flotantes.
float RestarNumeros(float, float);

/// @brief Calcula si es posible hacer la divisi�n de dos flotantes.
///
/// @param float - El primer flotante ingresado.
/// @param float - El segundo flotante ingresado.
/// @param float* - El puntero donde se encuentra el resultado de la divisi�n.
/// @return int - 1 si se puede realizar la divisi�n, o 0 si no (segundo flotante es igual a 0).
int DividirNumeros(float , float, float*);

/// @brief Multiplica dos flotantes.
///
/// @param float - El primer flotante ingresado.
/// @param float - El segundo flotante ingresado.
/// @return float - La multiplicaci�n de esos flotantes.
float MultiplicarNumeros(float, float);

/// @brief Calcula el factorial de cada flotante ingresado.
///
/// @param float - El flotante a calcular su factorial.
/// @return float - Devuelve 1 si el flotante es 0, 0 si es negativo o no entero, o el
		///resultado de la operaci�n de factorial si es posible (positivo y entero).
float CalcularFactorial(float);

#endif /* OPERACIONES_H_ */
