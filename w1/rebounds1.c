#include <stdio.h>
#include <math.h>

double const g = 9.81;

int main(void) {

    double H0 = 0.0;
    double eps = 0.0;
    int nbr = 0;

    
    do
    {
        printf("enter the initial height: "); scanf("%lf", &H0);
    } while (H0 < 0);
    
    do
    {
        printf("enter the rebound coefficient: "); scanf("%lf", &eps);
    } while (eps >= 1 || eps < 0);
    
    do
    {
        printf("enter the number of bounces: "); scanf("%d", &nbr);
    } while (nbr < 0);
    
    double v;
    double v1;
    double h = H0;
    double h1;

    for (size_t i = 0; i < nbr; i++)

    {
        v = sqrt(2*h*g);
        v1 = eps*v;
        h1 = pow(v1,2)/(2*g);
        h = h1;
    }
    
    printf("At the %dth bounce, the height will be %f\n", nbr, h);
    
}