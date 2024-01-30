#include <stdio.h>
#include <math.h>
#define PI 3.141593
#define ERROR 0.0001

int main(){
	char opcion;
	int i=0;
	printf("Menu de operaciones\n");
	printf("-Aproximar el valor PI (A)\n");
	printf("-Calcular sumatoria (B)\n");
	printf("Ingrese la opcion: ");
	scanf("%c", &opcion);
	if(opcion == 'A' || opcion == 'B'){
		if(opcion == 'A'){
			int iteracionesA;
			double sumatoria = 0;
			printf("Ingrese la cantidad de veces que desea iterar: ");
			scanf("%d", &iteracionesA);
			if(iteracionesA > 10 || iteracionesA < 0){
				printf("Cantidad de iteraciones inválidas\n");
			}
			else{
				while(i < iteracionesA){
					sumatoria += (pow(-1, i) / pow(4, i)) * ( (double)2 / (4 * i + 1) + (double) 2/ (4 * i + 2) + (double) 1 / (4 * i + 3));
					i++;
				}
				printf("Con %d iteraciones el valor de PI es: %lf\n", iteracionesA, sumatoria);
				printf("El valor de Pi definido es: %lf\n", PI);
				if(fabs(PI - sumatoria) < ERROR){
					printf("El resultado obtenido es aceptado porque la diferencia es menor que %lf", ERROR);
				}
				else{
					printf("El resultado obtenido NO es aceptado porque la diferencia es mayor que %lf", ERROR);

				}
			}
		}
		else{
			int iteracionesB;
			double sumatoria = 0, xB;
			printf("Ingrese el valor de x: ");
			scanf("%lf", &xB);
			if(xB > 5 || xB < 0){
				printf("Valor de x inválido\n");
			}
			else{
				printf("Ingrese la cantidad de veces que desea iterar: ");
				scanf("%d", &iteracionesB);
				if(iteracionesB > 10 || iteracionesB < 0){
					printf("La cantidad de iteraciones inválida\n");
				}
				else{
					double factorial1 = 1, factorial2 = 1;
					while(i <= iteracionesB){
						if(i>=1){
							factorial1 *= (2 * i + 1) * (2 * i);
							factorial2 *= i;
						}

 						double numerador = (pow(0.5, i) * (factorial1));
						double termino1 = numerador / factorial2;
						double termino2 = PI / pow(xB, i);
						sumatoria += (termino1 + termino2);
						
						i++;
					}
					printf("El resultado de la sumatoria es %lf\n", sumatoria);
				}
				
			}
		}
	}
	else{
		printf("Opción inválida\n");
	}
	return 0;
}
