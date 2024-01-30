#include <stdio.h>
#include <math.h>

int sumaNumero(int numero, int digitos);

int main(){
	int numero1, digitos1, numero2, digitos2, sumaNumero1, sumaNumero2;
	printf("Ingrese el número y su cantida de dígitos: ");
	scanf("%d %d", &numero1, &digitos1);
	printf("Ingrese el número y su cantidad de dígitos: ");
	scanf("%d  %d", &numero2, &digitos2);
	if(numero1 > 0 && digitos1 > 0 && numero2 > 0 && digitos2 > 0){
		
		printf("Los datos son mayores a 0\n");
		
		if(numero1 >= pow(10, digitos1-1) && numero1 < pow(10, digitos1) && numero2 >= pow(10, digitos2-1) && numero2 < pow(10, digitos2)){
			printf("Los datos del primer número son válidos.\n");
			printf("Los datos del segundo número son válidos\n");
			sumaNumero1 = sumaNumero(numero1, digitos1);
			sumaNumero2 = sumaNumero(numero2, digitos2);
			if(sumaNumero1 == sumaNumero2){
				printf("El número es Junction\n");
			}else{
				printf("El número no es Junction\n");
			}
		}else{
			if(!(numero1 >= pow(10, digitos1-1) && numero1 < pow(10, digitos1)) && numero2 >= pow(10, digitos2-1) && numero2 < pow(10, digitos2)){
				printf("Los datos del primer número no son válidos.\n");
				printf("Los datos del segundo número son válidos\n");
			}else{
				if(!(numero2 >= pow(10, digitos2-1) && numero2 < pow(10, digitos2)) && numero1 >= pow(10, digitos1-1) && numero1 < pow(10, digitos1)){
					printf("Los datos del primer número son válidos.\n");
					printf("Los datos del segundo número no son válidos\n");
				}else{
					printf("Los datos del primer número no son válidos.\n");
					printf("Los datos del segundo número no son válidos\n");
				}
			}
		}
	}else{
		printf("Los datos deben ser mayores a 0\n");
	}
	return 0;
}

int sumaNumero(int numero, int digitos){
	int i = 0, x;
	int suma = numero;
	while(i < digitos){
		x = numero%10;
		suma += x;
		numero/=10;
		i++;
	}
	return suma;
}
