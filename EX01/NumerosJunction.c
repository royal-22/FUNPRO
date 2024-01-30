#include <stdio.h>

int main(){
	
	printf("Ingrese el número y su cantida de dígitos: ");
	scanf("%d %d", &numero1, &digitos1);
	printf("Ingrese el número y su cantidad de dígitos: ");
	scanf("%d  %d", &numero2, digitos2);
	if(numero1 > 0 && digitos1 > 0 && numero2 > 0 && digitos2 > 0){
		printf("Los datos son mayores a 0\n");
		if(numero1 >= pow(10, digitos1-1)) && numero1 < pow(10, digitos1) && numero2 >= pow(10, digitos2-1)) && numero2 < pow(10, digitos2){
			
		}else{
			if(!(numero1 >= pow(10, digitos1-1)) && numero1 < pow(10, digitos1))){
				printf("Los datos del primer número no son válidos.");
				printf("Los datos del segundo número son v+alidos")
			}
		}
	}else{
		printf("Los datos deben ser mayores a 0\n");
	}
	return 0;
}
