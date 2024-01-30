#include <stdio.h>

int evaluarDatos(int cantCifras,int numero);
void evaluarCapicuas(int cantCifras,int numero,int *esCapicua,int *esICapicua,int *esDCapicua);
int evaluarSiEsCapicua(int cantCifras,int numero);

int main(){
	int cantCifras, numero, esCapicua, esICapicua, esDCapicua;
	int esValido;
	printf("Ingrese la cantidad de cifras que tiene un número: ");
	scanf("%d",&cantCifras);
	if (cantCifras==4 || cantCifras==5){
		printf("Ingrese el número a evaluar: ");
		scanf("%d",&numero);
		esValido = evaluarDatos(cantCifras,numero);
		if (esValido){
			evaluarCapicuas(cantCifras,numero,&esCapicua,&esICapicua,&esDCapicua);
			if (esCapicua || esICapicua || esDCapicua){
				/*Aqui el número es distinguido*/
				printf("El número es Distinguido porque es: \n");
				if (esCapicua){
					printf("Capicúa\n");
				}
				if (esICapicua){
					printf("i-Capicúa\n");
				}
				if (esDCapicua){
					printf("d-Capicúa\n");
				}
			}
			else {
				printf("El número no es Distinguido");
			}
		}
		else {
			printf("El número ingresado no concuerda con la cantidad de cifras ingresada");
		}
	}
	else {
		printf("La cantidad de cifras ingresada no es correcta");
	}
	return 0;
}

int evaluarDatos(int cantCifras,int numero){
	return (numero>=1000 && numero<=9999 && cantCifras==4) ||  (numero>=10000 && numero<=99999 && cantCifras==5);
}

void evaluarCapicuas(int cantCifras,int numero,int *esCapicua,int *esICapicua,int *esDCapicua){
	int iNumero, dNumero;
	*esCapicua = evaluarSiEsCapicua(cantCifras,numero);
	iNumero = numero % (int)pow(10,cantCifras-1);
	*esICapicua = evaluarSiEsCapicua(cantCifras-1,iNumero);
	dNumero = numero/10;
	*esDCapicua = evaluarSiEsCapicua(cantCifras-1,dNumero);
}

int evaluarSiEsCapicua(int cantCifras,int numero){
	int i, invertido, digito, copiaNum;
	i = 1;
	invertido = 0;
	copiaNum = numero;
	while (i<=cantCifras){
		digito = numero % 10;
		numero = numero / 10;
		invertido = invertido*10 + digito;
		i++;
	}
	return (invertido==copiaNum);
}
