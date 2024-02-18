#include <stdio.h>
#include <math.h>

int evaluarDato(int n);
int esPrimo(int n);
void imprimirDatos(int n, int *inicioPrimoPos, int *finPrimoPos, int *existeSecuencia);
int anteriorPrimo(int n);

int main(){
	int n, inicioPrimo, finPrimoPos, inicioPrimoPos, primerPrimo, existeSecuencia, i, j, numeroPrimoI, numeroPrimoJ;
	printf("Ingrese el número para evaluar si cumple con la secuencia de cuadrados primos: ");
	scanf("%d", &n);
	if(evaluarDato(n)){
		printf("k    (k^2) mod p    S\n");
		printf("-----------------------\n");
		imprimirDatos(n, &inicioPrimoPos, &finPrimoPos, &existeSecuencia);
		if(existeSecuencia){
			printf("La secuencia de primos inicia en k = %d y termina en k = %d\n", inicioPrimoPos, finPrimoPos);
			printf("Números descendentes en la secuencia de primos: ");
			j = finPrimoPos;
			for(i = inicioPrimoPos; i <= (finPrimoPos + inicioPrimoPos)/2; i++){
				numeroPrimoI = (int) pow(i, 2) % n;
				numeroPrimoJ = (int) pow(j, 2) % n;
				if(numeroPrimoJ == numeroPrimoI){
					printf(" %d ", numeroPrimoI);
				}
				j--;
			}
		}else{
			printf("El número %d no cumple con la secuencia de cuadrados primos\n", n);
		}
	}else{
		printf("El número ingresado no es válido\n");
	}
	return 0;
}
void imprimirDatos(int n, int *inicioPrimoPos, int *finPrimoPos, int *existeSecuencia){
	int i, cantPrimos = 0, valor, primerPrimo;
	char s;
	*existeSecuencia = 0;
	for(i = 0; i <= n; i++){
		valor  = (int) pow(i, 2) % n;
		if(esPrimo(valor)){
			if(cantPrimos == 0){
				*inicioPrimoPos = i;
				primerPrimo = valor;
			}
			if(valor == primerPrimo && i - *inicioPrimoPos > 1){
				*existeSecuencia = 1;
				*finPrimoPos = i;
			}
			s = 'P';
			cantPrimos++;
		}
		else if(valor == 0){
			s = '0';
		}
		else if(valor == 1){
			s = '1';
		}else{
			s = 'C';
		}
		if(i < 10){
			printf(" %d", i);
		}else{
			printf("%d", i);
		}
		if(valor < 10){
			printf("        %d       %c\n", valor, s);
		}else{
			printf("       %d       %c\n", valor, s);
		}
		
	}
}

int anteriorPrimo(int n){
	do{
		n--;
	}while(!esPrimo(n));
	return n;
}

int evaluarDato(int n){
	return (esPrimo(n) && n > 0 && n < 50);
}

int esPrimo(int n){
	int i = 1, contador = 0;
	while(i <= n){
		if(n % i == 0){
			contador++;
		}
		i++;
	}
	return contador == 2;
}
