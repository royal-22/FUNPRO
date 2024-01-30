#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(){
    double radio, angulo;

    printf("Ingrese el valor del radio y ángulo del sector circular: ");
    scanf("%lf %lf", &radio, &angulo);

    if(radio > 0 && angulo > 0 && angulo < 360){
        double area = (PI * radio * radio * angulo) / 360;
        printf("El área es %lf \n", area);
    }
    else {
        printf("Los datos de entrada son incorrectos.\n");
    }
    return 0;
}
