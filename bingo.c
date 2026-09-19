#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 5
#define MAX_CARTELAS 100

/* enumeracao para representar as colunas do bingo */
typedef enum {
    B = 0,
    I = 1,
    N = 2,
    G = 3,
    O = 4
} Coluna;

/* struct para representar uma cartela (desafio 3) */
typedef struct {
    int numeros[LINHAS][COLUNAS];
} Cartela;

int minimoColuna[COLUNAS] = {1, 16, 31, 46, 61};
int maximoColuna[COLUNAS] = {15, 30, 45, 60, 75};

/* gera um numero inteiro aleatorio entre minimo e maximo (inclusive) */
int gerarNumero(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

/* verifica se um numero ja existe na coluna da cartela */
int numeroExiste(int cartela[LINHAS][COLUNAS], int coluna, int numero) {
    int linha;
    for (linha = 0; linha < LINHAS; linha++) {
        if (cartela[linha][coluna] == numero) {
            return 1;
        }
    }
    return 0;
}

/* ordena os numeros de uma coluna em ordem crescente (desafio 4) */
void ordenarColuna(int cartela[LINHAS][COLUNAS], int coluna) {
    int valores[LINHAS];
    int quantidade = 0;
    int linha, i, j, temp;

    /* copia os valores da coluna, ignorando o espaco livre (0) */
    for (linha = 0; linha < LINHAS; linha++) {
        if (cartela[linha][coluna] != 0) {
            valores[quantidade] = cartela[linha][coluna];
            quantidade++;
        }
    }

    /* ordenacao simples (bubble sort) */
    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (valores[j] > valores[j + 1]) {
                temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;
            }
        }
    }

    /* devolve os valores ordenados para a coluna, mantendo o espaco livre */
    i = 0;
    for (linha = 0; linha < LINHAS; linha++) {
        if (cartela[linha][coluna] != 0) {
            cartela[linha][coluna] = valores[i];
            i++;
        }
    }
}

/* preenche uma cartela respeitando as faixas de cada coluna */
void gerarCartela(int cartela[LINHAS][COLUNAS]) {
    int linha, coluna, numero;

    for (coluna = 0; coluna < COLUNAS; coluna++) {
        for (linha = 0; linha < LINHAS; linha++) {

            /* posicao central livre (linha 2, coluna N) */
            if (linha == 2 && coluna == N) {
                cartela[linha][coluna] = 0;
                continue;
            }

            do {
                numero = gerarNumero(minimoColuna[coluna], maximoColuna[coluna]);
            } while (numeroExiste(cartela, coluna, numero));

            cartela[linha][coluna] = numero;
        }
    }

    for (coluna = 0; coluna < COLUNAS; coluna++) {
        ordenarColuna(cartela, coluna);
    }
}

/* compara duas cartelas e informa se sao identicas (desafio 5) */
int cartelasIguais(Cartela a, Cartela b) {
    int linha, coluna;

    for (linha = 0; linha < LINHAS; linha++) {
        for (coluna = 0; coluna < COLUNAS; coluna++) {
            if (a.numeros[linha][coluna] != b.numeros[linha][coluna]) {
                return 0;
            }
        }
    }

    return 1;
}

/* imprime a cartela formatada no terminal */
void imprimirCartela(int cartela[LINHAS][COLUNAS]) {
    int linha, coluna;

    printf(" B    I    N    G    O\n");

    for (linha = 0; linha < LINHAS; linha++) {
        for (coluna = 0; coluna < COLUNAS; coluna++) {
            if (linha == 2 && coluna == N) {
                printf(" X   ");
            } else {
                printf("%2d   ", cartela[linha][coluna]);
            }
        }
        printf("\n");
    }
}

int main() {
    Cartela cartelas[MAX_CARTELAS];
    int quantidade, i, j, gerarNova;

    srand((unsigned int) time(NULL));

    printf("Quantas cartelas deseja gerar (max %d)? ", MAX_CARTELAS);
    scanf("%d", &quantidade);

    if (quantidade < 1) {
        quantidade = 1;
    }
    if (quantidade > MAX_CARTELAS) {
        quantidade = MAX_CARTELAS;
    }

    for (i = 0; i < quantidade; i++) {
        do {
            gerarCartela(cartelas[i].numeros);
            gerarNova = 0;

            /* garante que nenhuma cartela se repita (desafio 5) */
            for (j = 0; j < i; j++) {
                if (cartelasIguais(cartelas[i], cartelas[j])) {
                    gerarNova = 1;
                    break;
                }
            }
        } while (gerarNova);
    }

    for (i = 0; i < quantidade; i++) {
        printf("\nCartela %d\n", i + 1);
        imprimirCartela(cartelas[i].numeros);
    }

    return 0;
}
