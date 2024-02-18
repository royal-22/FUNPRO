#include <stdio.h>
#include <math.h>
#define BERNOULLI2 0.166666667
#define BERNOULLI4 -0.033333333
#define BERNOULLI6 0.023809524
#define BERNOULLI8 -0.033333333
#define BERNOULLI10 .075757576
#define PI 3.141592
/*
Nombre: Luciana Carrillo 
Código: 20230558
*/

/*Declaración de prototipos*/
double calcularSumatoriaA(int iteraciones);
double calcularSumatoriaB(int iteraciones, int a);
double numeroBernoulli(int i);

int main(){
	char opcion;
	int iteraciones, a;
	double sumatoria;
	printf("Ingrese la sumatoria que desea calcular:\n");
	printf("-Sumatoria A\n");
	printf("-Sumatoria B\n");
	scanf("%c", &opcion);
	
	if(opcion == 'A' || opcion == 'B'){
		printf("Ingrese el valor de n: ");
		scanf("%d", &iteraciones);
		/* Para la sumatoria A*/
		if(opcion == 'A'){
			if(iteraciones >= 1 && iteraciones <= 5){
				sumatoria = calcularSumatoriaA(iteraciones);
				printf("El resultado de la sumatoria A es %.10lf\n", sumatoria);
			}else{
				/*mensaje de error*/
				printf("El valor de n no es válido\n");
			}
		}
		/* Para la sumatoria B */
		else if(opcion == 'B'){
			printf("Ingrese el valor de a: ");
			scanf("%d", &a);
			if(iteraciones >= 1 && iteraciones <= 3 && a >= 3 && a <= 5){
				sumatoria = calcularSumatoriaB(iteraciones, a);
				printf("El resultado de la sumatoria B es %.10lf\n", sumatoria);
			}else{
				/*mensaje de error*/
				printf("Alguno de los valores ingresados no es válido\n");
			}
		}
		
	}else{
		/*mensaje de error*/
		printf("La opción ingresada no es válida\n");
	}
	return 0;
}
/* Calcular la sumatoria B */
double calcularSumatoriaB(int iteraciones, int a){
	int i = 1;
	double sumatoria = 0, factorial = 1;
	while(i <= iteraciones){
		factorial *= (2 * i + 1) * (2 * i);
		sumatoria += (factorial) / pow(3 * a, i) * pow(a, PI);
		i++;
	}
	return sumatoria;
}

/*Obtener el numero Bernoulli respectivo para la sumatoria A*/
double numeroBernoulli(int i){
	double valor;
	if(i == 2){
		valor = BERNOULLI2;
	}
	else if(i == 4){
		valor = BERNOULLI4;
	}
	else if(i == 6){
		valor = BERNOULLI6;
	}
	else if(i == 8){
		valor = BERNOULLI8;
	}else{
		valor = BERNOULLI10;
	}
	return valor;
}

/* Calcular la sumatoria A*/
double calcularSumatoriaA(int iteraciones){
	int i = 1; 
	double sumatoria = 0, factorial = 1;
	while(i <= iteraciones){
		factorial *= (2*i) * (2 * i - 1);
		sumatoria += (numeroBernoulli(i*2) * pow(-4, i) * (1 - pow(4, i))) / factorial;
		i++;
	}
	return sumatoria;
}
