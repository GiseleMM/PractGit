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
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	pFile=fopen(path,"r");
    	if(pFile!=NULL)
    	{
    		if(parser_EmployeeFromText(pFile,pArrayListEmployee)==1)
    		{
    			todoOk=1;
    		}
    		else
    		{
    			printf("Error en Lectura de archivo: %s\n",path);
    		}
    		fclose(pFile);
    	}

    }
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
    int todoOk=0;
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListEmployee)
    {
    	pFile=fopen(path,"rb");
    	if(pFile!=NULL)
    	{
    		if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1)
    		{
    			todoOk=1;
    		}
    		else
    		{
    			printf("Error de lectura de archivo: %s\n",path);
    		}

    		fclose(pFile);
    	}
    }
	return todoOk;
}
int mayorId(LinkedList* pArrayListEmployee)
{
	int id;
	int auxInt;
	Employee* auxEmpleado;
	int mayor;
	int flagMayor=0;
	int tam;
	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		for(int i=0;i<tam;i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
			if(auxEmpleado!=NULL)
			{
				auxInt=auxEmpleado->id;
				if(flagMayor==0 || auxInt> mayor)
				{
					mayor=auxInt;
					flagMayor=1;
				}
			}
		}
		if(flagMayor==0)
		{
			id=-1;//error no se ingreso a ningun empleado
		}
		else
		{
			id=mayor;
		}
	}
	return id;
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
	int todoOk=0;
	int id;
	int sueldo;
	int horas;
	char nombre[30];
	Employee* auxEmployee=NULL;
	char confirma[3];
	if(pArrayListEmployee!=NULL)
	{
		system("cls");
		auxEmployee=employee_new();//creo empleado vacio

		id=mayorId(pArrayListEmployee);
		if(id!=-1)
		{
			id++;/*no uso el mayor si no uno mas*/
			employee_setId(auxEmployee,id);
		}
		printf("ingrese nombre");
		fflush(stdin);
		gets(nombre);
		formatearNombre(nombre);
		puts(nombre);

		while(!employee_setNombre(auxEmployee,nombre))
		{
			printf("Error ");
			printf("Reingrese nombre:");
					fflush(stdin);
					gets(nombre);
		}
		printf("ingrese horas:");
		fflush(stdin);
		scanf("%d",&horas);
		while(!employee_setHorasTrabajadas(auxEmployee,horas))
		{
			printf("Error ");
			printf("REingrese horas:");
				fflush(stdin);
				scanf("%d",&horas);
		}
		printf("ingrese sueldo:");
		fflush(stdin);
		scanf("%d",&sueldo);
		while(!employee_setSueldo(auxEmployee,sueldo))
		{
			printf("Error ");
			printf("REingrese sueldo:");
				fflush(stdin);
				scanf("%d",&sueldo);
		}
		employee_mostrar(auxEmployee);
		printf("confirma empleado?si/no:\n");
		fflush(stdin);
		gets(confirma);
		if(stricmp(confirma,"si")==0)
		{
			if(ll_add(pArrayListEmployee,auxEmployee)==0)
			{
				todoOk=1;
			}

		}
		else
		{
			employee_delete(auxEmployee);
			auxEmployee=NULL;
			printf("Empleado no creado\n");
		}
	}
return todoOk;
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
	int todoOk=0;
	int id;
	int indice;

	Employee* auxEmployee=NULL;
	char confirma[3];

	int seModifico=0;
	if(pArrayListEmployee!=NULL)
	{
		//printf("ingrse a lista distinta denull>>>>>\n");
		if(controller_ListEmployee(pArrayListEmployee))//me falto modificar el retorno siempre devolvia 0 por eso no modif
		{

			//printf("ingrse a lista mostrar>>>>>\n");
			printf("ingrese id:");
			fflush(stdin);
			if(!scanf("%d",&id))
			{
				printf("dato no valido");
			}
			else
			{
				indice=controller_buscarEmployee(pArrayListEmployee,id);
				if(indice==-1)
				{
					printf("empleado no encontrado\n");
				}
				else
				{
					auxEmployee=(Employee*)ll_get(pArrayListEmployee,indice);
					if(auxEmployee!=NULL)
					{
						employee_mostrar(auxEmployee);
						printf("es el empleado  a modificar?si/no ");
						fflush(stdin);
						gets(confirma);
						if(stricmp(confirma,"si")==0)
						{

							switch(menuEdit())
							{

							case 1:
								if(modificarNombre(auxEmployee)==1)
								{
									seModifico=1;
								}

								break;
							case 2:
								if(modificarHoras(auxEmployee)==1)
								{
									seModifico=1;
								}
								break;
							case 3:

								if(modificarSueldo(auxEmployee)==1)
								{
									seModifico=1;
								}
								break;
							default:
								printf("opcion invalida");
								break;

						}

					}
					else
					{
						printf("modificacion cancelada\n");
					}
				}
			}

		}

	}

	}

	if(seModifico)
	{
		printf("Empleado modificado:\n");
		employee_mostrar(auxEmployee);
		todoOk=1;
	}
    return todoOk;
}
//edit----------------------------
int menuEdit(void)
{
	int opcion;
	system("cls");
	printf(" \nMenu modificacion\n");
	printf("Seleccione opcion:\n");
							printf("1-nombre\n");
							printf("2-horas\n");
							printf("3-sueldo\n");
							fflush(stdin);
							while(!scanf("%d",&opcion))
							{
								printf("opcion  invalida");
								fflush(stdin);
							}
	return opcion;
}
int modificarNombre(Employee* pElement)
{
	int seModifico=0;
	char nombre[30];
	if(pElement!=NULL)
	{
		printf("Ingrese nombre:");
		fflush(stdin);
		gets(nombre);
		printf("Confirma nuevo nombre %s?si/no\n",nombre);
		if(confirmarSiNo()==1)
		{
			if(employee_setNombre(pElement,nombre))
			{
				seModifico=1;
			}
		}
	}
	return seModifico;
}
int modificarHoras(Employee* pElement)
{
	int seModifico=0;
	int horas;
	if(pElement!=NULL)
	{
		printf("Ingrese horas:");
		fflush(stdin);
		if(!scanf("%d",&horas))
		{
			printf("dato no valido");
		}
		else
		{

			printf("Confirma nueva horas %d?si/no\n",horas);
			if(confirmarSiNo()==1)
			{
				if(employee_setHorasTrabajadas(pElement,horas))
				{
					seModifico=1;
				}
			}
		}
	}
	return seModifico;
}
int modificarSueldo(Employee* pElement)
{
	int seModifico=0;
	int sueldo;
	if(pElement!=NULL)
	{
		printf("Ingrese sueldo:");
		fflush(stdin);
		if(!scanf("%d",&sueldo))
		{
			printf("dato no valido");
		}
		else
		{

			printf("Confirma nuevo sueldo %d?si/no\n",sueldo);
			if(confirmarSiNo()==1)
			{
				if(employee_setSueldo(pElement,sueldo))
				{
					seModifico=1;
				}
			}
		}
	}
	return seModifico;
}
//-----------------------------
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
						todoOk=1;
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
		printf("\nid |nombre		      |horas		|sueldo\n");
		printf("------------------------------------------------\n");
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
		printf("\tlista vacia");
	}
	else
	{
		todoOk=1;
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

    int seOrdeno=0;
    if(pArrayListEmployee!=NULL)
    {

    		switch(menuSort())
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
int menuSort(void)
{
	system("cls");
	int opcion;
  	printf("indique criterio de ordenamiento\n");
    	printf("1-Id ascendete\n");
    	printf("2-Id descendete\n");
    	printf("3-Nombre ascendente\n");
    	printf("4-Nombre descendete\n");
    	fflush(stdin);
    	while(!scanf("%d",&opcion))
    	{
    		printf("Opcion no valida");
    		fflush(stdin);
    	}
    	return opcion;
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
    int todoOk=0;
    FILE* pFile=NULL;
    FILE* aux=NULL;
    char confirma[3];
    int tam;
    int contador=0;
    int id;
    char nombre[30];
    int horas;
    int sueldo;
    Employee* auxEmployee=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {

    	aux=fopen(path,"r");
    	if(aux!=NULL)
    	{
    		printf("Archivo: %s ya exite, desea sobreescribirlo?si/no\n",path);
    		fflush(stdin);
    		gets(confirma);
    		fclose(aux);//cierro archivo modo lectura
    	}
    	if(aux==NULL || (stricmp(confirma,"si")==0))
    	{
    		pFile=fopen(path,"w");
    		if(pFile!=NULL)
    		{
    			todoOk=1;
    			/*encabezado formato csv*/
    			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    			tam=ll_len(pArrayListEmployee);
    			for(int i=0;i<tam;i++)
    			{
    				auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
    				if(auxEmployee!=NULL)
    				{
    					if(employee_getCampos(auxEmployee,&id,nombre,&horas,&sueldo)==1)
    					{

    						fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);

    						contador++;
    					}
    				}
    			}
    			fclose(pFile);
    		}
    	}
    }
    printf("escritura en archivo %s de %d elementos\n",path,contador);
	return todoOk;
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
  int todoOk=0;
  FILE* aux=NULL;
  FILE* pFile=NULL;
  char confirma[3];
  int contador=0;
  int tam;
  Employee* auxEmployee=NULL;
  if(path!=NULL && pArrayListEmployee!=NULL)
  {
	  aux=fopen(path,"rb");/*abro modo lectura binaria para verificar si el archivo existe*/
	  if(aux!=NULL)
	  {
		  printf("Archivo : %s ya existe ,desea sobreescribirlo? si/no:\n",path);
			  fflush(stdin);
			  gets(confirma);
			  fclose(aux);
	  }
	  if((stricmp(confirma,"si")==0) || aux==NULL)/*si exite y lo queiro sobreescribir o si no exite*/
	  {
				  pFile=fopen(path,"wb");//abro para escritura
				  if(pFile!=NULL)
				  {
					  todoOk=1;
					  tam=ll_len(pArrayListEmployee);
					  printf("Recorro lista\n");
					  for(int i=0;i<tam;i++)//recorro lista;
					  {
						  auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
						  if(auxEmployee!=NULL)
						  {
							  employee_mostrar(auxEmployee);
							  fwrite(auxEmployee,sizeof(Employee),1,pFile);
							  	  	  //si pongo cant=fwrite y verifico que cant<1 no lee todos los elementos de la lisa
							  contador++;
						  }

					  }
					  fclose(pFile);
				  }
	  }


  }
  printf("escritura en archivo %s de %d elementos\n",path,contador);
	return todoOk;
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
