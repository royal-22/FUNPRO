#include <stdio.h>

int esOndulado(int num);
void esLibreCuadrados(int num, int *libreCuadrados);
int esPrimo(int n);
int siguientePrimo(int n);
void evaluarNumerosOndulados(int inicio, int fin);

int main(){
	int inicio, fin;
	printf("Ingrese un rango. Los números deben de tener al menos tres cifras: ");
	scanf("%d %d", &inicio, &fin);
	if(fin > inicio && inicio > 99 && fin > 99){
		evaluarNumerosOndulados(inicio, fin);
	}else{
		printf("Rango incorrecto\n");
	}
	return 0;
}

int esPrimo(int n){
	int i = 1, divisores = 0;
	while(i <= n){
		if(n % i == 0){
			divisores++;
		}
		i++;
	}
	return divisores == 2;
}

int siguientePrimo(int n){
	do{
		n++;
	}while(!(esPrimo(n)));
	return n;
}

void esLibreCuadrados(int num, int *libreCuadrados){
	int copiaNum = num, i = 0, divisor = siguientePrimo(1), divisorA;
	*libreCuadrados = 1;
	printf("[");
	while(num > 0 && divisor <= copiaNum){
		if(num % divisor == 0){
			printf("%d ", divisor);
			num /= divisor;
			if(i == 0){
				divisorA = divisor;
			}else{
				if(divisor == divisorA){
					*libreCuadrados = 0;
				}else{
					divisorA = divisor;
				}
			}
		}else{
			divisor = siguientePrimo(divisor);
		}
		i++;
	}
	printf("]");
}

int esOndulado(int num){
	int i = 0, digito, d1, d2;
	while(num > 0){
		digito = num % 10;
		if(i % 2 == 0){
			if(i == 0){
				d1 = digito;
			}else{
				if(digito != d1){
					return 0;
				}
			}
		}else{
			if(i == 1){
				d2 = digito;
			}else{
				if(digito != d2){
					return 0;
				}
			}
		}
		i++;
		num /= 10;
	}
	if(d1 == d2){
		return 0;
	}
	return 1;
}


void evaluarNumerosOndulados(int inicio, int fin){
	int i, libreCuadrados, numerosOndulados = 0, numerosLibresCuadrados = 0;
	printf("En el rango [%d, %d] se encontraron los siguientes números ondulados clasificados\n", inicio, fin);
	for(i = inicio; i < fin; i++){
		if(esOndulado(i)){
			printf("%d ", i);
			esLibreCuadrados(i, &libreCuadrados);
			numerosOndulados++;
			if(libreCuadrados){
				printf("Además de ondulado también es un número libre de cuadrados");
				numerosLibresCuadrados++;
			}
			printf("\n");
		}
		
	}
	if(numerosOndulados > 0){
		printf("En total hay %d ondulados libre de de cuadros de un total de %d\n", numerosLibresCuadrados, numerosOndulados);
	}else{
		printf("En el rango ingresado no hay números primos ondulados\n");
	}
}
