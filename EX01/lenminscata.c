#include <stdio.h>
#include <math.h>
#define ERROR 0.0001
int validarDatos(double x1, double y1, double x2, double y2, char funcionTrig, char signo);
void coordenadasPolares(double x, double y, double *distancia, double *angulo);
void coeficiente(double distancia, double angulo, char funcionTrig, char signo, double *coeficiente);

int main(){
	double x1, y1, x2, y2, distancia1, angulo1, distancia2, angulo2, coeficiente1, coeficiente2, 
	distanciaFocos, longitud;
	char funcionTrig, signo;
	printf("Ingrese las coordenads de los puntos a evaluar (x1, y1) y (x2, y2): ");
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	printf("Ingrese si se usa coseno C o seno S en la lenmiscata: ");
	scanf("\n%c", &funcionTrig);
	printf("Ingrese el signo positivo + o negativo - en la lenminscata: ");
	scanf("\n%c", &signo);
	if(validarDatos(x1, y1, x2, y2, funcionTrig, signo)){
		/*Calcular el coeficiente de cada punto para determinar si pertenecen a la misma lenmiscata*/
		coordenadasPolares(x1, y1, &distancia1, &angulo1);
		coordenadasPolares(x2, y2, &distancia2, &angulo2);
		coeficiente(distancia1, angulo1, funcionTrig, signo, &coeficiente1);
		coeficiente(distancia2, angulo2, funcionTrig, signo, &coeficiente2);
		
		if(fabs(coeficiente1 - coeficiente2) < ERROR){
			printf("Los dos puntos ingresados pertenecen a la misma lenmiscata, siendo la ecuación: \n");
			if(funcionTrig = 'C'){
				printf("r^2 = %c%lf^2 * cos(2*angulo)\n", signo, coeficiente1);
			}else{
				printf("r^2 = %c%lf^2 * sen(2*angulo)\n", signo, coeficiente1);
			}
			distanciaFocos = sqrt(pow(coeficiente1, 2) / 2);
			longitud = 5.24412 * sqrt(2) * distanciaFocos;
			printf("La distancia entre focos los focos es: %lf\", distanciaFocos);
			printf("La longitud es: %lf\n", longitud);
			printf("Las ecuaciones paramétricas de la lenmiscata son: \n");
			printf("x = %lf * cos(t) / (sen^2(t) + 1)\n", distanciaFocos/2 * sqrt(2));
			printf("y = %lf * cos(t) * sen(t) / (sen^2(t) + 1)\n", distanciaFocos/2 * sqrt(2));
			
		}else{
			printf("Los puntos ingresados no pertenecen a la misma lenmiscata.\n");
		}
		
	}else{
		printf("Los datos ingresados son incorrectos.\n");
	}
	return 0;
}

void coeficiente(double distancia, double angulo, char funcionTrig, char signo, double *coeficiente){
	if(funcionTrig = 'C'){
		if(signo = '+'){
			*coeficiente = sqrt(pow(distancia, 2) / cos(2*angulo));	
		}else{
			*coeficiente = sqrt(-1 * pow(distancia, 2) / cos(2*angulo));
		}
		
	}else{
		if(signo = '+'){
			*coeficiente = sqrt(pow(distancia, 2) / sin(2*angulo));
		}else{
			*coeficiente = sqrt(-1 * pow(distancia, 2) / sin(2*angulo));
		}
	}
	
}

void coordenadasPolares(double x, double y, double *distancia, double *angulo){
	*distancia = sqrt(pow(x, 2) + pow(y, 2));
	*angulo = atan(y/x);
}

int validarDatos(double x1, double y1, double x2, double y2, char funcionTrig, char signo){
	int valido = 1;
	if((x1 == 0 && y1 == 0) || (x1 == 0 && y1 == 0) || (funcionTrig != 'C' && funcionTrig != 'S') || (signo != '+' && signo != '-')){
		valido = 0;
	}
	return valido;
}
