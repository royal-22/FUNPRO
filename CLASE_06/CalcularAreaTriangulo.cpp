#include <stdio.h>
#include <math.h>
double CalcularAreaTriangulo(double lado1, double lado2, double lado3);
int EsTriangulo(double lado1, double lado2, double lado3);

int main(){
	double lado1, lado2, lado3;
	printf("Ingrese los lados del triangulo A, B, C: ");
	scanf("%lf %lf %lf", &lado1, &lado2, &lado3);
	int esTrianguloABC = EsTriangulo(lado1, lado2, lado3);
	if(esTrianguloABC){
		double area = CalcularAreaTriangulo(lado1, lado2, lado3);
		printf("El area del triángulo es: %lf\n", area);
	}
	else{
		printf("Los lados no forman un triangulo.\n");
	}
	
	return 0;
}
int EsTriangulo(double lado1, double lado2, double lado3){
	if((lado1 + lado2) > lado3 && (lado2 + lado3) > lado1 && (lado3 + lado1) > lado2 && lado1 > 0 && lado2 > 0 && lado3 > 0){
		return 1;
	}
	else{
		return 0;
	}
}
double CalcularAreaTriangulo(double lado1, double lado2, double lado3){
	double semiper = (lado1 + lado2 + lado3) / 2;
	double area = sqrt(semiper * (semiper - lado1) * (semiper - lado2) * (semiper - lado3));
	return area;
}
