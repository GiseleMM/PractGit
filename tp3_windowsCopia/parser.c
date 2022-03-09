
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
//int contador=0;
//int cant;
if(pFile!=NULL && pArrayListEmployee!=NULL)
{
	todoOk=1;
	/*lectura fanstasma del encabezado*/
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	printf("%s-%s-%s-%s-",buffer[0],buffer[1],buffer[2],buffer[3]);
}
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

    return 1;
}
