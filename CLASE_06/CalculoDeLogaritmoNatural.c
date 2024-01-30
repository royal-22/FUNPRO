#include <stdio.h>
#include <math.h>

void calcularLogaritmo(double x, int cantidadTerminos);
double evaluarLogaritmoValido(double x, int cantidadTerminos;);

int main(){
	double x;
	int cantidadTerminos;
	printf("Ingrese el valor de x: ");
	scanf("%lf", &x);
	printf("Ingrese la cantidad de términos: ");
	scanf("%d", &cantidadTerminos);
	calcularLogaritmo(x, cantidadTerminos);
	return 0;
}
double evaluarLogaritmoValido(double x, int cantidadTerminos){
	int i;
	double sumatoria = 0;
	for(i = 0; i<= cantidadTerminos; i++){
		sumatoria += (double)1/(2 * i + 1) * pow((x - 1)/(x + 1), 2 * i + 1);
	}
	return sumatoria * 2;
}

void calcularLogaritmo(double x, int cantidadTerminos){
	if(cantidadTerminos > 0){
		if(x <= 0){
			if(x == 0){
				printf("El logaritmo de %lf es -inf", x);
			}
			else{
				printf("El logaritmo de %lf es nan", x);
			}
		}
		else{
			double rspt = evaluarLogaritmoValido(x, cantidadTerminos);
			printf("El logaritmo de %lf es %lf", x, rspt);
		}
	}
	else{
		printf("La cantidad de términos debe ser mayor o igual a 0.\n");
	}
}
