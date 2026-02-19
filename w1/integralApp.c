#include <stdio.h>
#include <math.h>

double ask();
double integrate(double a, double b);

int main(void) {
    double b = ask();
    double a = ask();

    double app = integrate(a, b);

    printf("the approximate value of the integral of your function between %lf and %lf is %lf",a,b,app);
}

double f(double x) {
    return x*x;
}

double integrate(double a, double b) {
    double fraction1 = ((5*a + b)/ 6.0);
    double fraction2 = ((2*a + b)/ 3.0);
    double fraction3 = ((a + b)/ 2.0);
    double fraction4 = ((a + 2*b)/ 3.0);
    double fraction5 = ((a + 5*b)/ 6.0);

    double a1 = 41*f(a);
    double a2 = 216*f(fraction1);
    double a3 = 27*f(fraction2);
    double a4 = 272*f(fraction3);
    double a5 = 27*f(fraction4);
    double a6 = 216*f(fraction5);
    double a7 = 41*f(b);

    double A = a1 + a2 + a3 + a4 + a5 + a6 + a7;
    return ((b-a)/840.0) * A;
}

double ask() {
    double a = 0.0;
    printf("enter a real number: ");
    scanf("%lf", &a);
    return a;
}