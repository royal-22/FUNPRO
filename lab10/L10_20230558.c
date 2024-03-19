#include <stdio.h>
/*
Nombre: Luciana Carrillo
Codigo: 20230558
*/

/*Declarar prototipos*/
void buscarFechaCuriosaBisiesta(int dia, int mes, int ano, int *anoCB, int *mesCB, int* diaCB);
int validarFecha(int dia, int mes, int ano);
int esBisiesto(int ano);
int siguenteBisiesto(int ano);
int multiplicacionFechas(int dia,int mes,int ano);

int main(){
	int centinela = 1, dia, mes, ano, anoCB, mesCB, diaCB, fechasCuriosasIngresadas = 0, fechasCuriosasSiguientes = 0, ingresosValidos = 0;
	while(centinela){
		printf("Ingrese una fecha (día/ mes / año): ");
		scanf("%d %d %d", &dia, &mes, &ano);
		if(dia == 0 && mes == 0 && ano == 0){
			centinela = 0;
			break;
		}
		if(validarFecha(dia, mes, ano)){
			buscarFechaCuriosaBisiesta(dia, mes, ano, &anoCB, &mesCB, &diaCB);
			if(diaCB < 10){
				printf("0%d /", diaCB);
			}else{
				printf("%d /", diaCB);
			}
			if(mesCB < 10){
				printf(" 0%d /", mesCB);
			}else{
				printf(" %d /", mesCB);
			}
			printf(" %d es una fecha curiosa bisiesta porque ", anoCB);
			if(diaCB < 10){
				printf("0%d x", diaCB);
			}else{
				printf("%d x", diaCB);
			}
			if(mesCB < 10){
				printf(" 0%d = ", mesCB);
			}else{
				printf(" %d = ", mesCB);
			}
			if(anoCB%100 < 10){
				printf("0%d\n", anoCB%100);
			}else{
				printf("%d\n", anoCB%100);
			}
			if(dia == diaCB && mes == mesCB && ano == anoCB){
				fechasCuriosasIngresadas++;
			}else{
				fechasCuriosasSiguientes++;
			}
			ingresosValidos++;
		}else{
			printf("Ingresó una fecha inválida\n");
		}
			
	}
	if(ingresosValidos > 0){
		printf("\n---------------------------------------------\n");
		printf("En el rango se ingresaron:\n");
		printf("- %d fechas curiosas bisiestas\n", fechasCuriosasIngresadas);
		printf("- %d siguientes fechas curiosas bisiestas\n", fechasCuriosasSiguientes);		
	}

	return 0;
}

int multiplicacionFechas(int dia,int mes,int ano){
	return ( dia * mes == ano%100);
}

void buscarFechaCuriosaBisiesta(int dia, int mes, int ano, int *anoCB, int *mesCB, int* diaCB){
	int centinela1 = 1, maxDias, j, k, encontrado = 0;
	while(centinela1){
		if(multiplicacionFechas(dia, mes, ano) && esBisiesto(ano)){
			centinela1 = 0;
			*anoCB = ano;
			*mesCB = mes;
			*diaCB = dia;
			break; 
		}else{
			printf("No es una fecha curiosa bisiesta, por lo tanto se buscará la siguiente fecha curiosa bisiesta: \n");
			ano = siguienteBisiesto(ano);
			int ultimasCifras = ano%100;
			for(j = 1; j <= 12; j++){
				
				if(encontrado){
					break;
				}
				/*j es para contar los meses y k es para contar los días*/
				if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12){
					maxDias = 31;
				}else{
					if(j == 4 || j == 6 || j == 9 || j == 11){
						maxDias = 30;
					}else{
						maxDias = 29;
					}
				}
				for(k = 1; k <= maxDias; k++){
					if(k * j == ultimasCifras){
						encontrado = 1;
						*anoCB = ano;
						*mesCB = j;
						*diaCB = k;
						centinela1 = 0;
						break;
					}
				}
			}
		}
	}
}
/*
--------------------------------------------------Tabla de datos---------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------
iteracion    centinela1     ano     mes     dias     j       k      maxDias     encontrado     *ano      *mes     *dia    ultimasCifras
    0            1          2003    12       28      ND      ND      ND           0             ND         ND      ND          ND
    1            1          2004    12        28     1       1       31           0              ND        ND      ND           4
    2            1          2004    12        28     1       2       31           0              ND        ND      ND           4
    3            1          2004    12        28     1       3       31           0              ND        ND      ND           4
    4            0          2004    12        28     1       4       31           1              2004      01      04           4
*/

int siguienteBisiesto(int ano){
	do{
		ano++;
	}while(!(esBisiesto(ano)));
	return ano;
}

int esBisiesto(int ano){
	return ano%4 == 0 || (ano%100 == 0 && ano%400 == 0);
}
/*Validar fecha*/
int validarFecha(int dia, int mes, int ano){
	int meses31dias, meses30dias, febrero;
	meses31dias = (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12);
	meses30dias = (mes == 4 || mes == 6 || mes == 9 || mes == 11);
	febrero = (esBisiesto(ano) && dia <= 29 && dia >= 1) || (!esBisiesto(ano) && dia <= 28 && dia >= 1);
	return ((meses31dias && dia <= 31 && dia >= 1) || (meses30dias && dia == 30 && dia <= 31 && dia >= 1) || (febrero && mes == 2)) && ano >= 2000;
}
