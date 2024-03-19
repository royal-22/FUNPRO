#include <stdio.h>

/*
Nombre: Luciana Carrillo
Código: 20230558
*/
/* Declarar prototipos */
int validarDatos(int inicio, int fin, int k, char opc);
int sumaDivisores(int num, int incluir1, int incluirN);
void identificarNumero(int inicio, int fin, int valorK, char opc, int *totalNumeros, int *primerNum, int *primerK);

int main(){
	int inicio, fin, valorK, totalNumeros, primerNum, primerK;
	char opc;
	/* Solicitar datos de entrada */
	printf("Ingrese rango de números: ");
	scanf("%d %d", &inicio, &fin);
	printf("Ingrese el máximo valor de k: "),
	scanf("%d", &valorK);
	printf("Ingrese el tipo de número que desea evaluar en el rango\n");
	printf("H, h: Hiperperfecto; M, m: Multiperfecto \n");
	scanf(" %c", &opc);
	printf("-----------------------------------\n");
	if(validarDatos(inicio, fin, valorK, opc)){
		identificarNumero(inicio, fin, valorK, opc, &totalNumeros, &primerNum, &primerK);
		
		/*Imprimir el resumen */
		if(opc == 'M' || opc == 'm'){
			printf("En el rango [%d, %d] hay %d números multiperfectos\n", inicio, fin, totalNumeros);
		}else{
			printf("En el rango [%d, %d] hay %d números hiperperfecto\n", inicio, fin, totalNumeros);
		}
		if(totalNumeros > 0){
			printf("El primer número que cumple con la condición es %d con k = %d", primerNum, primerK);
		}
		
	}else{
		printf("Datos inválidos\n");
	}
	return 0;
}

/* calcular la suma de divisores ya sea tomando en cuenta el número 1 o no así como el número mismo */
int sumaDivisores(int num, int incluir1, int incluirN){
	int suma = 0, inicio, fin, i;
	if(incluir1 && incluirN){
		inicio = 1;
		fin = num;
	}else{
		inicio = 2;
		fin = num - 1;
	}
	for(i = inicio; i <= fin; i++){
		if(num % i == 0){
			suma += i;
		}
	}
	return suma;
}
/* identificar los números que son de determinado tipo dentro del rango ingresado */
void identificarNumero(int inicio, int fin, int valorK, char opc, int *totalNumeros, int *primerNum, int *primerK){
	int i, j, esPrimero = 1, suma;
	
	*totalNumeros = 0;
	for(i = inicio; i <= fin; i++){
		if(opc == 'M' || opc == 'm'){
			suma = sumaDivisores(i, 1, 1); 
		}else{
			suma = sumaDivisores(i, 0, 0);
		}
		/* iterar por los valores de k */
		for(j = 1; j <= valorK; j++){
			/* Si se buscan multiperfectos */
			if(opc == 'M' || opc == 'm'){
				if(suma / j == i){
					if(esPrimero){
						*primerNum = i;
						*primerK = j;
						esPrimero = 0;
					}
					(*totalNumeros)++;
					printf("El número %d es %d-multiperfecto\n", i, j);
				}
			/* Si se buscan hiperperfectos */
			}else{
				if(1 + suma * j == i){
					if(esPrimero){
						*primerNum = i;
						*primerK = j;
						esPrimero = 0;
					}
					(*totalNumeros)++;
					printf("El número %d es %d-hiperperfecto\n", i, j);
				}
			}
		}
	}
}

/* validar datos según lo establecido */
int validarDatos(int inicio, int fin, int k, char opc){
	return fin > inicio && inicio > 1 && k >= 1 && k <= 20 && (opc == 'M' || opc == 'm' || opc == 'H' || opc == 'h');
}
