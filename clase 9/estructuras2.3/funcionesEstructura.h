#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


#define TAM 3

typedef struct {
    int id;
    char sector[20];

}eSector;

typedef struct{
    int dia, mes, anio;

}eFecha;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fechaNac;
    eSector sector;

} eEmpleado;
//Main
int menu();
int subMenu(eEmpleado vec[], int indice);
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
//modificar
void ModificacionEmpleado(eEmpleado vec[], int tam);
void modificarSueldo(eEmpleado vec[], int indice);
void modificarNombre(eEmpleado vec[], int indice);
void modificarSexo(eEmpleado vec[], int indice);
void modificarEstado(eEmpleado vec[], int indice);
//Ordenar
void ordenarFilas(eEmpleado empl[], int tam);
int menuOrdenar();
void ordenarNombre(eEmpleado emp[], int tam);
void ordenarLegajo(eEmpleado emp[], int tam);
void ordenarSueldo(eEmpleado emp[], int tam);
//validar
int esSoloLetras(char cadena[]);
int esGenero(char genero);
