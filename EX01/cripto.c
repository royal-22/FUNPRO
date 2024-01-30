#include <stdio.h>
#include <math.h>

int calcularOperacion(int n1, int n2, char operacion);
int validarDatos(int numero1, int numero2, char operacion);
void cifrarNumero(int numero, int *digitosNumeroCifrado, int *numeroCifrado);


int main(){
	int numero1, numero2, numeroFinal, digitos, numeroCifrado = 0, digitosNumeroCifrado;
	char operacion;
	printf("Ingrese dos números: ");
	scanf("%d %d", &numero1, &numero2);
	printf("Ingrese la operación a realizar: ");
	scanf("\n%c", &operacion);
	if(validarDatos(numero1, numero2, operacion)){
		numeroFinal = calcularOperacion(numero1, numero2, operacion);
		printf("%d %c %d = %d\n", numero1, operacion, numero2, numeroFinal);
		if(numeroFinal>9 && numeroFinal <= 999){
			cifrarNumero(numeroFinal, &digitosNumeroCifrado, &numeroCifrado);
			printf("El número a cifrar tiene %d cifras y el número cifrado es %d\n", digitosNumeroCifrado, numeroCifrado);
		}else{
			printf("El resultado de la operación no es positivo o no tiene 2 o 3 cifras\n");
		}
	}else{
		printf("Datos inválidos\n");
	}
	return 0;
}
void cifrarNumero(int numero, int *digitosNumeroCifrado, int *numeroCifrado){
	int i = 0, unidades, decenas, centenas;
	unidades = numero%10;
	numero /= 10;
	decenas = numero%10;
	numero /= 10;
	centenas = numero % 10;
	
	if(centenas == 0){
		*digitosNumeroCifrado = 2;
	}else{
		*digitosNumeroCifrado = 3;
	}
	
	if(unidades > decenas){
		*numeroCifrado += decenas;
		*numeroCifrado += (unidades + decenas) * 10; 
	}else{
		*numeroCifrado += unidades;
		*numeroCifrado += (decenas - unidades) * 10;
	}
	
	if(*digitosNumeroCifrado == 2){
		*numeroCifrado += *digitosNumeroCifrado * 1000;
	}else{
		if(centenas >= decenas){
				*numeroCifrado += centenas * 1000;
				*numeroCifrado += (centenas / decenas) * 10000;
		}else{
				*numeroCifrado += decenas * 1000;
				*numeroCifrado += (centenas * decenas) * 10000;
		}
		*numeroCifrado += *digitosNumeroCifrado * 1000000;
	}
}

int calcularOperacion(int n1, int n2, char operacion){
	int resultado;
	if(operacion == '+'){
		resultado = n1 + n2;
	}else{
		if(operacion == '-'){
			resultado = n1 - n2;
		}
		else{
			if(operacion == '*'){
				resultado = n1 * n2;
			}
			else{
				resultado = n1 / n2;
			}
		}
	}
	return resultado;
}

int validarDatos(int numero1, int numero2, char operacion){
	return numero1 > 0 && numero2 > 0 && (operacion == '+ ' || operacion == '/' || operacion == '*' || operacion == '-');
}
