
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

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pElement=NULL;
	pElement=employee_new();
	if(pElement!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		pElement->id=atoi(idStr);
		strcpy(pElement->nombre,nombreStr);
		pElement->horasTrabajadas=atoi(horasTrabajadasStr);
		pElement->sueldo=atoi(sueldoStr);
	}
	return pElement;
}
void employee_mostrar(Employee* pElement)
{
	if(pElement!=NULL)
	{
		printf("%6d|%-20s|%6d|%6d\n",pElement->id,pElement->nombre,pElement->horasTrabajadas,pElement->sueldo);

	}
}
void employee_delete(Employee* pElement)
{
	if(pElement!=NULL)
	{
		free(pElement);
	}

}

int employee_setId(Employee* this,int id)
{ int todoOk=0;
	if(this!=NULL && id>=0)
	{
		this->id=id;
		todoOk=1;
	}
	return todoOk;
}
int employee_getId(Employee* this,int* id)
{
	int todoOk=0;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		todoOk=1;
	}
	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk=0;
	if(this!=NULL && nombre!=NULL && strlen(nombre)>0)
	{
		strcpy(this->nombre,nombre);
		todoOk=1;
	}
	return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk=0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{ int todoOk=0;
		if(this!=NULL && horasTrabajadas>=0)
		{
			this->horasTrabajadas=horasTrabajadas;
			todoOk=1;
		}
		return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk=0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		todoOk=1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{ int todoOk=0;
		if(this!=NULL && sueldo>=0)
		{
			this->sueldo=sueldo;
			todoOk=1;
		}
		return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk=0;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		todoOk=1;
	}
	return todoOk;
}

int employee_setCampos(Employee* this,int id,char* nombre,int horas,int sueldo)
{
	int todoOk=0;
	if(this!=NULL && nombre!=NULL)
	{
		if(employee_setId(this,id) && employee_setNombre(this,nombre) && employee_setHorasTrabajadas(this,horas) && employee_setSueldo(this,sueldo))
		{
			todoOk=1;
		}
	}
	return todoOk;
}
int employee_getCampos(Employee* this,int* id,char* nombre, int* horas, int* sueldo)
{
	int todoOk=0;
	if(this!=NULL && id!=NULL && nombre!=NULL && horas!=NULL && sueldo!=NULL)
	{
		if(employee_getId(this,id) && employee_getNombre(this,nombre) && employee_getHorasTrabajadas(this,horas) && employee_getSueldo(this,sueldo))
		{
			todoOk=1;
		}
	}
	return todoOk;
}
