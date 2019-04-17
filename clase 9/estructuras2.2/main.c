#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funcionesEstructura.h"

#define TAM 3
//ordenar
void ordenarFilas(eEmpleado empl[], int tam);
int menuOrdenar();
void ordenarNombre(eEmpleado emp[], int tam);
void ordenarLegajo(eEmpleado emp[], int tam);
void ordenarSueldo(eEmpleado emp[], int tam);
//validar
int esSoloLetras(char cadena[]);
int esGenero(char genero);

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]={{1234, "Juan", 'm', 30000, 1, {18}}, {1333, "Ana", 'f', 32000, 1}, {1200, "Jorge", 'm', 28000, 0}};
    lista[0].fechaNac.mes=8;
    lista[0].fechaNac.anio=1999;
    //inicializarEmpleados(lista, TAM); // llamada

    do
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

    return 0;
}

int menuOrdenar(){
    int opcion;

    printf("\n  *** ordenar filas ***\n\n");
    printf(" 1- Ordenar por nombre\n");
    printf(" 2- Ordenar por Legajo\n");
    printf(" 3- Ordenar por sueldo\n");;
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

return opcion;
}

 void ordenarFilas(eEmpleado empl[], int tam){

    switch(menuOrdenar()){

                    case 1:
                        //printf("\n  Orderanr por nombre\n");
                        ordenarNombre(empl, tam);
                        printf("\n Ordenado por nombre correctamente!!!\n\n");
                        system("pause");
                        break;
                    case 2:
                        ordenarLegajo(empl, tam);
                        printf("\n Ordenado por legajo correctamente!!!\n\n");
                        system("pause");
                        break;
                    case 3:
                        ordenarSueldo(empl, tam);
                        printf("\n Ordenado por sueldo correctamente!!!\n\n");
                        system("pause");
                        break;

                    default:
                        printf("\n Opcion invalida\n\n");
                       system("pause");
                        break;
                };
 }

 void ordenarNombre(eEmpleado emp[], int tam){

   eEmpleado aux;
     for(int i=0; i<tam; i++){
        for(int j=i+1; j<tam; j++){
    if((strcmp(emp[i].nombre, emp[j].nombre)) > 0 ){// si strcmp devuelve menor a cero entra


                aux=emp[i];
                emp[i]=emp[j];         //la emp[j] pasa a ser la primera
                emp[j]=aux;

            }

        }

    }
 }

void ordenarLegajo(eEmpleado emp[], int tam){

   eEmpleado aux;
     for(int i=0; i<tam; i++){
        for(int j=i+1; j<tam; j++){
    if(emp[i].legajo>emp[j].legajo){


                aux=emp[i];
                emp[i]=emp[j];         //la emp[j] pasa a ser la primera
                emp[j]=aux;

            }

        }

    }
 }

 void ordenarSueldo(eEmpleado emp[], int tam){

   eEmpleado aux;
     for(int i=0; i<tam; i++){
        for(int j=i+1; j<tam; j++){
    if(emp[i].sueldo<emp[j].sueldo){


                aux=emp[i];
                emp[i]=emp[j];         //la emp[j] pasa a ser la primera
                emp[j]=aux;

            }

        }

    }
 }

 int esSoloLetras(char cadena[]){
    int i=0;

    while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if((cadena[i]!=' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') ){
            return 0;
        }
      i++;
    }
    return 1;
}

int esGenero(char genero){

    if(tolower(genero) == 'm' || tolower(genero) == 'f'){
        return 1;
    }

    return 0;
}
