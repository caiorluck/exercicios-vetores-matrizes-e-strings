#include <stdio.h>

int main() {
    int a[3][3], b[3][3], soma[3][3];
    int i, j;

    printf("Digite os 9 elementos da matriz A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDigite os 9 elementos da matriz B:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            soma[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatriz A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz Soma (A + B):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
