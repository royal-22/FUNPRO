#include <stdio.h>
#include <math.h>

int validarDatos(int num1, int num2);
void verificarAlternoExistencia(int numero1, int numero2, int *esAlterno, int *digitosPares, int *digitosImpares, int *existenciaDigitos);
int verificarDigito(int num, int dig);

int main(){
	int numero1, numero2, esAlterno, digitosPares, digitosImpares, existenciaDigitos;
	printf("Ingrese el número para evaluar alternancia: ");
	scanf("%d", &numero1);
	printf("Ingrese el número para evaluar coincidencia de dígitos: ");
	scanf("%d", &numero2);
	if(validarDatos(numero1, numero2)){
		verificarAlternoExistencia(numero1, numero2, &esAlterno, &digitosPares, &digitosImpares, &existenciaDigitos);
		if(esAlterno){
			printf("El número %d es alterno\n", numero1);
			printf("El número con los dígitos pares es: %d\n", digitosPares);
			printf("El número con los digitos impares es: %d\n", digitosImpares);
		}else{
			printf("El número %d no es alterno\n", numero1);
		}
		if(existenciaDigitos){
			printf("Todos los dígitos del número %d se encuentran dentro del número %d\n", numero1, numero2);
		}else{
			printf("Exsiten dígitos del número %d que no se encuentran dentro del número %d\n", numero1, numero2);
		}
	}else{
		printf("Datos incorrectos\n");
	}
	return 0;
}

void verificarAlternoExistencia(int numero1, int numero2, int *esAlterno, int *digitosPares, int *digitosImpares, int *existenciaDigitos){
	int i = 0, anterior, dig, current, exponentePares = 0, exponenteImpares = 0, valido;
	/*
	1 - par
	2 - impar
	*/
	*existenciaDigitos = 1;
	*esAlterno = 1;
	while(numero1 > 0){
		dig = numero1 % 10;
		numero1 /= 10;
		valido = verificarDigito(numero2, dig);
		if(!valido){
			*existenciaDigitos = 0;
		}
		if(i == 0){
			if(dig % 2 == 0){
				anterior = 1;
				(*digitosPares) += dig * (int)pow(10, exponentePares);
				exponentePares++;
			}else{
				anterior = 2;
				(*digitosImpares) += dig * (int)pow(10, exponenteImpares);
				exponenteImpares++;
			}
		}else{
			if(dig % 2 == 0){
				current = 1;
				(*digitosPares) += dig * (int)pow(10, exponentePares);
				exponentePares++;
			}else{
				current = 2;
				(*digitosImpares) += dig * (int)pow(10, exponenteImpares);
				exponenteImpares++;
			}
			if(anterior == current){
				*esAlterno = 0;
				break;
			}
			
			anterior = current;
			
		}
		i++;
	}
}

int validarDatos(int num1, int num2){
	return num1 >= 10 && num2 > 0;
}

int verificarDigito(int num, int dig){
	int i, d;
	while(num > 0){
		d = num % 10;
		num /= 10;
		if(d == dig){
			return 1;
		}
	}
	return 0;
}
