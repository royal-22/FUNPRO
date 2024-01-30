#include <stdio.h>
#include <math.h>
void verificarTrio(int carta1, int carta2, int carta3, int carta4, int carta5, int *hayTrio, int *cartaMayorMano);

int main(){
	int cantidadJugadores, i=0, carta1, carta2, carta3, carta4, carta5, cartaMayor = 0, hayTrio, cartaMayorMano, jugador;
	printf("Ingrese la cantidad de jugadores: ");
	scanf("%d", &cantidadJugadores);
	if(cantidadJugadores >= 2){
		while(i < cantidadJugadores){
			printf("Ingrese cartas del jugador %d: ", i+1);
			scanf("%d %d %d %d %d", &carta1, &carta2, &carta3, &carta4, &carta5);
			verificarTrio(carta1, carta2, carta3, carta4, carta5, &hayTrio, &cartaMayor);
			if(cartaMayor > cartaMayorMano){
				cartaMayorMano = cartaMayor;
				jugador = i+1;
			}
			i++;
		}
		printf("Ha ganado el jugador %d con un trio de %d\n", jugador, cartaMayorMano);
	}else{
		printf("La cantida de jugadores debe ser mayor o igual que dos.\n");
	}
	return 0;
}

void verificarTrio(int carta1, int carta2, int carta3, int carta4, int carta5, int *hayTrio, int *cartaMayorMano){
	*cartaMayorMano = -1;
	*hayTrio = 0;
	if((carta1 == carta2 && carta2 == carta3) || (carta1 == carta2 && carta2 == carta4) || (carta1==carta2 && carta2 == carta5) || (carta1 == carta3 && carta3 == carta4) || (carta1 == carta3 && carta3 == carta5) || (carta1 == carta4 && carta4 == carta5)){
		*hayTrio = 1;
		*cartaMayorMano = carta1;
	}else{
		if((carta2 == carta3 && carta3 == carta4) || (carta2 == carta4 && carta4 == carta5) || (carta2 == carta4 && carta4 == carta5)){
			*hayTrio = 1;
			*cartaMayorMano = carta2;
		}else{
			if((carta3 == carta4 && carta4 == carta5)){
				*hayTrio = 1;
				*cartaMayorMano = carta3;
			}
		}
	}
}

