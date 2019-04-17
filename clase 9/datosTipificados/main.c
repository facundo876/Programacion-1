#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char desc[31];
}eSector;

int main()
{
    int idSector= 1,2,3;//rrhh, ventas, sist

    for(int i=0; i<CANT_SEC; i++){
        for(int j=0; j<CANT_EMP; j++){
            if(sectorAux==sector[i] && sector[i]==emp[j].idSector){
                printf("%d %s %s", emp[j])
            }
        }
    }

    return 0;
}
