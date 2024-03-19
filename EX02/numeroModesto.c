#include <stdio.h>
#include <math.h>

int validarRango(int inicio, int fin);
int calcularCifras(int num);
void validarNumeroModesto(int num, int *esModesto, int *iteracion, int *a, int *b);

int main(){
	int inicio, fin, esModesto, iteracion, a, b, i, contadorNumeros = 0;
	printf("Ingrese el rango de inicio y fin: ");
	scanf("%d %d", &inicio, &fin);
	if(validarRango(inicio, fin)){
		for(i = inicio; i <= fin; i++){
			esModesto = 0;
			validarNumeroModesto(i, &esModesto, &iteracion, &a, &b);
			if(esModesto){
				contadorNumeros++;
				printf("El número %d es modesto\n", i);
				printf("En el intento %d se encontró la combinación que hace que la propiedad se cumpla\n", iteracion);
				printf("a = %d y b = %d, el residua de %d / %d = %d\n", a, b, i, b, a);
			}
		}
		printf("RESUMEN\n");
		printf("En total se encontraron %d números modestos dentro del rango\n", contadorNumeros);
	}else{
		printf("Datos incorrectos");
	}
	return 0;
}

void validarNumeroModesto(int num, int *esModesto, int *iteracion, int *a, int *b){
	int i, cifras = calcularCifras(num), n1, n2; 
	for(i = cifras; i > 0; i--){
		n1 = num / (int)pow(10, i - 1);
		n2 = num % (int)pow(10, i - 1);
		if(n1 != 0 && n2 != 0 && num % n2 == n1){
			*esModesto = 1;
			*a = n1;
			*b = n2;
			*iteracion = cifras - i + 1;
			break;
		}
	}
	if(*esModesto != 1){
		*esModesto = 0;
	}
}

int calcularCifras(int num){
	return (int)log10(num) + 1;
}

int validarRango(int inicio, int fin){
	return fin > inicio && inicio > 9 && fin < (int)pow(10, 6);
} 
