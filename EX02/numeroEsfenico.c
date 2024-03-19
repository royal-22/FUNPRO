#include <stdio.h>

int esPrimo(int n);
int siguientePrimo(int n);
void evaluarNumerosEsfenicos(int inicio, int fin, int *rangoValido, int *cantEsfenicos);
int esEsfenico(int num);

int main(){
	int inicio, fin, rangoValido, cantEsfenicos, inicioRangoMayor, finRangoMayor, cantRangoMayor, rangoValidos = 0;
	while(1){
		printf("Ingrese el rango: ");
		scanf("%d %d", &inicio, &fin);
		if(inicio == 0 && fin == 0){
			break;
		}else{
			cantEsfenicos = 0;
			evaluarNumerosEsfenicos(inicio, fin, &rangoValido, &cantEsfenicos);
			if(rangoValido){
				rangoValidos++;
				if(cantEsfenicos > 0){
					printf("En el rango [%d, %d] se encontraron %d números esfénicos\n", inicio, fin, cantEsfenicos);
				}else{
					printf("No existen números esfénicos en el rango [%d %d]\n", inicio, fin);
				}
				if(rangoValidos > 0){
					if(rangoValidos == 1){
						finRangoMayor = fin;
						inicioRangoMayor = inicio;
						cantRangoMayor = cantEsfenicos;
					}else{
						if(cantEsfenicos >= cantRangoMayor){
							finRangoMayor = fin;
							inicioRangoMayor = inicio;
							cantRangoMayor = cantEsfenicos;
						}
					}
				}
			}else{
				printf("El rango ingresado no es válido\n");
			}
		}
	}
	if(rangoValidos > 0){
		printf("--------------------------Reporte--------------------\n");
		printf("En el rango [%d, %d] se encontró la mayor cantidad de números esfénicos: %d\n", finRangoMayor, inicioRangoMayor, cantRangoMayor);
	}
	
	return 0;
}

int esEsfenico(int num){
	int i = siguientePrimo(1), divisor1 = 0, divisor2 = 0, divisor3 = 0, cantDivisores = 0;
	while(i < num && cantDivisores != 3){
		if(num % i == 0){
			cantDivisores++;
			if(cantDivisores == 1){
				divisor1 = i;
			}
			if(cantDivisores == 2){
				divisor2 = i;
			}
			if(cantDivisores == 3){
				divisor3 = i;
			}
		}
		i = siguientePrimo(i);
	}
	return num == divisor1 * divisor2 * divisor3;
}

int siguientePrimo(int n){
	do{
		n++;
	}while(!(esPrimo(n)));
	return n;
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

void evaluarNumerosEsfenicos(int inicio, int fin, int *rangoValido, int *cantEsfenicos){
	int i;
	if(fin > inicio && fin > 0 && inicio > 0){
		*rangoValido = 1;
		for(i = inicio; i <= fin; i++){
			if(esEsfenico(i)){
				printf("%d ", i);
				(*cantEsfenicos)++;
			}
		}
		printf("\n");
	}else{
		*rangoValido = 0;
	}
}
