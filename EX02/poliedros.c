#include <stdio.h>
#include <math.h>

void calcularPoliedrosRegulares(int iteraciones);
void calcularPrismaPiramide(int iteraciones);
void calcularAreaVolumen(int caras, double aristas, double *area, double *volumen);

int main(){
	int opc, iteraciones;
	while(1){
		printf("Cálculos a realizar sobre poliedros: \n");
		printf("1: Poliedros regulares\n");
		printf("2: Prismas y pirámides\n");
		printf("3: Salir\n");
		printf("Ingrese la opción seleccionada: ");
		scanf("%d", &opc);
		if(opc == 3){
			break;
		}
		if(opc == 1 || opc == 2){
			printf("Ingrese la cantidad de poliedros a evaluar: ");
			scanf("%d", &iteraciones);
			if(opc == 1){
				calcularPoliedrosRegulares(iteraciones);
			}else{
				calcularPrismaPiramide(iteraciones);
			}
			printf("-----------------------------------------------\n");
		}else{
			printf("Seleccionó una opción inválida\n");
		}
	}
	return 0;
}

void calcularPrismaPiramide(int iteraciones){
	int i, base, altura, opcion;
	double volumen;
	for(i = 1; i <= iteraciones; i++){
		printf("--------------PRISMA / PIRÁMIDE #%d---------------\n", i);
		printf("Ingrese 1 si es prisma o 2 si es piramide: ");
		scanf("%d", &opcion);
		printf("Ingrese el área de la base y la altura: ");
		scanf("%d %d", &base, &altura);
		if(opcion == 1){
			volumen = base * altura;
			printf("El volumen del prisma es %lf\n", volumen);
		}
		if(opcion == 2){
			volumen = (base * altura) / 3;
			printf("El volumen de la piramide es %lf\n", volumen);
		}
		
	}
}

void calcularAreaVolumen(int caras, double arista, double *area, double *volumen){
	
	if(caras == 4){
		*area = sqrt(3) * pow(arista, 2);
		*volumen = (sqrt(2) / 12) * pow(arista, 3);
	}
	if(caras == 6){
		*area = 6 * pow(arista, 2);
		*volumen = pow(arista, 3);
	}
	if(caras == 8){
		*area = 2*sqrt(3) * pow(arista, 2);
		*volumen = sqrt(2) / 3 * pow(arista, 3);
	}
}

void calcularPoliedrosRegulares(int iteraciones){
	int i, caras;
	double arista, area, volumen;
	for(i = 1; i <= iteraciones; i++){
		printf("--------------POLIEDRO REGULAR #%d-------------\n", i);
		do{
			printf("Ingrese la cantidad de caras que tiene el poliedro regular %d: ", i);
			scanf("%d", &caras);
		}while(caras != 4 && caras != 6 && caras != 8);
		printf("Ingrese el valor de la arista: ");
		scanf("%lf", &arista);
		if(caras == 4){
			printf("Poliedro regular: TETRAEDRO\n");
		}
		if(caras == 6){
			printf("Poliedro regular: HEXAEDRO\n");
		}
		if(caras == 8){
			printf("Poliedro regular: OCTAEDRO\n");
		}
		calcularAreaVolumen(caras, arista, &area, &volumen);
		printf("El área del poliedro es %lf\n", area);
		printf("El volumen del poliedro es %lf\n", volumen);
	}
}

