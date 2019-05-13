#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fecha;

}eEmpleado;


int main()
{

    eEmpleado unEmpleado = {1234, "Juan", 'm', 30000, {(12),(5),(2019)}};
    eEmpleado otroEmpleado = {1235, "ana", 'm', 30000, {(13),(5),(2019)}};

    eEmpleado lista [] ={unEmpleado, otroEmpleado};

    eEmpleado* punteroEmpleado;


    punteroEmpleado = &unEmpleado;

    printf("Legajo : %d\n", punteroEmpleado->legajo);
    printf("Dia : %d\n", punteroEmpleado->fecha.dia);
    printf("Nombre : %s", (lista + 1)->n);

    return 0;
}
