#include <stdio.h>
#include <math.h>

int main(){
    int n, i, puntosDentro, puntosFuera;
    double Ax, Ay, Bx, By, Cx, Cy, Px, Py;
    puntosDentro = 0;
    puntosFuera = 0;

    printf("Ingrese la cantidad de puntos, debe ser un múltiplo de 4 y encontrarse en el rango [4, 32]: ");
    scanf("%d", &n);

    if(n >= 0 && n <= 32){
        for(i = 0; i < n; i++){
            printf("Ingrese el punto A: ");
            scanf("%lf %lf", &Ax, &Ay);
            printf("Ingrese el punto B: ");
            scanf("%lf %lf", &Bx, &By);
            printf("Ingrese el punto C: ");
            scanf("%lf %lf", &Cx, &Cy);
            printf("Ingrese el punto P: ");
            scanf("%lf %lf", &Px, &Py);

            double margenDeError = fabs((Cx - Bx) / (Bx - Ax) - (Cy - By)/(By - Ay));
            if(margenDeError <= 0.01){
                printf("Los puntos esán alineados, no forman un triángulo.\n");
            }
            else{
                /* Calcular la orientación de ABC, ABP, BCP y CAP */
                double orientacionABC, orientacionABP, orientacionBCP, orientacionCAP;

                orientacionABC = (Ax - Cx) * (By - Cy) - (Ay - Cy) * (Bx - Cx);
                orientacionABP = (Ax - Px) * (By - Py) - (Ay - Py) * (Bx - Px);
                orientacionBCP = (Bx - Px) * (Cy - Py) - (By - Py) * (Cx - Px);
                orientacionCAP = (Cx - Px) * (Ay - Py) - (Cy - Py) * (Ax - Px);

                if((orientacionABC > 0 && orientacionABP > 0 && orientacionBCP > 0 && orientacionCAP > 0) || (orientacionABC < 0 && orientacionABP < 0 && orientacionBCP < 0 && orientacionCAP < 0)){
                    printf("El punto P(%.2lf, %.2lf) se encuentra dentro del triangulo formado por los puntos\n", Px, Py);
                    puntosDentro++;
                }
                else{
                    printf("El punto P(%.2lf, %.2lf) no se encuentra dentro del triangulo formado por los puntos\n", Px, Py);
                    puntosFuera++;
                }
            }
        }
        printf("Los puntos que se encontraron dentro de un triangulo son: %d \n", puntosDentro);
        printf("Los puntos que se encontraron fuera de un triángulo son: %d \n", puntosFuera);
    }
    else{
        printf("El valor ingresado no cumple con lo solicitado.\n");
    }

    return 0;
}
