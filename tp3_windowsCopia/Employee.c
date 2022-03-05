
#include "Employee.h"



Employee* employee_new()
{
	Employee* pElement=NULL;
	pElement=(Employee*)malloc(sizeof(Employee));
	if(pElement!=NULL)
	{
		pElement->id=0;
		strcpy(pElement->nombre," ");
		pElement->horasTrabajadas=0;
		pElement->sueldo=0;
	}
	return pElement;
}
/*
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

*/
