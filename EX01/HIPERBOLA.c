#include <stdio.h>
#include <math.h>
#define ERROR 0.0001
int validarDatos(double centrox, double centroy, char tipoH, double semieje1, double semieje2);
void focosHiperbola(double centrox, double centroy, char tipoH, double semiejeFocal, double *focox1, double *focoy1, double *focox2, double *focoy2);
double distanciaPuntos(double x1, double y1, double x2, double y2);

int main(){
	double centrox, centroy, semieje1, semieje2;
	char tipoH;
	printf("Ingrese el centro de la hipérbola: ");
	scanf("%lf %lf", &centrox, &centroy);
	printf("Ingrese el tipo de hiérbola (H: horizontal, V: Vertical): ");
	scanf("\n%c", &tipoH);
	scanf("");
	printf("Ingrese los semiejes: ");
	scanf(" %lf %lf", &semieje1, &semieje2);
	
	if(validarDatos(centrox, centroy, tipoH, semieje1, semieje2)){
		double semiejeFocal, focox1, focoy1, focox2, focoy2, puntoPx, puntoPy, distanciaFoco1P, distanciaFoco2P;
		semiejeFocal = sqrt(pow(semieje1, 2) + pow(semieje2, 2));
		focosHiperbola(centrox, centroy, tipoH, semiejeFocal, &focox1, &focoy1, &focox2, &focoy2);
		printf("Foco 1 = (%lf, %lf)\n", focox1, focoy1); 
		printf("Foco 2 = (%lf, %lf)\n", focox2, focoy2);
		printf("Ingrese un punto para validar si pertenece a la hipérbola: ");
		scanf("%lf %lf", &puntoPx, &puntoPy);
		double ecuacionValida;
		if(tipoH = 'H'){
			ecuacionValida = pow(puntoPx - centrox, 2) / pow(semieje1, 2) - pow(puntoPy - centroy, 2) / pow(semieje2, 2);
		}else{
			ecuacionValida = pow(puntoPy - centroy, 2) / pow(semieje1, 2) - pow(puntoPx - centrox, 2) / pow(semieje2, 2);
		}
		
		if(fabs(ecuacionValida - 1) < ERROR){
			printf("El punto ingresado pertenece a la hipérbola.\n");
			distanciaFoco1P = distanciaPuntos(puntoPx, puntoPy, focox1, focoy1);
			distanciaFoco2P = distanciaPuntos(puntoPx, puntoPy, focox2, focoy2);
			if(fabs((distanciaFoco1P - distanciaFoco2P) - 2 * semieje1) < ERROR){
				printf("Se cumple la propiedad de la hipérbola.\n");
			}else{
				printf("No se cumple la propiedad de la hipérbola.\n");
			}
		}else{
			printf("El punto no pertenece a la hipérbola.\n");
		}
	}else{
		printf("Los datos ingresados son incorrectos.\n");
	}
}

double distanciaPuntos(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));	
}

void focosHiperbola(double centrox, double centroy, char tipoH, double semiejeFocal, double *focox1, double *focoy1, double *focox2, double *focoy2){
	if(tipoH == 'H'){
		*focox1 = centrox - semiejeFocal;
		*focoy1 = centroy;
		*focox2 = centrox + semiejeFocal;
		*focoy2 = centroy;		
	}else{
		*focox1 = centrox;
		*focoy1 = centroy - semiejeFocal;
		*focox2 = centrox;
		*focoy2 = centroy + semiejeFocal;
	}
}


int validarDatos(double centrox, double centroy, char tipoH, double semieje1, double semieje2){
	int valido = 0;
	if(tipoH == 'H' || tipoH == 'V'&& (semieje1 > 0 && semieje2 > 0)){
		if(tipoH == 'H'){
			if((centrox > 0 && centroy > 0) || (centrox < 0 && centroy > 0)){
				valido = 1;
			}else{
				valido = 0;
			}
		}else{
			if((centrox < 0 || centrox > 0) && centroy < 0){
				valido = 1;
			}else{
				valido = 0;
			}
		}
		 
	}else{
		valido = 0;
	}

	return valido;
}
