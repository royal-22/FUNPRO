#include <stdio.h>

int esPrimo(int n);
int siguientePrimo(int n);
void imprimirPrimos(int opcion, int iteraciones, int diferencia);

int main(){
	int opcion, iteraciones, diferencia;
	printf("Seleccione una opción: \n");
	printf("(1) Listado\n");
	printf("(2) Consecutivos\n");
	printf("(3) Trillizos\n");
	printf("(4) Salir\n");
	printf("¿Opción?: ");
	scanf("%d", &opcion);
	if(opcion >= 1 && opcion <= 3){
		printf("Ingrese la cantidad de elementos a imprimir: ");
		scanf("%d", &iteraciones);
		if(iteraciones > 0){
			if(opcion == 1){
				printf("Impresión de números primos\n");
				imprimirPrimos(opcion, iteraciones, 0);
			}else{
				if(opcion == 2){
					printf("Ingrese la diferencia entre primos: ");
					scanf("%d", &diferencia);
					if(diferencia > 1){
						printf("Impresión de par de primos consecutivos\n");
						imprimirPrimos(opcion, iteraciones, diferencia);
					}
				}else{
					printf("Impresión de tripletas de primos trillizos\n");
					imprimirPrimos(opcion, iteraciones, 0);
				}
			}
		}else{
			printf("Los datos de ejecución son incorrectos\n");
		}
		
		
	}else{
		if(opcion == 4){
			printf("Salir del programa");
		}else{
			printf("Ha ingresado una opción inválida\n");
		}
	}
	return 0;
}
void imprimirPrimos(int opcion, int iteraciones, int diferencia){
	int impresiones = 0, primo1 = 1, primo2, primo3;
	do{
		primo1 = siguientePrimo(primo1);
		if(opcion == 1){
			printf("%d ", primo1);
			impresiones++;
		}else{
			if(opcion == 2){
				primo2 = siguientePrimo(primo1);
				if(primo2 - primo1 == diferencia){
					printf("(%d, %d) ", primo1, primo2);
					impresiones++;
				}
			}else{
				primo2 = siguientePrimo(primo1);
				primo3 = siguientePrimo(primo2);
				if(primo2 - primo1 == 4 && primo3 - primo2 == 2){
					printf("(%d, %d, %d) ", primo1, primo2, primo3);
					impresiones++;
				}
			}
		}
	}while(impresiones < iteraciones);
}

int siguientePrimo(int n){
	do{
		n++;
	}while(!esPrimo(n));
	return n;
}

int esPrimo(int n){
	int contador = 0, i = 1;
	do{
		if(n%i == 0){
			contador++;
		}
		i++;
	}while(i<=n);
	return contador == 2;
}



