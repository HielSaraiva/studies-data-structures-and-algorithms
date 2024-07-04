#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define capacidade 10

struct aluno
{
    char nome[255];
    char matricula[25];
};

struct lista
{
    int tamanho;
    int cap;
    int type;
    struct aluno *valores[capacidade];
};

// Prototipos de funcoes
void ler(char *str);
void all_free(struct lista *p);
void all_null(struct lista *p);
void iniciar(struct lista *p, int type);
int buscar(struct lista *p, char nome[]);
int inserir(struct lista *p, int mode, char nome[], char matricula[]);
int alterar(struct lista *p, char nomeAntigo[], char nomeNovo[], char matriculaNova[]);
int excluir(struct lista *p, char nome[]);
int ordenar(struct lista *p);
int listar_todos(struct lista *p);

int main()
{
    struct lista lista;
    struct lista *listaP;
    listaP = &lista;

    int input, mode, type;
    char nomeBase[255], nomeNovo[255], matricula[25];

    printf("A lista sera um conjunto?(0-Sim; Qualquer outro numero-Nao): ");
    scanf("%d", &type);

    iniciar(listaP, type);

    do
    {
        printf("\n[1] - Inserir um aluno na lista\n");
        printf("[2] - Alterar um aluno da lista\n");
        printf("[3] - Excluir um aluno da lista\n");
        printf("[4] - Buscar um aluno na lista\n");
        printf("[5] - Ordenar os alunos da lista pelo nome\n");
        printf("[6] - Listar todos os alunos da lista\n");
        printf("[0] - Sair do programa\n=> ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("\nSaindo...");
            all_free(listaP);
            break;
        case 1:
            printf("\nDigite o nome do aluno: ");
            ler(nomeBase);
            printf("\nDigite a matricula do aluno: ");
            ler(matricula);
            printf("\nDigite o mode(0 para inserir no final, qualquer outro valor para inserir no inicio): ");
            scanf("%d", &mode);
            if (inserir(listaP, mode, nomeBase, matricula) == 0)
            {
                printf("Aluno inserido!\n");
            }
            else if (inserir(listaP, mode, nomeBase, matricula) == -1)
            {
                printf("Nao ha espaco no vetor!\n");
            }
            else
            {
                printf("O valor nao pode ser inserido novamente!\n");
            }
            break;
        case 2:
            if (listaP->tamanho != 0)
            {
                printf("\nDigite o nome do aluno que deseja alterar: ");
                ler(nomeBase);
                printf("\nDigite o nome do novo aluno que deseja colocar: ");
                ler(nomeNovo);
                printf("\nDigite a matricula do novo aluno que deseja colocar: ");
                ler(matricula);
                if (alterar(listaP, nomeBase, nomeNovo, matricula) == 0)
                {
                    printf("Aluno alterado!\n");
                }
                else
                {
                    printf("Esse aluno nao consta no vetor!\n");
                }
            }
            else
            {
                printf("Nao ha alunos no vetor para serem alterados!!!\n");
            }
            break;
        case 3:
            if (listaP->tamanho != 0)
            {
                printf("\nDigite o nome do aluno que deseja excluir: ");
                ler(nomeBase);
                if (excluir(listaP, nomeBase) == 0)
                {
                    printf("Aluno excluido!\n");
                }
                else
                {
                    printf("Esse aluno nao consta no vetor!\n");
                }
            }
            else
            {
                printf("Nao ha alunos no vetor para serem excluidos!!!\n");
            }
            break;
        case 4:
            if (listaP->tamanho != 0)
            {
                printf("\nDigite o nome do aluno que deseja buscar: ");
                ler(nomeBase);
                if (buscar(listaP, nomeBase) != -1)
                {
                    printf("O aluno esta na posicao %d do vetor!\n", buscar(listaP, nomeBase) + 1);
                }
                else
                {
                    printf("O aluno nao se encontra no vetor!\n");
                }
            }
            else
            {
                printf("Nao ha alunos no vetor para serem buscados!!!\n");
            }
            break;
        case 5:
            if (ordenar(listaP) == 0)
            {
                printf("Vetor ordenado!\n");
            }
            else
            {
                printf("Nao ha nenhum aluno no vetor para ser ordenado!\n");
            }
            break;
        case 6:
            if (listar_todos(listaP) == 0)
            {
                printf("\nEsses sao os nomes dos alunos e suas matriculas!\n");
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

void ler(char *str)
{
    fpurge(stdin);
    fflush(stdin);
    gets(str);
}

void all_free(struct lista *p)
{
    for (int i = 0; i < capacidade; i++)
    {
        if (p->valores[i] != NULL)
        {
            free(p->valores[i]);
        }
    }
}

void all_null(struct lista *p)
{
    for (int i = 0; i < capacidade; i++)
    {
        p->valores[i] = NULL;
    }
}

void iniciar(struct lista *p, int type)
{
    p->tamanho = 0;
    p->cap = capacidade;
    p->type = type;
    all_null(p);
}

int buscar(struct lista *p, char nome[])
{
    // Serao usado o algoritmo de busca sequencial que retornara o index do vetor caso o nome do aluno estiver no vetor ou -1 caso nao estiver
    for (int i = 0; i < p->tamanho; ++i)
    {
        if (strcmp(nome, (p->valores[i])->nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

int inserir(struct lista *p, int mode, char nome[], char matricula[])
{
    // O aluno sera inserido ao final do vetor, caso houver espaco retorna 0, caso contrario retorna -1
    // Se o mode = 0, o aluno sera inserido no final. Qualquer valor diferente para mode fara o aluno ser inserido no comeco
    // Se for um conjunto e ja houver o nome do aluno, retornara -2
    if (p->tamanho != p->cap)
    {
        if (p->type == 0)
        {
            if (buscar(p, nome) != -1)
            {
                return -2;
            }
        }

        if (mode)
        {
            // Inserir no inicio
            for (int i = p->tamanho; i > 0; --i)
            {
                p->valores[i] = p->valores[i - 1];
            }
            p->valores[0] = malloc(sizeof(struct aluno));
            strcpy((p->valores[0])->nome, nome);
            strcpy((p->valores[0])->matricula, matricula);
            ++(p->tamanho);
            return 0;
        }
        else
        {
            // Inserir no final
            p->valores[p->tamanho] = malloc(sizeof(struct aluno));
            strcpy((p->valores[p->tamanho])->nome, nome);
            strcpy((p->valores[p->tamanho])->matricula, matricula);
            ++(p->tamanho);
            return 0;
        }
    }

    return -1;
}

int alterar(struct lista *p, char nomeAntigo[], char nomeNovo[], char matriculaNova[])
{
    // Caso o nome do aluno que se deseja alterar estiver no vetor, sera retornado 0, caso contrario, -1 sera retornado
    // Caso hajam 2 alunos como nomes iguais, o primeiro aluno a aparecer no vetor sera o alterado
    if (buscar(p, nomeAntigo) != -1)
    {
        strcpy((p->valores[buscar(p, nomeAntigo)])->matricula, matriculaNova);
        strcpy((p->valores[buscar(p, nomeAntigo)])->nome, nomeNovo);

        return 0;
    }

    return -1;
}

int excluir(struct lista *p, char nome[])
{
    // Caso o aluno que se deseja excluir estiver no vetor, sera retornado 0, caso contrario, -1 sera retornado
    // Caso hajam 2 alunos de nomes iguais, o primeiro aluno a aparecer no vetor sera o excluido
    if (buscar(p, nome) != -1)
    {
        free(p->valores[buscar(p, nome)]);
        for (int i = buscar(p, nome); i < p->tamanho - 1; ++i)
        {
            p->valores[i] = p->valores[i + 1];
        }
        p->valores[p->tamanho - 1] = NULL;
        --(p->tamanho);
        return 0;
    }

    return -1;
}

int ordenar(struct lista *p)
{
    // Serao usado o algoritmo de ordenacao bubble-sort para colocar em ordem alfabetica os nomes dos alunos contidos no vetor
    // Se nao houver nenhum valor no vetor, a funcao retornara -1, caso o bubble-sort funcione, retornara 0

    if (p->tamanho != 0)
    {
        for (int i = 0; i < p->tamanho - 1; ++i)
        {
            for (int j = i + 1; j < p->tamanho; ++j)
            {
                if (strcmp((p->valores[i])->nome, (p->valores[j])->nome) > 0)
                {
                    struct aluno *aux;
                    aux = p->valores[i];
                    (p->valores[i]) = (p->valores[j]);
                    (p->valores[j]) = aux;
                }
            }
        }
        return 0;
    }

    return -1;
}

int listar_todos(struct lista *p)
{
    // A funcao retornara -1 caso nao houver valores dentro do vetor e 0 caso houver algum valor
    if (p->tamanho != 0)
    {
        printf("=>");
        for (int i = 0; i < p->tamanho; ++i)
        {
            printf("\n%d Aluno: %s\tMatricula: %s", i + 1, (p->valores[i])->nome, (p->valores[i])->matricula);
        }
        return 0;
    }
    return -1;
}
