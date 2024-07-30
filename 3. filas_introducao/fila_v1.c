#include <stdio.h>

#define capacidade 10

struct fila
{
    int fim;
    int cap;
    int vetor[capacidade];
};

void iniciar(struct fila *);
int inserir(struct fila *, int);
int remover(struct fila *);
int espiar(struct fila *);
int listarTodos(struct fila *);

int main()
{
    struct fila *filaP;
    struct fila fila;
    filaP = &fila;

    iniciar(filaP);

    int input, num;

    do
    {
        printf("\n1 - Inserir um valor na fila\n");
        printf("2 - Excluir um valor da fila\n");
        printf("3 - Listar informacoes do primeiro elemeto da fila\n");
        printf("4 - Listar todos os valores da fila\n");
        printf("0 - Sair do programa\n=> ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            printf("\nDigite o numero que deseja inserir na fila: ");
            scanf("%d", &num);
            if (inserir(filaP, num) == 0)
            {
                printf("Valor inserido!\n");
            }
            else
            {
                printf("Nao ha espaco no vetor!\n");
            }
            break;
        case 2:
            if (remover(filaP) == 0)
            {
                printf("Valor da primeira posicao da fila excluido!\n");
            }
            else
            {
                printf("A fila esta vazia, nao e possivel remover!\n");
            }
            break;
        case 3:
            if (espiar(filaP) == -1)
            {
                printf("Nao ha valor na fila para ser espiado!\n");
            }
            else
            {
                printf("O valor do primeiro elemento da fila e: %d", espiar(filaP));
            }
            break;
        case 4:
            if (listarTodos(filaP) == 0)
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

void iniciar(struct fila *p)
{
    p->fim = -1;
    p->cap = capacidade;
}

int inserir(struct fila *p, int num)
{
    // Se nao houver espaco na fila, sera retornado -1.
    // Caso o valor seja inserido no comeco, sera retornado 0.

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
    // Caso nao haja nenhum valor na fila, sera retornado -1.
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
    // Caso nao haja nenhum valor na fila para ser espiado, sera retornado -1.
    // Caso tenha valor para espiar, sera retornado o valor.

    if (p->fim != -1)
    {
        return p->vetor[0];
    }
    return -1;
}

int listarTodos(struct fila *p)
{
    // A funcao retornara -1 caso nao houver valores dentro do vetor e 0 caso houver algum valor.
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