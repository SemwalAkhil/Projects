/*
    128. Matrix multiplication
*/
#include <stdio.h>

int main() {
    int m, n, p, q;

    // Input dimensions for the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &m, &n);

    // Input dimensions for the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication is not possible. Inner dimensions must match.\n");
        return 1;
    }

    // Initialize matrices
    int firstMatrix[m][n], secondMatrix[p][q], resultMatrix[m][q];

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < n; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }

    // Display the result
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
