#include <stdio.h>
#include <math.h>

/*prototipos*/
/*Para recibir un parámetro por referencia (una dirección de memoria) se debe colocar un (*) luego del tipo de dato,
recordar que no es necesario colocar el nombre de la variable cuando se escriben los prototipos de los subprogramas*/
void leerDatos(double *dirLado1,double *dirLado2,double *dirLado3);
double calcularSemiP(double lado1,double lado2,double lado3);
double calcularArea(double semiP,double lado1,double lado2,double lado3);
int validarLadosTriangulo(double lado1,double lado2,double lado3);

int main() {
	/*declaración de variables*/		
	double lado1,lado2,lado3,area,semiP;
	int validarDatos;
	/*la lectura de datos recibe la cantidad de variables que luego deben
	tener el valor ingresado por el usuario, entonces se deben pasar
	por referencia (&) porque van a ser actualizadas*/
	leerDatos(&lado1,&lado2,&lado3);
	
	/*Usamos una función que retorna 1 si todos los lados del triángulo son >0 caso contrario, retorna 0. 
	Como solo retorna un resultado, es una función*/
	validarDatos=validarLadosTriangulo(lado1,lado2,lado3);
	 
	 if (validarDatos) {
	 	/*calcular semiP*/
	 	semiP=calcularSemiP(lado1,lado2,lado3);
	 	/*calcular el área*/
	 	area=calcularArea(semiP,lado1,lado2,lado3);
	 	/*según el diagrama de módulos, no especifica la impresión del semiP
		 lo imprimimos para que tenga sentido que el principal haya hecho el cálculo, en otros diagramas se puede ver
		 que el semiP es calculado dentro de la función que calcular el área*/
		printf("El semiP es: %lf\n",semiP);
		printf("El área es: %lf\n",area);		 
	 } else {
	 	printf("alguno de los lados no es válido");
	 }
	
	return 0;
}

/*implementación*/
int validarLadosTriangulo(double lado1,double lado2,double lado3) {
	return lado1>0 && lado2>0 && lado3>0;
}

double calcularArea(double semiP,double lado1,double lado2,double lado3) {
	return sqrt(semiP*(semiP-lado1)*(semiP-lado2)*(semiP-lado3));		
}


double calcularSemiP(double lado1,double lado2,double lado3) {
	return (lado1+lado2+lado3)/2;
}

void leerDatos(double *dirlado1,double *dirlado2,double *dirlado3) {
	printf("Ingrese los 3 lados del triángulo: ");
	/*dirLado1 y las demás variables ya son direcciones de memoria,
	por lo tanto no necesitan un & delante*/
	scanf("%lf %lf %lf", dirlado1,dirlado2,dirlado3);
}
