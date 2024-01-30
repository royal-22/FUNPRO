#include <stdio.h>

int mayus(char letra);
char codificacion(char c, int n);
char decodificacion(char c, int n);

int main(){
	int caracteresDesplazamiento, codificarDecodificar, c1Valido, c2Valido, c3Valido, c4Valido;
	char caracter1, caracter2, caracter3, caracter4,  cModificado1, cModificado2, cModificado3, cModificado4;
	printf("Ingrese la cantidad a caracteres de desplazamiento: ");
	scanf("%d", &caracteresDesplazamiento);
	
	if((caracteresDesplazamiento > 0 && caracteresDesplazamiento <= 25)){
		printf("Ingrese 1 palabra para codificar o 2 para decodificar: ");
		scanf("%d", &codificarDecodificar);	
		if(codificarDecodificar == 1 || codificarDecodificar == 2){
			printf("Ingrese la palabra de 4 caracteres: ");
			scanf("\n%c%c%c%c", &caracter1, &caracter2, &caracter3, &caracter4);
			c1Valido = mayus(caracter1);
			c2Valido = mayus(caracter2);
			c3Valido = mayus(caracter3);
			c4Valido = mayus(caracter4);
			printf("%c%c%c%c\n", caracter1, caracter2, caracter3, caracter4);
			if( c1Valido && c2Valido && c3Valido && c4Valido){
				if(codificarDecodificar == 1){
					cModificado1 = codificacion(caracter1, caracteresDesplazamiento);
					cModificado2 = codificacion(caracter2, caracteresDesplazamiento);
					cModificado3 = codificacion(caracter3, caracteresDesplazamiento);
					cModificado4 = codificacion(caracter4, caracteresDesplazamiento);
					printf("La palabra codificada es: %c %c %c %c\n", cModificado1, cModificado2, cModificado3, cModificado4);
				}else{
					cModificado1 = decodificacion(caracter1, caracteresDesplazamiento);
					cModificado2 = decodificacion(caracter2, caracteresDesplazamiento);
					cModificado3 = decodificacion(caracter3, caracteresDesplazamiento);
					cModificado4 = decodificacion(caracter4, caracteresDesplazamiento);
					printf("La palabra decodificada es: %c %c %c %c\n", cModificado1, cModificado2, cModificado3, cModificado4);
				}
			}else{
				printf("El caracter ingresado no es una letra mayúscula válida.\n");
				printf("No se puede continuar con la codificación-decodificación de la palabra.\n");
			}
		}else{
			printf("Error al ingresar la opción para codificar o decodificar\n");
		}
	}else{
		printf("Error al ingresar la cantidad de caracteres para realizar el cifrado.\n");
	}
	
	return 0;
}

char decodificacion(char c, int n){
	int dividendo = c - n - 'A', cDecodificado;
	
	if(dividendo < 0){
		cDecodificado = (dividendo%26 + 26)%26 + 'A';
	}else{
		cDecodificado = dividendo%26 + 'A';
	}
	printf("%c\n", cDecodificado);
	return cDecodificado;
}

char codificacion(char c, int n){
	return (c + n - 'A')%26 + 'A';
}

int mayus(char letra){
	return letra >= 'A' && letra <= 'Z';
}
