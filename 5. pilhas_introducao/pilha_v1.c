#include <stdio.h>
#include <stdlib.h>

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
                printf("Valor do topo da pilha excluido!\n");
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
                printf("O valor do topo da pilha e: %d\n", espiar(pilhaP));
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
    p->dados = malloc((p->cap) * sizeof(int));
}

int inserir(struct pilha *p, int num)
{
    // Se nao houver espaco na pilha, sera retornado -1.
    // Caso o valor seja inserido no topo, sera retornado 0.

    if (p->topo != p->cap - 1)
    {
        ++(p->topo);
        *(p->dados + p->topo) = num;
        return 0;
    }
    return -1;
}

int remover(struct pilha *p)
{
    // Caso nao haja nenhum valor na pilha, sera retornado -1.
    // Caso o numero seja removido sera retornado 0.

    if (p->topo != -1)
    {
        *(p->dados + p->topo) = 0;
        --(p->topo);
        return 0;
    }
    return -1;
}

int espiar(struct pilha *p)
{
    // Caso nao haja nenhum valor na pilha para ser espiado, sera retornado -1.
    // Caso tenha valor para espiar, sera retornado o valor.

    if (p->topo != -1)
    {
        return *(p->dados + p->topo);
    }
    return -1;
}

int listarTodos(struct pilha *p)
{
    // A funcao retornara -1 caso nao houver valores dentro da pilha e 0 caso houver algum valor.
    if (p->topo != -1)
    {
        printf("[ ");
        for (int i = 0; i <= p->topo; ++i)
        {
            printf("%d ", *(p->dados + i));
        }
        printf("]\n");
        return 0;
    }
    return -1;
}
