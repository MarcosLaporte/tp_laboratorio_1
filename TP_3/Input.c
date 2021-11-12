/*
 * Input.c
 *      Author: Marcos Laporte
 */

#include "Input.h"

/// @brief Pide una cadena de caracteres.
///
/// @param input - El array donde se va a guardar la cadena.
/// @param length - El tama�o m�ximo de la cadena.
/// @return int - Retorna 0 si la cadena supera el par�metro 'length', o 1 si est� todo bien.
int myGets(char input[], int length){
	int Return;
	char aux[3000];
	Return = 0;
	if(input != NULL && length > 0) {
		fflush(stdin);
		gets(aux);
		if(strnlen(aux, sizeof(aux)) <= length){
			strncpy(input, aux, length);
			Return = 1;
		}
	}

	return Return;
}

/// @brief Revisa que todos los caracteres de la cadena sea num�rica.
///
/// @param input - La cadena de caracteres a revisar.
/// @param length - El tama�o m�ximo de la cadena.
/// @return int - Retorna 0 si alg�n caracter de la cadena no es num�rico (con la
///				excepci�n de '-' o '+' como primer caracter), o 1 si est� todo bien.
int isAnInt(char input[], int length){
	int Return;
	int i;
	Return = 1;
	for(i = 0; i < length  && input[i] != '\0' ; i++){
		if(i == 0 && (input[i] == '-' || input[i] == '+')){
			continue;
		}
		if(input[i] > '9' || input[i] < '0'){
			Return = 0;
			break;
		}
	}

	return Return;
}

/// @brief Verifica el retorno de las funciones myGets() e isAnInt() para pasar el valor num�rico de la cadena.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a entero.
/// @return int - Retorna 0 si alguna de las dos funciones que llama dan error, o 1 si la cadena es v�lida.
int getAnInt(int* refResult){
	int Return;
	char aux[3000];
	Return = 0;

	if(refResult != NULL && myGets(aux, sizeof(aux)) && isAnInt(aux, sizeof(aux))){
		*refResult = atoi(aux);
		Return = 1;
	}

	return Return;
}

/// @brief Utiliza myGets(), isAnInt() y getAnInt() para pedir un entero y validarlo como tal.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a entero.
/// @param message - El mensaje a mostrar al momento de pedir el entero.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
/// @return int - Retorna 0 si 'refResult', 'message' o 'errorMessage' son nulos o si 'min' es mayor que 'max',
///				o 1 si est� todo bien.
int getInt(int* refResult, char message[], char errorMessage[], int min, int max){
	int Return;
	int number;
	int auxNumber;
	Return = 0;
	if (refResult != NULL && message != NULL && errorMessage != NULL && min <= max){
		printf("%s", message);
		auxNumber = getAnInt(&number);
		while(!auxNumber || number < min || number > max){
			printf("%s", errorMessage);
			auxNumber = getAnInt(&number);
		}
		*refResult = number;
		Return = 1;
	}

	return Return;
}

/// @brief Revisa que todos los caracteres de la cadena sea num�rica.
///
/// @param input - La cadena de caracteres a revisar.
/// @param length - El tama�o m�ximo de la cadena.
/// @return int - Retorna 0 si alg�n caracter de la cadena no es num�rico (con la
///				excepci�n de '-' o '+' como primer caracter y un '.'), o 1 si est� todo bien.
int isAFloat(char input[], int length){
	int Return;
	int i;
	int pointCont;
	Return = 1;
	pointCont = 0;
	for(i = 0; i < length  && input[i] != '\0' ; i++){
		if(input[i] == '.'){
			pointCont++;
		}
		if((i == 0 && (input[i] == '-' || input[i] == '+')) || input[i] == '.'){
			continue;
		}
		if(input[i] > '9' || input[i] < '0' || pointCont > 1){
			Return = 0;
			break;
		}
	}

	return Return;
}

/// @brief Verifica el retorno de las funciones myGets() e isAFloat() para pasar el valor num�rico de la cadena.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a flotante.
/// @return int - Retorna 0 si alguna de las dos funciones que llama dan error, o 1 si la cadena es v�lida.
int getAFloat(float* refResult){
	int Return;
	char aux[3000];
	Return = 0;

	if(refResult != NULL && myGets(aux, sizeof(aux)) && isAFloat(aux, sizeof(aux))){
		*refResult = atof(aux);
		Return = 1;
	}

	return Return;
}

/// @brief Utiliza myGets(), isAnInt() y getAnInt() para pedir un entero y validarlo como tal.
///
/// @param *refResult - Puntero donde se va a guardar el n�mero convertido a flotante.
/// @param message - El mensaje a mostrar al momento de pedir el flotante.
/// @param errorMessage - El mensaje a mostrar en pantalla si el flotante ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el flotante.
/// @param max - El m�ximo que puede ser el flotante.
/// @return int - Retorna 0 si 'refResult', 'message' o 'errorMessage' son nulos o si 'min' es mayor que 'max',
///				o 1 si est� todo bien.
int getFloat(float* refResult, char message[], char errorMessage[], int min, int max){
	int Return;
	float number;
	float auxNumber;
	Return = 0;
	if (refResult != NULL && message != NULL && errorMessage != NULL && min <= max){
		printf("%s", message);
		auxNumber=getAFloat(&number);
		while(!auxNumber || number < min || number > max){
			printf("%s", errorMessage);
			auxNumber = getAFloat(&number);
		}
		*refResult = number;
		Return = 1;
	}

	return Return;
}

/// @brief Pide un array de enteros de manera aleatoria.
///
/// @param list - El array donde se van a guardar los enteros.
/// @param length - El tama�o del array.
/// @param message - El mensaje a mostrar al momento de pedir los enteros.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el entero.
/// @param max - El m�ximo que puede ser el entero.
void getRandomArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max){
	int i;
	char keepGoing;

	do{
		getInt(&i, "En qu� posici�n desea ingresar el n�mero?: ", "ERROR! Ingrese una posici�n v�lida: ", 1, length);
		getInt(&list[i-1], message, errorMessage, min, max);
		printf("Desea continuar? s/n: ");
		keepGoing = tolower(getchar());
		while(!(keepGoing == 's' || keepGoing == 'n')){
			printf("Si desea continuar escriba 's', si no, 'n': ");
			keepGoing = tolower(getchar());
		}
	}while(keepGoing == 's');
}

/// @brief Pide un array de flotantes de manera aleatoria.
///
/// @param list - El array donde se van a guardar los flotantes.
/// @param length - El tama�o del array.
/// @param message - El mensaje a mostrar al momento de pedir los flotantes.
/// @param errorMessage - El mensaje a mostrar en pantalla si el flotante ingresado no entra en los par�metros dados.
/// @param min - El m�nimo que puede ser el flotante.
/// @param max - El m�ximo que puede ser el flotante.
void getRandomArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max){
	int i;
	char keepGoing;

	do{
		getInt(&i, "En qu� posici�n desea ingresar el n�mero?: ", "ERROR! Ingrese una posici�n v�lida: ", 1, length);
		getFloat(&list[i-1], message, errorMessage, min, max);
		printf("Desea continuar? s/n: ");
		keepGoing = tolower(getchar());
		while(!(keepGoing == 's' || keepGoing == 'n')){
			printf("Si desea continuar escriba 's', si no, 'n': ");
			keepGoing = tolower(getchar());
		}
	}while(keepGoing == 's');
}

/// @brief Pone la primer letra de cada palabra en may�scula y el resto en min�scula.
///
/// @param input - El array a modificar y donde se va a guardar la cadena.
void camelStr(char input[]){
	if(input != NULL){
		strlwr(input);
		for(int i = 0; i < strlen(input); i++){
			if(i == 0 || isspace(input[i-1]) || input[i-1] == '-'){
				input[i] = toupper(input[i]);
			}
		}
	}
}

/// @brief Revisa que la cadena contenga solo letras y espacios. (C�digo ASCII)
///
/// @param input - La cadena de caracteres a revisar.
/// @return int - Retorna 1 si est� todo bien, o 0 si alguno de los
/// 			caracteres no cumple con la funci�n isalpha() o isspace().
int isAlphaSpace(char input[]){
	int length = strlen(input);
	int Return = 1;
	for(int i = 0; i < length; i++){
		if(length == 0 || (!isalpha(input[i]) && !isspace(input[i]) && input[i] != '-')){
			Return = 0;
			break;
		}
	}
	return Return;
}

/// @brief Pide una confirmaci�n textual para aceptar una acci�n.
///
/// @param message - El mensaje a mostrar por pantalla.
/// @param confirmation - La cadena de caracteres para la confirmaci�n.
/// @param cancel - La cadena de caracteres para cancelar.
/// @param length - El tama�o m�ximo de texto.
/// @param tries - La cantidad m�xima de intentos que tiene el usuario para confirmar
/// 	o cancelar antes de que se cancele autom�ticamente.
/// @return int - Retorna -1 si cancela, 0 si se acaban los intentos, o 1 si confirma.
int getConfirmation(char message[], char* confirmation, char* cancel, int length, int tries){
	int Return;
	char input[length];
	Return = 0;

	printf("%s", message);
	myGets(input, length);

	do{
		if(strcmpi(input, confirmation) != 0 && strcmpi(input, cancel) != 0){
			printf("ERROR! Aseg�rese de escribir '%s' si desea confirmar o '%s' para cancelar la acci�n.\nLe quedan %d intentos: ", confirmation, cancel, tries);
			myGets(input, length);
			tries--;
		}else{
			if(strcmpi(input, confirmation) == 0){
				Return = 1;
			}else{
				if(strcmpi(input, cancel) == 0){
					Return = -1;
				}
			}
		}
	}while(tries > 0 && Return != 1 && Return != -1);

	if(tries == 0){
		printf("Muchos intentos fallidos. ");
	}

	return Return;
}

/// @brief Pide una cadena de caracteres validando que sean letras, espacios o guiones, para luego darles formato.
///
/// @param input
/// @param message
/// @param errorMessage
/// @param len
/// @return
int myGetName(char* input, char* message, char* errorMessage, int len){
	int Return;
	char aux[len];
	Return = 0;

	if(input != NULL && message != NULL && errorMessage != NULL && len > 0){
		printf("%s", message);
		myGets(aux, len);
		while(!isAlphaSpace(aux)){
			printf("%s", errorMessage);
			myGets(aux, len);
		}
		camelStr(aux);
		strcpy(input, aux);
		Return = 1;
	}

	return Return;
}

//-------------------------------------------------------------
/// @brief Imprime el men� principal y pide una opci�n.
///
/// @return int - Retorna la opci�n elegida.
int printMenu(){
	int option;

	printf("\n1. Cargar empleados modo texto.\n");
	printf("2. Cargar empleados modo binario.\n");
	printf("3. Alta de empleado.\n");
	printf("4. Modificar empleado.\n");
	printf("5. Baja de empleado.\n");
	printf("6. Listar empleados.\n");
	printf("7. Ordenar empleados.\n");
	printf("8. Guardar datos de empleados modo texto.\n");
	printf("9. Guardar datos de empleados modo binario.\n");
	printf("10. Salir.\n");

	getInt(&option, "Elija una opci�n: ", "ERROR! Elija una opci�n existente: ", 0, 10);

	return option;
}

