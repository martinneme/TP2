
 #define LENSTR 25 /* CANTIDAD DE CARACTERES ESPERADOS */
 #define MAXSALARY 1000000 /* SALARIO MAXIMO DE EMPLEADOS */
 #define MINSALARY 1 /* SALARIO MINIMO DE EMPLEADOS */

typedef struct
{
    int id;
    char name[LENSTR];
    char lastName[LENSTR];
    float salary;
    char sector[LENSTR];
    int isEmpty;
}employees;


/* PROTOTIPOS DE FUNCIONES*/

/** \brief MUESTRA MENU DE OPCIONES PRINCIPAL DEL SISTEMA DE ABM DE EMPLEADOS
 *
 * \param void No requiere el pasaje de valores dado su fin de imprimir mensajes.
 * \return Retorna un entero el cual resuelve la opcion del menu que el usuario selecciono en el switch del main.
 *
 */
int menu(void);

/** \brief INICIALIZA LOS EMPLEADOS CON VALOR 1 (DISPONIBLE)
 *
 * \param employes[] employees  Recibe el vector de empleados a fin de recorrerlo y realizar la asignacion de valores
 * \param TAM int recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \return void Retorna (-1) hubo algun error o (0) si esta ok.
 *
 */
void initemployes(employees employes[], int TAM);

/** \brief BUSCA LUGAR DISPONIBLE EN VECTOR DE EMPLEADOS
 *
 * \param employes[] employees Recibe el vector de empleados a fin de recorrerlo
 * \param TAM int recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \return int Devuelve (-1) no encuentra lugar, o el indice del vector donde se encuentra un espacio disponible.
 *
 */
int searchFree(employees employes[], int TAM);
/** \brief AGREGA EMPLEADOS AL SISTEMA
 *
 * \param employes employees* Recibe la posicion de memoria del vector de empleados a fin de asignar valores sobre el
 * \param TAM int Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \param id int Recibe el id del empleado generado automaticamente en forma secuencial
 * \param name[] char recibe el nombre del empleado a ingresar generado en la funcion dataEntry()
 * \param lastName[] char recibe el apellido del empleado a ingresar generado en la funcion dataEntry()
 * \param salary float recibe el salario del empleado a ingresar generado en la funcion dataEntry()
 * \param sector[] int recibe el sector del empleado a ingresar generado en la funcion dataEntry()
 * \return int retorna (1) si fue una carga exitosa,(0) si hubo un error.
 *
 */
int addemployes(employees *employes, int TAM,int id, char name[],char lastName[],float salary,int sector[]);
/** \brief RECIBE LOS DATOS DEL NUEVO EMPLEADO
 *
 * \param employes[] employees  Recibe el vector de empleados a fin de recorrerlo
 * \param tam int   Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \param lastId int Recibe el valor que le corresponde de ID al usuario proximo a cargar.
 * \return int Devuelve (1) si la carga de datos llego al final de la funcion,(0) si falla.
 *
 */
int dataEntry(employees employes[],int tam,int lastId);
/** \brief  MUESTRA LOS DATOS DE UN EMPLEADO
 *
 * \param x employees Recibe el una posicion del vector de empleados
 * \return void No retorna ningun valor, su finalidad es imprimir el mensaje
 *
 */
void printEmploye(employees x);
/** \brief MUESTRA TODOS LOS EMPLEADOS ACTIVOS
 *
 * \param employes[] employees ecibe el vector de empleados a fin de recorrerlo
 * \param TAM int Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \return void No retorna ningun valor, su finalidad es imprimir el mensaje
 *
 */
void printEmployes(employees employes[],int TAM);
/** \brief GENERA BAJA LOGICA DE UN EMPLEADO EN EL SISTEMA
 *
 * \param employes employees* Recibe la posicion de memoria del vector de empleados a fin de asignar valores sobre el
 * \param tam int Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \param id int Recibe el ID del empleado a buscar para luego aplicar la baja logica.
 * \return int Devuelve (0) si esta ok la baja, (-1) si hubo algun error.
 *
 */
int removeEmployee(employees *employes, int tam, int id);
/** \brief BUSCA UN EMPLEADO POR ID
 *
  * \param employes employees* Recibe la posicion de memoria del vector de empleados a fin de asignar valores sobre el
 * \param len int Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \param id int Recibe el ID del empleado a buscar.
 * \return int retorna (-1) si hubo algun error o la posicion del vector si lo encuentra.
 *
 */
int findEmployeeById(employees* employes, int len,int id);
/** \brief ORDENA EL LISTADO DE EMPLEADOS
 *
 * \param employes employees*  Recibe la posicion de memoria del vector de empleados a fin de asignar valores sobre el
 * \param tam int  Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \param order int Recibe el 1 para ordenar en forma descendente y 0 en forma ascendente
 * \return int Retorna 0  si llega al final del codigo y 1 si falla.
 *
 */
int sortEmployees(employees* employes, int tam, int order);
/** \brief PERMITE MODIFICAR TODOS LOS CAMPOS QUE CONFORMAN A UN EMPLEADO
 *
 * \param employes employees*  Recibe la posicion de memoria del vector de empleados a fin de asignar valores sobre el
 * \param tam int  Recibe el tamaño del vector de empleados como dato necesario para recorrerlo en su totalidad
 * \param id int Recibe el ID del empleado para buscarlo.
 * \return int Retorna 1 si ejecuto la opcion correctamente , 0 si no entro al switch
 *
 */
int editEmployes(employees *employes,int tam,int id);
/** \brief MUESTRA TITULOS QUE ACOMPAÑAN EL MOSTRAR EMPLEADOS.
 *
 * \param void No recibe parametros, solo imprime el mensaje.
 * \return void No retorna valor.
 *
 */
void MostrarCartel(void);
/** \brief RECIBE UN VECTOR Y VALIDA SI CORRESPONDE A UNA CADENA.
 *
 * \param x[] char Recibe una cadena
 * \param lenstr int Recibe el largo esperado
 * \return int Retorna 1 si es correcto, 0 si hay algun error.
 *
 */
int validaCadenas(char x[],int lenstr);
/** \brief RECIBE UN VECTOR Y VALIDA SI ES DEL LARGO ACEPTABLE
 *
 * \param auxLen[] char  Recibe una cadena
 * \param lenstr int  Recibe el largo esperado
 * \return int Retorna 1 si esta ok, 0 si falla.
 *
 */
int validadorLen(char auxLen[],int lenstr);
/** \brief VALIDA SI ES UN NUMERO
 *
 * \param auxlen[] char Recibe un vector auxiliar de char contenedor del entero en formato string
 * \param lenstr int recibe el largo esperado
 * \return int Retorna 1 si esta ok, 0 si falla.
 */
int validadorInputInt(char auxlen[],int lenstr);
int salaryInformation(employees employes[],int tam);
