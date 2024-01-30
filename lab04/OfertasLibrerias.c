#include <stdio.h>
#define DLibro1 0.2
#define Dlibro2 0.3
#define DLibro3 0.4
#define DLibro4 0.5
#define Mayores50 0.45


void LeerDatos(int *libroCodigo, int *edadCliente, int *cantidadLibros);
double descuentoPorEdad(int edadCliente);
void descuentoFinal(int descuentoEdad, int descuentoLibro,int *descuentoFinal, int *descuentoLibroTotal, int *descuentosEdadTotal);
int main(){
	int cantidadPersonas, i = 0;
	printf("Ingrese la cantidad de personas que realizaron una compra: ");
	scanf("%d", &cantidadPersonas);
	if(cantidadPersonas > 0){
		int librosCodigo1 = 0, librosCodigo2 = 0, librosCodigo3 = 0, librosCodigo4 = 0, peluchesTotal = 0, 
		agendasTotal = 0, separadoresTotal = 0, descuentosEdadTotal = 0, descuentosLibroTotal = 0, clientesProcesados;
		while(i <  cantidadPersonas){
			int libroCodigo, edadCliente, cantidadLibros, precioLibro;
			double descuentoEdad, descuentoLibro, precioFinal;
			printf("Para el cliente %d\n", i+1);
			LeerDatos(&libroCodigo, &edadCliente, &cantidadLibros);
			if( edadCliente > 18 && edadCliente < 90 && cantidadLibros > 0 && libroCodigo >= 1 && libroCodigo <= 4){
				descuentoEdad = descuentoPorEdad(edadCliente);
	
				if(libroCodigo == 1){
					descuentoLibro = DLibro1;
					precioLibro = 120;
				}
				if(libroCodigo == 2){
					descuentoLibro = DLibro2;
					precioLibro = 100;
				}
				if(libroCodigo == 3){
					descuentoLibro = DLibro3;
					precioLibro = 70;
				}
				if(libroCodigo == 4){
					descuentoLibro = DLibro4;
					precioLibro = 65;
				}
				descuentoFinal(descuentoEdad, descuentoLibro, &descuentoFinal, &descuentoLibroTotal, &descuentosEdadTotal);
				precioFinal = 
				clientesProcesados++;
			}
			else{
				printf("Alguno de los datos no es válido, por lo que no se procesará el cliente %d\n", i+1);
			}
			i++;
		}
		
	}
	else{
		printf("La cantidad de personas debe ser mayor a 0.\n");
	}
	return 0;
}

void descuentoFinal(int descuentoEdad, int descuentoLibro,int *descuentoFinal, int *descuentoLibroTotal, int *descuentosEdadTotal){
	if(descuentoEdad > descuentoLibro){
		descuentoFinal = descuentoEdad;
		descuentosEdadTotal++;
	}
	else{
		descuentoFinal = descuentoEdad;
		descuentosLibroTotal++;
	}
}


void LeerDatos(int *libroCodigo, int *edadCliente, int *cantidadLibros){
	printf("1: Roma soy yo\n");
	printf("2: Los genios\n");
	printf("3: Mi fiesta es mía\n");
	printf("4: Un bárbaro en París\n");
	printf("Ingrese el código del libro: ");
	scanf("%d", libroCodigo);
	printf("Ingrese la edad del cliente: ");
	scanf("%d", edadCliente);
	printf("Ingrese la cantidad de libros que compró: ");
	scanf("%d", cantidadLibros);
}

double descuentoPorEdad(int edadCliente){
	double edadDescuento;
	if(edadCliente >= 30){
		if(edadCliente < 50){
			edadDescuento = 0.35; 
		}
		else{
			edadDescuento = 0.45;
		}
	}
	else{
		edadDescuento = 0.25;
	}
	return edadDescuento;
}
