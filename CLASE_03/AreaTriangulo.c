#include <stdio.h>
#include <math.h>

int main(){
    double ladoA, ladoB, ladoC, s;
    printf("Inserte los valores de los ladoA, ladoB, ladoC: ");
    scanf("%lf %lf %lf", &ladoA, &ladoB, &ladoC);
    
    if(((ladoA + ladoB) > ladoC && (ladoB + ladoC) > ladoA && (ladoC + ladoA) > ladoB) && (ladoA > 0 && ladoB > 0 && ladoC > 0)){
        s = (ladoA + ladoB + ladoC) / 2;
        double area = sqrt(s * (s - ladoA) * (s - ladoB) * (s - ladoC));
        printf("El área del triángulo es %lf", area);
    }
    else{
        printf("Datos de entrada incorrectos\n");
    }
    
    return 0;
}
