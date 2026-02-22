#include <stdio.h>

#define TAILLE_MOT 40

int main(void) {
    FILE* entree = NULL;
    entree = fopen("data.dat", "r");
    
    char name[40] = "";

    int nbr_personnes = 0;
    unsigned int age = 0;

    double age_total = 0.0;
    int age_max = 0;
    int age_min = 200;

    if (entree == NULL)
    {
        fprintf(stderr,"Erreur : impossible de lire le fichier %s\n", "data.dat");
        return 1;
    } else {
        printf("+-----------------+-----+\n");
        while (fscanf(entree, "%s %u", name, &age) == 2 ) 
        {
            nbr_personnes += 1;
            age_total     += age;
            
            if (age < age_min) age_min = age;
            if (age > age_max) age_max = age;

            printf("| %-15s |", name);
            printf(" %3u |\n",age);
                      
        }
        fclose(entree);
        printf("+-----------------+-----+\n");
        printf("  minimum age    :%3d\n", age_min);
        printf("  maximum age    :%3d\n",age_max);
        printf("%d people, average age: %5.1f years\n", nbr_personnes, age_total/nbr_personnes);  
    }
    return 0;
}