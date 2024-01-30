#include <stdio.h>

int main(){
    int n, m;
    printf("Ingrese n y m: ");
    scanf("%d %d", &n, &m);

    if(m%n == 0.0){
        printf("m es múltiplo de n\n");
    }
    else{
        printf("m no es múltiplo de n\n");
    }

    return 0;
}
