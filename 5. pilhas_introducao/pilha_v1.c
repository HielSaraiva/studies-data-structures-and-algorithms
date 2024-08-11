#include <stdio.h>

#define capacidade 10

struct pilha
{
    int cap;
    int topo;
    int *dados;
};

void iniciar(struct pilha *);
int inserir(struct pilha *, int);
int remover(struct pilha *);
int espiar(struct pilha *);
int listarTodos(struct pilha *);

int main()
{
    struct pilha *pilhaP;
    struct pilha pilha;
    pilhaP = &pilha;

    iniciar(pilhaP);

    int input, num;

    do
    {
        printf("\n1 - Inserir um valor na pilha\n");
        printf("2 - Excluir um valor da pilha\n");
        printf("3 - Listar informacoes do topo da pilha\n");
        printf("4 - Listar todos os valores da pilha\n");
        printf("0 - Sair do programa\n=> ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            printf("\nDigite o numero que deseja inserir na pilha: ");
            scanf("%d", &num);
            if (inserir(pilhaP, num) == 0)
            {
                printf("Valor inserido!\n");
            }
            else
            {
                printf("Nao ha espaco no vetor!\n");
            }
            break;
        case 2:
            if (remover(pilhaP) == 0)
            {
                printf("Valor da primeira posicao da pilha excluido!\n");
            }
            else
            {
                printf("A pilha esta vazia, nao e possivel remover!\n");
            }
            break;
        case 3:
            if (espiar(pilhaP) == -1)
            {
                printf("Nao ha valor na pilha para ser espiado!\n");
            }
            else
            {
                printf("O valor do primeiro elemento da pilha e: %d", espiar(pilhaP));
            }
            break;
        case 4:
            if (listarTodos(pilhaP) == 0)
            {
                printf("Valores printados!!\n");
            }
            else
            {
                printf("Nao ha valores para serem listados!\n");
            }
            break;
        default:
            printf("Digite um valor valido e tente novamente!\n");
            break;
        }
    } while (input != 0);

    return 0;
}

void iniciar(struct pilha *p)
{
    p->cap = capacidade;
    p->topo = -1;
    p->dados = malloc(cap * sizeof(int))
}

int inserir(struct fila *p, int num)
{
    // Se nao houver espaco na pilha, sera retornado -1.
    // Caso o valor seja inserido no topo, sera retornado 0.

    if (p->fim != p->cap - 1)
    {
        ++(p->fim);
        p->vetor[p->fim] = num;
        return 0;
    }
    return -1;
}

int remover(struct fila *p)
{
    // Caso nao haja nenhum valor na pilha, sera retornado -1.
    // Caso o numero seja removido sera retornado 0.

    if (p->fim != -1)
    {
        for (int i = 0; i < p->fim; i++)
        {
            p->vetor[i] = p->vetor[i + 1];
        }
        p->vetor[p->fim] = 0;
        --(p->fim);
        return 0;
    }

    return -1;
}

int espiar(struct fila *p)
{
    // Caso nao haja nenhum valor na pilha para ser espiado, sera retornado -1.
    // Caso tenha valor para espiar, sera retornado o valor.

    if (p->fim != -1)
    {
        return p->vetor[0];
    }
    return -1;
}

int listarTodos(struct fila *p)
{
    // A funcao retornara -1 caso nao houver valores dentro da pilha e 0 caso houver algum valor.
    if (p->fim != -1)
    {
        printf("[ ");
        for (int i = 0; i <= p->fim; ++i)
        {
            printf("%d ", p->vetor[i]);
        }
        printf("]\n");
        return 0;
    }
    return -1;
}
