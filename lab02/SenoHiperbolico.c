#include <stdio.h>
#include <math.h>

int main(){
    double x; 
    x = 2.5;
    double senh = (exp(x) - exp(-x)) / 2;
    double ans = sinh(x);

    printf("El resultado del seno hiperbolico de x es %lf", senh); 

    return 0;
}