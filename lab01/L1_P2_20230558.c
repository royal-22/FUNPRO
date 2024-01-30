#include <stdio.h>
/* 
Nombre: Luciana Carrillo
Codigo: 20230558
*/

int main(){
	double calorEspecificoCobre, masa, temperaturaInicialC,temperaturaInicialF, temperaturaFinalC, temperaturaFinalF;
	calorEspecificoCobre = 0.093;
	masa = 0.012;
	temperaturaInicialF = 35;
	temperaturaFinalF = 87; 
	
	// Convertir temperatura a grados C° y también transformar masa de gramos a kg
	temperaturaInicialC = temperaturaInicialF * (double)5/9 - 32;
	temperaturaFinalC = temperaturaFinalF * (double)5/9 - 32; 
	masa  = masa * 1000; 
	double variacionTemperatura = temperaturaFinalC - temperaturaInicialC;
	double calorTransferido = masa * calorEspecificoCobre * (variacionTemperatura);
	
	printf("El calor necesario para elevar la temperatura de %.2lf grados Fahrenheit a %.2lf grados Fahrenheit es: %.4lf calorias.", temperaturaInicialF, temperaturaFinalF, calorTransferido);
	return 0;
}
