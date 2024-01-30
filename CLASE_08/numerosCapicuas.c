#include <stdio.h>
#include <math.h>
int evaluarDatos(int cifras, int numero);
void evaluarCapicuas(int cifras, int numero, int *capicua, int *i_capicua, int *d_capicua);
int evaluarSiEsCapicua(int cifras, int numero);

int main(){
	int cifras, numero;
	printf("Ingrese la cantidad de cifras de un número: ");
	scanf("%d", &cifras);
	if(cifras<4 || cifras > 5){
		printf("La cantidad de cifras ingresada no es correcta.\n");
	}
	else{

		printf("Ingrese el número a evaluar: ");
		scanf("%d", &numero);
		
		int capicua, i_capicua, d_capicua;
		if(evaluarDatos(cifras, numero)){
			evaluarCapicuas(cifras, numero, &capicua, &i_capicua, &d_capicua);
			
			if(capicua || i_capicua || d_capicua){
				printf("El número es Distinguido porque es: \n");
				if(capicua){
					printf("Capicua\n");
				}
				if(i_capicua){
					printf("i-Capicua\n");
				}
				if(d_capicua){
					printf("d-Capicua\n");
				}
			}
		}
	}
}

int evaluarCapicua(int cifras, int numero){
	int nInvertido = 0;
	int i = 0;
	int copiaNum = numero;
	while(i<cifras){
		int digito = numero%10;
		numero /= 10;
		nInvertido += digito * pow(10, cifras - 1 - i);
		i++;
	}
	return nInvertido == copiaNum;
}

int evaluarDatos(int cifras, int numero){
	return(pow(10, cifras-1) <= numero) && (numero < pow(10, cifras));
	/*return (log10(numero) + 1) == cifras;*/
}

void evaluarCapicuas(int cifras, int numero, int *capicua, int *i_capicua, int *d_capicua){
	int numeroI = numero % (int)pow(10, cifras - 1);
	int numeroD = (numero / 10);
	*capicua = evaluarCapicua(cifras, numero);
	*i_capicua = evaluarCapicua(cifras - 1, numeroI);
	*d_capicua = evaluarCapicua(cifras -1, numeroD);

}
