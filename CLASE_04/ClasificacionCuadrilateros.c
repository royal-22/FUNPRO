#include <stdio.h>

int main(){
    int lado1, lado2, lado3, lado4;
    int angulo1, angulo2, angulo3, angulo4;
    int ladoParalelos;
    printf("Ingrese los 4 lados del cuadrilatero: ");
    scanf("%d %d %d %d", &lado1, &lado2, &lado3, &lado4);
    printf("Ingrese los 4 angulos internos del cuadrilatero: ");
    scanf("%d %d %d %d", &angulo1, &angulo2, &angulo3, &angulo4);
    printf("Ingrese la cantidad de lados paralelos: ");
    scanf("%d", &ladoParalelos);
    int angulo90 = 0;
    if(angulo1 == 90){
        angulo90++;
    }
    if (angulo2 == 90) {
        angulo90++;
    }
    if(angulo3 == 90){
        angulo90++;
    }
    if(angulo4 == 90){
        angulo90++;
    }

    printf("%d", angulo90);

    if(ladoParalelos%2 != 0){
        printf("Los lados paralelos ingresados solo pueden ser los valores de 0, 2 y 4");
    }
    else{ 
        if(angulo1 + angulo2 + angulo3 + angulo4 == 360){
            if(ladoParalelos == 4){
                if(angulo90 == 4){
                    if (lado1 == lado2 && lado2 == lado3 && lado3 == lado4){
                        printf("Cuadrilatero Cuadrado\n");
                    }
                    else if((lado1 == lado2 && lado3 == lado4) || (lado1 == lado3 && lado2 == lado4) || (lado1 == lado4 && lado2 == lado3)){
                        printf("Cuadrilatero-Rectángulo\n");
                    }
                    else{
                        printf("Los datos ingresados no corresponden a un cuadrilatero\n");
                    }
                }
                else if((angulo1 == angulo2 && angulo3 == angulo4) || (angulo1 == angulo3 && angulo2 == angulo4) || (angulo4 == angulo1 && angulo2 == angulo3)){
                    if(lado1 == lado2 && lado2 == lado3 && lado3 == lado4){
                        printf("Cuadrilatero-Rombo\n");
                    }
                    else if((lado1 == lado2 && lado3 == lado4) || (lado1 == lado3 && lado2 == lado4) || (lado1 == lado4 && lado2 == lado3)){
                        printf("Cuadrilatero-Romboide");
                    }
                    else{
                        printf("Los datos ingresados no corresponden a un cuadrilatero\n");
                    }
                }
                else{
                    printf("Los datos ingresados no corresponden a un cuadrilatero\n");
                }

            }
            else if(ladoParalelos == 2){
                if ((angulo90 == 2) ) {
                    printf("Trapecio-Rectángulo\n");
                }
                else if(angulo1 == angulo2 || angulo3 == angulo4 || angulo1 == angulo3 || angulo2 == angulo4 || angulo1 == angulo4 || angulo2 == angulo3){
                    printf("Trapecio isósceles\n");
                }
                else{
                    printf("Trapecio escaleno\n");
                }
            }
            else{
                printf("Trapezoide");
            }
        }
        else{
            printf("Los datos ingresados no corresponden a un cuadrilatero.\n");
        }
    }
}
