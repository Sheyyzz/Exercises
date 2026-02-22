#include <stdio.h>
#include <string.h>


#define STATISTICS_SIZE 221

typedef unsigned long int Statistics[STATISTICS_SIZE];

FILE* request_file();
void initialize_statistics(Statistics stat, size_t size);
unsigned long int collect_statistics(Statistics to_be_filled, FILE* file_to_read);
void display(Statistics stat, size_t size);


int main(void) {
    Statistics stat;
    initialize_statistics(stat, STATISTICS_SIZE);  
    FILE* data = request_file();
    if (data != NULL)
    {
        collect_statistics(stat, data);
        fclose(data);
        display(stat, STATISTICS_SIZE);  
    }
    return 0;
    

}



FILE* request_file() {
    FILE* file;
    char file_name[FILENAME_MAX+1] = "";
    
    size_t len = 0;
    int nb_tries = 3;


    while (nb_tries > 0)
    {
        do
        {
            printf("Name of the file to read: ");fflush(stdout);
            fgets(file_name, FILENAME_MAX+1, stdin);
            len = strlen(file_name);
            if ((len != 0) && file_name[--len] == '\n')
            {
                file_name[len] = '\0';
            }
        } while (len == 0 && !ferror(stdin) && !feof(stdin));
        
        
        file = fopen(file_name, "r");
        if (file == NULL)
        {
            printf(" -> ERROR, I cannot read the file \"%s\"\n", file_name);
            nb_tries-=1;
        } else {
            printf(" -> OK, \"%s\" file opened for reading.\n",file_name);
            return file;
        }
    }
    
    printf("=> I give up!\n");
    return NULL;

}

void initialize_statistics(Statistics stat, size_t size) {
    if (size == 0) return;
    for (int i = 0; i < size; i++)
    {
        stat[i] = 0UL;
    }
}

unsigned long int collect_statistics(Statistics to_be_filled, FILE* file_to_read){
    if (file_to_read == NULL)
    {
        return 0UL;
    } else {
        unsigned long total_char = 0;
        
        int ch;
        while ((ch = fgetc(file_to_read)) != EOF)
        {
            if (ch >=32 && ch < (32 + STATISTICS_SIZE)) {
                to_be_filled[ch -32] += 1UL;
                ++total_char;
            }
        } 
        
    }
}

void display(Statistics stat, size_t size) {
    if (size != 0)
    {
        double tot = 0.0;
        for (int i = 0; i < size; i++)
        {
            tot += stat[i];
        }
        
        for (int i = 0; i < size; i++)
        {
            unsigned long nb = stat[i];
            if ( nb != 0)
            {
                char c = (char)(i +32);
                printf("%c:",c);
                printf("%11lu - ", nb);
                printf("%5.2f%%\n", (nb*100)/tot);
            }
        }
    }
}