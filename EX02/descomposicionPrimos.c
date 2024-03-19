#include <stdio.h>
#include <math.h>

void obtenerFactoresOpcion1(int num);
void obtenerFactoresOpcion2(int num);
void descomposicionPrimos(int factor, int num, int *esDivisible, int *cantVeces);
int esPrimo(int n);
int siguientePrimo(int n);

int main(){
	int opc, num;
	while(1){
		printf("Menú de opciones: \n");
		printf("1. Descomposición de factores primos\n");
		printf("2. Descomposición de factores primos con exponentes\n");
		printf("3. Salir\n");
		printf("\n");
		printf("Ingrese una opción: ");
		scanf("%d", &opc);
		if(opc == 3){
			break;
		}
		if(opc == 2 || opc == 1){
			printf("Ingrese número: ");
			scanf("%d", &num);
			if(num > 1){
				if(opc == 1){
					obtenerFactoresOpcion1(num);
				}else{
					obtenerFactoresOpcion2(num);
				}
			}else{
				printf("Debe de ingresar un número mayor que 1\n");
			}
		}else{
			printf("La opción ingresada es incorrecta\n");
		}
		printf("\n");
	}
	return 0;
}

void descomposicionPrimos(int factor, int num, int *esDivisible, int *cantVeces){
	*cantVeces = 0, *esDivisible = 0;
	while(1){
		if(num % factor == 0){
			*esDivisible = 1;
			(*cantVeces)++;
			num /= factor;
		}else{
			break;
		} 
	}
}

void obtenerFactoresOpcion2(int num){
	int cantVeces2, i = siguientePrimo(1), divisible, k, primeraVez2 = 1;
	printf("%d = ", num);
	while(num > 1){
		descomposicionPrimos(i, num, &divisible, &cantVeces2);
		if(divisible){
			if(!primeraVez2){
				printf("x ");
			}else{
				primeraVez2 = 0;
			}
			printf("%d", i);
			if(cantVeces2 > 1){
				printf("^%d ", cantVeces2);
			}
			num /= (int)pow(i, cantVeces2);
		}
		i = siguientePrimo(i);
	}
	printf("\n");
}

void obtenerFactoresOpcion1(int num){
	int cantVeces, i = siguientePrimo(1), divisible, j, primeraVez = 1;
	printf("%d = ", num);
	while(num > 1){
		descomposicionPrimos(i, num, &divisible, &cantVeces);
		if(divisible){
			for(j = 1; j <= cantVeces; j++){
				if(!primeraVez){
					printf("x ");
				}else{
					primeraVez = 0;
				}
				printf("%d ", i);				
			}
			num /= (int)pow(i, cantVeces);
		}
		i = siguientePrimo(i);
	}
	printf("\n");
}

int siguientePrimo(int n){
	do{
		n++;
	}while(!esPrimo(n));
	return n;
}

int esPrimo(int n){
	int i, cantDivisores = 0;
	for(i = 1; i <= n; i++){
		if(n % i == 0){
			cantDivisores++;
		}
	}
	return cantDivisores == 2;
}
