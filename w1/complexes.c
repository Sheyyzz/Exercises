#include <stdio.h>
#include <stdio.h>


typedef struct {
    double x;
    double y;
}Complexe;

void display(Complexe c);
Complexe add(Complexe c1, Complexe c2);
Complexe multiply(Complexe c1, Complexe c2);
Complexe subtract(Complexe c1, Complexe c2);    
Complexe divide(Complexe c1, Complexe c2);

int main(void) {

    Complexe c1;
    c1.x = 1;
    c1.y = 0;
    Complexe c2;
    c2.x = 0;
    c2.y = 1;
    display(add(c1,c2));
    printf("\n");
    display(divide((Complexe){2,-3}, (Complexe){1,1}));
    
    


    
}

void display(Complexe c) {
    printf("%.2lf + %.2lf*i",c.x,c.y);
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

Complexe subtract(Complexe c1, Complexe c2) {
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