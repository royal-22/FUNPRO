#include <stdio.h>
#include <math.h>

void validarNumerosPoderosos(int inicio, int fin);
void numeroOdiosoMalvado(int num, int *tipoNumero);
int esPoderoso(int num);
int siguientePrimo(int d);
int esPrimo(int n);

int main(){
	int inicio, fin;
	printf("Ingrese un rango: ");
	scanf("%d %d", &inicio, &fin);
	if(fin > inicio && inicio >= 1){
		validarNumerosPoderosos(inicio, fin);
	}else{
		printf("Rango incorrecto\n");
	}
	return 0;
}

void numeroOdiosoMalvado(int num, int *tipoNumero){
	int binario, cantUnos = 0, digito, exponente = 0;
	while(num > 0){
		digito = num % 2;
		num /= 2;
		binario += digito * pow(10, exponente);
		if(digito == 1){
			cantUnos++;
		}
		exponente++;
	}
	if(cantUnos % 2 != 0){
		*tipoNumero = 1;
	}else{
		*tipoNumero = 2;
	}
}

int esPrimo(int n){
	int i = 1, cantDivisores = 0;
	while(i <= n){
		if(n % i == 0){
			cantDivisores++;
		}
		i++;
	}
	return cantDivisores == 2;
}

int siguientePrimo(int d){
	do{
		d++;
	}while(!esPrimo(d));
	return d;
}

int esPoderoso(int num){
	int resto, nuevoDivisor, divisor = 2;
	while(divisor <= num){
		resto = num % divisor;
		if(resto == 0){
			nuevoDivisor = divisor * divisor;
			if(num % nuevoDivisor != 0){
				return 0;
			}
		}
		divisor = siguientePrimo(divisor);
		
		
	}
	return 1;
}

void validarNumerosPoderosos(int inicio, int fin){
	int i, tipoNumero, malvados = 0, odiosos = 0;
	for(i = inicio; i < fin; i++){
		if(esPoderoso(i)){
			printf("%d es un número poderoso ", i);
			numeroOdiosoMalvado(i, &tipoNumero);
			if(tipoNumero == 1){
				printf("odioso");
				odiosos++;
			}else{
				printf("malvado");
				malvados++;
			}
			printf("\n");
		}
	}
	printf("En total hay %d poderosos malvados y %d poderosos odiosos\n", malvados, odiosos);
}
