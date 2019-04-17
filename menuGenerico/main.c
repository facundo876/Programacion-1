#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int menu();

int main()
{
    char seguir = 's';
    char confirma;

    do
    {
        switch(menu())
        {

        case 1:
            printf("\nAlta empleado\n\n");
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
// menu
int menu()
{
    int opcion;

    system("cls");// limpia el menu
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
