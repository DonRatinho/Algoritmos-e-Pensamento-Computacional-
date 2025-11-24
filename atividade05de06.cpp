#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 10

/* --- Protótipos das Funções --- */
void exibirMenu();
int lerNotas(float notas[], int max_tamanho);
float calcularMedia(const float notas[], int tamanho);
float maiorNota(const float notas[], int tamanho);
float menorNota(const float notas[], int tamanho);

/* --- Implementação das Funções --- */

void exibirMenu() {
    printf("\n==================================\n");
    printf("     ?? Menu de Cálculos Estatísticos\n");
    printf("==================================\n");
    printf("1. Calcular Média das Notas\n");
    printf("2. Encontrar Maior Nota\n");
    printf("3. Encontrar Menor Nota\n");
    printf("4. Sair\n");
    printf("----------------------------------\n");
}

int lerNotas(float notas[], int max_tamanho) {
    int i = 0;
    float nota_lida;
    
    printf("Digite as notas (máx. %d notas). Digite um valor negativo (ex: -1) para terminar:\n", max_tamanho);
    
    while (i < max_tamanho) {
        printf("Nota #%d: ", i + 1);
        
        if (scanf("%f", &nota_lida) != 1) {
             printf("Erro na leitura. Terminando a entrada de notas.\n");
             while (getchar() != '\n');
             break;
        }

        if (nota_lida < 0) {
            break;
        }
        
        notas[i] = nota_lida;
        i++;
    }
    
    printf("\n%d notas foram lidas com sucesso.\n", i);
    return i;
}

float calcularMedia(const float notas[], int tamanho) {
    if (tamanho == 0) {
        return 0.0f;
    }
    
    float soma = 0.0f;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    
    return soma / tamanho;
}

float maiorNota(const float notas[], int tamanho) {
    if (tamanho == 0) {
        return -1.0f;
    }
    
    float maior = notas[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    
    return maior;
}

float menorNota(const float notas[], int tamanho) {
    if (tamanho == 0) {
        return -1.0f;
    }
    
    float menor = notas[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    
    return menor;
}

/* --- Função Principal (main) --- */
int main() {
    float notas[MAX_NOTAS];
    int qtd_notas = 0;
    int opcao;
    
    printf("--- Módulo de Leitura de Notas ---\n");
    qtd_notas = lerNotas(notas, MAX_NOTAS);
    
    if (qtd_notas == 0) {
        printf("\nNenhuma nota lida. Encerrando o programa.\n");
        return 0;
    }
    
    do {
        exibirMenu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\nResultado: Média das notas = %.2f\n", calcularMedia(notas, qtd_notas));
                break;
            case 2:
                printf("\nResultado: Maior nota = %.2f\n", maiorNota(notas, qtd_notas));
                break;
            case 3:
                printf("\nResultado: Menor nota = %.2f\n", menorNota(notas, qtd_notas));
                break;
            case 4:
                printf("\nEncerrando o programa. Até mais!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
        if (opcao != 4) {
            printf("\nPressione ENTER para continuar...");
            while (getchar() != '\n'); 
            getchar();
        }

    } while (opcao != 4);
    
    return 0;
}
