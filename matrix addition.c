#include <stdio.h>


// Program to add two matrices of any dimensions input by the user 

int main() {
    int rows;
    int cols;
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);
    int m1[rows][cols];
    int m2[rows][cols];
    int total[rows][cols];
    printf("Enter Matrix A\n");

    for (int r1 = 0; r1 < rows; r1++) {
        for (int r2 = 0; r2 < cols; r2++) {
            scanf("%d", &m1[r1][r2]);
        }
    }
    
    
    printf("Enter Matrix B\n");

    for (int r1 = 0; r1 < rows; r1++) {
        for (int r2 = 0; r2 < cols; r2++) {
            scanf("%d", &m2[r1][r2]);
        }
    }
     printf("A + B = \n");

    for (int r1 = 0; r1 < rows; r1++) {
      for (int r2 = 0 ; r2 < cols; r2++) {
          total[r1][r2] = m1[r1][r2] + m2[r1][r2];
          printf("%d ", total[r1][r2]);
      }
      printf("\n");
    }
      
    
    
    return 0;
}