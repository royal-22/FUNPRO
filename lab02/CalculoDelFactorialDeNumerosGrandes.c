#include <stdio.h>
#include <math.h>
#define E 2.7182818284
#define PI 3.1415926535

int main(){
    double n = 1;

    double factorial = sqrt(2 * PI * n) * pow(n / E, n);

    printf("El valor del factorial n es %lf", factorial);

    return 0;
}