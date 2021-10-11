/*===========================================================================
 Name        : TP N�2
 Author      : Marcos Laporte
===========================================================================*/

/*===========================================================================
Consigna:
	Una empresa requiere un sistema para administrar su n�mina de empleados.
	Se sabe que dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
	El sistema deber� tener el siguiente men� de opciones:
		1.  ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero de Id.
			El resto de los campos se le pedir� al usuario.
		2.  MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
		3.  BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
		4.  INFORMAR:
			1.  Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
			2.  Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	int option;
	Employee arrayEmployees[MAX_EMPLOYEES];
	Employee auxEmployee;
	int contId;
	int id;
	float averageSalary;
	float salarySum;
	int overSalary;
	contId = 1;

	printf("\t\t#=======================================#\n"
		   "\t\t|\t     TP 2 - EMPLEADOS\t\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

	if(initEmployees(arrayEmployees, MAX_EMPLOYEES) == -1){
		printf("Hubo un problema en el sistema.\n");
	}

	do{
		option = getMenuOption();
		switch(option){
		case 1:
			auxEmployee = getEmployee(arrayEmployees, MAX_EMPLOYEES);
			if(addEmployee(arrayEmployees, MAX_EMPLOYEES, contId, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector) == -1){
				printf("ERROR! Ya se han ingresado la cantidad m�xima de empleados.\n");
			}else{
				printf("Se ha a�adido un empleado. ID N�%d.\n", contId);
				contId++;
			}
			break;
		case 2:
			if(checkAnEmployee(arrayEmployees, MAX_EMPLOYEES) == -1){
				printf("ERROR! No se han ingresado empleados.\n");
			}else{
				printList(arrayEmployees, MAX_EMPLOYEES);
				id = getInt("Ingrese el ID del empleado a modificar: ");
				if(modifyEmployee(arrayEmployees, MAX_EMPLOYEES, id) == -1){
					printf("ERROR! No existe un empleado con ese ID.\n");
				}else{
					printf("El empleado ha sido modificado!\n");
				}
			}
			break;
		case 3:
			if(checkAnEmployee(arrayEmployees, MAX_EMPLOYEES) == -1){
				printf("ERROR! No se han ingresado empleados.\n");
			}else{
				printList(arrayEmployees, MAX_EMPLOYEES);
				id = getInt("Ingrese el ID a del empleado a dar de baja: ");
				if(removeEmployee(arrayEmployees, MAX_EMPLOYEES, id) == -1){
					printf("ERROR! No existe un empleado con ese ID.\n");
				}else{
					printf("El empleado ha sido dado de baja!\n");
				}
			}
			break;
		case 4:
			if(checkAnEmployee(arrayEmployees, MAX_EMPLOYEES) == -1){
				printf("ERROR! No se han ingresado empleados.\n");
			}else{
				if(sortEmployee(arrayEmployees, MAX_EMPLOYEES, 1) == -1){
					printf("No hay empleados suficientes para ordenar.\n");
				}
				printList(arrayEmployees, MAX_EMPLOYEES);
				if(calcAverageSalary(arrayEmployees, MAX_EMPLOYEES, &averageSalary, &salarySum) == -1){
					printf("ERROR! No se han ingresado empleados.\n");
				}else{
					overSalary = calcEmployeesOverSalary(arrayEmployees, MAX_EMPLOYEES, averageSalary);
					printFinalSalaries(salarySum, averageSalary, overSalary);
				}
			}
			break;
		case 5:
			printf("Ha salido del sistema.");
			break;
		}

	}while(option != 5);

	return 0;
}
