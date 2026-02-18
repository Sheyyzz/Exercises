#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    double a0 = 0.0;
    double a1 = 0.0;
    double a2 = 0.0;

    double z1 = 0.0;
    double z2 = 0.0;
    double z3 = 0.0;


    double Q = 0.0;
    double R = 0.0;
    double D = 0.0;
    double S = 0.0;
    double T = 0.0;

    printf("enter a0;"); scanf("%lf",&a0);
    printf("enter a1;"); scanf("%lf",&a1);
    printf("enter a2;"); scanf("%lf",&a2);
    
    Q = (3 * a1 - pow(a2,2)) / 9;
    R = (9*a2*a1 - 27*a0 - 2*pow(a2,3)) / 54;
    D = pow(Q,3) + pow(R,2);

    if (D < 0)
    {
        double theta = acos(R / sqrt(-pow(Q,3)));
        z1 = 2 * sqrt(-Q) * cos(theta / 3) - a2 / 3;
        z2 = 2 * sqrt(-Q) * cos((theta + 2 * M_PI) / 3) - a2 / 3;
        z3 = 2 * sqrt(-Q) * cos((theta + 4 * M_PI) / 3) - a2 / 3;

        printf("z1 = %lf\n", z1);
        printf("z2 = %lf\n", z2);
        printf("z3 = %lf\n", z3);
    }
    else
    {
        double s = R + sqrt(D);
        if (s = 0)
        {
            S = 0;
        } 
        else if (s > 0)
        {
            S = pow(s, 1.0/3.0);
        }
        else if (s < 0)
        {
            S = -pow(-s, 1.0/3.0);
        }
        
        double t = R - sqrt(D);
        if (t = 0)
        {
            T = 0;
        }
        else if (t > 0)
        {
            T = pow(t, 1.0/3.0);
        }
        else if (t < 0)
        {            
            T = -pow(-t, 1.0/3.0);
        }

        z1 = (S + T) - a2 / 3;

        if (D = 0 && (S+T) != 0)
        {
            
            z2 = - (S + T) / 2 - a2 / 3;
            z3 = z2;

            printf("z1 = %lf\n", z1);
            printf("z2 = %lf\n", z2);
            printf("z3 = %lf\n", z3);
        }
        else
        {
            printf("z1 = %lf\n", z1);
        }
        
    }
    
    
}