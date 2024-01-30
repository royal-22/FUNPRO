#include <stdio.h>

int main(){
    double AB, BC, CD, DA, anA, anB, anC, anD;

    AB = 7;
    BC = 5;
    CD = 7;
    DA = 5;
    anA = 120;
    anB = 60;
    anC = 120;
    anD = 60;

    if(( AB == BC && BC == CD && CD == DA && DA == AB ) && (anA == 90 && anB == anA && anA == anC && anA == anD)){
        printf("Cuadrado\n");
    }

    else if ((AB == CD && BC == DA) && (anA == 90 && anB == anA && anA == anC && anA == anD)) {
        printf("Rectángulo\n");
    }

    else if((AB == BC && BC == CD && CD == DA && DA == AB ) && (anA == anC && anB == anD) && ((anA > 90 && anB < 90) || (anA < 90 && anB > 90)) ){
        printf("Rombo\n");
    }
    else if ((AB == CD && BC == DA) && (anA == anC && anB == anD) && ((anA > 90 && anB < 90) || (anA < 90 && anB > 90))){    
        printf("Romboide\n");
    }


    return 0;
}
