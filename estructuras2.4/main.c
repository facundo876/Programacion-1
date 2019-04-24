#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funcionesEstructura.h"

#define TAM 4
#define TAM_SECTORES 5


int main(){
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]= {//legaj, nombre, sexo, sueldo, estado, fechanaci, sector.
                            {1234, "Juan", 'm', 30000, 1, {(18),(8),(1999)}, 0},
                            {1333, "Ana", 'f', 32000, 1, {(15),(12),(1990)}, 5},
                            {1200, "Jorge", 'm', 28000, 1, {(2),(5),(1995)}, 1}
                          };
   eSector sector[]=
   {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},
   };

    //inicializarEmpleados(lista, TAM); // llamada

do
    {
        switch(menu())
        {

        case 1:
            // printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sector, TAM_SECTORES);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM, sector, TAM_SECTORES);
            system("pause");
            break;

        case 3:
            //printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(lista,TAM, sector, TAM_SECTORES);
            system("pause");
            break;

        case 4:
            //printf("\nOrdenar empleados\n\n");
            ordenarFilas(lista, TAM);
            //system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sector, TAM_SECTORES);
            system("pause");
            break;

        case 6:
            //printf("\nListar empleados\n\n");
            mostrarSectoresConEmpleados(sector, TAM_SECTORES, lista, TAM);
            system("pause");
            break;

        case 7:
            //printf("\nListar empleados\n\n");
            mostrarCantEmpleadosXSector(sector, TAM_SECTORES, lista, TAM);
            system("pause");
            break;

        case 8:
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
    }while(seguir == 's');


    return 0;
}
void initEmpeldos(){


}


