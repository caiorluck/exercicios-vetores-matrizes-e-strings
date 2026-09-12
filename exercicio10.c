#include <stdio.h>

void inicializarTabuleiro(char tabuleiro[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int posicaoOcupada(char tabuleiro[3][3], int linha, int coluna) {
    return tabuleiro[linha][coluna] != ' ';
}

int verificarVencedor(char tabuleiro[3][3]) {
    int i;

    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }

    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }

    return 0;
}

int tabuleiroCheio(char tabuleiro[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char tabuleiro[3][3];
    char jogadorAtual = 'X';
    int linha, coluna;
    int fimDeJogo = 0;

    inicializarTabuleiro(tabuleiro);

    while (!fimDeJogo) {
        exibirTabuleiro(tabuleiro);
        printf("Vez do jogador %c\n", jogadorAtual);
        printf("Digite a linha (0-2): ");
        scanf("%d", &linha);
        printf("Digite a coluna (0-2): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posicao invalida! Tente novamente.\n");
            continue;
        }

        if (posicaoOcupada(tabuleiro, linha, coluna)) {
            printf("Posicao ja ocupada! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVencedor(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("O jogador %c venceu!\n", jogadorAtual);
            fimDeJogo = 1;
        } else if (tabuleiroCheio(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate!\n");
            fimDeJogo = 1;
        } else {
            if (jogadorAtual == 'X') {
                jogadorAtual = 'O';
            } else {
                jogadorAtual = 'X';
            }
        }
    }

    return 0;
}
