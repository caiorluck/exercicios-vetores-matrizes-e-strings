#include <stdio.h>

int main() {
    int vetor[10];
    int i;

    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nValores na ordem digitada:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n\nValores na ordem inversa:\n");
    for (i = 9; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    return 0;
}
