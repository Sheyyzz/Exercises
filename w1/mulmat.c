#include <stdio.h>

#define N 100

typedef struct {
    unsigned int rows;
    unsigned int columns;
    int m[N][N];

} Matrix;

Matrix readMatrix(void);
Matrix multiply(const Matrix a, const Matrix b);
void display_matrix(const Matrix m);

int main(void) {
    Matrix M1 = readMatrix();
    Matrix M2 = readMatrix();

    Matrix result = multiply(M1,M2);
    display_matrix(result);
}

Matrix readMatrix(void) {
    int rows = 0;
    int columns = 0;
    do
    {
        printf("number of rows: "); 
        scanf("%d", &rows);
        printf("number of columns: "); 
        scanf("%d", &columns);
    } while (rows > N || rows <= 0 || columns > N || columns <= 0); 
    
    Matrix matrix;
    matrix.rows = rows;
    matrix.columns = columns;

    for (int i = 0; i < rows; i++)   
    {
        for (int j = 0; j < columns; j++)
        {
            printf("M[%d,%d] ",i+1,j+1);
            scanf("%d", &matrix.m[i][j]);
        }
    }
    return matrix;
}


Matrix multiply(const Matrix a, const Matrix b) {
    if (a.columns != b.rows)
    {
        fprintf(stderr, "Matrix multiplication impossible!");
    }

    

    else {
        Matrix mult;

        mult.rows = a.rows;
        mult.columns = b.columns;

         for (unsigned int i = 0; i < mult.rows; ++i)
            for (unsigned int j = 0; j < mult.columns; ++j)
                mult.m[i][j] = 0;
                
        for (int i = 0; i < a.rows; i++)
        {
            for (int j = 0; j < b.columns; j++)
            {
                int tmp = 0;
                for (int k = 0; k < a.columns; k++)
                {
                    tmp += (a.m[i][k]*b.m[k][j]);
                }
                mult.m[i][j] = tmp;
            }
        }
        return mult;
    }
}

void display_matrix(const Matrix matrix) {
    printf("result: \n");
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            printf("%d ",matrix.m[i][j]);
        }
        printf("\n");
    }
}