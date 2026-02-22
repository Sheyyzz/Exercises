#include <stdio.h>
#include <string.h>



#define MAX_NAME 100

int main(void){

    FILE* data = fopen("data.dat", "w");
    char name[MAX_NAME+1]= "";
    unsigned int age= 0;

    if (data == NULL)
    {
        fprintf(stderr, "Erreur : impossible de lire le fichier %s\n", "data.dat");
        return 1;
    }

    else
    {
        size_t len = 0;
        int j = 0;
        
        while (!feof(stdin))
        {
            do
            {
                
                printf("Enter a name (CTRL+D to finish): ");fflush(stdout);                
                fgets(name, MAX_NAME+1, stdin);
                len = strlen(name);
                if (len!=0 && name[--len] == '\n')
                {
                    name[len] = '\0';
                }
            } while (len == 0 && !feof(stdin) && !ferror(stdin));
            
            
            if (!feof(stdin))
            {
                printf("age: "); fflush(stdout);
                j = scanf("%d", &age);
                if (!j)
                {
                    printf("I'm asking you for an age (positive integer)! \n");
                    printf("This registration is canceled. \n");
                    while (!feof(stdin) && !ferror(stdin) && getc(stdin) != '\n'); 
                    fclose(data); 
                    return 1;    
                } 
                else
                {
                    getc(stdin);    
                    fprintf(data, "%s    ", name);
                    fprintf(data, "%u \n", age);
                }  
            }
        }
    }    
    fclose(data);
    return 0;

}

