#include <stdio.h>
#include <math.h>

int main(){
    double m, n;

    printf("Ingrese los valores de n (número consecutivos) y m (número en el cual inicia): ");
    scanf("%lf %lf", &n, &m);

    double l = n + m - 1;

    double rspt =  (pow(l, 2) * pow(l + 1, 2)) / 4 -  (pow(m-1, 2) * pow(m, 2))/4;

    printf("El resultado es %lf", rspt);
    
    return 0;
}