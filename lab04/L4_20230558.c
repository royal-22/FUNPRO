#include <stdio.h>
#include <math.h>
#define PI 3.141592
/*
Nombre: Luciana Carrillo 
Codigo: 20230558
*/

int main(){
	int opcion, iteraciones, i=0;
	printf("Men� de opciones\n");
	printf("------------------\n");
	printf("1. Calcular PI\n");
	printf("2. Operaciones con d�gitos\n");
	printf("Ingrese la opci�n a evaluar: ");
	scanf("%d", &opcion);
	if(opcion == 1 || opcion == 2 ){
		/* Calcular PI*/
		if(opcion == 1){
			double serieMadhava = 0, serieEuler = 0, factorial1, factorial2;
			printf("Ingrese la cantidad de t�rminos a iterar: ");
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
				
				printf("Valor de PI seg�n la sumatoria de Euler = %lf\n", serieEuler*2);
				printf("Valor de PI seg�n la sumatora de Madhava = %lf\n", serieMadhava*4);
				double diferenciaEuler = fabs(serieEuler - PI);
				double diferenciaMadhava = fabs(serieMadhava - PI);
				
				/*Comparar cual tiene menor diferencia respecto al valor de PI*/
				if(diferenciaEuler < diferenciaMadhava){
					printf("El c�lculo de la sumatoria de Euler es m�s cercano al valor de PI definido\n");
				}
				else{
					printf("El c�lculo de la sumatoria de Madhava es m�s cercano al valor de PI definido\n");
				}
			}
			else{
				printf("Cantidad de t�rminos incorrecta\n");
			}
		}
		else{
			int numero, digitos, n, sumaDigitos = 0, copiaNumero, x, base, potenciaDigitos; 
			char operacion;
			
			printf("Ingrese un n�mero y su cantidad de d�gitos: ");
			scanf("%d %d", &numero, &digitos);
			printf("Ingrese la operaci�n a realizar con los d�gitos (S: suma, P: potencia): ");
			scanf(" %c", &operacion);
			copiaNumero = numero;
			int digitosComprobar = log10(numero) + 1;
			
			/*Validar datos para realizar las operaciones*/
			if(digitosComprobar == digitos && numero > 0 && (operacion == 'P' || operacion == 'S')){
				while(i<digitos){
					/*Extraer n�meros de derecha a izquierda para sumar d�gitos*/
					if(operacion == 'S'){
						n = numero%10;
						sumaDigitos += n;
						numero/=10;
						
					}
					/*Extraer n�meros de izquierda a derecha para la potencia*/
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
					printf("Potencia de d�gitos es %d\n", potenciaDigitos);
				}
				else{
					printf("Suma de los d�gitos es %d\n", sumaDigitos);
				}
			}else{
				printf("Datos incorrectos para operar los d�gitos del n�mero.\n");
			}
		}
	}else{
		printf("Opci�n incorrecta\n");
	}	
	return 0;
}
