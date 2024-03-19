#include <stdio.h>
#include <math.h>

int factorial(int num);

int main(){
	int numero, i, factorialp, factorialr, factorialpR, coeficiente, coeficientesDivisibles = 0;
	printf("Ingrese el número a evaluar: ");
	scanf("%d", &numero);
	for(i = 0; i <= numero; i++){
		factorialp = factorial(numero);
		factorialr = factorial(i);
		factorialpR = factorial(numero - i);
		coeficiente = factorialp / (factorialr * factorialpR);
		if(coeficiente != 1 ){
			printf("coeficiente %d\n", coeficiente);
			coeficientesDivisibles++;
			if(coeficiente % numero != 0){
				break;
			}	
		}
	}
	if(coeficientesDivisibles == numero - 1){
		printf("El número %d es primo según el test de primalidad AKS\n", numero);
	}else{
		printf("El número %d NO es primo según el test de primalidad AKS\n", numero);
	}
	return 0;
}

int factorial(int num){
	int i, rspt = 1;
	for(i = 1; i <= num; i++){
		rspt *= i;
	}
	return rspt;
}
