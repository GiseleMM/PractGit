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



int main()
{
	setbuf(stdout,NULL);
    //int option = 0;
	int id;
	char nombre[20];
	int sueldo;
	int horas;
	Employee* p=employee_new();
	printf("%d- %s- %d- %d",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
	//compruebo setters
	employee_setId(p,33);
	employee_setNombre(p,"Luis");
	employee_setHorasTrabajadas(p,100);
	employee_setSueldo(p,30000);
	employee_mostrar(p);
	//compruebo getCampos
	if(employee_getCampos(p,&id,nombre,&horas,&sueldo)==1)
	{
		printf("campos con get_campo:%d%s%d%d\n",id,nombre,horas,sueldo);
	}
	//compruebo setCampos
	if(employee_setCampos(p,1,"Anya",20,15000)==1)
	{
		employee_mostrar(p);
	}

	//compruebo constructor
	Employee* p2=employee_newParametros("100","Joni","60","12000");
	//compruebo getters

	if(employee_getId(p2,&id)==1)
	{
		printf("id:%d\n",id);
	}
	if(employee_getNombre(p2,nombre)==1)
		{
			printf("nombre:%s\n",nombre);
		}
	if(employee_getHorasTrabajadas(p2,&horas)==1)
		{
			printf("horas:%d\n",horas);
		}
	if(employee_getSueldo(p2,&sueldo)==1)
		{
			printf("sueldo:%d\n",sueldo);
		}
	//compruebo mostrar
	employee_mostrar(p2);
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {
    	printf("lista creada  con exito");
    	ll_add(listaEmpleados,p);
    	ll_add(listaEmpleados,p2);
    	controller_ListEmployee(listaEmpleados);
    }
	//compruebo delete
	employee_delete(p2);
	employee_delete(p);

    /*
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/

	ll_deleteLinkedList(listaEmpleados);
    return 0;
}

