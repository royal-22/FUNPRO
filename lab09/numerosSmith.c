#include <stdio.h>

void evaluarNumerosSmith(int inicio, int fin);
int esSmith(int numero);
int sumaDigito(int numero);
int sumaExponentes(int numero);
int esPrimo(int n);
int siguientePrimo(int n);

int main(){
	int inicio, fin;
	printf("Ingrese un rango: ");
	scanf("%d %d", &inicio, &fin);
	if(fin >= inicio && fin > 0 && inicio > 0){
		evaluarNumerosSmith(inicio, fin);
	}else{
		printf("Rango incorrecto\n");
	}	
	return 0;
}

int sumaDigito(int numero){
	int sumaDigito = 0, digito;
	while(numero > 0){
		digito = numero % 10;
		sumaDigito += digito;
		numero /= 10;
	}
	
	return sumaDigito;
}


int esSmith(int numero){
	if(sumaDigito(numero) == sumaExponentes(numero)){
		return 1;
	}else{
		return 0;
	}
}

void evaluarNumerosSmith(int inicio, int fin){
	int cantidadNumeros = 0, i;
	printf("En el rango [%d, %d] se encontraron los siguientes número de Smith\n", inicio, fin);
	for(i = inicio; i <= fin; i++){
		if(esSmith(i)){
			cantidadNumeros++;
			printf("%d ", i);
		}
	}
	printf("\nEn total hay %d número de Smith\n", cantidadNumeros);
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

int siguientePrimo(int n){
	do{
		n++;
	}while(!esPrimo(n));
	return n;
}

int sumaExponentes(int numero){
	int i = siguientePrimo(1), sumaExponente = 0, copiaNum = numero;
	while(numero > 0 && i < copiaNum){
		if(numero%i == 0){
			numero /= i;
			if(i > 10){
				sumaExponente += sumaDigito(i);
			}else{
				sumaExponente += i;
			}
		}else{
			i = siguientePrimo(i);
		}
	}
	return sumaExponente;
}
