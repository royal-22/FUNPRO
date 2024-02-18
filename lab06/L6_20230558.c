#include <stdio.h>
#define vMEscolar 25
#define vMHospital 20
#define vMComercial 30
#define vMResidencial 50
#define COBRANZA1 5200
#define COBRANZA2 4800
#define SANCION1 0.18
#define RESTAPUNTOS1 20
#define SANCION2 0.24
#define RESTAPUNTOS2 40
#define SANCION3 0.50
#define RESTAPUNTOS3 60

/*
Nombre: Luciana Carrillo 
Código: 20230558
*/

/*Declarar prototipos*/
void leerDatos(int *distrito, char *zona, double *distancia, double *tiempo);
int validarDatos(double distancia, double tiempo, int distrito, char zona);
double calcularVelocidad(double tiempo, double distancia);
void baseCobranzaVelocidadMaxima(int distrito, char zona, double *baseCobranza, double *velocidadMaxima);
void existeMulta(double velocidad, double velocidadMaxima, double baseCobranza, int *existeExceso, double *multa, int *puntaje);

int main(){
	int iteraciones, distrito, puntaje, i, contadorDesplazamientos = 0, existeExceso;
	char zona;
	double distancia, tiempo, multa, velocidad, baseCobranza, velocidadMaxima, multaTotal = 0, distanciaTotal = 0;
	
	printf("Ingrese la cantidad de zonas por donde se desplazó: ");
	scanf("%d", &iteraciones);
	/*Iniciar las iteraciones*/
	if(iteraciones > 0){
		printf("Ingrese el puntaje del conductor: ");
		scanf("%d", &puntaje);
		if(puntaje > 0 && puntaje <= 100){
			printf("\n");
			while(i < iteraciones){
				printf("INGRESE LA INFORMACIÓN DEL DESPLAZAMIENTO %d\n", i + 1);
				leerDatos(&distrito, &zona, &distancia, &tiempo);
				/*Válidar los datos*/
				if(validarDatos(distancia, tiempo, distrito, zona)){
					distanciaTotal += distancia;
					/*Calcular la velocidad, multa, si existe exceso de velocidad*/
					velocidad = calcularVelocidad(tiempo, distancia);
					baseCobranzaVelocidadMaxima(distrito, zona, &baseCobranza, &velocidadMaxima);
					existeMulta(velocidad, velocidadMaxima, baseCobranza, &existeExceso, &multa, &puntaje);
					multaTotal += multa;
					printf("\n");
					printf("Información del desplazamiento %d\n", i + 1);
					printf("-Velocidad (Km/h): %.2lf\n", velocidad);
					if(existeExceso){
						printf("-Multa por exceso de velocidad: %.2lf\n", multa);
					}else{
						printf("-No hubo exceso de velocidad\n");
					}
					contadorDesplazamientos++;
				}else{
					printf("Alguno de los valores del desplazamiento no es válido, no se tomará en cuenta en el reporte\n");
				}
				printf("\n");
				i++;
			}
			printf("\n");
			if(contadorDesplazamientos > 0){
				/*Imprimir resumen*/
				printf("RESUMEN\n");
				printf("============\n");
				printf("-En total se consideraron %d desplazamientos válidos\n", contadorDesplazamientos);
				printf("-La distancia total recorrida en Km es: %.2lf\n", distanciaTotal / 1000);
				printf("-La multa total que debe de pagar es: %.2lf\n", multaTotal);
				printf("-Su puntaje es %d.", puntaje);
				if(puntaje < 0){
					printf(" Su brevete ha sido suspendido\n");
				}else{
					printf(" Su brevete NO ha sido suspendido\n");
				}
				
			}else{
				printf("No hay información suficiente para mostrar un resumen\n");
			}
		}else{
			printf("El puntaje del conductor no es válido\n");
		}
	}else{
		printf("La cantidad de desplazamientos debe ser mayor que 0\n");
	}
	
	return 0;
}
/*Determinar si existe exceso de velocdiad y la respectiva multa y reducción de puntaje*/
void existeMulta(double velocidad, double velocidadMaxima, double baseCobranza, int *existeExceso, double *multa, int *puntaje){
	double diferencia = velocidad - velocidadMaxima;
	if(velocidad > velocidadMaxima){
		*existeExceso = 1;
		if(diferencia > 10){
			if(diferencia <= 30){
				*multa = baseCobranza * SANCION2;
				*puntaje -= RESTAPUNTOS2;
			}else{
				*multa = baseCobranza * SANCION3;
				*puntaje -= RESTAPUNTOS3;
			}
		}else{
			*multa = baseCobranza * SANCION1;
			*puntaje -= RESTAPUNTOS1;
		}
	}else{
		*existeExceso = 0;
		*multa = 0;
	}
}
/*Deteminar la base de cobranza y velocidad máxima respectiva de la zona y distrito*/
void baseCobranzaVelocidadMaxima(int distrito, char zona, double *baseCobranza, double *velocidadMaxima){
	if(distrito == 1){
		*baseCobranza = COBRANZA1;
		if(zona == 'E'){
			*velocidadMaxima = vMEscolar;
		}else{
			if(zona == 'C'){
				*velocidadMaxima = vMComercial;
			}else{
				*velocidadMaxima = vMResidencial;
			}
		}
	}else{
		*baseCobranza = COBRANZA2;
		if(zona == 'E'){
			*velocidadMaxima = vMEscolar;
		}else{
			*velocidadMaxima = vMHospital;
		}
	}
}
/*Calcular datos*/
double calcularVelocidad(double tiempo, double distancia){
	return (distancia/1000)/(tiempo/3600); 
}

/*validar datos*/
int validarDatos(double distancia, double tiempo, int distrito, char zona){
	return distancia > 0 && tiempo > 0 && ((distrito == 1 && (zona == 'E' || zona == 'C' || zona == 'R')) || (distrito == 2 && (zona == 'E' || zona == 'H'))); 
}
/*Leer Datos*/
void leerDatos(int *distrito, char *zona, double *distancia, double *tiempo){
	printf("-Ingrese el distrito por donde se desplazó Distrito 1 (1), Distrito 2 (2): ");
	scanf("%d", distrito);
	printf("-Ingrese el tipo de zona por donde se desplazó: ");
	scanf(" %c", zona);
	printf("-Ingrese la distancia recorrida en metros: ");
	scanf("%lf", distancia);
	printf("-Ingrese el tiempo que recorrió la distancia en segundos: ");
	scanf("%lf", tiempo);
}
