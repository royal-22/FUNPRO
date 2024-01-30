#include <stdio.h>

int main(){
    int AB, BC, CA, rspt;

    AB = 8;
    BC = 5; 
    CA = 7;

    rspt = (AB != BC) && (BC != CA) && (CA != AB);

    printf("%d", rspt);
    return 0;
}
