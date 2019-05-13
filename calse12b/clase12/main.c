#include <stdio.h>
#include <stdlib.h>
void leerPuntero(int* p);
void asicPuntero(int* p);
void mostrarVector1(int vec[], int tam);//nomenclatura vectorial
void mostrarVector2(int vec[], int tam);//nomenclaura de punteros
void mostrarVector3(int* vec, int tam);// puntero a vector
void mostrarVector4(int* vec, int tam);// puntero a puntero

int main()
{
    /*int x =10;


    printf("Antes : ");
    leerPuntero(&x);

    printf("\nDespues : ");
    asicPuntero(&x);
    */

    int numero []= {3,5,2,4,3 };

    //funciones
    mostrarVector1(numero, 5);
    mostrarVector2(numero, 5);
    mostrarVector3(numero, 5);
    mostrarVector4(numero, 5);



    return 0;
}

void leerPuntero(int* p){

    printf("%d", *p);
}

void asicPuntero(int* p){
    *p = 33;
    printf("%d", *p);
}

void mostrarVector1(int vec[], int tam){

        printf("Mostrar 1\n");
        for(int i=0; i<tam; i++){

        printf("%d ",vec[i]);
    }
    printf("\n");
}
void mostrarVector2(int vec[], int tam){

        printf("Mostrar 2\n");
        for(int i=0; i<tam; i++){

        printf("%d ", *(vec+i));
    }
    printf("\n");
}

void mostrarVector3(int* vec, int tam){

        printf("Mostrar 3\n");
        for(int i=0; i<tam; i++){

        printf("%d ", vec[i]);
    }
    printf("\n");
}

void mostrarVector4(int* vec, int tam){

        printf("Mostrar 4\n");
        for(int i=0; i<tam; i++){

        printf("%d ", *(vec+i));
    }
    printf("\n");
}
