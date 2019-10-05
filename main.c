#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<conio.h>
#include "ArrayEmployees.h"
#define TAM 3 /* CANTIDAD DE EMPLEADOS */

/*FUNCION PRINCIPAL*/

int main()
{

employees employes[TAM];

initemployes(employes,TAM);
int lastId=1;
int id;
int check;
int order;
int salir=0;
char auxLen[LENSTR];
do
    {
        switch(menu())
        {
        case 1:  system("cls");
            printf("**SISTEMA DE EMPLEADOS**ALTAS**\n");
            dataEntry(employes,TAM,lastId);

            lastId++;
            break;

        case 2:   system("cls");
                printf("**SISTEMA DE EMPLEADOS**BAJAS**\n");
            do{
                printf("Ingrese el ID del empleado:\n");
                scanf("%s",auxLen);
                check=validadorInputInt(auxLen,LENSTR);
                if(check==1)
                {
                    id=atoi(auxLen);
                }
                }while(check!=1);
                removeEmployee(employes,TAM,id);
            break;

        case 3: system("cls");
                printf("**SISTEMA DE EMPLEADOS**MODIFICACIONES**\n");
                 do{
                printf("Ingrese el ID del empleado:\n");
                scanf("%s",auxLen);
                check=validadorInputInt(auxLen,LENSTR);
                if(check==1)
                {
                    id=atoi(auxLen);
                }
                }while(check!=1);
                editEmployes(employes,TAM,id);

            break;

        case 4:printf("LISTADO DE EMPLEADOS \n");
            printEmployes(employes,TAM);
            printf("_______________________________________________\n");
            printf("1-ORDENAR DE MAYOR A MENOR \n");
            printf("0-ORDENAR DE MENOR A MAYOR \n");
            printf("2-MOSTRAR INFORME DE SALARIOS\n");
            printf("3-VOLVER AL MENU PRINCIPAL  \n");
            scanf("%d",&order);
            sortEmployees(employes, TAM,order);
            break;


        case 5:
            printf("Confirma salir?:");
            printf("1-SI | 2-NO ");
            scanf("%d",&salir);
            if(salir==1)
            {
                break;

            }
            else if(salir==2)
            {
                main();
            }


        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir != 1);

    return 0;
}







