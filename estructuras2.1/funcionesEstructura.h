#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


#define TAM 3

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;

} eEmpleado;

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
