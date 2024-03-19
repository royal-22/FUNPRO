#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238

int main(){
    double a, b, c, Q, R;
    printf("Ingrese los coeficientes de la ecuación cuadrática (x^3 + Ax^2 + Bx + C): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    Q = (pow(a, 2) - 3 * b) / 9;
    R = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;

    double angulo = acos(R/sqrt(pow(Q, 3)));
    double raiz1, raiz2, raiz3;

    raiz1 = -2 * sqrt(Q) * cos(angulo/3) - a / 3;
    raiz2 = -2 * sqrt(Q) * cos((angulo + 2 * PI) / 3) - a / 3;
    raiz3 = -2 * sqrt(Q) * cos((angulo - 2 * PI) / 3) - a / 3;

    printf("Las raices de la ecuación cuadrática son %lf %lf %lf.\n", raiz1, raiz2, raiz3);

    return 0;
}
