#include <stdio.h>
#include <math.h>

int validarDatos(int numero, int tipoOrdenamiento);
void ordenarNumeroCalcularDiferencia(int num, int opc, int *nuevoNum, int *diferencia);
int verificarNumeroMenorMayor(int num, int opcion);

int main(){
	int numero, opcion, nuevoNum, diferencia;
	printf("Ingrese un número: ");
	scanf("%d", &numero);
	printf("Ingrese el tipo de ordenamiento (1: ascendente, 2: descendente): ");
	scanf("%d", &opcion);
	if(validarDatos(numero, opcion)){
		ordenarNumeroCalcularDiferencia(numero, opcion, &nuevoNum, &diferencia);
		if(opcion = 1){
			printf("El número con los dígitos en forma ascendente es %d\n", nuevoNum);
		}else{
			printf("El número con los dígitos en forma descendente es %d\n", nuevoNum);
		}
		printf("La diferencia entre el número ingresado y el número ordenado es: %d\n", diferencia);
	}else{
		printf("Datos incorrectos\n");	
	}
	return 0;
}

void ordenarNumeroCalcularDiferencia(int num, int opc, int *nuevoNum, int *diferencia){
	int numMayor, numMenor, numAux, i, exponente = log10(num) + 1, d2, d1, aux, iteracion = 0, copiaNum = num;
	*nuevoNum = 0;
	while(num > 0){
		if(opc == 1){
			if(iteracion == 0){
				numMenor = verificarNumeroMenorMayor(num, 1);
			}else{
				numMenor++;
			}
			numAux = num;
			i = 0;
			aux = 0;
			while(numAux > 0){
				d1 = numAux % 10;
				numAux /= 10;
				if(d1 == numMenor){
					(*nuevoNum) += d1 * (int)pow(10, exponente - 1);
					exponente--;
				}else{
					aux += d1 * (int) pow(10, i);
					i++;
				}
				printf("%d %d\n", *nuevoNum, aux);
			}
			num = aux;
			iteracion++;
		}else{
			if(iteracion == 0){
				numMayor = verificarNumeroMenorMayor(num, 2);
			}else{
				numMayor--;
			}
			numAux = num;
			i = 0;
			aux = 0;
			while(numAux > 0){
				d2 = numAux % 10;
				numAux /= 10;
				if(d2 == numMayor){
					(*nuevoNum) += d2 * (int)pow(10, exponente - 1);
					exponente--;
				}else{
					aux += d2 * (int) pow(10, i);
					i++;
				}
			}
			num = aux;
			iteracion++;
		}
	}
	*diferencia = abs(copiaNum - *nuevoNum);
}

int validarDatos(int numero, int tipoOrdenamiento){
	return numero > 0 && (tipoOrdenamiento == 1 || tipoOrdenamiento == 2);
}

int verificarNumeroMenorMayor(int num, int opcion){
	int i = 0, d, menor, mayor;
	while(num > 0){
		d = num % 10;
		num /= 10;
		if(opcion == 1){
			if(i == 0){
				menor = d;
			}else{
				if(d < menor){
					menor = d;
				}
			}
		}else{
			if(i == 0){
				mayor = d;
			}else{
				if(d > mayor){
					mayor = d;
				}
			}
		}
		i++;
	}
	if(opcion == 1){
		return menor;
	}else{
		return mayor;
	}
}
