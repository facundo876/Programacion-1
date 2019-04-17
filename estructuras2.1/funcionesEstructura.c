#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>



typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;

} eEmpleado;

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
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

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado emp)
{

    printf("  %04d   %7s   %c    %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);

}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int cont= 0;

    printf("\n\n legajo  nombre  sexo  sueldo\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {

            mostrarEmpleado(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;
    int flag;


    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        //verificar

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);

            //gets(vec[indice].nombre);
            //verificar
            do{
                    flag=0;
                if( esSoloLetras(gets(vec[indice].nombre)) != 1){
                    printf("\n Error! Ingrese nombre : ");
                    flag=1;
                }
            }while(flag != 0);

            printf("Ingrese sexo: ");
            fflush(stdin);
            //scanf("%c", &vec[indice].sexo);
            //verificar
            do{
                flag=0;
                scanf("%c", &vec[indice].sexo);

                if( esGenero(vec[indice].sexo) != 1){
                    fflush(stdin);
                    printf("\n Error! Ingrese sexo : ");
                    flag=1;
                }

            }while(flag != 0);
            tolower(vec[indice].sexo);


            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);
            //verificar

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta]);
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            vec[esta].ocupado = 0;
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }

}

void ModificacionEmpleado(eEmpleado vec[], int tam){

    int legajo;
    int esta;
    int atras=0;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
            printf("\n");
            //mostrarEmpleado(vec[esta]);
            printf("\n");
        do{
            switch(subMenu(vec, esta)){

                case 1:
                    modificarNombre(vec, esta);
                    system("pause");
                    break;
                case 2:
                    modificarSexo(vec, esta);
                    system("pause");
                    break;
                case 3:
                    modificarSueldo(vec, esta);
                    system("pause");
                    break;
                case 4:
                    modificarEstado(vec, esta);
                    system("pause");
                    break;
                case 5:
                    atras=1;
                    break;

                default:
                    printf("\n Opcion invalida\n\n");
                    system("pause");
                    break;
            }
        }while(atras == 0);

    }

}
int subMenu(eEmpleado vec[], int indice){
    int opcion;

    system("cls");

    printf(" Legajo  Nombre  Sexo  Sueldo\n");
        mostrarEmpleado(vec[indice]);
    printf("\n  *** modificar datos ***\n\n");
    printf(" 1- Modificar el nombre\n");
    printf(" 2- Modificar el sexo\n");
    printf(" 3- modificar el sueldo\n");
    printf(" 4- modificar el estado\n");
    printf(" 5- atras\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

return opcion;
}

void modificarSueldo(eEmpleado vec[], int indice){
        char confirma;
        float nuevoSueldo;

        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            //valido sueldo
            vec[indice].sueldo = nuevoSueldo;

            printf("\nSueldo ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el sueldo\n");
        }
}

void modificarNombre(eEmpleado vec[], int indice){
        char confirma;
        char nuevoNombre [20];

        printf("\nQuiere cambiar el nombre? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo nombre: ");
            gets(nuevoNombre);
            //valido nombre
            strcpy(vec[indice].nombre, nuevoNombre);

            printf("\nNombre ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el nombre\n");
        }
}

void modificarSexo(eEmpleado vec[], int indice){
        char confirma;
        char nuevoSexo;

        printf("\nQuiere cambiar el Sexo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sexo: ");
            scanf("%c", &nuevoSexo);
            //valido nombre
            vec[indice].sexo = nuevoSexo;

            printf("\nSexo ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el sexo\n");
        }
}

void modificarEstado(eEmpleado vec[], int indice){
        char confirma;
        int nuevoEstado;

        printf("\nQuiere cambiar el estado? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo Estado (0/1): ");
            scanf("%d", &nuevoEstado);
            //valido nombre
            vec[indice].ocupado = nuevoEstado;

            printf("\nEstado ingresado exitosamente!!\n\n");
        }
        else{
            printf("\nNo se ha modificado el estado\n");
        }
}

