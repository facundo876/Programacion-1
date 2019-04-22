#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funcionesEstructura.h"

#define TAM 3

void mostrarSectores(eEmpleado vec[], int tam, int id);


int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]= {
                            {1234, "Juan", 'm', 30000, 1, {(18),(8),(1999)}, 0},
                            {1333, "Ana", 'f', 32000, 1, {(15),(12),(1990)}, 0},
                            {1200, "Jorge", 'm', 28000, 0, {(2),(5),(1995)}, 1}
                          };

    //inicializarEmpleados(lista, TAM); // llamada

    printf("selecionar sector : \n");

    mostrarSectores(lista, TAM, 0);

    /*do
    {
        switch(menu())
        {

        case 1:
            // printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM);
            system("pause");
            break;

        case 3:
            //printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:
            //printf("\nOrdenar empleados\n\n");
            ordenarFilas(lista, TAM);
            //system("pause");
            break;



        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');
*/

    return 0;
}

void mostrarSectores(eEmpleado vec[], int tam, int id){
    for(int i=0; i<tam; i++){

        if(vec[i].sector.id == id){
            mostrarEmpleado(vec[i]);
        }
    }

}
