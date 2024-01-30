#include <stdio.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592653589793238

int main(){
    double ladoA, ladoB, alpha;
    char criterio;
    printf("Ingrese la magnitud del lado A: ");
    scanf("%lf", &ladoA);
    printf("Ingrese la magnitud del lado B: ");
    scanf(" %lf", &ladoB);
    printf("Ingrese el ángulo alpha (en grados sexagesimales): ");
    scanf(" %lf", &alpha);
    printf("Ingrese el criterio de clasificación A(según ángulos) o L(según lados): ");
    scanf(" %c", &criterio);
    
    if(ladoA <= 0 || ladoB <= 0){
        printf("Los lados del triángulo no pueden ser menores o iguales a cero.\n");
    }
    else if(alpha >= 180 || alpha <= 0){
        printf("El ángulo de un triángulo debe ser mayor que cero y menor que 180 grados sexagesimales.\n");
    }
    else if(criterio != 'A' && criterio == 'L'){
        printf("Los únicos criterios permitidos son A y L.\n");
    }
    
    alpha = (2 * PI * alpha) / 360;    
    
    double ladoC = sqrt(pow(ladoA, 2) + pow(ladoB, 2) - 2 * ladoA * ladoB * cos(alpha));
    double theta = (asin(sin(alpha) * ladoA * 1/ladoC) * 180) / PI;
    double beta = (asin(sin(alpha) * ladoB * 1/ladoC) * 180) / PI;
    printf("LadoC: %lf \n", ladoC);
    printf("Angulo theta: %lf \n", theta);
    printf("Angulo beta: %lf \n", beta);

    if(criterio == 'A'){
        if(theta == (double)90 || beta == (double)90 || alpha == (double)90){
            printf("Triángulo rectángulo\n");
        }
        else if(){

        }
    }
    else{

    }
    return 0;
}
