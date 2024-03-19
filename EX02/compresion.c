#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define E 30000

void realizarCalculos(double diametro, double longitud, double *area, double *cargaAxial, double *inercia, double *esfuerzoCompresion);
double calcularArea(double r);
double calcularInercia(double r);
double calcularCargaAxial(double inercia, double longitud);

int main(){
	int opc, iteraciones;
	double diametro, longitud, cargaAxial, area, inercia, esfuerzoCompresion, menorEsfuerzo, mayorEsfuerzo, sumatoriaCompresiones = 0;
	while(1){
		printf("Menú de opciones\n");
		printf("1: Cálculo de valores de comprensión\n");
		printf("0: Fin\n");
		printf("Ingrese la opción: ");
		scanf("%d", &opc);
		if(opc == 0){
			break;
		}else{
			if(opc == 1){
				printf("Ingrese la cantidad de columnas a evaluar: ");
				scanf("%d", &iteraciones);
				int i = 1;
				while(i <= iteraciones){
					do{
						printf("Ingrese el diámetro de la sección transversal: ");
						scanf("%lf", &diametro);
						printf("Ingrese longitud de la columna: ");
						scanf("%lf", &longitud);
					}while(diametro < 0 || longitud < 0);
					realizarCalculos(diametro, longitud, &area, &cargaAxial, &inercia, &esfuerzoCompresion);
					printf("El área del círculo es: %.6lf\n", area);
					printf("La carga axial es: %.6lf\n", cargaAxial);
					printf("La inercia es: %.6lf\n", inercia);
					printf("El esfuerzo de compresión es: %.6lf\n", esfuerzoCompresion);
					sumatoriaCompresiones += esfuerzoCompresion;
					if(i == 1){
						menorEsfuerzo = esfuerzoCompresion;
						mayorEsfuerzo= esfuerzoCompresion;
					}else{
						if(esfuerzoCompresion < menorEsfuerzo){
							menorEsfuerzo = esfuerzoCompresion;
						}
						if(esfuerzoCompresion > mayorEsfuerzo){
							mayorEsfuerzo = esfuerzoCompresion;
						}
					}
					printf("----------------------------------\n");
					i++;
				}
				printf("REPORTE - Grupo de columnas\n");
				printf("El promedio de esfuerzos es: %lf\n", sumatoriaCompresiones / iteraciones);
				printf("El mayor valor de esfuerzo calculado es: %lf\n", mayorEsfuerzo);
				printf("El menor valor de esfuerzo calculado es: %lf\n", menorEsfuerzo);
			}else{
				printf("Opción incorrecta\n");
			}
		}
	} 
	
	return 0;
}

void realizarCalculos(double diametro, double longitud, double *area, double *cargaAxial, double *inercia, double *esfuerzoCompresion){
	*area = calcularArea(diametro/2);
	*inercia = calcularInercia(diametro / 2);
	*cargaAxial = calcularCargaAxial(*inercia, longitud);
	*esfuerzoCompresion = *cargaAxial / *area;
}

double calcularCargaAxial(double inercia, double longitud){
	return pow(PI, 2) * E * inercia / pow(longitud, 2);
}

double calcularInercia(double r){
	return (PI * pow(r, 4)) / 4;
}

double calcularArea(double r){
	return PI * pow(r, 2);
}
