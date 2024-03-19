#include <stdio.h>
#include <math.h>

/*
Nombre: Luciana Carrillo 
Codigo: 20230558
 */
 
 int main(){
 	double catetoTrianguloAF1, catetoTrianguloDF2, baseMenorF3;
 	printf("FIGURA 1\n");
 	printf("Ingrese el cateto del triángulo A: ");
 	scanf("%lf", &catetoTrianguloAF1);
 	
 	printf("FIGURA 2\n");
 	printf("Ingrese el cateto del triángulo D: ");
 	scanf("%lf", &catetoTrianguloDF2);
 	
 	printf("FIGURA 3\n");
 	printf("Ingrese la base menor del paralelogramo: ");
 	scanf("%lf", &baseMenorF3);
 	
 	/* Calculos para la figura 1 */
 	double areaTotalF1,areaTrianguloDF1, areaTrianguloAF1, areaTrianguloBF1, areaCuadradoF1, areaParalelogramoF1;
 	areaTrianguloAF1 = (pow(catetoTrianguloAF1, 2)) / 2;
 	areaTrianguloBF1 = 2 * areaTrianguloAF1; 
 	areaTrianguloDF1 = (pow(catetoTrianguloAF1 * 2, 2)) / 2;
 	/* Como el cateto del triangulo A es igual al lado del cuadrado de C*/
 	areaCuadradoF1 = pow(catetoTrianguloAF1, 2);
 	/*Como la base menor del paralelogramo es igual al lado del cuadrado entonces 
	 igual cateto del triangulo A y su altura es igual a cateto del triangulo A*/
	areaParalelogramoF1 = catetoTrianguloAF1 * catetoTrianguloAF1;
	areaTotalF1 = areaTrianguloAF1 * 2 + areaTrianguloBF1 + areaTrianguloDF1 * 2 + areaCuadradoF1 + areaParalelogramoF1;    
	
 	
 	/* Calculos para la figura 2 */
 	double areaTotalF2,areaTrianguloDF2, areaTrianguloAF2, areaTrianguloBF2, areaCuadradoF2, areaParalelogramoF2;
 	areaTrianguloDF2 = (pow(catetoTrianguloDF2, 2)) / 2;
 	areaTrianguloAF2 = (pow(catetoTrianguloDF2 / 2, 2)) / 2;
 	areaTrianguloBF2 = areaTrianguloAF2 * 2;
 	areaCuadradoF2 = pow(catetoTrianguloDF2/2, 2);
 	areaParalelogramoF2 = (catetoTrianguloDF2 / 2) * (catetoTrianguloDF2 / 2);
 	areaTotalF2 = areaTrianguloAF2 * 2 + areaTrianguloBF2 + areaTrianguloDF2 * 2 + areaCuadradoF2 + areaParalelogramoF2;
 	
	 /* Calculos para la figura 3 */
 	double areaTotalF3,areaTrianguloDF3, areaTrianguloAF3, areaTrianguloBF3, areaCuadradoF3, areaParalelogramoF3;
	areaTrianguloAF3 = (pow(baseMenorF3, 2)) / 2;
	areaTrianguloBF3 = areaTrianguloAF3 * 2;
	areaTrianguloDF3 = (pow(baseMenorF3 * 2, 2)) / 2;
	areaCuadradoF3 = (pow(baseMenorF3, 2));
	areaParalelogramoF3 = baseMenorF3 * baseMenorF3; 
 	areaTotalF3 = areaTrianguloAF3 * 2 + areaTrianguloBF3 + areaTrianguloDF3 * 2 + areaCuadradoF3 + areaParalelogramoF3;
 	/* Realizar comparaciones */
	double areaMayor = ((areaTotalF3 > areaTotalF2) && (areaTotalF3 > areaTotalF1)) * 3 +  ((areaTotalF2 > areaTotalF1) && (areaTotalF2 > areaTotalF3)) *2 + ((areaTotalF1 > areaTotalF3) && (areaTotalF1 > areaTotalF2)) * 1;
	
	double TrianguloDMayor = ((areaTrianguloDF3 > areaTrianguloDF2) && (areaTrianguloDF3 > areaTrianguloDF1)) * 3 + ((areaTrianguloDF2 > areaTrianguloDF3) && (areaTrianguloDF2 > areaTrianguloDF1)) * 2 + ((areaTrianguloDF1 > areaTrianguloDF3) && (areaTrianguloDF1 > areaTrianguloDF2)) * 1;
	
	
 	/* Imprimir valores */
 	printf("El área total de la figura 1 es: %lf\n", areaTotalF1);
 	printf("El área total de la figura 2 es: %lf\n", areaTotalF2);
 	printf("El área total de la figura 3 es: %lf\n", areaTotalF3);
 	printf("La figura con mayor área total es la figura: %.0lf\n", areaMayor);
 	printf("El área del triángulo D de la figura 1 es: %lf\n", areaTrianguloDF1);
	printf("El área del triángulo D de la figura 2 es: %lf\n", areaTrianguloDF2);
 	printf("El área del triángulo D de la figura 3 es: %lf\n", areaTrianguloDF3);
	printf("El triángulo D con mayor área se encuentra en la figura: %.0lf\n", TrianguloDMayor);
 	return 0;
 }
