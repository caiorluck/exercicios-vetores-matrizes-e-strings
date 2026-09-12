#include <stdio.h>

int maior(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int menor(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

float media(float a, float b) {
    return (a + b) / 2;
}

int fatorial(int n) {
    int resultado = 1;
    int i;

    for (i = 1; i <= n; i++) {
        resultado = resultado * i;
    }

    return resultado;
}

int main() {
    int a, b, n;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    printf("Maior: %d\n", maior(a, b));
    printf("Menor: %d\n", menor(a, b));
    printf("Media: %.2f\n", media((float)a, (float)b));

    printf("\nDigite um numero para calcular o fatorial: ");
    scanf("%d", &n);
    printf("Fatorial de %d: %d\n", n, fatorial(n));

    return 0;
}
