/*
 * auxiliar.c
 *
 *  Created on: 13 mar. 2022
 *      Author: 1
 */

#include "auxiliar.h"

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
int pasarAminuscula(char* palabra)
{
	int todoOk=0;
	if(palabra!=NULL)
	{
		todoOk=1;
		int i=0;
		while(palabra[i]!='\0')
		{
			palabra[i]=tolower(palabra[i]);
			i++;
		}
	}
	return todoOk;
}
int formatearNombre(char* nombre)
{
	int todoOk=0;

	if(nombre!=NULL)
	{
		todoOk=1;
		int i=0;
		pasarAMinuscula(nombre);
		nombre[i]=toupper(nombre[i]);
		while(nombre[i]!='\0')
		{

			if(nombre[i]==' ')
			{
				nombre[i+1]=toupper(nombre[i+1]);

			}
			i++;
		}
		puts(nombre);
	}
	return todoOk;
}
int comprobrarPath(char* path, char tipo)
{
	int todoOk=0;/*no existe*/
	FILE* pFile=NULL;
	tipo=tolower(tipo);
	if(path!=NULL && (tipo=='t' || tipo=='b'))
	{
		if(tipo =='t')
		{
			pFile=fopen(path,"r");
			if(pFile!=NULL)
			{
				todoOk=1;/*existe archivo modo texto con ese nombre*/
				fclose(pFile);
			}
		}
		else
		{
			pFile=fopen(path,"rb");
			if(pFile!=NULL)
			{
				todoOk=1;/*existe archivo binario con ese nombre*/
				fclose(pFile);
			}
		}
	}
	return todoOk;
}
