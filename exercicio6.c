#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nome[100];
    int i, tamanho;
    int vogais = 0, consoantes = 0, espacos = 0;
    char letra;

    printf("Digite o nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    /* remove o \n deixado pelo fgets */
    nome[strcspn(nome, "\n")] = '\0';

    tamanho = strlen(nome);

    for (i = 0; i < tamanho; i++) {
        letra = tolower(nome[i]);

        if (letra == ' ') {
            espacos++;
        } else if (letra == 'a' || letra == 'e' || letra == 'i' ||
                   letra == 'o' || letra == 'u') {
            vogais++;
        } else if (isalpha(letra)) {
            consoantes++;
        }
    }

    printf("\nQuantidade de caracteres: %d\n", tamanho);
    printf("Quantidade de vogais: %d\n", vogais);
    printf("Quantidade de consoantes: %d\n", consoantes);
    printf("Quantidade de espacos em branco: %d\n", espacos);

    return 0;
}
