#include <stdio.h>
#include <math.h>

void evaluarSumatoriaHarshad(int digitos);
void obtenerImprimirHarshad(int num, int sumatoria, int sumatoriaAuxiliar);
void calcularSumatorias(int num, int digitos, int *sumatoria, int *sumatoriaAuxiliar);

int main(){
	int digitos;
	while(1){
		printf("Ingrese el número de dígitos: ");
		scanf("%d", &digitos);
		if(digitos > 0){
			evaluarSumatoriaHarshad(digitos);
			printf("/n");
		}else{
			break;
		}
	}
	return 0;
}

void evaluarSumatoriaHarshad(int digitos){
	int inicio = (int)pow(10, digitos - 1), fin = (int)pow(10, digitos), i, sumatoria, sumatoriaAuxiliar;
	printf("Los números de Harshad en base 10 de %d dígitos son (A, X)\n", digitos);
	for(i = inicio; i < fin; i++){
		sumatoria = 0;
		sumatoriaAuxiliar = 0;
		calcularSumatorias(i, digitos, &sumatoria, &sumatoriaAuxiliar);
		obtenerImprimirHarshad(i, sumatoria, sumatoriaAuxiliar);
	}
}

void calcularSumatorias(int num, int digitos, int *sumatoria, int *sumatoriaAuxiliar){
	int m, cifra;
	/**sumatoria = 0;
	*sumatoriaAuxiliar = 0;*/
	for(m = 0; m < digitos; m++){
		cifra = num % 10;
		num /= 10;
		*sumatoria += (int)pow(10, m) * cifra;
		*sumatoriaAuxiliar += cifra;
	}
}

void obtenerImprimirHarshad(int num, int sumatoria, int sumatoriaAuxiliar){
	int a;
	for(a = 1; a < sumatoria; a++){
		if(a * sumatoriaAuxiliar == sumatoria){
			printf("(%d, %d) ", a, num);
		}
	}
}
