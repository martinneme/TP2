#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<conio.h>
#include "ArrayEmployees.h"

/* FUNCIONES */

int menu(void)
{
    int opcion;

    system("cls");
    printf("****** ABM EMPLEADOS *******\n\n");
    printf("1-Alta empleado\n");
    printf("2-Baja empleado\n");
    printf("3-Modificar empleado\n");
    printf("4-Listar empleados\n");
    printf("5-Salir\n\n");
    printf("----------------\n");
    scanf("%d",&opcion);

    return opcion;
}

void initemployes(employees employes[], int tam)
{ int resultado=0;
    for(int i = 0; i < tam; i++)
    {
        employes[i].isEmpty = 1;
    }
    for(int i=0; i < tam; i++)
    {
        if( employes[i].isEmpty != 1 )
        {
            resultado=-1;
            break;
        }
    }
    return resultado;
}

int addEmployes(employees *employes,int tam,int id, char name[],char lastName[],float salary,int sector)
{
int resultado=0;
int l;
int check=0;

l=searchFree(employes,tam);

    if(l!=-1)
        {employes[l].id=id;
        strcpy(employes[l].name,name);
        strcpy(employes[l].lastName,lastName);
        strcpy(employes[l].sector,sector);
        employes[l].salary=salary;
        employes[l].isEmpty=0;
        check=1;

            if(check==1)
                {   resultado=1;
                    system("cls");
                    MostrarCartel();
                  printEmploye(employes[l]);
                }

        }
return resultado;

}
///////////////////////////
int searchFree(employees employes[],int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( employes[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}
///////////////////////////

int validaCadenas(char x[],int lenstr)
{
    int i;
    int res=0;
    int len;

    len=strlen(x);

    for(i=0;i<len;i++)
    {
            if(isalpha(x[i])&&len<=lenstr)
            {
                res=1;
            }
            else
            {
                break;
            }
    }



    return res;
}

int dataEntry(employees employes[],int tam,int lastId)
{
    char auxLen[100];
    char name[LENSTR];
    char lastName[LENSTR];
    char sector[LENSTR];
    int auxInt;
    int val=0;
    int check=0;
    int resultado=0;
    float salary;

do{
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);

     if(check==1)
        {
            strcpy(name,auxLen);
            val=validaCadenas(name,LENSTR);
        }
}while(val!=1 || check!=1);


do{
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);
     if(check==1)
        {
            strcpy(lastName,auxLen);
            val=validaCadenas(lastName,LENSTR);
        }


}while(val!=1 || check!=1);


do{
        printf("Ingrese sector: ");
        fflush(stdin);
        gets(auxLen);
        check=validadorLen(auxLen,LENSTR);
     if(check==1)
        {
            strcpy(sector,auxLen);
            val=validaCadenas(sector,LENSTR);
        }
}while(val!=1 || check!=1);

do{
        printf("Ingrese Salario:");
        scanf("%s",auxLen);
       check=validadorInputInt(auxLen,LENSTR);

       if(check==1){
        salary=atof(auxLen);
        resultado=addEmployes(employes,tam,lastId,name,lastName,salary,sector);
        }
        }while(check!=1);
resultado=1;
         return resultado;
}
///////////////////////////
void printEmploye(employees x)
{

    printf(" %d   %s  %s    %.2f     %s   \n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector
          );

printf("-----------------------------------------------\n");
}
//////////////////////////////////////
void printEmployes(employees employes[], int tam)
{

    int flag = 0;
    system("cls");
    int i;

    MostrarCartel();
    for(i=0; i < tam; i++)
    {
        if( employes[i].isEmpty == 0)
        {
            printEmploye(employes[i]);
            flag = 1;
        }
    }
    if (flag==0)
    {
        system("cls");
        printf("NO HAY NADA QUE MOSTRAR\n");
    }
}

int findEmployeeById(employees* employes, int tam,int id)
{ int i;
int null=-1;
    for(i=0;i<tam;i++)
    { if(employes[i].id==id && employes[i].isEmpty==0)
                {
                 null=i;
                 break;
                }

    }
    if(null==-1)
    {
                printf("No se encontro empleado con ese ID\n");
    }

 return null;
}

int removeEmployee(employees* employes, int tam, int id)
{
    int check=-1;
    int opcion;
    int posicion;

    posicion=findEmployeeById(employes,tam,id);
        if(posicion!=-1){
                            printEmploye(employes[posicion]);
                            printf("Desea dar de baja este usuario?\n");
                            printf("1-SI | 2-NO\n");
                            scanf("%d",&opcion);

                            switch(opcion)
                                {
                                case 1: employes[posicion].isEmpty=1;
                                        check=0;
                                        printf("Baja exitosa\n");
                                        break;
                                case 2:printf("Baja cancelada\n");
                                        break;
                                }
                        }



 return check;
}

int sortEmployees(employees* employes, int tam, int order)
{
     employees auxEmployes;
    int resultado=1;

     switch(order){
   case 0: for(int i= 0; i < tam-1 ; i++)
                {
                    for(int j= i+1; j <tam; j++)
                    {
                        if( strcmp(employes[i].lastName,employes[j].lastName )>0)
                        {
                            auxEmployes = employes[i];
                            employes[i] = employes[j];
                            employes[j] = auxEmployes;
                        }
                        if( strcmp(employes[i].sector,employes[j].sector )>0)
                        {
                            auxEmployes = employes[i];
                            employes[i] = employes[j];
                            employes[j] = auxEmployes;
                        }
                    }
                }
                    system("cls");
                    printEmployes(employes,tam);
                    break;
    case 1:for(int i= 0; i < tam-1 ; i++)
                {
                    for(int j= i+1; j <tam; j++)
                    {
                        if( strcmp(employes[i].lastName,employes[j].lastName )<0)                        {
                            auxEmployes = employes[i];
                            employes[i] = employes[j];
                            employes[j] = auxEmployes;

                        if( strcmp(employes[i].sector,employes[j].sector )<0)                        {
                            auxEmployes = employes[i];
                            employes[i] = employes[j];
                            employes[j] = auxEmployes;

                        }
                    }
                }
                 system("cls");
                 resultado=0;
            printEmployes(employes,tam);
             break;
    case 2: system("cls");
            salaryInformation(employes,tam);

    case 3:break;
default:printf("OPCION INVALIDA, REINTENTE");
     }
 return resultado;
}
}

int editEmployes(employees *employes,int tam,int id)
{
    int confirm=0;
    int opcion;
    char auxName[25];
    float auxSalary;
    char auxlen[LENSTR];
    int check;
    int resultado=0;

system("cls");


        confirm = findEmployeeById(employes,tam,id);

    if(confirm!=-1){
            do{
        system("cls");
        MostrarCartel();
        printEmploye(employes[confirm]);
        printf("________________________________\n");
            printf("Elija la modificacion que desea realizar\n");
            printf(" 1- nombre \n 2- Apellido \n 3-salario \n 4- sector\n");
            fflush(stdin);
            scanf("%s",auxlen);
            check=validadorInputInt(auxlen,LENSTR);
            if(check==1){
            opcion=atoi(auxlen);
                }
            }while(check!=1);
        switch(opcion)
        {
        case 1:system("cls");
                MostrarCartel();
                printEmploye(employes[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo nombre \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(employes[confirm].name,auxName);
                MostrarCartel();
                printEmploye(employes[confirm]);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 2: system("cls");
                MostrarCartel();
                printEmploye(employes[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo apellido \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(employes[confirm].lastName,auxName);
                MostrarCartel();
                printEmploye(employes[confirm]);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 3:system("cls");
                MostrarCartel();
                printEmploye(employes[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo salario \n");
                scanf("%f",&auxSalary);
                system("cls");

               employes[confirm].salary=auxSalary;
                MostrarCartel();
                printEmploye(employes[confirm]);
                resultado=1;
                printf("Cambio exitoso\n");
                break;
        case 4:system("cls");
                MostrarCartel();
                printEmploye(employes[confirm]);
                printf("__________________________\n");
                printf("Ingrese el nuevo sector \n");
                fflush(stdin);
                scanf("%s",auxName);
                system("cls");

                strcpy(employes[confirm].sector,auxName);
                MostrarCartel();
                printEmploye(employes[confirm]);
                resultado=1;
                printf("Cambio exitoso\n");
                break;

        }}

    return resultado;

}
void MostrarCartel(void)
{printf("_______________________________________________\n");
printf("ID   NOMBRE  APELLIDO   SALARIO   SECTOR\n");
printf("-----------------------------------------------\n");
}
int validadorLen(char auxLen[],int lenstr)
{   int check=0;
    int vlen;
    vlen=strlen(auxLen);
    if(vlen<lenstr)
    {
        check=1;
    }
    return check;

}
int validadorInputInt(char auxlen[],int lenstr)
{
    int i;
    int cont;
    int flag=0;

    int resultado=1;
cont=strlen(auxlen);
for(i=0;i<lenstr;i++)
{  if(i+1<=cont)
        {
                     if(auxlen[i]<48 || auxlen[i]>57)
                    {
                          resultado=0;
                          break;
                    }
        }
        else
            {
            break;
            }
}
return resultado;

}
int salaryInformation(employees employes[],int tam)
{
int i;

float acumSalary=0;
int cantEmp=0;
float promedio;

int contPlusSalary=0;

for(i=0;i<tam ; i++)
{
if(employes[i].isEmpty==0)
{
cantEmp++;
acumSalary=acumSalary+(employes[i].salary);
}

}
promedio=(float)(acumSalary/cantEmp);

for(i=0;i<tam ; i++)
{
if(employes[i].isEmpty==0 && employes[i].salary>promedio)
{
contPlusSalary++;

}
}
printf("El total de salarios de empleados es: %.2f\n",acumSalary);
printf("El salario promedio: %.2f\n",promedio);
printf("%d empleado/s superan el salario promedio\n",contPlusSalary);

return 1;
}












