#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main(){
    int n, i;
    double productoria, error;
    printf("Ingrese la cantidad de términos: ");
    scanf("%d", &n);
    productoria = 1;
    i = 1;
    if(n>0){
        while(i<=n){
            productoria *= pow(4*i, 2)/((4 * i - 1) * (4 * i + 1));
            printf("%lf\n", productoria);
            i++;
        }
        productoria *= 2 * sqrt(2);
        error = fabs(PI - productoria);

        printf("El valor calculado de PI a través de la productoria para %d términos es %lf\n", n, productoria);
        if(error < 0.005){
            printf("El error calculado no es considerable (<0.005): %lf\n", error);
        }
        else{
            printf("El error calculado es considerable (>= 0.005): %lf", error);
        }
    }
    else{
        printf("La cantidad de términos debe ser mayor que cero.\n");
    }

    return 0;
}
