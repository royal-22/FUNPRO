#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define G 9.80

int validarDatos(double masaA,double masaB,int angulo);
void calcularVariaciones(int variaciones, double masaA, double masaB, int angulo, double *inicioMovimiento);
double calcularAceleracion(double masaA, double masaB, int angulo, double fuerza);

int main(){
	int centinela = 1, i = 0, angulo, j = 0, variaciones;
	double inicioMovimiento, masaA, masaB;
	char nuevaIteracion;
	while(centinela){
		printf("Ingrese el número de variaciones de la fuerza para las pruebas a realizar: ");
		scanf("%d", &variaciones);
		if(variaciones > 0){
			do{
				if(j > 0){
					printf("Las masa deben ser mayor a cero y el ángulo mayor a cero y menor a noventa\n");
					printf("Ingrese nuevamente la prueba %d\n", i + 1);
				}
				printf("Ingrese la masa del cuerpo A en kg de la prueba %d: ", i + 1);
				scanf("%lf", &masaA);
				printf("Ingrese la masa del cuerpo B en kg de la prueba %d: ", i + 1);
				scanf("%lf", &masaB);
				printf("Ingrese el ángulo de la plataforma en grados de la prueba %d: ", i + 1);
				scanf("%d", &angulo);
				j++;
			}while(!(validarDatos(masaA, masaB, angulo)));
			
			printf("Los resultados de un sistema con masas de %lf kg y %lf kg y un ángulo de %d grados son: \n", masaA, masaB, angulo);
			calcularVariaciones(variaciones, masaA, masaB, angulo, &inicioMovimiento);
			if(inicioMovimiento < 0){
				printf("El sistema no avanzó con ninguna dee las fuerzas probadas.\n");
			}else{
				if(inicioMovimiento == (double)10){
					printf("El sistema avanzó desde la primera fuerza probada.\n");
				}else{
					printf("El sistema no avanzó inicialmente, pero a partir de una fuerza de %.2lf empezó a avanzar\n", inicioMovimiento);
				}
			}
			
		}else{
			printf("El número de variaciones de la fuerza debe ser mayor que cero\n");
			centinela = 0;
			break;
		}
		printf("Desea realizar una nueva iteracion (S / N): ");
		scanf("%c", &nuevaIteracion);
		if(nuevaIteracion == 'S' || nuevaIteracion == 's'){
			
		}else{
			centinela = 0;
		}
		i++;
	}
	
	return 0;
}

double calcularAceleracion(double masaA, double masaB, int angulo, double fuerza){
	double anguloR = angulo * PI / 180;
	return (fuerza - masaA * G * sin(anguloR)) / (masaA + masaB);
}


void calcularVariaciones(int variaciones, double masaA, double masaB, int angulo, double *inicioMovimiento){
	int i;
	double aceleracion, fuerza;
	*inicioMovimiento = -40;
	for(i = 1; i <= variaciones; i++){
		fuerza = 10 * i;
		aceleracion = calcularAceleracion(masaA, masaB, angulo, fuerza);
		printf("Con una fuerza de %.2lf N se obtiene una aceleración de %.2lf", fuerza, aceleracion);
		if(aceleracion > 0){
			printf(" el sistema avanza\n");
			if(*inicioMovimiento < 0){
				*inicioMovimiento = fuerza;
			}
		}else{
			printf(" el sistema no avanza");
		}
	}
}



int validarDatos(double masaA,double masaB,int angulo){
	return (masaA > 0 && masaB > 0 && angulo > 0 && angulo < 90);
}
