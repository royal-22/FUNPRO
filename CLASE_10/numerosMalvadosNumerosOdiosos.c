#include <stdio.h>
#define BASE 2
void calcularNumerosOdiososMalvados(int a, int b);
int validarRango(int a, int b);
int esMalvadoEsOdioso(int numeros);
void calcularPorcentaje(int numerosMalvados, int numerosOdiosos, float *porcentaje1, float *porcentaje2);


int main(){
	int a, b;
	float porcentajeMalvados, porcentajeOdiosos;
	printf("Ingrese el rango de números a evaluar: ");
	scanf("%d %d", &a, &b);
	
	if(validarRango(a, b)){
		calcularNumerosOdiososMalvados(a, b);
	}else{
		printf("Los valores ingresados para el rango no son válidos\n");
	}
	
	return 0;
}

int esMalvadoEsOdioso(int numero){
	int i = 0, contador = 0, digito;
	while(numero > 0){
		digito = numero%BASE;
		numero/=BASE;
		if(digito == 1){
			contador++;
		}
	}
	printf("%d\n", contador);
	if(contador%2 == 0){
		return 1;
	}else{
		return 2;
	}
}

void calcularPorcentaje(int numerosMalvados, int numerosOdiosos, float *porcentaje1, float *porcentaje2){
	*porcentaje1 = ( (double) numerosMalvados) / (numerosMalvados + numerosOdiosos) * 100;
	*porcentaje2 = (double)numerosOdiosos / (numerosMalvados + numerosOdiosos) * 100;
}

void calcularNumerosOdiososMalvados(int a, int b){
	int i, numerosMalvados = 0, numerosOdiosos = 0, resultado;
	float porcentajeMalvados, porcentajeOdiosos;
	for(i = a; i <= b; i++){
		resultado = esMalvadoEsOdioso(i);
		if(resultado == 1){
			printf("El número %d es malvado\n", i);
			numerosMalvados++;
		}else{
			printf("El número %d es odioso\n", i);
			numerosOdiosos++;
		}
	}
	calcularPorcentaje(numerosMalvados, numerosOdiosos, &porcentajeMalvados, &porcentajeOdiosos);
	printf("--------Reporte---------\n");
	printf("El porcentaje de números malvados es %lf\n", porcentajeMalvados);
	printf("El porcentaje de números odiosos es %lf\n", porcentajeOdiosos);
}

int validarRango(int a, int b){
	return a < b;
}

