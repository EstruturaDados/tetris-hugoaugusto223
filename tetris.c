#include <stdio.h>
#include <stdlib.h>

#define MAX_FILA 10

typedef struct {
    char nome;
    int id;
} Peca;

char tipos[] = {'I', 'O', 'T', 'L'};

Peca gerarPeca(int id) {
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = id;
    return p;
}

void exibirFila(Peca fila[], int inicio, int fim, int quantidade) {
    printf("\nFila de peças:\n");
    if (quantidade == 0) {
        printf("[vazia]\n");
        return;
    }
    int i = inicio;
    for (int c = 0; c < quantidade; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % MAX_FILA;
    }
    printf("\n");
}

int main() {
    Peca fila[MAX_FILA];
    int inicio = 0;
    int fim = 0;
    int quantidade = 0;
    int idAtual = 0;
    int opcao;

    srand(1);

    for (int i = 0; i < 5; i++) {
        fila[fim] = gerarPeca(idAtual++);
        fim = (fim + 1) % MAX_FILA;
        quantidade++;
    }

    do {
        exibirFila(fila, inicio, fim, quantidade);

        printf("\n1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (quantidade == 0) {
                printf("\nFila vazia.\n");
            } else {
                inicio = (inicio + 1) % MAX_FILA;
                quantidade--;
            }
        }

        else if (opcao == 2) {
            if (quantidade == MAX_FILA) {
                printf("\nFila cheia.\n");
            } else {
                fila[fim] = gerarPeca(idAtual++);
                fim = (fim + 1) % MAX_FILA;
                quantidade++;
            }
        }

    } while (opcao != 0);

    return 0;
}
