#include <stdio.h>
#include <math.h>

void calcularNumerosEsteticos(int inicio, int fin, int *existenEsteticos, int *cantEsteticos);
int cambioBase(int num, int base);

int main(){
	int inicio, fin, existenNumerosEsteticos, cantEsteticos;
	while(1){
		printf("Ingrese el rango: ");
		scanf("%d %d", &inicio, &fin);
		if(inicio == 0 && fin == 0){
			break;
		}else{
			if(fin >= inicio && fin > 0 && inicio > 0){
				calcularNumerosEsteticos(inicio, fin, &existenNumerosEsteticos, &cantEsteticos);
				if(existenNumerosEsteticos){
					printf("En el rango [%d %d] se encontraron %d números estéticos\n", inicio, fin, cantEsteticos);
				}else{
					printf("No existen números estéticos en el rango [%d %d]\n", inicio, fin);
				}
			}else{
				printf("El rango ingresado no es válido\n");
			}
		}
	}
	return 0;
}

int esEstetico(int num){
	int i = 0, d1, d2;
	while(num > 0){
		if(num < 10){
			return 1;
		}else{
			d1 = num % 10;
			num /= 10;
			d2 = num % 10;
			if(abs(d1 - d2) != 1){
				return 0;
			}
		}
	}
	return 1;
}

int cambioBase(int num, int base){
	int nuevoNum = 0, d, exponente = 0;
	while(num > 0){
		d = num % base;
		num /= base;
		nuevoNum += d * (int)pow(10, exponente);
		exponente++;
	}
	return nuevoNum;
}

void calcularNumerosEsteticos(int inicio, int fin, int *existenEsteticos, int *cantEsteticos){
	int i, base, nuevoNum, contador; 
	*cantEsteticos = 0;
	for(i = inicio; i <= fin; i++){
		contador = 0;
		for(base = 2; base <= 10; base++){
			nuevoNum = cambioBase(i, base);

			if(esEstetico(nuevoNum)){
				contador++;
				if(contador == 1){
					printf("%d = %d (%d) , ", i, nuevoNum, base);
				}else{
					printf("%d (%d), ", nuevoNum, base);
				}
			}
		}
		if(contador > 0){
			(*cantEsteticos)++;
			*existenEsteticos = 1;
			printf("\n");
		}
	}
}
