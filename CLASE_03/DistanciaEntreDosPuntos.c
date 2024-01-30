#include <stdio.h>
#include <math.h>

int main(){
    double x1, y1, x2, y2, d;
    printf("Ingrese los valores de las coordenadas x1, y1, x2, y2: ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    
    if(x1 > 0 || y1 > 0 || x2 > 0 || y2 > 0){
        d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        printf("La distancia entre dos puntos es %lf", d);
    }
    else{
        printf("Por lo menos uno de los puntos no se encuentra en el primer cuadrante");
    }

    return 0;
}
