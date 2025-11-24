#include <stdio.h>

int main() {
    float nota;
    int continuar;
    int contador = 0;

    do {
        printf("\n--- Cadastro de Nota #%d ---\n", contador + 1);
        printf("Digite a nota (0 a 10): ");
        scanf("%f", &nota);

        if (nota >= 0.0 && nota <= 10.0) {
            printf("Nota %.2f cadastrada com sucesso.\n", nota);
            contador++;
        } else {
            printf("ERRO: Nota inválida. O valor deve estar entre 0 e 10.\n");
        }
        
        printf("\nDeseja cadastrar outra nota? (1 para Sim / 0 para Não): ");
        scanf("%d", &continuar);

    } while (continuar == 1);

    printf("\nCadastro encerrado. Total de notas válidas cadastradas: %d\n", contador);

    return 0;
}
