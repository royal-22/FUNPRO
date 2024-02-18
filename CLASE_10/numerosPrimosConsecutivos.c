#include <stdio.h>

int esPrimo(int n);
int siguientePrimo(int n);
int calcularSumatoria(int a);

int main(){
	int a, b, i, cantidadSumas, mayorRepresentaciones, cantidadRepresentaciones;
	printf("Ingrese el rango a y b: ");
	scanf("%d %d", &a, &b);
	if(b > a){
		for(i = 0; i <= (b - a); i++){
			cantidadSumas = calcularSumatoria(a + i);
			printf("El número %d tiene %d representaciones\n", a + i, cantidadSumas);
			if(i==0){
				mayorRepresentaciones = a + i;
				cantidadRepresentaciones = cantidadSumas;
			}else{
				if(cantidadSumas >= cantidadRepresentaciones){
					mayorRepresentaciones = a + i;
					cantidadRepresentaciones = cantidadSumas;
				}
			}
		}
		printf("El número con mayor cantidad de representaciones es %d\n", mayorRepresentaciones);
	}else{
		printf("El rango ingresado no es correcto\n");
	}
	return 0;
}

int siguientePrimo(int n){
	do{
		n++;
	}while(!esPrimo(n));
	return n;
}

int esPrimo(int n){
	int i = 1, contador = 0;
	while(i <= n){
		if(n % i == 0){
			contador++;
		}
		i++;
	}
	return contador == 2;
}

int calcularSumatoria(int a){
	int i = siguientePrimo(1), suma, j, cantidadSumatorias = 0;
	while(i < a){
		suma = i;
		j = i;
		while(suma < a){
			j = siguientePrimo(j);
			suma += j;
			if(suma == a){
				cantidadSumatorias++;
			}
		}
		i = siguientePrimo(i);
	}
	return cantidadSumatorias;
}
