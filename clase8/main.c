#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

struct datosPersonales {

    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;

};

int main()
{

    struct datosPersonales agenda[20], aux;

    /*for(int i=0; i<MAX; i++){

        printf("Ingresar Nombre :");
        gets(agenda[i].nombre);
        fflush(stdin);

        printf("Ingresar Apellido :");
        gets(agenda[i].apellido);
        fflush(stdin);

        printf("Ingresar Calle :");
        gets(agenda[i].calle);
        fflush(stdin);

        printf("Ingresar Numero :");
        scanf("%d", &agenda[i].numero);
        fflush(stdin);


    }*/
    fflush(stdin);
    strcpy(agenda[0].nombre, "juan");
    strcpy(agenda[0].apellido, "Aguirre");
    strcpy(agenda[0].calle, "Mitre");
    agenda[0].numero= 750;

    strcpy(agenda[1].nombre, "juan");
    strcpy(agenda[1].apellido, "Gomez");
    strcpy(agenda[1].calle, "Mitre");
    agenda[1].numero= 760;

    strcpy(agenda[2].nombre, "juan");
    strcpy(agenda[2].apellido, "Perez");
    strcpy(agenda[2].calle, "Mitre");
    agenda[2].numero= 767;


    for(int i=0; i<MAX; i++){
        printf("\nNombre Ingresado : %s", agenda[i].nombre);
        printf("\nApellido Ingresado : %s", agenda[i].apellido);
        printf("\nCalle Ingresada : %s", agenda[i].calle);
        printf("\nNumero de calle ingresada : %d", agenda[i].numero);

            printf("\n\n");
    }

    /*for(int i=0; i<MAX; i++){
        for(int j=i+1; j<MAX; j++){

     //solo char       //if((strcmp(agenda[i].numero, agenda[j].numero)) < 0 ){// si strcmp devuelve menor a cero entra
            if((agenda[i].numero<agenda[j].numero)){

                aux=agenda[i];
                agenda[i]=agenda[j];         //la agenda[j] pasa a ser la primera
                agenda[j]=aux;

            }

        }

    }

    printf("\n Ordenados por el valor de numero:\n");
    */

    for(int i=0; i<MAX; i++){
        for(int j=i+1; j<MAX; j++){
    if((strcmp(agenda[i].apellido, agenda[j].apellido)) > 0 ){// si strcmp devuelve menor a cero entra


                aux=agenda[i];
                agenda[i]=agenda[j];         //la agenda[j] pasa a ser la primera
                agenda[j]=aux;

            }

        }

    }

    printf("\n Ordenados por el valor de apellido:\n");

    for(int i=0; i<MAX; i++){

        printf("\nNombre Ingresado : %s", agenda[i].nombre);
        printf("\nApellido Ingresado : %s", agenda[i].apellido);
        printf("\nCalle Ingresada : %s", agenda[i].calle);
        printf("\nNumero de calle ingresada : %d", agenda[i].numero);

            printf("\n\n");
    }




    return 0;
}
