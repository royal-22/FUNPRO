#include <stdio.h>

int main(){
    int p, q, r, rst;

    p = 1;
    q = 0; 
    r = 0; 

    if(q == 1){
        if (p == 1 && r == 1) {
            printf("Año bisiesto\n");
        }
        else{
            printf("Año no bisiesto\n");
        }
    }

    else {
        if (p == 1) {
        printf("Año bisiesto\n");
        }
        else{
            printf("Año no bisiesto");
        }
    }
    return 0;
}
