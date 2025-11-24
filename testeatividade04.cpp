#include <stdio.h>
#include <stdlib.h> 
#include <float.h>  

#define VAL_NOTAS 9

int main() {
    
    float notas[VAL_NOTAS]; 
    float soma = 0.0;
    float media = 0.0;
    
    float maior = 0.0;
    float menor = 10.0; 

    int i;
    
    printf("**Insira as %d notas:**\n", VAL_NOTAS);
    for (i = 0; i < VAL_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        if (scanf("%f", &notas[i]) != 1) {
            printf("Erro: Entrada NEGADA. Encerrando o programa.\n");
            return 1; 
        }
        
        if (notas[i] < 0 || notas[i] > 10) {
            printf("Atenção: Nota fora da ordem 0 ate 10. Prosseguindo...\n");
        }
    }
    
    printf("\n--- CALCULO ---\n");
    for (i = 0; i < VAL_NOTAS; i++) {
        
        soma += notas[i];
        
        if (notas[i] > maior) {
            maior = notas[i];
        }

        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    media = soma / VAL_NOTAS;

    printf("\n--- Resultados ---\n");
    printf("Notas Registradas: [");
    for (i = 0; i < VAL_NOTAS; i++) {
        printf("%.2f%s", notas[i], (i < VAL_NOTAS - 1) ? ", " : "");
    }
    printf("]\n");
    printf("Soma Total das Notas: **%.2f**\n", soma);
    printf("Media das Notas: **%.2f**\n", media);
    printf("Maior Nota: **%.2f**\n", maior);
    printf("Menor Nota: **%.2f**\n", menor);

    return 0; 
}
