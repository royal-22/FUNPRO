#include <stdio.h>
#include <math.h>
#define PI 3.141592
/*
Nombre: Luciana Carrillo 
Codigo: 20230558
*/

int main(){
	int opcion, iteraciones, i=0;
	printf("Menú de opciones\n");
	printf("------------------\n");
	printf("1. Calcular PI\n");
	printf("2. Operaciones con dígitos\n");
	printf("Ingrese la opción a evaluar: ");
	scanf("%d", &opcion);
	if(opcion == 1 || opcion == 2 ){
		/* Calcular PI*/
		if(opcion == 1){
			double serieMadhava = 0, serieEuler = 0, factorial1, factorial2;
			printf("Ingrese la cantidad de términos a iterar: ");
			scanf("%d", &iteraciones);
			if(iteraciones > 0 && iteraciones <= 50){
				
				while(i < iteraciones){
					/*Serie de Madhava*/
					serieMadhava += (pow(-1, i) / (2 * i + 1));
					
					/*Serie de Euler*/
					if(i==0){
						factorial1 = 1;
						factorial2 = 1;
					}
					else{
						factorial1 *= i;
						factorial2 *= (i*2 + 1) * (i*2);
						printf("%lf %lf\n", factorial1, factorial2);
					}
					double numerador = pow(2, i) * pow(factorial1, 2);
					serieEuler += (numerador / (factorial2));
					printf("%lf\n", serieEuler);
					
					i++;
				}
				
				printf("Valor de PI según la sumatoria de Euler = %lf\n", serieEuler*2);
				printf("Valor de PI según la sumatora de Madhava = %lf\n", serieMadhava*4);
				double diferenciaEuler = fabs(serieEuler - PI);
				double diferenciaMadhava = fabs(serieMadhava - PI);
				
				/*Comparar cual tiene menor diferencia respecto al valor de PI*/
				if(diferenciaEuler < diferenciaMadhava){
					printf("El cálculo de la sumatoria de Euler es más cercano al valor de PI definido\n");
				}
				else{
					printf("El cálculo de la sumatoria de Madhava es más cercano al valor de PI definido\n");
				}
			}
			else{
				printf("Cantidad de términos incorrecta\n");
			}
		}
		else{
			int numero, digitos, n, sumaDigitos = 0, copiaNumero, x, base, potenciaDigitos; 
			char operacion;
			
			printf("Ingrese un número y su cantidad de dígitos: ");
			scanf("%d %d", &numero, &digitos);
			printf("Ingrese la operación a realizar con los dígitos (S: suma, P: potencia): ");
			scanf(" %c", &operacion);
			copiaNumero = numero;
			int digitosComprobar = log10(numero) + 1;
			
			/*Validar datos para realizar las operaciones*/
			if(digitosComprobar == digitos && numero > 0 && (operacion == 'P' || operacion == 'S')){
				while(i<digitos){
					/*Extraer números de derecha a izquierda para sumar dígitos*/
					if(operacion == 'S'){
						n = numero%10;
						sumaDigitos += n;
						numero/=10;
						
					}
					/*Extraer números de izquierda a derecha para la potencia*/
					else{
						x = copiaNumero/ (int)pow(10, digitos-1 - i);
						if(i==0){
							potenciaDigitos = x;
						}
						else{
							potenciaDigitos = pow(potenciaDigitos, x);
						}
						copiaNumero %= (int)pow(10, digitos - 1 - i);		
						}
							
					i++;
				}
				
				/*Imprimir datos*/
				if(operacion == 'P'){
					printf("Potencia de dígitos es %d\n", potenciaDigitos);
				}
				else{
					printf("Suma de los dígitos es %d\n", sumaDigitos);
				}
			}else{
				printf("Datos incorrectos para operar los dígitos del número.\n");
			}
		}
	}else{
		printf("Opción incorrecta\n");
	}	
	return 0;
}
