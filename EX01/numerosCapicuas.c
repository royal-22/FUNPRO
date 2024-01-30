#include <stdio.h>
#include <math.h>
int evaluarDatos(int cifras, int numero);
void evaluarCapicuas(int cifras, int numero, int *capicua, int *i_capicua, int *d_capicua);
int evaluarSiEsCapicua(int cifras, int numero);

int main(){
	int cifras, numero;
	printf("Ingrese la cantidad de cifras de un n�mero: ");
	scanf("%d", &cifras);
	if(cifras<4 || cifras > 5){
		printf("La cantidad de cifras ingresada no es correcta.\n");
	}
	else{

		printf("Ingrese el número a evaluar: ");
		scanf("%d", &numero);

		int capicua, i_capicua, d_capicua;
		int esValido = evaluarDatos(cifras, numero);
		if(esValido){
			evaluarCapicuas(cifras, numero, &capicua, &i_capicua, &d_capicua);
			if(capicua || i_capicua || d_capicua){
				printf("El número es Distinguido porque es: ");
				if(capicua){
					printf("Capicua");
				}
				if(i_capicua){
					printf("i-Capicua");
				}
				if(d_capicua){
					printf("d-Capicua");
				}
			}
		}
		else{
			printf("La cantidad de cifras no coinciden con las cifras del número .\n");
		}
	}
}

int evaluarDatos(int cifras, int numero){
	printf("%lf", pow(10, 3));
	return (pow(10, cifras-1) <= (double)numero) && ((double)numero < pow(10, cifras));
	/*printf("%lf\n", log10(numero));
	return (int) log10(numero) + 1 == cifras;*/
}

int evaluarCapicua(int cifras, int numero){
	int nInvertido = 0;
	int i = 0;
	int copiaNum = numero;
	while(i<cifras){
		int digito = numero%10;
		printf("  %d  ", digito);
		numero /= 10;
		int m = pow(10, cifras - 1 - i);
		nInvertido += digito * m ;
		printf("%d  ", nInvertido);
		i++;
	}
	printf("%d  %d\n", nInvertido, copiaNum);
	printf("%d\n", nInvertido == copiaNum);
	return nInvertido == copiaNum;
}


void evaluarCapicuas(int cifras, int numero, int *capicua, int *i_capicua, int *d_capicua){
	int multi10 = pow(10, cifras - 1);
	printf("%d\n", multi10);
	int numeroI = numero % multi10;
	printf("%d\n", numeroI);
	int numeroD = (numero / 10);
	*capicua = evaluarCapicua(cifras, numero);
	*i_capicua = evaluarCapicua(cifras - 1, numeroI);
	*d_capicua = evaluarCapicua(cifras -1, numeroD);

}
