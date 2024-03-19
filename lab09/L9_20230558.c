#include <stdio.h>
#include <math.h>

/*
Nombre: Luciana Carrillo
Código: 20230558
*/

/*Declarar prototipos*/
int calcularMultiplicacionCantidadCifrasIguales(int n1, int n2, int cifras);
void CalcularOperaciones(int num1, int num2, int cantCifras1, int cantCifras2, int *rspt, int *operacionesValida);
int calcularMultiplicacionCifrasMenorImpar(int numMayor, int numMenor, int cifrasMenor, int cifrasMayor);
int validarCifras(int n, int cifras);
int calcularMultiplicacionCifraMenorPar(int numMayor, int numMenor, int cifrasMenor, int cifrasMayor);

int main(){
	int centinela = 1, i = 0, num1, num2, cantCifras1, cantCifras2, rspt, operacionValida, operacionesValidas = 0, rsptMenor, posRsptMenor;
	while(centinela){
		printf("Solicitud del par de números #%d\n", i + 1);
		printf("Ingrese el primer número y su cantidad de dígitos: ");
		scanf("%d %d", &num1, &cantCifras1);
		printf("Ingrese el segundo número y su cantidad de dígitos: ");
		scanf("%d %d", &num2, &cantCifras2);
		if(num1 == 0 || num2 == 0){
			centinela = 0;
			printf("Fin del ingreso de datos\n");
			break;
		}else{
				CalcularOperaciones(num1, num2, cantCifras1, cantCifras2, &rspt, &operacionValida);
				if(!operacionValida){
					printf("Datos inválidos\n");
				}else{
					printf("Resultado de la operación: %d\n", rspt);
					operacionesValidas++;
				}
		}
		if(operacionValida){
			if(operacionesValidas == 1){
				rsptMenor = rspt;
				posRsptMenor = i + 1;
			}else{
				if(rspt < rsptMenor){
					rsptMenor = rspt;
					posRsptMenor = i + 1;
				}
			}
		}
		i++;	
	}
	/*IMPRIMIR RESUMEN*/
	printf("Se ingresaron %d pares de números, de los cuales %d tuvieron errores\n", i, i - operacionesValidas);
	if(operacionesValidas > 0){
		printf("El menor resultado se encontró con los pares de números ingresados en la posición %d\n", posRsptMenor);
		printf("El menor resultado fue %d\n", rsptMenor);
	}else{
		printf("Ya que ningún par de números fue correcto no se pudo identificar el menor resultado\n");
	}
	return 0;
}

/*Calculo cuando la cantidad menor de cifras es impar*/
int calcularMultiplicacionCifrasMenorImpar(int numMayor, int numMenor, int cifrasMenor, int cifrasMayor){
	int i = 0, digito1, digito2, rspt = 0;
	while(numMenor > 10){
		if(i % 2 == 0){
			digito1 = numMayor % 10;
			numMayor /= 10;
			digito2 = numMenor / (int) pow(10, cifrasMenor - i - 1);
			numMenor %= (int) pow(10, cifrasMenor - i - 1);
		}else{
			digito1 = numMayor / (int) pow(10, cifrasMayor - i - 1);
			numMayor %= (int) pow(10, cifrasMayor - i - 1);
			digito2 = numMenor % 10;
			numMenor /= 10;
		}
		rspt += digito1 * digito2;
		i++;
	}
	while(numMayor > 0){
		digito1 = numMayor % 10;
		numMayor /= 10;
		rspt += digito1 * numMenor;
	}
	return rspt;
}
/*Calculo cuando la cantidad menor de cifras es par*/
int calcularMultiplicacionCifraMenorPar(int numMayor, int numMenor, int cifrasMenor, int cifrasMayor){
	int  i = 0, digito1, digito2, rspt = 0, promedio;
	while(numMenor > 0){
		if(numMenor >= 10 && numMenor <= 99){
			promedio = (numMenor%10 + numMenor/10) / 2;
		}
		if(i % 2 == 0){
			digito1 = numMayor % 10;
			numMayor /= 10;
			digito2 = numMenor / (int) pow(10, cifrasMenor - i - 1);
			numMenor %= (int) pow(10, cifrasMenor - i - 1);
		}else{
			digito1 = numMayor / (int) pow(10, cifrasMayor - i - 1);
			numMayor %= (int) pow(10, cifrasMayor - i - 1);
			digito2 = numMenor % 10;
			numMenor /= 10;
		}
		rspt += digito1 * digito2;
		i++;
	}
	while(numMayor > 0){
		digito1 = numMayor % 10;
		numMayor /= 10;
		rspt += promedio * digito1;
	}
	return rspt;
}

/*Determinar que cálculo realizar según los números*/
void CalcularOperaciones(int num1, int num2, int cantCifras1, int cantCifras2, int *rspt, int *operacionValida){
	int cantCifrasMenor, cantCifrasMayor, numMenor, numMayor;
	if(num1 >= 10 && num2 >= 10 && validarCifras(num1, cantCifras1) && validarCifras(num2, cantCifras2)){
		/*Cuando la cantidad de cifras de ambos números es la misma*/
		if(cantCifras1 == cantCifras2){
			*rspt = calcularMultiplicacionCantidadCifrasIguales(num1, num2, cantCifras1);
		}else{
			/*Determinar cuales números son menores y mayores y sus respectiva cantidad de cifras*/
			if(cantCifras1 > cantCifras2){
				cantCifrasMenor = cantCifras2;
				cantCifrasMayor = cantCifras1;
				numMenor = num2;
				numMayor = num1;
			}else{
				cantCifrasMenor = cantCifras1;
				numMenor = num1;
				numMayor = num2;
				cantCifrasMayor = cantCifras2;
			}
			
			if(cantCifrasMenor%2 == 0){
				*rspt = calcularMultiplicacionCifraMenorPar(numMayor, numMenor, cantCifrasMenor, cantCifrasMayor);
			}else{
				*rspt = calcularMultiplicacionCifrasMenorImpar(numMayor, numMenor, cantCifrasMenor, cantCifrasMayor);
			}
		}
		*operacionValida = 1;
	}else{
		*operacionValida = 0;
	}
}

/*Calculo cuando la cantidad de cifras es la misma de ambos números*/
int calcularMultiplicacionCantidadCifrasIguales(int n1, int n2, int cifras){
	int i, rspt = 0, digito1, digito2;
	for(i = 0; i < cifras; i++){
		if(i%2 == 0){
			digito1 = n1 % 10;
			n1 /= 10;
			digito2 = n2 / (int)pow(10, cifras - i - 1);
			n2 %= (int)pow(10, cifras - i - 1);
		}else{
			digito1 = n1 / (int)pow(10, cifras - i - 1);
			n1 %= (int)pow(10, cifras - i - 1);
			digito2 = n2 % 10;
			n2 /= 10;
		}
		rspt += digito2 * digito1;
	}
	return rspt;
}
/*Validar cifras*/
int validarCifras(int n, int cifras){
	return (int)log10(n) + 1 == cifras;
}
