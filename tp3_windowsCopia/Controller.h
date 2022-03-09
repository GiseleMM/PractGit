#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>
#include "Parser.h"

int mayorId(LinkedList* pArrayListEmployee);

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_buscarEmployee(LinkedList* pArrayListEmployee,int id);

int compararId(void* p1,void* p2);
int compararNombre(void* p1,void* p2);

#endif // controller_H_INCLUDED
