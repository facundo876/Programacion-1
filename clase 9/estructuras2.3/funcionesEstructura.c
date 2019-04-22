#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

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

int esGenero(char genero){

    if(tolower(genero) == 'm' || tolower(genero) == 'f'){
        return 1;
    }

    return 0;
}

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
        if( vec[i].legajo == legajo && (vec[i].ocupado == 1 || vec[i].ocupado == 0))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado emp)
{

    printf("  %04d   %7s   %c    %.2f  %02d / %02d / %d \n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaNac.dia,emp.fechaNac.mes,emp.fechaNac.anio);

}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int cont= 0;

    printf("\n\n legajo  nombre  sexo  sueldo    Fecha Nac\n");
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
            vec[indice].nombre[0] = toupper(vec[indice].nombre[0]);// facundo = Facundo;

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

        printf("\nConfirma la eliminacion? s/n\n");
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

    printf(" Legajo  Nombre  Sexo   Sueldo    Estado\n");

    printf("  %04d   %7s   %c    %.2f   %d\n", vec[indice].legajo, vec[indice].nombre, vec[indice].sexo, vec[indice].sueldo, vec[indice].ocupado);

        //mostrarEmpleado(vec[indice]);
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
        int flag;

        printf("\nQuiere cambiar el nombre? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo nombre: ");

            do{
                     flag=0;
                if( esSoloLetras(gets(nuevoNombre)) != 1){
                    printf("\n Error! Ingrese nombre : ");
                    flag=1;
                }
            }while(flag != 0);
            nuevoNombre[0]=toupper(nuevoNombre[0]);// faucndo = Facundo;

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
        int flag;

        printf("\nQuiere cambiar el Sexo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sexo: ");
            //scanf("%c", &nuevoSexo);
            //valido nombre
            do{
                flag=0;
                scanf("%c", &nuevoSexo);

                if( esGenero(nuevoSexo) != 1){
                    fflush(stdin);
                    printf("\n Error! Ingrese sexo : ");
                    flag=1;
                }
            }while(flag != 0);

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


