#include <stdio.h>

#define TAMANHO 5

void lerNotas(float notas[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

float calcularMedia(float notas[], int tamanho) {
    float soma = 0;
    int i;

    for (i = 0; i < tamanho; i++) {
        soma += notas[i];
    }

    return soma / tamanho;
}

float encontrarMaiorNota(float notas[], int tamanho) {
    float maior = notas[0];
    int i;

    for (i = 1; i < tamanho; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }

    return maior;
}

float encontrarMenorNota(float notas[], int tamanho) {
    float menor = notas[0];
    int i;

    for (i = 1; i < tamanho; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    return menor;
}

void imprimirRelatorio(float media, float maior, float menor) {
    printf("\n--- Relatorio da Turma ---\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
}

int main() {
    float notas[TAMANHO];
    float media, maior, menor;

    lerNotas(notas, TAMANHO);
    media = calcularMedia(notas, TAMANHO);
    maior = encontrarMaiorNota(notas, TAMANHO);
    menor = encontrarMenorNota(notas, TAMANHO);
    imprimirRelatorio(media, maior, menor);

    return 0;
}
