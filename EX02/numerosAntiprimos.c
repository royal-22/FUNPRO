#include <stdio.h>

void calcularNumerosAntiprimos(int inicio, int fin, int *existenAntiprimos, int *cantAntiprimos);
void esAntiprimo(int num, int *existe, int *divisores, int *numeroMayor, int *mayorDivisores);
int calcularDivisores(int n);

int main(){
	int inicio, fin, cantAntiprimos, existenAntiprimos;
	char opc;
	while(1){
		printf("Ingrese un rango de números positivos mayores a 1: ");
		scanf("%d %d", &inicio, &fin);
		if(fin > inicio && inicio > 1){
			cantAntiprimos = 0;
			calcularNumerosAntiprimos(inicio, fin, &existenAntiprimos, &cantAntiprimos);
			if(existenAntiprimos){
				printf("En el rango [%d, %d] hay %d númerosAntiprimos\n", inicio, fin, cantAntiprimos);
			}else{
				printf("En el rango [%d, %d] NO hay números antiprimos\n", inicio, fin);
			}
		}else{
			printf("Rango Incorrecto\n");
		}
		do{
			printf("Desea evaluar otro rango: ");
			scanf(" %c", &opc);
			if(opc == 'S' || opc == 's' || opc == 'N' || opc == 'n'){
				break;
			}else{
				printf("Opción incorrecta\n");
			}
		}while(1);
		if(opc == 'N' || opc == 'n'){
			break;
		}
	}
	printf("Fin de la evaluación de números antiprimos\n");
	return 0;
}

int calcularDivisores(int n){
	int i, cantDivisores = 0;
	for(i = 1; i <= n; i++){
		if(n % i == 0){
			cantDivisores++;
		}
	}
	return cantDivisores;
}

void esAntiprimo(int num, int *existe, int *divisores, int *numeroMayor, int *mayorDivisores){
	int i, divAnterior, anteriorMayor;
	*existe = 1;
	*divisores = calcularDivisores(num);
	for(i = num - 1; i > 0; i--){
		divAnterior = calcularDivisores(i);
		if(divAnterior >= *divisores){
			*existe = 0;
			*numeroMayor = i;
			*mayorDivisores= divAnterior;
			break;
		}
	}
}

void calcularNumerosAntiprimos(int inicio, int fin, int *existenAntiprimos, int *cantAntiprimos){
	int i, es, divisores, numeroMayor, mayorDivisores;
	*existenAntiprimos = 0;
	for(i = inicio; i <= fin; i++){
		esAntiprimo(i, &es, &divisores, &numeroMayor, &mayorDivisores);
		if(es){
			printf("%d tiene %d divisores, es antiprimo\n", i, divisores);
			(*cantAntiprimos)++;
			*existenAntiprimos = 1;
		}else{
			printf("%d tiene %d divisores, no es antiprimo ya que el número %d tiene %d divisores\n", i, divisores, numeroMayor, mayorDivisores);
		}
	}
}
