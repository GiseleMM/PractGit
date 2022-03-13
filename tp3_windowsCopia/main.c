#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int confirmarSiNo(void);
int menu(void);
int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char path[30];
    int estaVacia=1;

    LinkedList* listaEmpleados = ll_newLinkedList();



    do{
        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	estaVacia=ll_isEmpty(listaEmpleados);
            	//printf("Esta vacia: %d",estaVacia);
            if(estaVacia==0)
            {
            	printf("lista ya cargada,desea sobreescribirla?");
            	fflush(stdin);
            }
            if((confirmarSiNo()==1) || estaVacia==1)
            {
            	ll_clear(listaEmpleados);
            	printf("Ingrese path:");
            	fflush(stdin);
            	gets(path);
            		if(controller_loadFromBinary(path,listaEmpleados))
            		{
            			printf("Lectura exitosa");
            		}
            		else
            		{
            			printf("error en lectura de archivo  binario\n");
            		}
            }
            	break;
            case 3:

            		if(controller_addEmployee(listaEmpleados))
            		{
            			printf(" empleado agregado a lista exitosamente");
            		}
            		else
            		{
            			printf("Error al  agregar empleado");
            		}

            	break;
            case 4:
            	if(ll_isEmpty(listaEmpleados)==0)
            	{
            		if(controller_editEmployee(listaEmpleados))
            		{
            			printf("Modificacion exitosa");
            		}
            		else
            		{
            			printf("Error en modificacion");
            		}
            	}
            	else
            	{
            		printf("no hay empleados para modificar ");
            	}
            	break;
            case 5:
               	if(ll_isEmpty(listaEmpleados)==0)
               	{
                    		if(controller_removeEmployee(listaEmpleados))
                    		{
                    			printf("Eliminacion exitosa");
                    		}
                    		else
                    		{
                    			printf("Error en Eliminacion");
                    		}
              	}
				else
				{
					printf("no hay empleados para Eliminar");
				}
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
               	if(ll_isEmpty(listaEmpleados)==0)
				{
					if(controller_sortEmployee(listaEmpleados))
					{
						printf("Ordenamiento exitoso");
					}
					else
					{
						printf("Error en Ordenamiento");
					}
				}
				else
				{
					printf("no hay empleados para ordenar ");
				}
            	break;
            case 8:
            	if(ll_isEmpty(listaEmpleados)==0)
            	{
            		printf("ingrese path");
            		fflush(stdin);
            		gets(path);
            		if(controller_saveAsText(path,listaEmpleados))
            		{
            			printf("Se guardo con exito en archivo:  %s",path);
            		}
            		else
            		{
            			printf("Error en guardar archivo");
            		}
            	}
            	else
            	{
            		printf("lista vacia");
            	}

            	break;
            case 9:
            	if(ll_isEmpty(listaEmpleados)==0)
                    	{
                    		printf("ingrese path");
                    		fflush(stdin);
                    		gets(path);
                    		if(controller_saveAsBinary(path,listaEmpleados))
                    		{
                    			printf("Se guardo con exito en archivo:  %s",path);
                    		}
                    		else
                    		{
                    			printf("Error en guardar archivo");
                    		}
                    	}
                    	else
                    	{
                    		printf("lista vacia");
                    	}
            	break;
            case 10:
            	//salir
            	printf("seguro desea salir? si/ no:");
            	if(confirmarSiNo())//llamo a la funcion
            	{
            		option=10;
            	}
            	break;


        }
        system("pause");
    }while(option != 10);

	ll_deleteLinkedList(listaEmpleados);
    return 0;
}
//-------------------------------------auxiliares-----------------------------
int menu(void)
{int opcion;
system("cls");


printf("\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
 printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
 printf("3. Alta de empleado\n");
 printf("4. Modificar datos de empleado\n");
 printf("5. Baja de empleado\n");
 printf("6. Listar empleados\n");
 printf("7. Ordenar empleados\n");
 printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
 printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
printf("10.Salir\n");
fflush(stdin);
	while(!scanf("%d",&opcion))
	{
		printf("dato no valido\n");
		fflush(stdin);
	}
	return opcion;
}
int confirmarSiNo(void)
{
	int todoOk=0;
	char confirma[3];
	fflush(stdin);
	gets(confirma);
	if(stricmp(confirma,"si")==0)
	{
		todoOk=1;
	}
	return todoOk;
}
