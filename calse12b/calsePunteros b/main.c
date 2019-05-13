#include <stdio.h>
#include <stdlib.h>
void getChar(char* message, char* caracter);
void mostrarCadena(char* cadena);

int main()
{
    char nombre [20]= "Sebastian";
    char mensaje[20]= "Hola mundo";

    mostrarCadena(mensaje);

    return 0;
}
void getChar(char* message, char* caracter){


}

void mostrarCadena(char* cadena){

    while(*cadena != '\0' ){
        printf("%c", *cadena);
        cadena++;
    }
}
