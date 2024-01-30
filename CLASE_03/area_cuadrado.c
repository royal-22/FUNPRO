#include <stdio.h>

int main(){
    printf("Ingrese medida del lado del triángulo: ");
    double lado;
    scanf("%lf", &lado);

    if(lado > 0){
        printf("El área del triángulo es %lf", lado*lado);
    }
    else{
        printf("Ingrese valor válido");
    }
    return 0;
}
