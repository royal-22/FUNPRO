#include <stdio.h>
#include <math.h>

int esPrimo(int num);
int esNumeroMPrimo(int num);
int esNumeroAlReves(int num);
void primerUltimoDigito(int num, int digitos, int *n1, int *n2);

int main(){
	char opcion;
	int numero;
	printf("Menú de opciones:\n");
	printf("M: Números primos m-punteros.\n");
	printf("R: Números al revés\n");
	printf("\n");
	printf("Ingrese una opción: \n");
	scanf(" %c", &opcion);
	
	if(opcion == 'M' || opcion == 'R'){
		printf("Ingrese el número: ");
		scanf("%d", &numero);
		if(opcion == 'M' && numero < 10000 && numero > 0){
			if(esPrimo(numero)){
				if(esNumeroMPrimo(numero)){
					printf("El número %d es un número primo m-puntero.\n", numero);
				}else{
					printf("El número %d no es un número primo m-puntero\n", numero);
				}
			}else{
				printf("El número ingresado no es primo\n");
			}
		}
		else if(opcion == 'R' && numero > 0){
			if(esNumeroAlReves(numero)){
				printf("El número %d es un número al revés.\n", numero);
			}else{
				printf("El número %d no es un número al revés,\n", numero);
			}
		}else{
			printf("El número ingresado es inválido\n");
		}
	}else{
		printf("Opción inválida\n");
	}
	return 0;
}

void primerUltimoDigito(int num, int digitos, int *n1, int *n2){
	*n1 = num / pow(10, digitos - 1);
	*n2 = num % 10;
}

int esNumeroAlReves(int num){
	int digitos = log10(num) + 1, copiaD = digitos, i = 0, n1, n2; 
	do{
		primerUltimoDigito(num, copiaD, &n1, &n2);
		printf("%d %d\n", n1, n2);
		if(n1 + n2 != 10){
			return 0;
		}
		num /= 10;
		num %= (int)pow(10, digitos - 2 - i * 2);
		copiaD -= 2;
		i++;
	}while(i < digitos/2);
	if(digitos%2 == 1){
		if(num == 5){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}

int esNumeroMPrimo(int num){
	int producto = 1, x, copiaNum = num;
	do{
		x = num%10;
		producto *= x;
		num/=10;
	}while(num != 0);
	return esPrimo(copiaNum + producto);
}

int esPrimo(int num){
	int i = 1, contador = 0;
	do{
		if(num%i == 0){
			contador++;
		}
		i++;
	}while(i <= num);
	return contador == 2;
}
