#include <stdio.h>

int main(){
	int dig;
	printf("Ingrese un dígito del 1 al 10: ");
	scanf("%d", &dig);
	switch(dig){
		case 1:
			{
				printf("El valor ingresado es 1\n");
				break;
			}
		case 2:
			{
				printf("El valor ingresado es 2\n");
				break;
			}
		case 3:
			{
				printf("El valor ingresado es 3\n");
				break;
			}
		case 4:
			{
				printf("El valor ingresado es 4\n");
				break;
			}
		case 5:
			{
				printf("El valor ingresado es 5\n");
				break;
			}
		default:{
			printf("El valor ingresado es 6, 7, 8 o 9\n");
			break;
		}
			
	}
	return 0;
}
