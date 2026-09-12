#include <stdio.h>

int main() {
    int vetor[20];
    int i, maior, menor, pares = 0, impares = 0;
    float soma = 0, media;

    printf("Digite 20 numeros inteiros:\n");
    for (i = 0; i < 20; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (i = 0; i < 20; i++) {
        soma += vetor[i];

        if (vetor[i] > maior) {
            maior = vetor[i];
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
        }

        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    media = soma / 20;

    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Media: %.2f\n", media);
    printf("Quantidade de pares: %d\n", pares);
    printf("Quantidade de impares: %d\n", impares);

    return 0;
}
