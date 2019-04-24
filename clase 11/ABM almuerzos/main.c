#include <stdio.h>
#include <stdlib.h>


#define TAM 3

typedef struct{
    int codigoMenu;
    char descripcion;
    float importe;
}eMenu;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char apellido[20];
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaDeIngreso;
    int idSector;
    int isEmpty;
}eEmpledos;

typedef struct{
    int codigoAlmuerzo;
    int codigoMenu;
    int legajoEmpleado;
    eFecha fecha;
}eAlmuerzo;

typedef struct{
    int id;
    char descripcion[20];
}eSector;
*/
int main{

    char seguir = 's';
    char confirma;
       eEmpledos empleados[];
        initEmpleados();
    eSector sectores[];
        initSector();
    eMenu menu[];
        initMenu();

    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");

            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            printf("\nListar empleados\n\n");
            system("pause");
            break;

        case 6:
            printf("\nListar empleados\n\n");
            system("pause");
            break;

        case 7:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();//getche detecta la primera leta ingresada

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

return 0;
}

int menu(){
    int opcion;

    system("cls");// limpia el menu
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- alta almuerzo\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

//corcodear
void initSectores(eSector sectores[], int tamSector){

    sectores[tamSector]={
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},
   };
}

void initEmpleados(eEmpledos empl[], int tamEmpl){

    empl[tamEmpl]= { //legaj, apellido, nombre, sexo, sueldo, estado, fechaIngreso, sector ishmpty.
            {1234, "Gonzales", "Juan", 'm', 30000, {(18),(8),(1999)}, 0, 1},
            {1333, "Perez", "Ana", 'f', 32000, {(15),(12),(1990)}, 5, 1},
            {1200, "Aguirre", "Jorge", 'm', 28000, {(2),(5),(1995)}, 1, 1}
            };

}

void initMenu(eMenu menu[], int tamMenu){
    menu[]={
            {1,"Sopa", 22},
            {2,"Ensalada", 15},
            {3,"Milanesa", 60}
        };
}
//muchso a muchos

