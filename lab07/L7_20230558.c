#include <stdio.h>
#include <math.h>

/*
Nombre: Luciana Carrillo
C�digo: 20230558
*/

/*Declarar prototipos*/
void obtenerDigitos(int numero, int *centena, int *decena, int *unidad);
int esZuckerman(int inicio, int fin);
int esAlterno(int inicio, int fin);
int validarDatos(int inicio, int fin);

int main(){
	char opcion;
	int inicio, fin, i;
	printf("Men� de opciones: \n");
	printf("Z: N�meros Zuckerman\n");
	printf("A: N�meros alternos\n");
	printf("\nIngrese una opci�n:\n");
	scanf(" %c", &opcion);
	if(opcion == 'Z' || opcion == 'A'){
		printf("Ingrese el rango: ");
		scanf("%d %d", &inicio, &fin);
		if(validarDatos(inicio, fin)){
			if(opcion == 'Z'){
				printf("En el rango [%d, %d] hay los siguientes n�meros Zuckerman: \n", inicio, fin);
				/*Si no hay n�meros Zuckerman imprime el siguiente mensaje*/
				if(!(esZuckerman(inicio, fin))){
					printf("En el rango no existen n�meros Zuckerman\n");
				}
			}else{
				printf("En el rango [%d, %d] hay los siguientes n�meros alternos: \n", inicio, fin);
				/*Si no hay n�meros alternos imprime el siguiete mensaje*/
				if(!(esAlterno(inicio, fin))){
					printf("En el rango no existen n�meros alternos\n");
				}
			}
		}else{
			printf("El rango ingresado es inv�lido\n");
		}
	}else{
		printf("Opci�n inv�lida\n");
	}
	return 0;
}

/*Extrae cada digito de acuerdo a la cantidad de d�gitos del n�mero*/
void obtenerDigitos(int numero, int *centena, int *decena, int *unidad){
	int digitos = log10(numero) + 1;
	if(digitos == 1){
		*unidad = numero;
		*decena = 0;
		*centena = 0;
	}else{
		if(digitos == 2){
			*unidad = numero % 10;
			*decena = numero / 10;
			*centena = 0;
		}else{
			*unidad = numero % 10;
			*centena = numero / 100;
			*decena = (numero / 10) % 10;
		}
	}
}
/*Determina los n�meros Zuckerman en un rango definido*/
int esZuckerman(int inicio, int fin){
	int i = inicio, existenNumerosZuckerman = 0, unidad, decena, centena, digitos, producto;
	do{
		obtenerDigitos(i, &centena, &decena, &unidad);
		
		digitos = log10(i) + 1;
		if(digitos == 1){
			producto = unidad;
		}else{
			if(digitos == 2){
				producto = unidad * decena;
			}else{
				producto = centena * decena * unidad;
			}
		}
		if(producto != 0 && i % producto == 0){
			/*Imprime y cuenta la cantidad de numerosZuckerman que se encuentran*/
			printf("%d ", i);
			existenNumerosZuckerman++;
		}
		i++;
	}while(i <= fin);
	return existenNumerosZuckerman > 0;
}
/*Determina los numeros alternos en un rango definido*/
int esAlterno(int inicio, int fin){
	int i = inicio, existenNumerosAlternos = 0, centena, decena, unidad, digitos;
	do{
		obtenerDigitos(i, &centena, &decena, &unidad);
		digitos = log10(i) + 1;
		if(digitos == 2){
			if(unidad%2 == 0){
				if(decena%2 != 0){
					existenNumerosAlternos++;
					printf("%d ", i);
				}
			}else{
				if(decena%2 == 0){
					existenNumerosAlternos++;
					printf("%d ", i);
				}		
			}
		}else{
			if(unidad%2 == 0){
				if(decena%2 != 0){
					if(centena%2 == 0){
						existenNumerosAlternos++;
						printf("%d ", i);
					}
				}
			}else{
				if(decena%2 == 0){
					if(centena % 2 != 0){
						existenNumerosAlternos++;
						printf("%d ", i);
					}
				}
			}
		}
		i++;
	}while(i <= fin);
	
	return existenNumerosAlternos > 0;
}
/* Valida el rango */
int validarDatos(int inicio, int fin){
	return inicio < fin && inicio > 0 && fin < 1000;
}
