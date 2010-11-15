
/**
 * Matrix Multiplication
 * Vishesh Yadav
 *
 */

#include<stdio.h>


#define ORDER 2


void mulMatrix(int a[][ORDER], int b[][ORDER], int c[][ORDER])
{
    int i;
    for (i=0; i<ORDER; i++) {
        int j;
        for (j=0; j<ORDER; j++) {
            int k;
            c[i][j] = 0;
            for (k=0; k<ORDER; k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void getMatrix(int mat[][ORDER])
{
    int i;
    for (i=0; i<ORDER; i++) {
        int j;
        for (j=0; j<ORDER; j++) {
            printf("\nEnter matrix[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[][ORDER])
{
    int i;
    for (i=0; i<ORDER; i++) {
        int j;
        for (j=0; j<ORDER; j++) {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int a[ORDER][ORDER], b[ORDER][ORDER], c[ORDER][ORDER];

    printf("\n\nENTER MATRIX A\n");
    getMatrix(a);
    printMatrix(a);

    printf("\n\nENTER MATRIX B\n");
    getMatrix(b);
    printMatrix(b);

    printf("\n\nMATRIX MULTIPLICATION RESULT\n");
    mulMatrix(a, b, c);
    printMatrix(c);

    fflush(stdin);
    getchar();
    return 0;
}
