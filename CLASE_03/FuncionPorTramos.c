#include <stdio.h>

int main(){
    double x;
    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);
    
    if(x<5){
        printf("El valor de f(x) es %lf", x*x);
    }
    else if(x >= 5 && x < 10){
        printf("El valor de f(x) es %lf", x * x * x - 1);
    }
    else {
        printf("El valor de f(x) es %lf\n", x / 2);
    }

    return 0;
}
