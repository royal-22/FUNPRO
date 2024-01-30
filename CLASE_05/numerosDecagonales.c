#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(){
    int numeroDn, iteraciones, j;
    double numeroDecagonal, sumatoria, baseTangente, error;
    printf("Ingrese la cantidad de iteraciones y cantidad de números Dn a imprimir: ");
    scanf("%d %d", &iteraciones, &numeroDn);

    if(numeroDn > 0 && iteraciones > 0){
        sumatoria = 0;
        printf("Los %d números decagonales son:", numeroDn);
        for(j = 1; j <= numeroDn; j++){
            numeroDecagonal = 5 * j * (j - 1) + 1;
            printf(" %.0lf", numeroDecagonal);
        }
        printf("\n");
        for(int i = 1; i <= iteraciones; i++){
            sumatoria += (double) 1 / (5 * i * (i - 1) + 1);
        }
        
        baseTangente = (PI * tan(PI / (2 * sqrt(5)))) / sqrt(5);
        error = fabs(baseTangente - sumatoria);
        printf("La sumatoria de la inversa es: %lf\n", sumatoria);
        printf("El valor en base a la tangente es: %lf\n", baseTangente);
        printf("El error estimado es: %lf\n", error);
    }
    else{
        if(numeroDn <= 0 && iteraciones <= 0){
            printf("La cantidad de iteraciones y números Dn deben ser mayores que cero.\n");
        }
        else{
            if(iteraciones <= 0){
                printf("La cantidad de iteraciones debe ser mayor que cero.\n");
            }
            else{
                printf("La cantidad de números Dn debe ser mayor que cero.\n");
            }
        }
    }

    return 0;
}
