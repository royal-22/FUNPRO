#include <stdio.h>
#include <math.h>

int main(){
    int iteraciones, i;
    double A1, A2, B1, B2, C1, C2;
    printf("Ingrese la cantidad de veces que desea validar si 2 rectas son secantes, paralelas o coincidentes: ");
    scanf("%d", &iteraciones);
    if(iteraciones <= 20 && iteraciones >= 1){
        for(i = 0; i < iteraciones; i++){
            printf("Ingrese los coeficientes A, B y C de la recta %d (Ax + By + C = 0): ", i+1);
            scanf("%lf %lf %lf", &A1, &B1, &C1);
            printf("Ingrese los coeficientes A, B y C de la recta %d (Ax + By + C = 0): ", i+2);
            scanf("%lf %lf %lf", &A2, &B2, &C2);
            
            double cA = A1 / A2;
            double cB = B1 / B2;
            double cC = C1 / C2;

            if(fabs(cA - cB) <= 0.01){
                if((fabs(cA - cC) <= 0.01)){
                    printf("La rectas son coincidentes.\n");
                }
                else{
                    printf("Las rectas son paralelas.\n");
                }
            }
            else{
            printf("Las rectas son secantes.\n");
            }
        }
    }
    else{
        printf("El valor de n no se encuentra dentro del rango solicitado.\n");
    }
    return 0;
}
