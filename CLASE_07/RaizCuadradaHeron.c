#include <stdio.h>
void RaizCuadradaHeron(int iteraciones, int numero, double *ans);
void LeerDatos(int *iteraciones, int *numero);

int main(){
    int iteraciones, numero;
    double ans;
    LeerDatos(&iteraciones, &numero);
    if(numero > 0 && iteraciones > 1){
        RaizCuadradaHeron(iteraciones, numero, &ans);
        printf("La raíz cuadrada de %d obtenida es %lf\n", numero, ans);
    }
    else{
        if(numero <= 0){
            printf("Ingrese un número postivo.\n");
        }
        else{
            printf("La cantidad de iteraciones debe ser mayor que 1.\n");
        }
        
    }
    return 0;
}

void RaizCuadradaHeron(int iteraciones, int numero, double *ans){
    int i = 0;
    double a = 1;
    double nA, promedio;
    printf("i N    a         N/a     Promedio\n");
    while(i < iteraciones){
        nA = (double) numero/a;
        promedio = (a + nA) / 2;
        printf("%d %d %lf %lf %lf\n", i+1, numero, a, nA, promedio);
        a = promedio;
        i++;
    }
    *ans = promedio;
}


void LeerDatos(int *iteraciones, int *numero){
    printf("Ingrese un número positivo: ");
    scanf("%d", numero);
    printf("Ingrese la cantidad de iteraciones: ");
    scanf("%d", iteraciones);
}
