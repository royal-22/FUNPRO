#include <stdio.h>

void calcularCifrasParesImpares(int numero, int *cifrasPares, int *cifrasImpares);
int esPrimo(int n);
int sumaDigitos(int numero);

int main(){
	int numero, prediccionCombinaciones, i, combinacionesEncontradas = 0, cifrasPares = 0, cifrasImpares = 0, complemento;
	printf("Ingrese un número: ");
	scanf("%d", &numero);
	printf("Ingrese la cantidad de combinaciones que piensa encontrar: ");
	scanf("%d", &prediccionCombinaciones);
	if(numero > 0 && numero <= 1000 && prediccionCombinaciones < numero){
		if(esPrimo(numero)){
			for(i = 0; i < numero; i++){
				complemento = numero - i;
				if(sumaDigitos(i) == sumaDigitos(complemento) && i > complemento){
					printf("%d + %d = %d\n", i, complemento, numero);
					combinacionesEncontradas++;
				}
			}	
		}
		
		if(combinacionesEncontradas > 0){
			printf("El número %d es dócil y primo y se encontraron %d combinaciones\n", numero, combinacionesEncontradas);
			if(combinacionesEncontradas == prediccionCombinaciones){
				printf("Adivinaste la cantidad de combinaciones\n");
			}else{
				printf("No adivinaste la cantidad de combinaciones\n");
			}	
			calcularCifrasParesImpares(numero, &cifrasPares, &cifrasImpares);		
			printf("La cantidad de dígitos pares del número ingresado es: %d\n", cifrasPares);
			printf("La cantidad de dígitos impares del número ingresado es: %d\n", cifrasImpares);
		}else{
			printf("El número %d NO es dócil y primo\n");
		}
		
	}else{
		printf("Los datos ingresados no son correctos\n");
	}
	return 0;
}

int sumaDigitos(int numero){
	int suma = 0;
	while(numero > 0){
		suma += (numero % 10);
		numero /= 10;
	}
	return suma;
}

int esPrimo(int n){
	int i = 1, cantDivisores = 0;
	while(i <= n){
		if(n % i == 0){
			cantDivisores++;
		}
		i++;
	}
	return cantDivisores == 2;
}

void calcularCifrasParesImpares(int numero, int *cifrasPares, int *cifrasImpares){
	int digito;
	while(numero > 0){
		digito = numero % 10;
		if(digito % 2 == 0){
			(*cifrasPares)++;
		}else{
			(*cifrasImpares)++;
		}
		numero /= 10;
	}
}
