#include <stdio.h>

int main(){
    int anguloAlfa, anguloBeta, anguloGamma, anguloDelta, rspt;

    anguloAlfa = 180;
    anguloGamma = 90;
    anguloDelta = 90;

    rspt = anguloDelta + anguloGamma + anguloAlfa == 360;

    printf("%d", rspt);

    return 0;
}
