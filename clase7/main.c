#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/** \brief recibe un nombre y apellido y pasa la cadena ej: Juan, Perez
 *
 * \param recibe nombre
 * \param recibe apeliido
 * \return retorna nombre y apellido en forma ordanada
 *
 */

int main()
{
    //Perez, Juan
    int i=0;
    char nombre [20];
    char apellido[20];
    char nombreCompleto [100];//minimo que puede medir es de 41

    printf("Ingresar nombre :");
    gets(nombre);
    printf("Ingresar apellido : ");
    gets(apellido);

    strcpy(nombreCompleto,strcat(nombre, ", "));
    strcat(nombreCompleto,apellido);
    //strcpy(nombreCompleto, strcat(strcat(nombre, ", "), apellido));

    strlwr(nombreCompleto);

    nombreCompleto[0]= toupper(nombreCompleto[0]);

    while(nombreCompleto[i] != '\0'){

        if(nombreCompleto[i] == ' '){
            nombreCompleto[i+1]= toupper(nombreCompleto[i+1]);
        }
        i++;
    }

    //printf("%s", nombreCompleto);
    puts(nombreCompleto);//imprime la cadena de carracters
    return 0;
}
