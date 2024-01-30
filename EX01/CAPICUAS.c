#include <stdio.h>
#include <math.h>

int evaluarDatos(int numero, int cifras);
void evaluarCapicuas(int cifras, int numero, int *capicuas, int *icapicuas, int *dcapicuas);
int esCapicua(int cifras, int numero);

int main(){
	int cifrasNumero, numero, iCapicuas, Capicuas, dCapicuas;
	printf("Ingrese la cantidad de cifras de un número: ");
	scanf("%d", &cifrasNumero);

	if(cifrasNumero == 4 || cifrasNumero == 5){
		printf("Ingrese el número a evaluar: ");
		scanf("%d", &numero);
		if(evaluarDatos(numero, cifrasNumero)){
			evaluarCapicuas(cifrasNumero, numero, &Capicuas, &iCapicuas, &dCapicuas);
			
			if(Capicuas == 1 || iCapicuas == 1 || dCapicuas == 1){
				printf("El número es distinguido :\n");
				if(iCapicuas == 1){
					printf("i-Capicúas\n");
				}
				
				if(Capicuas == 1){
					printf("Capicuas\n");
				}
				if(dCapicuas == 1){
						printf("d-Capicuas\n");
					}
				
			}else{
				printf("El número no es distinguido.\n");
			}
		
		}else{
			printf("El número ingresado no concuerda con la cantidad de cifras ingresada.\n");
		}
	}else
	printf("La cantida de cifras ingresada no es correcta.\n");
	
	return 0;
}

int esCapicua(int cifras, int numero){
	int i = 0, x, copiaNumero, numeroInvertido = 0;
	copiaNumero = numero;
	while(i < cifras){
		x = numero%10;
		numeroInvertido += x * pow(10, cifras-1-i);
		numero /= 10;		
		i++;
	}
	printf("%d %d %d\n", numeroInvertido, copiaNumero, numeroInvertido == copiaNumero);

	return numeroInvertido == copiaNumero;
	
}

void evaluarCapicuas(int cifras, int numero, int *capicuas, int *icapicuas, int *dcapicuas){
	int numeroICapicua, numeroDCapicua;
	numeroDCapicua = numero/10;
	numeroICapicua = numero% (int)pow(10, cifras - 1);
	printf("%\n", numeroICapicua);
	if(esCapicua(cifras, numero)){
		*capicuas=1;
	}
	if(esCapicua(cifras - 1, numeroICapicua)){
		*icapicuas=1;
	}
	if(esCapicua(cifras - 1, numeroDCapicua)){
		*dcapicuas=1;
	}
	printf("%d %d %d", *dcapicuas, *icapicuas, *capicuas);
}

int evaluarDatos(int numero, int cifras){
	return cifras == (int) log10(numero) + 1;
}
