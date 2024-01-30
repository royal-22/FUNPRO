#include <stdio.h>

int main(){

    int AB, BC, CA, rspt;

    AB = 8;
    BC = 2;
    CA = 1;

    rspt = (AB + BC < CA) && (BC + CA < AB) && (CA + AB < BC);

    printf("%d", rspt);

    return 0;
}
