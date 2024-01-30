#include <stdio.h>
#include <math.h>

int main(){
	int numero, i = 0, patron;
	printf("Ingrese el número a evaluar: ");
	scanf("%d", &numero);
	
	if(numero >= 1000 && numero <= 9999){
		printf("Ingrese el patrón: ");
		scanf("%d", &patron);
		if(patron<=9 && patron>= 1){
		int mayor = 0, menor = 9, numeroInvertido = 0, pares=1, impares = 0, x, cifrado;	
			while(i < 4){
				x = numero%10;
				if(x >= mayor){
					mayor = x;
				}
				if(x <= menor){
					menor = x;
				}
				numeroInvertido += x * pow(10, 4 - i- 1);
				
				if(i%2 == 0){
					impares += x;
					printf("Pares %d\n", pares);
				}else{
					pares *= x;
					printf("Impares %d\n", impares);
				}
				numero/=10;
				i++;
			}
			
			printf("Eldigito mayor es %d y el dígito menor es %d\n", mayor, menor);
			printf("El número invertido es: %d\n", numeroInvertido);
			cifrado = mayor * patron + pow(menor, patron) - impares * pares - numeroInvertido;
			printf("El número encriptado es: %d", cifrado);
		}else{
			printf("Ingresó un patrón incorrecto.\n");
		}
	}else{
		printf("Ingresó un número que no tiene 4 dígitos.\n");
	}
	return 0;
}
