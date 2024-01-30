#include <stdio.h>
#include <math.h>
#define ERROR 0.0001

int main(){
	char opcion;
	printf("Men� de opciones\n");
	printf("-Aproximar ra�z c�bica (A)\n");
	printf("- Calcular sumatoria (B)\n");
	printf("Ingrese la opci�n: ");
	scanf("%c", &opcion);
	
	if(opcion == 'A' || opcion == 'B'){
		if(opcion == 'B'){
			int x, iteracionesB;
			printf("Ingrese el valor de x: ");
			scanf("%d", &x);
			printf("Ingrese la cantidad de veces que desea iterar: ");
			scanf("%d", &iteracionesB);
			if(iteracionesB < 0 || iteracionesB > 10 || x < 1 || x > 5){
				if(iteracionesB < 1 || iteracionesB > 5 ){
					printf("Cantidad de iteraciones inv�lida\n");
				}
				else{
					printf("Valor de x inv�lido.\n");
				}
			}
			else{
				int iB = 0;
				double sumatoria = 0;
				double factorial1, factorial2;
				
				while(iB <= iteracionesB){
					if(iB == 0){
						factorial1 = 1;
						factorial2 = 1;
					}
					else{
						factorial1 *= (2 * iB) * (2 * iB - 1);
						factorial2 *= (2 * iB + 1) * (2 * iB);
					}
					sumatoria += (pow(x, 2) / (factorial1) + pow(2 + iB, 2) / factorial2);
					iB++;
				
				}
				printf("El resultado de la sumatoria es: %lf\n", sumatoria);
			}
			
		}
		else{
			double a, raizCubicaP, raizCubicaF;
			int iteracionesA, iA;
			printf("Ingrese el n�mero cuya ra�z c�bica desea calcular: ");
			scanf("%lf", &a);
			printf("Ingrese la cantidad de veces que desea iterar: ");
			scanf("%d", &iteracionesA);
			if(iteracionesA > 50 || iteracionesA < 0 || a <= 0){
				if(a <= 0){
					printf("El n�mero debe ser mayor que cero.\n");
				}
				else{
					printf("Cantidad de iteraciones inv�lida.\n");
				}
			}
			else{
				iA = 0;
				raizCubicaF = 1;
				while(iA <= iteracionesA){
					raizCubicaF = ((double) 1 / 3 )* (a / pow(raizCubicaF, 2) + 2 * raizCubicaF);
					iA++;
				}
			}
			raizCubicaP = pow(a, (double)1/3);
			printf("La raiz c�bica de %lf es %lf\n", a, raizCubicaF);
			printf("La ra�z c�bica calculada con pow es: %lf", raizCubicaP);
			
			if(fabs(raizCubicaP - raizCubicaF) < ERROR){
				printf("El resultado obtenido es aceptado porque la diferencia es menor que %lf", ERROR);
			}
			else{
				printf("El resultado obtenido no es aceptado porque la diferencia es menor que %lf", ERROR);

			}
		}
	}
	else{
		printf("Opci�n inv�lida.\n");
	}
	
	return 0;
}
