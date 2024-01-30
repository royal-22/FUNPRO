#include <stdio.h>

int main(){
    double xA, yA, xB, yB, xC, yC, xD, yD;
    printf("Ingrese coordenadas punto A: ");
    scanf("%lf %lf", &xA, &yA);
    printf("Ingrese coordenadas punto B: ");
    scanf(" %lf %lf", &xB, &yB);
    printf("Ingrese coordenadas punto C: ");
    scanf(" %lf %lf", &xC, &yC);
    printf("Ingrese coordenadas punto D: ");
    scanf(" %lf %lf", &xD, &yD);

    double mAB, mBC, mCD, mDA; 
    mAB = (yB - yA) / (xB - xA);
    mBC = (yC - yB) / (xC - xB);
    mCD = (yD - yC) / (xD - xC);
    mDA = (yA - yD) / (xA - xD);
    double per1 = mAB * mBC;
    double per2 = mCD * mDA;
    
    if(mAB == mCD || mBC == mDA){
        if ( (int) per1 == -1) {
            if ( (int) per29 == -1) {
                printf("Los puntos ingresados forman un rectángulo.\n");
            }
            else{
                printf("Las rectas CD y DA no son perpendiculares.\n");
            }
        }
        else {
            printf("Las rectas AB y BC no son perpendiculares.\n");
        }
    }
    else{
        printf("Las rectas (AB, CD) o (BC, DA) no son paralelas.\n");
    }

    return 0;
}
