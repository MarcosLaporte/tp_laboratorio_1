/*
 * Input.h
 *      Author: Marcos
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @brief Pide un entero con un mensaje pasado por par�metro.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el entero.
/// @return int - El entero pedido por scanf.
int getInt(char message[]);

/// @brief Pide un entero y lo valida entre un m�nimo y un m�ximo.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el entero.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
/// @return int - El entero pedido por scanf.
int getLimitedInt(char message[], char errorMessage[], int min, int max);

/// @brief Pide un flotante con un mensaje pasado por par�metro.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el flotante.
/// @return float - El flotante pedido por scanf.
float getFloat(char message[]);

/// @brief Pide un flotante y lo valida entre un m�nimo y un m�ximo.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el flotante.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
/// @return float - El flotante pedido por scanf.
float getLimitedFloat(char message[], char errorMessage[], int min, int max);

/// @brief Pide un array de enteros de manera secuencial.
///
/// @param list - El array donde se van a guardar los enteros.
/// @param length - El tama�o del array.
/// @param message - El mensaje a mostrar al momento de pedir los enteros.
/// @param errorMessage - El mensaje a mostrar si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
void getSequentialArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Pide un array de enteros de manera aleatoria.
///
/// @param list - El array donde se van a guardar los enteros.
/// @param length - El tama�o del array.
/// @param message - El mensaje a mostrar al momento de pedir los enteros.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
void getRandomArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Muestra en pantalla el array de enteros pasado por par�metro.
///
/// @param message - El mensaje a mostrar antes que el array.
/// @param number - El array a imprimir.
/// @param length - El tama�o de la lista.
void printArrayInt(char message[], int list[], int length);

/// @brief Pide un array de flotantes de manera secuencial.
///
/// @param list - El array donde se van a guardar los flotantes.
/// @param length - El tama�o del array.
/// @param message - El mensaje a mostrar al momento de pedir los flotantes.
/// @param errorMessage - El mensaje a mostrar si el flotante ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el flotante.
/// @param max - El m�ximo que puede ser el flotante.
void getSequentialArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Pide un array de flotantes de manera aleatoria.
///
/// @param list - El array donde se van a guardar los flotantes.
/// @param length - El tama�o del array.
/// @param message - El mensaje a mostrar al momento de pedir los flotantes.
/// @param errorMessage - El mensaje a mostrar en pantalla si el flotante ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el flotante.
/// @param max - El m�ximo que puede ser el flotante.
void getRandomArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Muestra en pantalla el array de flotantes pasado por par�metro.
///
/// @param message - El mensaje a mostrar antes que el array.
/// @param list - El array a imprimir.
/// @param length - El tama�o de la lista.
void printArrayFloat(char message[], float list[], int length);

/// @brief Pide una cadena de caracteres.
///
/// @param message - El mensaje a mostrar antes que el array.
/// @param input - El array donde se va a guardar la cadena.
/// @param length - El tama�o m�ximo de la cadena.
void getString(char message[], char input[], int length);

/// @brief Imprime las distintas opciones del men� de la lista.
///
/// @return int - Retorna el entero pedido con "getLimitedInt()"
int getMenuOption();

/// @brief Imprime las distintas opciones del men� de modificaciones.
///
/// @return int - Retorna el entero pedido con "getLimitedInt()"
int getModificationMenu();

/// @brief Pone la primer letra de cada palabra en may�scula y el resto en min�scula.
///
/// @param input - El array a modificar y donde se va a guardar la cadena.
void formatName(char input[]);

/// @brief Revisa que la cadena
///
/// @param input - La cadena de caracteres a revisar.
/// @return int - Retorna 0 si est� todo bien, o -1 si alguno de los caracteres
/// 			no cumple con las funciones isalpha y isspace.
int checkAlphabetAndSpace(char input[]);

/// @brief Pide una cadena de caracteres.
///
/// @param input - El array donde se va a guardar la cadena.
/// @param length - El tama�o m�ximo de la cadena.
/// @return int - Retorna -1 si la cadena supera el par�metro 'length', o 0 si est� todo bien.
int myGets(char input[], int length);

/// @brief Revisa que todos los caracteres de la cadena sea num�rica.
///
/// @param input - La cadena de caracteres a revisar.
/// @param length - El tama�o m�ximo de la cadena.
/// @return int - Retorna -1 si alg�n caracter de la cadena no es num�rico (con la
///				excepci�n de '-' o '+' como primer caracter), o 0 si est� todo bien.
int isAnInt(char input[], int length);

/// @brief Verifica el retorno de las funciones myGets() e isAnInt() para pasar el valor num�rico de la cadena.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a entero.
/// @return int - Retorna -1 si alguna de las dos funciones que llama dan error, o 0 si la cadena es v�lida.
int getAnInt(int* refResult);

/// @brief Utiliza myGets(), isAnInt() y getAnInt() para pedir un entero y validarlo como tal.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a entero.
/// @param message - El mensaje a mostrar al momento de pedir el entero.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
/// @return int - Retorna -1 si 'refResult', 'message' o 'errorMessage' son nulos o si 'min' es mayor que 'max',
///				o 0 si est� todo bien.
int getFinalInt(int* refResult, char message[], char errorMessage[], int min, int max);

/// @brief Revisa que todos los caracteres de la cadena sea num�rica.
///
/// @param input - La cadena de caracteres a revisar.
/// @param length - El tama�o m�ximo de la cadena.
/// @return int - Retorna -1 si alg�n caracter de la cadena no es num�rico (con la
///				excepci�n de '-' o '+' como primer caracter y un '.'), o 0 si est� todo bien.
int isAFloat(char input[], int length);

/// @brief Verifica el retorno de las funciones myGets() e isAFloat() para pasar el valor num�rico de la cadena.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a flotante.
/// @return int - Retorna -1 si alguna de las dos funciones que llama dan error, o 0 si la cadena es v�lida.
int getAFloat(float* refResult);

/// @brief Utiliza myGets(), isAnInt() y getAnInt() para pedir un entero y validarlo como tal.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a flotante.
/// @param message - El mensaje a mostrar al momento de pedir el flotante.
/// @param errorMessage - El mensaje a mostrar en pantalla si el flotante ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el flotante.
/// @param max - El m�ximo que puede ser el flotante.
/// @return int - Retorna -1 si 'refResult', 'message' o 'errorMessage' son nulos o si 'min' es mayor que 'max',
///				o 0 si est� todo bien.
int getFinalFloat(float* refResult, char message[], char errorMessage[], int min, int max);

#endif /* INPUT_H_ */
