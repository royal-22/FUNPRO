#include <stdio.h>
#include <math.h>

void primeraUltimaCifra(int num, int *primero, int *ultimo);
int evaluarPernicioso(int numero,int *cantUnos, double *binario, int *esPernicioso);
int esPrimo(int n);
int calcularInverso(int numero);

int main(){
	int centinela = 1, numero, esPernicioso, cantUnos, inverso, primero, ultimo;
	
	while(centinela){
		printf("Ingrese el número a evaluar: ");
		scanf("%d", &numero);
		if(numero == 0){
			centinela = 0;
			break;
		}else{
			if(numero > 0){
				/*Evaluar pernicioso*/
				cantUnos = 0;
				double binario = 0;
				evaluarPernicioso(numero, &cantUnos, &binario, &esPernicioso);
				if(esPernicioso){
					printf("El número es pernicioso porque %d = %.0lf tiene %d y %d es primo\n", numero, binario, cantUnos, cantUnos);
				}
				/*Evaluar emirp*/
				inverso = calcularInverso(numero);
				if(esPrimo(inverso) && esPrimo(numero)){
					printf("El número es emirp ya que %d es primo y %d es también primo\n", numero, inverso);
				}
				/*Evaluar gapful*/
				primeraUltimaCifra(numero, &primero, &ultimo);
				if(numero % (primero*10 + ultimo) == 0){
					printf("El número es gapful ya qeu %d es divisible entre %d\n", numero, primero*10 + ultimo);
				}
			}else{
				printf("Error al ingresar el número\n");
			}
		}
	}
	
	return 0;
}

int evaluarPernicioso(int numero,int *cantUnos, double *binario, int *esPernicioso){
	int cantCifras = (int)log10(numero) + 1, i = 0, digito;
	while(numero > 0){
		digito = numero % 2;
		numero /= 2;
		if(digito == 1){
			(*cantUnos)++;
		}
		(*binario) += digito * (int)pow(10, i);
		i++;
		printf("%d\n", digito);
	}
	printf("%d\n", *cantUnos);
	if(esPrimo(*cantUnos)){
		*esPernicioso = 1;
	}else{
		*esPernicioso = 0;
	}
}

void primeraUltimaCifra(int num, int *primero, int *ultimo){
	int i = 0, digito;
	while(num > 0){
		digito = num % 10;
		if(i == 0){
			*ultimo = digito;
		}
		if(num < 10){
			*primero = digito;
		}
		i++;
		num /= 10;
	}
}

/*
----------------------------- Tabla de datos------------------------------------
iteracion      i        digito        num        primero       ultimo
    0          0          ND          92736        ND            ND
    1		   1          6           9273         ND            6
    2          2          3           927          ND            6
    3          3          7           92           ND            6
    4          4          2           9            ND            6
    5          5          9           0.9          9             6
*/


int esPrimo(int n){
	int i = 1, cantDivisores = 0;
	while(i <= n){
		if(n%i == 0){
			cantDivisores++;
		}
		i++;
	}
	return cantDivisores == 2;
}

int calcularInverso(int numero){
	int i = 0, inverso = 0, cantCifras, digito;
	cantCifras = (int)log10(numero) + 1;
	while(numero > 0){
		digito = numero % 10;
		numero /= 10;
		inverso += digito * (int) pow(10, cantCifras - 1 - i);
		i++;
	}
	return inverso;
}


