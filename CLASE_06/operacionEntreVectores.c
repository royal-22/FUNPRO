#include <stdio.h>
#include <math.h>
void CalculadoraVectores(int cantidadOperaciones);
void operaciones(double x1, double y1, double z1, double x2, double y2, double z2, char operador, double *x3, double *y3, double *z3, int *multiplicacion);

int main(){
	int cantidadOperaciones, dimensiones;
	printf("Ingrese la cantidad de operaciones a realizar con los vectores: ");
	scanf("%d", &cantidadOperaciones);
	printf("Ingrese la cantidad de dimensiones: ");
	scanf("%d", &dimensiones);
	if(cantidadOperaciones > 0 && dimensiones==3){
		CalculadoraVectores(cantidadOperaciones);
	}
	else{
		printf("Debe ingresar una cantidad válida");
	}
	return 0;
}

void operaciones(double x1, double y1, double z1, double x2, double y2, double z2, char operador, double *x3, double *y3, double *z3, int *multiplicacion){
	if(operador == '+'){
		*x3 = x1 + x2;
		*y3 = y1 + y2;
		*z3 = z1 + z2;
	}
	else{
		if(operador == '-'){
			*x3 = x1 - x2;
			*y3 = y1 - y2;
			*z3 = z1 - z2;
		}
		else{
			printf("Ingrese el tipo de multiplicación a calcular: ");
			scanf("%d", multiplicacion);
			if(*multiplicacion == 1){
				*x3 = x1 * x2;
				*y3 = y1 * y2;
				*z3 = z1 * z2;
			}
			else{
				*x3 = y1*z2 - y2*z1;
				*y3 = -1 * (x1*z2 - x2*z1);
				*z3 = x1*y2 - x2*y1;
			}
		}
	}
}

void CalculadoraVectores(int cantidadOperaciones){
	int i, multiplicacion;
	double x1, x2, x3, y1, y2, y3, z1, z2, z3;
	char operador;
	multiplicacion = 0;
	i = 0;
	while(i < cantidadOperaciones){
		printf("Ingrese la operación a realizar entre los vectores tridimensionales: ");
		scanf(" %c", &operador);
		
		printf("Ingrese las coordenadas del primer vector: ");
		scanf(" %lf %lf %lf", &x1, &y1, &z1);
		printf("Ingrese las coordenadas del segundo vector: ");
		scanf(" %lf %lf %lf", &x2, &y2, &z2);
		operaciones(x1, y1, z1, x2, y2, z2, operador, &x3, &y3, &z3, &multiplicacion);
		if(multiplicacion == 0){
			printf("(%.2lf, %.2lf, %.2lf) %c (%.2lf, %.2lf, %.2lf) = (%.2lf, %.2lf, %.2lf)\n", x1, y1, z1, operador, x2, y2, z2, x3, y3, z3);
		}
		else{
			if(multiplicacion == 1){
				printf("Producto escalar: (%.2lf, %.2lf, %.2lf) %c (%.2lf, %.2lf, %.2lf) = (%.2lf)\n", x1, y1, z1, operador, x2, y2, z2, x3 + y3 + z3);
			}
			else{
				printf("Producto vectorial: (%.2lf, %.2lf, %.2lf) %c (%.2lf, %.2lf, %.2lf) = (%.2lf, %.2lf, %.2lf)\n", x1, y1, z1, operador, x2, y2, z2, x3, y3, z3);
			}
		}
		i++;
	}

}
