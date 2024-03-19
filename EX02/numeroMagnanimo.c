#include <stdio.h>
#include <math.h>

int esPrimo(int n);
int calcularCifras(int n);
void esMagnanimo(int num, int *magnanimoValido, int *iteracion, int *num1, int *num2, int *suma);

int main(){
	int num, cantCifras, magnanimoValido, iteracion, num1, num2, suma;
	printf("Ingrese el número y su cantidad de cifras: ");
	scanf("%d %d", &num, &cantCifras);
	if(cantCifras >= 2 && cantCifras <= 7 && calcularCifras(num) == cantCifras){
		esMagnanimo(num, &magnanimoValido, &iteracion, &num1, &num2, &suma);
		if(magnanimoValido){
			printf("El número %d es magnánimo\n", num);
		}else{
			printf("El númerp %d no es magnánimo\n", num);
			printf("En el intento %d falló la combinación: %d + %d = %d, pues %d no es primo\n", iteracion, num1, num2, suma, suma);
		}
	}else{
		printf("Datos incorrectos\n");
	}	
}



int esPrimo(int n){
	int i = 1, divisores = 0;
	while(i <= n){
		if(n % i == 0){
			divisores++;
		}
		i++;
	}
	return divisores == 2;
}

int calcularCifras(int n){
	return (int)log10(n) + 1;
}

void esMagnanimo(int num, int *magnanimoValido, int *iteracion, int *num1, int *num2, int *suma){
	int cifras = calcularCifras(num), i, n1, n2, sum;
	for(i = cifras; i > 0; i--){
		n1 = num / (int)pow(10, i - 1);
		n2 = num % (int)pow(10, i - 1);
		sum = n1 + n2;
		if(!esPrimo(sum)){
			*magnanimoValido = 0;
			*iteracion = cifras - i + 1;
			*num1 = n1;
			*num2 = n2;
			*suma = sum;
			break;
		}
	}
	if(*magnanimoValido != 0){
		*magnanimoValido = 1;	
	}
	
}
