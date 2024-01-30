#include <stdio.h>
#include <math.h>
int comprobarCifras(double numero, int cifras);
void calcularBases(double numero, int cifras);
void MayorSumaCifras(double numero, int cifras, int *mayor, int *sumaCifras); 
int main(){
	double numero;
	int cifras;
	printf("Ingrese el número: ");
	scanf("%lf", &numero);
	printf("Ingrese el número de cifras del número ingresado: ");
	scanf("%d", &cifras);
	
	if(comprobarCifras(numero, cifras)){
		calcularBases(numero, cifras);
	}
	else{
		printf("La cantidad de cifras ingresadas no concuerda con la cantidad de cifras del número.\n");
	}
	
	return 0;
}

void MayorSumaCifras(double numero, int cifras, int *mayor, int *sumaCifras){
	int i;
	*mayor = 0;
	*sumaCifras = 0;
	for(i = 0; i < cifras; i++){
		int n = (int) numero % 10;
		numero /= 10;
		*sumaCifras += n;
		if(n > *mayor){
			*mayor = n;
		}
	}	
}


void calcularBases(double numero, int cifras){
	int mayor, sumaCifras;
	MayorSumaCifras(numero, cifras, &mayor, &sumaCifras);
	printf("La suma de cifras del número es %d y la cifra mayor es %d.\n", sumaCifras, mayor);
	int j, numeroBases;
	numeroBases = 0;
	for(j = mayor; j <= 10; j++){
		if(sumaCifras%(j-1) == 0){
			printf("La base %d es una base que cumple la propiedad, porque la suma de cifras del número es divisible por %d.\n", j, j-1);
			numeroBases ++;
		}
	}
	if(numeroBases > 0){
		printf("La cantidad total de bases encontradas fue: %d.\n", numeroBases);
	}
	else{
		printf("No se encontró ninguna base que cumpla con la propiedad.\n");
	}
}

int comprobarCifras(double numero, int cifras){
	int nCifras = log10(numero);
	return cifras == (nCifras+1) && cifras <= 6 && cifras >= 3;
}
