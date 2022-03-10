
#include "Parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
int todoOk=0;
char buffer[4][30];
int contador=0;
int cant;
Employee* auxEmployee=NULL;
if(pFile!=NULL && pArrayListEmployee!=NULL)
{
	todoOk=1;
	/*lectura fanstasma del encabezado*/
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	//printf("%s-%s-%s-%s",buffer[0],buffer[1],buffer[2],buffer[3]);
	do{
		cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		printf("leyendo:%s-%s-%s-%s\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		if(cant<4)
		{
			break;
		}
		auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
		if(auxEmployee!=NULL)
		{
			employee_mostrar(auxEmployee);
			if(ll_add(pArrayListEmployee,auxEmployee)==0)
			{
				contador++;
			}
		}
	}while(!feof(pFile));
}
printf(" Se agrego a lista %d elementos",contador);
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
int todoOk=0;
int contador=0;
int cant;
Employee* auxEmployee=NULL;
if(pFile!=NULL && pArrayListEmployee!=NULL)
{
	todoOk=1;
	do
	{
		auxEmployee=employee_new();
		if(auxEmployee!=NULL)
		{

			cant=fread(auxEmployee,sizeof(Employee),1,pFile);
			if(cant<1)
			{
				break;
			}
			employee_mostrar(auxEmployee);
			if(ll_add(pArrayListEmployee,auxEmployee)==0)
			{
				contador++;
			}
		}


	}while(!feof(pFile));
}
printf("se agregaron a lista %d elementos de archivo binario\n",contador);
    return todoOk;
}
