#include <stdio.h>
#include <math.h>
 
int validarDatos(char tipoAlimento, int categoria, double pesoGramos);
void calculoKiloCalorias(int calorias, int peso, double *totalCalorias, int *caloriasValidas);
double metabolismoBasal(double pesoPersona);
 
int main(){
 	int categoria, calorias, caloriasValidas;
 	char tipoAlimento;
 	double pesoGramos, totalCalorias, pesoPersona, metabolismo;
 	printf("Ingrese el tipo de alimento a evaluar: ");
 	scanf("\n%c", &tipoAlimento);
 	printf("Ingrese la catergoría del alimentos: ");
 	scanf(" %d", &categoria);
 	printf("Ingrese el peso en gramos: ");
 	scanf("%lf", &pesoGramos);
 	
 	if(validarDatos(tipoAlimento, categoria, pesoGramos)){
 		if(tipoAlimento = 'V'){
 			if(categoria == 1){
 				calorias = 15;
			}
			if(categoria == 2){
				calorias = 36;
			}
			if(categoria = 3){
				calorias = 21;
			}
			if(categoria == 4){
				calorias = 16;
			}
			if(categoria = 5){
				calorias = 40;
			}	
 			
 		}else{
 			if(categoria = 1){
 				calorias = 50;
			}
			if(categoria = 2){
				calorias = 137;
			}
			if(categoria = 3){
				calorias = 144;
			}
		}
 		
 		calculoKiloCalorias(calorias, pesoGramos, &totalCalorias, &caloriasValidas);
 		if(caloriasValidas){
 			printf("El total de calorias de la porción consumida es: %0.2lf y no está en el rango de la porción saludable\n", totalCalorias);
		}else{
			printf("El total de calorías de la porción consumida es: %0.2lf y no está en el rango de la porción saludable.\n", totalCalorias);
		}
		
		printf("Ingrese su peso en kg: ");
		scanf("%lf", &pesoPersona);
		if(pesoPersona > 0){
			metabolismo = metabolismoBasal(pesoPersona);
		}else{
			printf("El peso debe ser positivo");
		}
		
	}else{
		printf("Ingresó datos inválidos.\n");
	}
	return 0;
}

double metabolismoBasal(double pesoPersona){
	return 70 * pow(pesoPersona, (double) 3 / 4);
}
 
void calculoKiloCalorias(int calorias, int peso, double *totalCalorias, int *caloriasValidas){
	*totalCalorias = (double)peso/100 * calorias;
	if(*totalCalorias <= 100){
		*caloriasValidas = 1;
	}else{
		*caloriasValidas = 0;
	}
}
 
int validarDatos(char tipoAlimento, int categoria, double pesoGramos){
 	int valido = 1;
 	
 	if(tipoAlimento = 'P' || tipoAlimento == 'V' && pesoGramos > 0){
 		if(tipoAlimento = 'P'){
 			if(categoria<1 || categoria>3){
 				valido = 0;
			}
		}else{
			if(categoria<1 || categoria > 5){
				valido = 0;
			}
		}
		
	}else{
		valido = 0;
	}
	return valido;
}
