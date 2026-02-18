#include <stdio.h>
#include <math.h>


int main(void) {
    int divisor = 1;
    int nbr = 0;

    
    do
    {
        printf("enter a number (integer): ");
        scanf("%d", &nbr);
        /* code */
    } while (nbr <= 1);

    if (nbr%2 == 0 && nbr != 2)
    {
        divisor = 2;

    }
    
    else
    {
        const int borneMax = sqrt(nbr);
        for (int i = 3; (divisor == 1) && (i < borneMax); i+=2)
        {
            if (nbr % i == 0)
            {
                divisor = i;
            }
            
        }
        
    }

    if (divisor == 1)
    {
        printf("I strongly believe that this number is prime");
    } 
    
    else
    {
        printf("The number is not prime, because it is divisible by %d", divisor);

    }
    
    
    
    

    
}