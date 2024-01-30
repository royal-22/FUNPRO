#include <stdio.h>
#include <math.h>
#define G 9.8
#define PI 3.141592653589793238

int main(){
    double m, h, k, d, x_m, theta, c, r;
    printf("Altura del edificio (h) en m: ");
    scanf("%lf", &h);
    printf("Masa (m) en g: ");
    scanf(" %lf", &m);
    printf("Constante (k) del muelle en N/m: ");
    scanf(" %lf", &k);
    printf("Distancia inicial (d) del objeto en cm: ");
    scanf(" %lf", &d);
    printf("Desplazamiento (x_m) en cm: ");
    scanf(" %lf", &x_m);
    printf("Ángulo theta en grados sexagesimales: ");
    scanf(" %lf", &theta);
    printf("Distancia entre el edificio y el punto medio de la ratita (c) en m: ");
    scanf(" %lf", &c);
    printf("Tamaño de la ratita (r) en cm: ");
    scanf(" %lf", &r);
    
    d = d * pow(10, -2);
    x_m = x_m * pow(10, -2);
    r = r * pow(10, -2);
    m = m * pow(10, -3);

    if ( h == 0 && m == 0 && k == 0 && d == 0 && x_m == 0 && theta == 0 && c == 0 && r == 0) {
        printf("Ingresar valores válidos\n");
    }

    theta = (theta * 2 * PI) / 360;

    double v = sqrt((2 * (0.5 * k * pow(x_m, 2) + m * G * (x_m + d) * sin(theta)))/m);
    if (v > 0){
        double discriminante = sqrt( pow(v * sin(theta), 2) + 2 * G * h);
        if (discriminante > 0) {
            double tiempo = (- v * sin(theta) + discriminante) / G;
            double distancia = v * tiempo * cos(theta);
            printf("¿Llega a impactar el objeto a la ratita?\n");
            if(distancia <= c + r  && distancia >= c - r){
                printf("Sí, porque el objeto impacta a %lf m del edificio.\n", distancia);
            }
            else{
                printf("No, porque el objeto impacta a %lf m del edificio", distancia);
            }
        }
        else{
            printf("No se puede hallar el tiempo que demora en caer el objeto.\n");
        }
    }
    else{
        printf("No se puede hallar la velocidad del objeto.\n");
    }
    return 0;
}
