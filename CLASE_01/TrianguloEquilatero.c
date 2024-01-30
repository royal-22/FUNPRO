#include <stdio.h>

int main(){
    int AB, BC, CA, rspt;

    AB = 3; 
    BC = 3; 
    CA = 3;

    rspt = (AB == BC) && (BC == CA) && (CA == AB);
    printf("%d", rspt);
    return 0;
}
