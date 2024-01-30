#include <stdio.h>

int main(){
    int cantCaras, cantAristas, cantVertices;

    cantCaras = 4;
    cantAristas = 6;
    cantVertices = 4;

    int rspt = (cantCaras - cantAristas + cantVertices) == 2;

    printf("%d", rspt);

    return 0;
}
