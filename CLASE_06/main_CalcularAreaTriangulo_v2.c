#include <stdio.h>
#include <math.h>

/*Prototipos de los módulos*/
void calcularSemiperimetroyArea(double lado1,double lado2,double lado3,double *semiperimetro,double *area);
void mostrarArea(double area);
double calcularSemiperimetro(double lado1,double lado2,double lado3);
double calcularArea(double semiperimetro,double lado1,double lado2,double lado3);

int main(){
	double lado1, lado2, lado3, semiperimetro, area;
	int ladosMayoresCero, cumpleDesigualdad;
	printf("Ingrese los 3 lados del triángulo: ");
	scanf("%lf %lf %lf",&lado1,&lado2,&lado3);
	ladosMayoresCero = lado1>0 && lado2>0 && lado3>0;
	cumpleDesigualdad = (lado2+lado3)>lado1 && (lado1+lado3)>lado2 && (lado2+lado1)>lado3;
	if (ladosMayoresCero && cumpleDesigualdad){
		calcularSemiperimetroyArea(lado1,lado2,lado3,&semiperimetro,&area);
		mostrarArea(area);
	}
	else {
		printf("Los lados ingresados no forman un triángulo");	
	}
	return 0;
}

/*Implementación de módulos*/
void calcularSemiperimetroyArea(double lado1,double lado2,double lado3,double *semiperimetro,double *area){
	*semiperimetro = calcularSemiperimetro(lado1,lado2,lado3);
	*area = calcularArea(*semiperimetro,lado1,lado2,lado3);
}

void mostrarArea(double area){
	printf("El área del triángulo es: %lf",area);
}

double calcularSemiperimetro(double lado1,double lado2,double lado3){
	double semiperimetro;
	semiperimetro = (lado1+lado2+lado3)/2;
	return semiperimetro;
}

double calcularArea(double semiperimetro,double lado1,double lado2,double lado3){	
	return sqrt(semiperimetro*(semiperimetro-lado1)*(semiperimetro-lado2)*(semiperimetro-lado3));
}
