#include <stdio.h>
#include <stdlib.h>

int pedirDato(int min, int max, int* valor, int intentos, char *mensaje, char *mensajeError);

int main()
{
    int x;
    int ok;

    ok=pedirDato(18, 65, &x, 3, "ingrear edad", "Error. Ingresar edad");

    if(ok==1){
        printf("Numero Ingresado : %d", x);
    }
    else{
        printf("No se pudo ingresar el dato");
    }


    return 0;
}
int pedirDato(int min, int max, int *pValor, int intentos, char *mensaje, char *mensajeError){
    int edad;
    int todoOk = 0;
    int cout = 0;

    printf("%s entre %d y %d : ", mensaje, min, max);
    scanf("%d", &edad);

    while(edad < min || edad > max){//Edad tiene que estar entre min y max.
    cout++;
        if(cout==intentos){
            break;
        }

     printf(" %s : ", mensajeError);
        scanf("%d", &edad);
    }
    if(cout < intentos){
        *pValor = edad;
        todoOk = 1;
    }

    return todoOk;
}
