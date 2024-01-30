#include <stdio.h>
#include <math.h>
int validarCombinacion(int calcularTiempo, int calcularDistancia, int calcularRitmo);
double Distancia(double ritmoT, double horas, double minutos, double segundos);
void Tiempo(double distancia, double ritmoT, double *horas, double *minutos, double *segundos);


int main(){
	int calcularTiempo, calcularDistancia, calcularRitmo;
	printf("Debe ingresar solo dos de los tres datos de entrada\n");
	printf("Calcular tiempo (0 : No | 1 : Si): ");
	scanf("%d", &calcularTiempo);
	printf("Calcular distancia (0 : No | 1 : Si): ");
	scanf("%d", &calcularDistancia);
	printf("Calcular ritmo (0 : No | 1 : Si): ");
	scanf("%d", &calcularRitmo);
	
	if(validarCombinacion(calcularTiempo, calcularDistancia, calcularRitmo)){
		double distancia, mm, ss, horas, minutos, segundos, ritmoT, tiempo;
		
		if(calcularTiempo == 1){
			printf("Leer distancia en km: ");
			scanf("%lf", &distancia);
			printf("Leer ritmo 1km x mm-ss: ");
			scanf("%lf %lf", &mm, &ss);
			ritmoT = (double)1/(mm / 60 + ss / 3600);
			Tiempo(distancia, ritmoT, &horas, &minutos, &segundos);
			printf("El tiempo calculado es %lf horas, %lf minutos y %lf segundos", horas, minutos, segundos);
		}
		else{
			if(calcularDistancia == 1){
				printf("Leer tiempo hh-mm-ss: ");
				scanf("%lf %lf %lf", &horas, &minutos, &segundos);
				printf("Leer ritmo 1km x mm-ss: ");
				scanf("%lf %lf", &mm, &ss);
				double ritmoTDistancia = (double)1/(mm / 60 + ss / 3600);
				distancia = Distancia(ritmoTDistancia, horas, minutos, segundos);
				printf("%lf\n", ritmoT);
				printf("La distancia calculada es %lf km", distancia);
			}else{
				printf("Leer tiempo hh-mm-ss: ");
				scanf("%lf %lf %lf", &horas, &minutos, &segundos);
				printf("Leer distancia en (km): ");
				scanf("%lf", &distancia);
				tiempo = horas + minutos / 60 + segundos / 3600;
				printf("El ritmo calculado es %lf km/horas", distancia/tiempo);
			}
		}
	}else{
		printf("Combinación incorrecta de valores");
	}
	return 0;
}

void Tiempo(double distancia, double ritmoT, double *horas, double *minutos, double *segundos){
	double tiempoTotal = ritmoT / distancia;
	*horas = (int)tiempoTotal;
	*minutos = (int)((tiempoTotal - *horas) * 60);
	*horas = ((tiempoTotal - *horas)*60 - *minutos)*60;
}


double Distancia(double ritmoT, double horas, double minutos, double segundos){
	double tiempo, distancia;
	tiempo = horas + minutos / 60 + segundos / 3600;
	distancia = ritmoT * tiempo;
	return distancia;
}

int validarCombinacion(int calcularTiempo, int calcularDistancia, int calcularRitmo){
	return (calcularTiempo == 1 && calcularDistancia == 0 && calcularRitmo == 0) || (calcularTiempo == 0 && calcularDistancia == 1 && calcularRitmo == 0) || (calcularTiempo == 0 && calcularDistancia == 0 && calcularRitmo == 1);
}
