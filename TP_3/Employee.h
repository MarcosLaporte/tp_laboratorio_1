#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "Input.h"
#define MAX_CHAR 128
typedef struct{
    int id;
    char nombre[MAX_CHAR];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo);

Employee* employee_newFromUser(int id);

void employee_delete(Employee* this);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);

int employee_printEmpleado(Employee* this);

int employee_compareId(void* this, void* that);
int employee_compareNombre(void* this, void* that);
int employee_compareHoras(void* this, void* that);
int employee_compareSueldo(void* this, void* that);


#endif // employee_H_INCLUDED
