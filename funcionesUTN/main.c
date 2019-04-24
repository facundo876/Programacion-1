#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"

int main()
{
    char numero[20];
    printf("Ingresar dato : ");
    gets(numero);

    //fgets(numero,sizeof(numero)-2,stdin);

    if( esSoloLetras(numero) != 0){
        printf("es LETRAS");
    }
    else{
        printf("No es letras");
    }


    //metodoBurbujeo(numero);

    //esNumerico(numero);

    //esSoloLetras(numero);

    //esAlfanumerico(numero);

    //esTelefono(numero);

    /*int vec [5]={2,8,55,22,6};
    printf("numero mayor : %d", numeroMayor(vec,5));

    printf("\nnumero menor : %d", numeroMenor(vec,5));

    printf("\nPromedio del array : %.2f", promedioArray(vec,5));
*/


}
