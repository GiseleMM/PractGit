/*
 * Parser.h
 *
 *  Created on: 8 mar. 2022
 *      Author: 1
 */

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);



#endif /* PARSER_H_INCLUDED */
