#include <stdio.h>
#include <stdlib.h>
int obtenerMaximo(int x, int y, int z);

int main()
{
    printf("numero max : %d", obtenerMaximo(5,9,2));

    return 0;
}
int obtenerMaximo(int x, int y, int z){

    int max;

    if(x>y && x>z){
        max=x;
    }
    else{
        if(y>x && y>z){
            max=y;
        }
        else{
            max=z;
        }
    }

    /*if(max>5){
        return 0;
    }
    else{
        return 1;
    }*/

    return max;
}
