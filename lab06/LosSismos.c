#include <stdio.h>
#include <math.h>

void leerProfundidad(int *profundidad);
int validarProfundidad(int profundidad);
int validarTiempo(char tiempo);
double calcularMagnitud(double amplitud, double tiempo);
void grupoSismos(double magnitud, int *grupo1, int *grupo2, int *grupo3, int *grupo4, int *grupo5, int *grupo6, int *grupo7);

int main(){
	int profundidad, iteraciones, i, g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0, g6 = 0, g7 = 0;
	double tiempo, amplitud, magnitud;
	char opcion;
	printf("Ingrese la cantidad de sismos a evaluar: ");
	scanf("%d", &iteraciones);
	for(i = 0; i < iteraciones; i++){
		leerProfundidad(&profundidad);
		if(validarProfundidad(profundidad)){
			printf("Ingrese en que unidad ingresará el tiempo (m o s): ");
			scanf(" %c", &opcion);
			if(validarTiempo(opcion)){
				printf("Ingrese el tiempo: ");
				scanf("%lf", &tiempo);
				if(opcion == 'm' || opcion == 'M'){
					tiempo *= 0.001;
				}
				if(tiempo <= 30 && tiempo > 0){
					printf("Ingrese la amplitud en milimetros: ");
					scanf("%lf", &amplitud);
					if(amplitud > 0 && amplitud <= 750){
						magnitud = calcularMagnitud(amplitud, tiempo);
						printf("Magnitud = %lf", magnitud);
						grupoSismos(magnitud, &g1, &g2, &g3, &g4, &g5, &g6, &g7);
					}else{
						printf("La amplitud ingresada no se encuentra en el rango correcto\n");
					}
				}else{
					printf("El tiempo ingresado no se encuentra en el rango correcto\n");
				}
			}else{
				printf("La opción ingresada para el tiempo no es correcta\n");
			}
		}else{
			printf("Profundidad incorrecta - No es posible aplicar la escala de medición Richter\n");
		}
		printf("\n");
	}
	printf("Pertenece al Grupo1 = %d, Grupo2 = %d, Grupo3 = %d, Grupo4 = %d, Grupo5 = %d, Grupo6 = %d y Grupo7 = %d", g1, g2, g3, g4, g5, g6, g7);
	
	
	return 0;
}

void grupoSismos(double magnitud, int *grupo1, int *grupo2, int *grupo3, int *grupo4, int *grupo5, int *grupo6, int *grupo7){
	if(magnitud >= 2){
		if(magnitud < 2.9){
			(*grupo2)++;
		}else{
			if(magnitud <3.9){
				(*grupo3)++;
			}else{
				if(magnitud < 4.9){
					(*grupo4)++;
				}else{
					if(magnitud < 5.9){
						(*grupo5)++;
					}else{
						if(magnitud < 6.9){
							(*grupo6)++;
						}else{
							(*grupo7)++;
						}
					}
				}
			}
		}
	}else{
		(*grupo1)++;
	}
}

double calcularMagnitud(double amplitud, double tiempo){
	return log10(amplitud * pow(tiempo, 3) / 1.62);
}

int validarTiempo(char tiempo){
	return tiempo == 'M' || tiempo == 'm' || tiempo == 's' || tiempo == 'S';
}

int validarProfundidad(int profundidad){
	return profundidad > 0 && profundidad <= 400;
}

void leerProfundidad(int *profundidad){
	printf("Ingrese la profundidad del sismo en Km: ");
	scanf("%d", profundidad);
}
