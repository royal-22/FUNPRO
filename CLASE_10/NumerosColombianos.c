#include <stdio.h>

void leerDatos(int *a, int *b);
int calcularSuma(int num);
int calcularColombianos(int a, int b);

int main(){
	int a, iteracion = 1, b, numerosColombianos , rangoIncorrecto = 0, mayorCantidadDeNumeros = 0, valor1, valor2;
	do{
		leerDatos(&a, &b);
		if(a < b && a > 0 && b > 0){
			numerosColombianos = calcularColombianos(a, b);
			printf("En el rango %d y %d existen %d números colombianos\n", a, b, numerosColombianos);
			if(iteracion == 1){
				mayorCantidadDeNumeros = numerosColombianos;
				valor1 = a;
				valor2 = b;
			}else{
				if(numerosColombianos >= mayorCantidadDeNumeros){
					mayorCantidadDeNumeros  = numerosColombianos;
					valor1 = a;
					valor2 = b;
				}
			}
		}else{
			if(a > b && a > 0 && b > 0){
				rangoIncorrecto++;
				printf("El rango ingresado es incorrecto\n");
			}else{
				break;
			}
			
		}
		iteracion++;
	}while(a>0 && b>0);
	
	printf("\n--------------Reporte----------------\n");
	printf("Se ingresaron %d rangos incorrectos\n", rangoIncorrecto);
	if(mayorCantidadDeNumeros){
		printf("El rango de números %d y %d tuvo la mayor cantidad de números colombianos\n", valor1, valor2);
	}else{
		printf("Ningún rango tuvo la mayor cantidad de números colombianos\n");	
	}
	
	return 0;
}
int calcularSuma(int num){
	int suma = 0, copiaNum = num, digito;
	while(num != 0){
		digito = num%10;
		suma += digito;
		num /= 10;
	}
	return suma + copiaNum;
}

int calcularColombianos(int a, int b){
	int numerosColombianos = 0, i, j, suma, cantidad;
	for(i = a; i < b; i++){
		cantidad = 0;
		for(j = 1; j < i; j++){
			suma = calcularSuma(j);
			if(suma != i){
				cantidad++;
			}
		}	
		if(cantidad == i - 1){
			numerosColombianos++;
		}	
	}
	return numerosColombianos;
}

void leerDatos(int *a, int *b){
	printf("Ingrese un rango de números: ");
	scanf("%d %d", a, b);
}


