#include <stdio.h>
#include <string.h>

int main() {
    char nome1[100], nome2[100];
    int resultado;

    printf("Digite o primeiro nome: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("Digite o segundo nome: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    resultado = strncmp(nome1, nome2, 100);

    if (resultado == 0) {
        printf("\nOs nomes sao iguais.\n");
    } else if (resultado < 0) {
        printf("\nOs nomes sao diferentes.\n");
        printf("%s e alfabeticamente maior.\n", nome2);
    } else {
        printf("\nOs nomes sao diferentes.\n");
        printf("%s e alfabeticamente maior.\n", nome1);
    }

    return 0;
}
