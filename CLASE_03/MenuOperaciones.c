#include <stdio.h>

int main(){
    double a, b, rspt;
    char operacion;
    printf("Ingrese los numeros que se serán los operandos de la operación (a+b, a-b, a*b, a/b) más el caracter que represente a la operación (+, -, *, /): ");
    scanf("%lf %lf %c", &a, &b, &operacion);
    int rsptValida = 1;

    if(operacion == '+'){
        rspt = a + b;
    }
    else if(operacion == '-'){
        rspt = a - b;
    }
    else if (operacion == '/') {
        if (b > 0){
            rspt = a / b;
        }
        else {
            printf("No se puede dividir entre cero");
            rsptValida = 0;
        }
    }
    else if(operacion == '*'){
        rsptValida = a * b;
    }
    else {
        printf("Ingrese valores válidos\n");
        rsptValida = 0;
    }

    if(rsptValida == 1){
        printf("El resultado de la operación %lf %c %lf = %lf", a, operacion, b, rspt);
    }

    return 0;
}
