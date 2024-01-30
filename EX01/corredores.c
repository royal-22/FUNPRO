#include <stdio.h>
#include <math.h>

int frecuenciaCardiacaCalculo(int frecuenciaCardiaca, double fcm);

int main(){
	int corredores, distancia, i = 0;
	printf("Ingrese la cantidad de corredores: ");
	scanf("%d", &corredores);
	printf("Ingresar la distancia en km: ");
	scanf("%d", &distancia);
	if(distancia == 10 || distancia == 5 && corredores > 0){
		int horas, minutos, segundos, pasos, frecuenciaCardiaca, edad, fmpNoValidas=0, fmp4y5=0, cadencia, zona; 
		double minutosTotales, fmp;
		char sexo;
		while(i < corredores){
			printf("Corredor [%d]\n", i+1);
			printf("Edad: ");
			scanf("%d", &edad);
			printf("Sexo [H:hombre | M:mujer]: ");
			scanf("\n%c", &sexo);
			printf("Tiempo hh:mm:ss: ");
			scanf("\n%d %d %d", &horas, &minutos, &segundos);
			printf("Cantidad de pasos: ");
			scanf("%d", &pasos);
			printf("Frecuencia cardiaca: ");
			scanf("%d", &frecuenciaCardiaca);  
			minutosTotales = horas*60 + minutos + (double)segundos / 60;
			printf("%lf\n", minutosTotales);
			cadencia = (double)pasos / minutosTotales;
			if(sexo == 'M'){
				fmp = 226 - edad;
			}else{
				fmp = 220 - edad;
			}
			printf("La cadencia es: %d\n", cadencia);
			printf("%lf %d\n", fmp, frecuenciaCardiaca);
			zona = frecuenciaCardiacaCalculo(frecuenciaCardiaca, fmp);
			printf("%lf  %d\n", fmp, zona);
			if(zona == 0){
				fmpNoValidas += 1;
			}else{
				if(zona == 4 || zona == 5){
				fmp4y5 += 1;
				}
			}
			
			i++;
		}
		printf("Hay %d corredores en zonas 4 y 5 de la frecuencia cardiaca\n", fmp4y5);
		printf("Hubo %d tomas erróneas de la frecuencia cardiaca\n", fmpNoValidas);
	
	}else{
		if(corredores <= 0){
			printf("La cantidad de corredores es incorrecta.\n");
		}else{
			printf("La distancia es incorrecta.\n");	
		}
	}
	return 0;
}

int frecuenciaCardiacaCalculo(int frecuenciaCardiaca, double fcm){
	int valor;
	
	if(frecuenciaCardiaca <= fcm * 0.60){
		return 1;
	}
	else if(frecuenciaCardiaca <= fcm * 0.70){
		return 2;
	}
	else if(frecuenciaCardiaca <= fcm * 0.80){
		return 3;
	}
	else if(frecuenciaCardiaca <= fcm * 0.90){
		return 4;
	}
	else if(frecuenciaCardiaca <= fcm){
		return 5;
	}
	else{
		return 0;
	}
	
}

