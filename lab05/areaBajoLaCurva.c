#include <stdio.h>

void leerDatos(double *A, double *B, double *C, double *D);
void rangoIntervalo(int *inferior, int *superior, int *valorSubintervalo);
double sumaRiemann();
double reglaSimpson();


int main(){
    char opcion;
    double A, B, C, D;
    int inferior, superior, valorSubintervalo;
    printf("Ingrese la opción con la que desea calcular el área de la función: \n");
    printf("Suma de Riemann (R o r)\n");
    printf("Regla de Simpson 3/8 compuesta (T o t)\n");
    scanf("%c", &opcion);

    if(opcion == 'R' || opcion == 'r' || opcion == 'T' || opcion == 't'){
        leerDatos(&A, &B, &C, &D);
        rangoIntervalo(&inferior, &superior, &valorSubintervalo);
    }
    return 0;
}

void leerDatos(double *A, double *B, double *C, double *D){
    printf("Ingrese los coeficientes de la función (Ax^3 + Bx^2 + Cx + D): \n");
    scanf("%lf %lf %lf %lf", *A, *B, *C, *D);
}

void rangoIntervalo(int *inferior, int *superior, int *valorSubintervalo){
    printf("Ingrese el límite inferior y superior del intervalor:\n");
    scanf("%d %d", &inferior , &superior);
    print("Ingrese la cantidad de subintervalos:\n");
    scanf("%d", &valorSubintervalo);

}
