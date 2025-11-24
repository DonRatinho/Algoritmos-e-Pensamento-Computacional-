#include <stdio.h>

int main() {
    float nota;

    printf("Digite a nota (entre 0 e 10): ");
    scanf("%f", &nota);

    if (nota >= 0.0 && nota <= 10.0) {
        printf("Nota válida: %.2f\n", nota);
    } else {
        printf("ERRO: A nota inserida (%.2f) é inválida. O valor deve estar entre 0 e 10.\n", nota);
    }

    return 0;
}	
