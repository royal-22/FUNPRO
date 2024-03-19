#include <stdio.h>
/*
Nombre: Luciana Carrillo
Código: 20230558
*/

/*Declarar prototipos*/
int sumaDivisores(int num);
int calcularMCD(int num1, int num2);
void calcularNumerosDeffinianos(int inicio, int fin, int *existenDuffinianos, int *cantDuffinianos);
int cantDivisores(int num);

int main(){
	int inicio, fin, rangoValidos = 0, mayorRangoInicio, mayorRangoFinal, cantidadRangoMayor, esPrimero = 1, existenDuffinianos, cantDuffinianos;
	while(1){
		/*Datos de entrada*/
		printf("Ingrese un rango: ");
		scanf("%d %d", &inicio, &fin);
		if(inicio == 0 && fin == 0){
			break;
		}
		if(fin > inicio && inicio > 0){
			/*Buscar números duffinianos en el rango ingresado*/
			calcularNumerosDeffinianos(inicio, fin, &existenDuffinianos, &cantDuffinianos);
			if(existenDuffinianos){
				printf("\nEn el rango [%d, %d] se encontraron %d números duffinianos\n", inicio, fin, cantDuffinianos);
				if(esPrimero){
					mayorRangoInicio = inicio;
					mayorRangoFinal = fin;
					cantidadRangoMayor = cantDuffinianos;
				}else{
					if(cantDuffinianos >= cantidadRangoMayor){
						mayorRangoInicio = inicio;
						mayorRangoFinal = fin;
						cantidadRangoMayor = cantDuffinianos;
					}
				}
			}else{
				printf("\nEn el rango [%d, %d] no se encontraron números duffinianos\n", inicio, fin);
			}
			rangoValidos++;
		}else{
			printf("El rango ingreado no es válido\n");
		}
	}
	/*imprimir resumen en caso se ingresaron rangos válidos*/
	if(rangoValidos > 0){
	printf("En el rango [%d, %d] se encontró la mayor cantidad de números duffinianos\n", mayorRangoInicio, mayorRangoFinal);		
	}
	return 0;
}

/*Calcular la cantidad de divisores de un número*/
int cantDivisores(int num){
	int i = 1, cantDiv = 0; 
	while(i <= num){
		if(num % i == 0){
			cantDiv++;
		}
		i++;
	}
	return cantDiv;
}

/*Calcular el MCD de dos números*/
int calcularMCD(int num1, int num2){
	int m, n, residuo, maximoDivisor;
	if(num1 > num2){
		m = num1;
		n = num2;
	}else{
		m = num2;
		n = num1;
	}
	while(n >= 1){
		residuo = m % n;
		if(residuo == 0){
			maximoDivisor = n;
			break;
		}
		m = n;
		n = residuo;
	}
	return maximoDivisor;
}

/*Calcular si existen números duffinianos en el rango y si existen retornar la cantidad*/
void calcularNumerosDeffinianos(int inicio, int fin, int *existenDuffinianos, int *cantDuffinianos){
	int esPrimero = 1, i, sumaDiv;
	*cantDuffinianos = 0;
	*existenDuffinianos = 0;
	for(i = inicio; i <= fin; i++){
		sumaDiv = sumaDivisores(i);
		if(calcularMCD(sumaDiv, i) == 1 && cantDivisores(i) > 2){
			if(esPrimero){
				printf("En el rango existen los siguientes números duffinianos: \n");
				esPrimero = 0;
				*existenDuffinianos = 1;
			}
			printf("%d ", i);
			(*cantDuffinianos)++;
		}
	}
}

/*Calcular la suma de divisores*/
int sumaDivisores(int num){
	int suma = 0, i;
	for(i = 1; i <= num; i++){
		if(num % i == 0){
			suma += i;
		}
	}
	return suma;
}
