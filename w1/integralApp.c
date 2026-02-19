#include <stdio.h>
#include <math.h>

typedef enum {
    F_SQUARE=1,
    F_INV=2,
    F_SIN=3
}FuncChoice;

double ask();
double integrate(double a, double b, FuncChoice choice);
void askChoice(FuncChoice *c);

int main(void) {
    double a = ask();
    double b = ask();
    FuncChoice choice;
    askChoice(&choice);

    double app = integrate(a, b, choice);

    printf("the approximate value of the integral of your function between %lf and %lf is %lf",a,b,app);
}

double f(double x, FuncChoice choice) {
    switch (choice) {
        case F_SQUARE: return x*x;
        case F_INV: return 1/x;
        case F_SIN: return sin(x);
        default: return 0.0;
    }
}

double integrate(double a, double b, FuncChoice choice) {
    double fraction1 = ((5*a + b)/ 6.0);    
    double fraction2 = ((2*a + b)/ 3.0);
    double fraction3 = ((a + b)/ 2.0);
    double fraction4 = ((a + 2*b)/ 3.0);
    double fraction5 = ((a + 5*b)/ 6.0);

    double a1 = 41*f(a, choice);
    double a2 = 216*f(fraction1, choice);
    double a3 = 27*f(fraction2, choice);
    double a4 = 272*f(fraction3, choice);
    double a5 = 27*f(fraction4, choice);
    double a6 = 216*f(fraction5, choice);
    double a7 = 41*f(b, choice);

    double A = a1 + a2 + a3 + a4 + a5 + a6 + a7;
    return ((b-a)/840.0) * A;
}

double ask() {
    double a = 0.0;
    printf("enter a real number: ");
    scanf("%lf", &a);
    return a;
}

void askChoice(FuncChoice *c) {
    int tmp = 0;
    printf("chose your function 1: x*x | 2:1/x | 3:sin(x)");
    scanf("%d", &tmp);
    *c = (FuncChoice)tmp;
}
