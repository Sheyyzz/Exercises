#include <stdio.h>
#include <math.h>


typedef struct {
    double x;
    double y;
}Complexe;

typedef struct {
    Complexe z1;
    Complexe z2;
}Solutions;

void display(Complexe c);
Complexe add(Complexe c1, Complexe c2);
Complexe multiply(Complexe c1, Complexe c2);
Complexe substract(Complexe c1, Complexe c2);    
Complexe divide(Complexe c1, Complexe c2);
int sign(double x);

Complexe sroot(Complexe);

Solutions resolve_second_degree(Complexe b, Complexe c);



int main(void) {

    Complexe c1;
    c1.x = 1;
    c1.y = 0;
    Complexe c2;
    c2.x = 0;
    c2.y = 1;

    display(resolve_second_degree((Complexe){3,-2},(Complexe){-5,1}).z1);
    display(resolve_second_degree((Complexe){3,-2},(Complexe){-5,1}).z2);

    return 0;

    
    


    
}

void display(Complexe c) {
    printf("%.5lf + %.5lf*i",c.x,c.y);
}

Complexe add(Complexe c1, Complexe c2) {
    Complexe c;
    c.x = c1.x +c2.x;
    c.y = c1.y + c2.y;
    return c;
}

Complexe multiply(Complexe c1, Complexe c2) {
    Complexe c;
    c.x = c1.x * c2.x - c1.y * c2.y;
    c.y = c1.x * c2.y + c1.y * c2.x;
    return c;
}

Complexe substract(Complexe c1, Complexe c2) {
    Complexe c;
    c.x = c1.x - c2.x;
    c.y = c1.y - c2.y;
    return c;
}

Complexe divide(Complexe c1, Complexe c2) {
    Complexe c;
    double denominator = c2.x * c2.x + c2.y * c2.y;
    c.x = (c1.x * c2.x + c1.y * c2.y) / denominator;
    c.y = (c1.y * c2.x - c1.x * c2.y) / denominator;
    return c;
}

Complexe sroot(Complexe c) {
    double x = c.x;
    double y = c.y;
    double nominator = sqrt(x*x + y*y);

    double a = sqrt((nominator + x) / 2);
    double b = sign(y) * sqrt((nominator - x) / 2);

    return (Complexe){a, b};
}

int sign(double x) {
    if (x >= 0)
    {
        return 1;
    }
    else 
    {
        return -1;
    }
}

Solutions resolve_second_degree(Complexe b, Complexe c) {
    Complexe delta = substract(multiply(b,b), multiply((Complexe){4,0},c));

    Complexe sqrt_delta = sroot(delta);

    Complexe negb = (Complexe){-b.x,-b.y};

    Solutions s;
    s.z1 = divide(substract(negb,sqrt_delta), (Complexe){2,0});
    s.z2 = divide(add(negb,sqrt_delta), (Complexe){2,0});

    return s;
}