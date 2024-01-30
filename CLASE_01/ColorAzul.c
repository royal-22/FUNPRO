#include <stdio.h>

int main(){
    
    int longitudDeOnda, rspt;

    longitudDeOnda = 470;

    rspt = (longitudDeOnda >= 460) && (longitudDeOnda <= 482);

    printf("%d", rspt);

    return 0;
}
