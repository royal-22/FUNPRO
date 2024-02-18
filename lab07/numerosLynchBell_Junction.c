#include <stdio.h>
#include <math.h>

int esNumeroLynchBell(int num);
int esNumeroJunction(int num);
void cifrasNumero(int numero, int *centena, int *decena, int *unidad);

int main(){
	char opcion;
	int numero;
	printf("Menú de opciones:\n");
	printf("J: Números Junction\n");
	printf("L: Números de Lynch-Bell\n");
	printf("\n");
	printf("Ingrese una opción: \n");
	scanf(" %c", &opcion);
	if(opcion == 'J' || opcion == 'L'){
		printf("Ingrese un número: ");
		scanf("%d", &numero);
		if(numero > 0 && numero < 1000){
			if(opcion == 'J'){
				if(esNumeroJunction(numero)){
					printf("\nEl número %d es Junction\n", numero);
				}else{
					printf("\nEl número %d NO es Junction\n", numero);
				}
			}else{
				if(esNumeroLynchBell(numero)){
					printf("\nEl número %d es Lynch-Bell\n", numero);
				}else{
					printf("\nEl número %d NO es Lynch-Bell\n", numero);
				}
			}
		}else{
			printf("El número ingresado es inválido\n");
		}
	}else{
		printf("Opción inválida\n");
	}
	
	return 0;
}

void cifrasNumero(int numero, int *centena, int *decena, int *unidad){
	*centena = numero/100;
	*unidad = numero%10;
	*decena = (numero%100)/10;
}

int esNumeroJunction(int num){
	int centena, decena, unidad, i = num - 27, try, contador = 0;
	
	do{
		cifrasNumero(i, &centena, &decena, &unidad);
		try = i + centena + decena + unidad;
		if(try == num){
			printf("%d + %d + %d + %d = %d\n", i, unidad, decena, centena, num);
			contador ++;
		}
		i++;
	}while(i < num);
	return contador >= 2;
}

int esNumeroLynchBell(int num){
	int i = 0, numCifras = log10(num) + 1, divisores = 0, copiaNum;
	int digito;
	do{
		digito = num%10;
		if(copiaNum%num == 0 && digito != 0){
			printf("%d es divisible por %d\n", copiaNum, digito);
			divisores++;
		}else{
			printf("%d no es divisible por %d\n", copiaNum, digito);
		}
		num/= 10;
	}while(num != 0);
	return divisores == 3;
}
