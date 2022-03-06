#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=1;
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int id;
	int indice;
	Employee* auxEmployee=NULL;
	char confirma[3];
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("Ingrese id:");
		if(!scanf("%d",&id))
		{
			printf("dato no valido\n");
		}
		else
		{
			indice=controller_buscarEmployee(pArrayListEmployee,id);
			if(indice!=-1)
			{
				auxEmployee=(Employee*)ll_get(pArrayListEmployee,indice);
				employee_mostrar(auxEmployee);
				printf("Confirma baja de empleado?si/no:");
				fflush(stdin);
				gets(confirma);
				if(stricmp(confirma,"si")==0)
				{
					if(ll_remove(pArrayListEmployee,indice)==0)
					{
						todoOk=0;
					}
				}
				else
				{
					printf("baja cancelada por el usuario\n");
				}

			}
		}

	}
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	int tam;
	int contador=0;
	Employee* auxEmployee=NULL;
	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		for(int i=0;i<tam;i++)
		{
			auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			if(auxEmployee!=NULL)
			{
				employee_mostrar(auxEmployee);
				contador++;
			}
		}
	}
	if(contador==0)
	{
		printf("lista vacia");
	}
	else
	{
	printf(" se mostraron %d elementos \n",contador);
	}

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int opcion;
    int seOrdeno=0;
    if(pArrayListEmployee!=NULL)
    {
    	printf("indique criterio de ordenamiento\n");
    	printf("1-Id ascendete\n");
    	printf("2-Id descendete\n");
    	printf("3-Nombre ascendente\n");
    	printf("4-Nombre descendete\n");
    	fflush(stdin);
    	if(!scanf("%d",&opcion))
    	{
    		printf("Opcion no valida");
    	}
    	else
    	{
    		switch(opcion)
    		{
    		case 1:
    			if(ll_sort(pArrayListEmployee,compararId,1)==0)
    			{
    				seOrdeno=1;
    			}
    			break;
    		case 2:
    			if(ll_sort(pArrayListEmployee,compararId,0)==0)
    			{
    				seOrdeno=1;
    			}
    			break;
    		case 3:
    			if(ll_sort(pArrayListEmployee,compararNombre,1)==0)
    			{
    				seOrdeno=1;
    			}
    			break;
    		case 4:
    			if(ll_sort(pArrayListEmployee,compararNombre,0)==0)
    			{
    				seOrdeno=1;
    			}
    			break;
    		default:
    			printf("Opcion invalida\n");
    			break;
    		}
    	}
    }
    if(seOrdeno)
    {
    	controller_ListEmployee(pArrayListEmployee);
    	todoOk=1;

    }
	return todoOk;
}
//sort---------------------------------
int compararId(void* p1,void* p2)
{
	int todoOk=0;
	Employee* aux1=NULL;
	Employee* aux2=NULL;
	if(p1!=NULL && p2!=NULL)
	{
		aux1=(Employee*)p1;
		aux2=(Employee*)p2;
		if(aux1->id > aux2->id)
		{
			todoOk=1;
		}
		if(aux1->id < aux2->id)
				{
					todoOk=-1;
				}
	}
	return todoOk;
}
int compararNombre(void* p1,void* p2)
{
	int todoOk=0;
	Employee* aux1=NULL;
	Employee* aux2=NULL;
	if(p1!=NULL && p2!=NULL)
	{
		aux1=(Employee*)p1;
		aux2=(Employee*)p2;
		if(stricmp(aux1->nombre, aux2->nombre)>0)
		{
			todoOk=1;
		}
		if(stricmp(aux1->nombre, aux2->nombre)<0)
		{
					todoOk=-1;
				}
	}
	return todoOk;
}
//-----------------------------------
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
/** \brief busca en lista id de empleado si lo encuentra retorna indice si no -1
 *
 * \param path int id  campo buscado en elemento
 * \param pArrayListEmployee LinkedList* lista donde busca
 * \return int indice o -1 si  falla
 *
 */
int controller_buscarEmployee(LinkedList* pArrayListEmployee,int id)
{
	int todoOk=-1;//retorno un  indice invalido si no se encontro id
	int tam;
	Employee* auxEmployee=NULL;
	if(pArrayListEmployee!=NULL && id>=0)
	{
		tam=ll_len(pArrayListEmployee);
		for(int i=0;i<tam;i++)
		{
			auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			if(auxEmployee!=NULL)
			{
				if(auxEmployee->id==id)
				{
					todoOk=i;//retorno indice
					break;

				}
			}
		}

	}
	return todoOk;
}
