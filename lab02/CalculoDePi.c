#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main(){
    double value = 9801 * sqrt(2) /4412 ;
    double error = fabs(PI - value);

    printf("El resultado de la fórmula es %.10lf", error);

    return 0;
}