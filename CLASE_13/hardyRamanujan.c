#include <stdio.h>
#include <math.h>

int esPrimo(int num);
int evaluarSiEsHarshad(int num);
int evaluarSiEsCarmichael(int num);
int evaluarSiEsRamanujan(int num);

int main(){
	int inicio, fin, i, esCarmichael, esHarshad, esRamanujan;
	printf("Ingrese el rango de valores: ");
	scanf("%d %d", &inicio, &fin);
	if(fin > inicio){
		for(i = inicio; i <= fin; i++){
			printf("%d ", i );
			if(evaluarSiEsCarmichael(i) || evaluarSiEsHarshad(i) || evaluarSiEsRamanujan(i)){
				printf("El número %d es: ", i);
				if(evaluarSiEsCarmichael(i)){
					printf("Carmichael ");
				}
				if(evaluarSiEsHarshad(i)){
					printf("Harshad ");
				}
				if(evaluarSiEsRamanujan(i)){
					printf("Ramanujan ");
				}
				printf("\n");
			}
		}           
	}else{
		printf("Rango de datos incorrectos\n");
	}
	return 0;
}

int evaluarSiEsRamanujan(int num){
	int i, j, contadorFormas = 0, limite = pow(num, (float)1/3);
	for(i = 1; i <= limite; i++){
		for(j = i; j <= limite; j++){
			if((int)pow(i, 3) + (int)pow(j, 3) == num){
				contadorFormas++;
			}
		}
	}
	return contadorFormas == 2;
}

int evaluarSiEsCarmichael(int num){
	int divisor1, divisor2, divisor3, i, j, k, max = num / (2 * 3 * 5);
	for(i = 2; i < max; i++){
		if(esPrimo(i)){
			for(j = i + 1; j < max; j++){
				if(esPrimo(j)){
					for(k = j + 1; k < max; k++){
						if(esPrimo(k)){
							if(num == divisor1 * divisor2 * divisor3){
								divisor1 = i;
								divisor2 = j;
								divisor3 = k;
							}
						}
					}
				}
			}	
		}
		
	}
	return ((num - 1) % (divisor1 - 1) == 0) && ((num - 1) % (divisor2 - 1) == 0) && ((num - 1) % (divisor3 - 1) == 0);
}

int evaluarSiEsHarshad(int num){
	int digito, suma = 0, copiaNum = num;
	while(num > 0){
		digito = num % 10;
		num /= 10;
		suma += digito;
	}
	return copiaNum % suma == 0;
}


int esPrimo(int num){
	int i = 1, divisores = 0;
	while(i <= num){
		if(num % i == 0){
			divisores++;
		}
		i++;
	}
	return divisores == 2;
}
