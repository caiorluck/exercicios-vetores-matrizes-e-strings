#include <stdio.h>

int main() {
    int vetor[15];
    int i, numero, posicao = -1;

    printf("Digite 15 numeros inteiros:\n");
    for (i = 0; i < 15; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite o numero que deseja pesquisar: ");
    scanf("%d", &numero);

    for (i = 0; i < 15; i++) {
        if (vetor[i] == numero) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        printf("O numero %d foi encontrado na posicao %d.\n", numero, posicao);
    } else {
        printf("O numero %d nao foi encontrado no vetor.\n", numero);
    }

    return 0;
}
