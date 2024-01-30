#include <stdio.h>

int main(){
    double n;
    printf("Ingrese número para comparar: ");
    scanf("%lf", &n);

    if(n > 0){
        printf("El número es mayor que cero");
    }
    else if(n < 0){
        printf("El número es menor que cero");
    }
    else{
        printf("El número es igual a cero");
    }
    return 0;
}
