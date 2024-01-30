#include <stdio.h>

int main(){
    int a, b, c, rspt;
    // Calcular la discriminante
    
    a = 3;
    b = 3; 
    c = 5;
    rspt = (b^2 - 4 * a * c) < 0;

    printf("%d", rspt);
    return 0; 
}

