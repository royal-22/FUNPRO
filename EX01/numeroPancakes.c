#include <stdio.h>
#include <math.h>

double factorial(int n);

int main(){
	int valorN, valorEsperado, Pn, PnFormula;
	printf("Ingrese el valor de n y el valor esperado: ");
	scanf("%d %d", &valorN, &valorEsperado);
	
	if(valorN > 0 && valorEsperado > 0){
		
		if(valorN + 1 > 2){
			Pn = (factorial(valorN + 1) / (factorial(2) * (factorial(valorN + 1 - 2)))) + 1;
			PnFormula = (pow(valorN, 2) + valorN + 2) / 2;
			printf("El valor del combinatorio de (%d + 1  2) + 1 es: %d\n", valorN, Pn);
			printf("El valor de la fórmula es: %d\n", PnFormula);
			if(Pn == PnFormula && Pn == valorEsperado){
				printf("Se cumple la igualdad con el valor esperado %d\n", Pn);
			}else{
				printf("No se cumple la igualdad.\n");
			}
		}else{
			printf("El combinatorio no se pudo calcular\n");
		}
	}else{
		if(valorN <= 0 && valorEsperado > 0){
			if(valorN == 0){
				printf("El valor esperado es mayor a 0 pero n no puede ser igual a 0\n");
			}else{
				printf("El valor esperado es mayor a 0 pero n no puede ser menor a 0\n");
			}
		}else{
			printf("El valor esperado no puede ser menor a 0\n");
		}
	}
	return 0;
}

double factorial(int n){
	int i=0;
	double factorial;
	while(i <= n){
		if(i == 0 || i == 1){
			factorial = 1;
		}else{
			factorial *= i;
		}
		i++;
	}
	return factorial;
}
