#include <stdio.h>
#define capacidade 10

struct lista
{
    int tamanho;
    int cap;
    int *valores;
    int type;
};

void iniciar(struct lista *, int);
int inserir(struct lista *, int, int);
int buscar(struct lista *, int);
int alterar(struct lista *, int, int);
int excluir(struct lista *, int);
int ordenar(struct lista *);
int listar_todos(struct lista *);

int main()
{
    struct lista *listaP;
    struct lista lista;
    listaP = &lista;
    
    int input, num, oldNum, newNum, mode, type;
    printf("O vetor sera um conjunto(0-Sim; Qualquer outro numero-Nao): ");
    scanf("%d", &type);
    
    iniciar(listaP, type);

    do
    {
        printf("\n1 - Inserir um valor na lista\n");
        printf("2 - Alterar um valor da lista\n");
        printf("3 - Excluir um valor da lista\n");
        printf("4 - Buscar um valor na lista\n");
        printf("5 - Ordenar os valores da lista\n");
        printf("6 - Listar todos os valores da lista\n");
        printf("0 - Sair do programa\n=> ");
        scanf("%d", &input);

        switch (input)
        {
            case 0:
                printf("\nSaindo...");
                free(lista.valores);
                break;
            case 1:
                printf("\nDigite o numero que deseja inserir: ");
                scanf("%d", &num);
                printf("\nDigite o mode(0 para inserir no final, qualquer outro valor para inserir no inicio): ");
                scanf("%d", &mode);
                if (inserir(listaP, num, mode) == 0)
                {
                    printf("Valor inserido!\n");
                }
                else if (inserir(listaP, num, mode) == -1)
                {
                    printf("Nao ha espaco no vetor!\n");
                } else {
                	printf("O valor nao pode ser inserido novamente!\n");
				}
                break;
            case 2:
                printf("\nDigite o numero do vetor que deseja alterar: ");
                scanf("%d", &oldNum);
                printf("\nDigite o novo numero que deseja inserir no vetor: ");
                scanf("%d", &newNum);
                if (alterar(listaP, newNum, oldNum) == 0)
                {
                    printf("Valor alterado!\n");
                }
                else
                {
                    printf("Esse valor nao consta no vetor!\n");
                }
                break;
            case 3:
                printf("\nDigite o numero que deseja excluir: ");
                scanf("%d", &num);
                if (excluir(listaP, num) == 0)
                {
                    printf("Valor excluido!\n");
                }
                else
                {
                    printf("Esse valor nao consta no vetor!\n");
                }
                break;
            case 4:
                printf("\nDigite o numero que deseja buscar: ");
                scanf("%d", &num);
                if (buscar(listaP, num) != -1)
                {
                    printf("O valor esta na posicao %d do vetor!\n", buscar(listaP, num) + 1);
                }
                else
                {
                    printf("O valor nao se encontra no vetor!\n");
                }
                break;
            case 5:
                if (ordenar(listaP) == 0)
                {
                    printf("Vetor ordenado!\n");
                }
                else
                {
                    printf("Nao ha nenhum valor no vetor para ser ordenado!\n");
                }
                break;
            case 6:
                if (listar_todos(listaP) == 0)
                {
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

void iniciar(struct lista *p, int type)
{
    p->tamanho = 0;
    p->cap = capacidade;
    p->type = type;
    p->valores = malloc(capacidade * sizeof(int));
}

int buscar(struct lista *p, int num)
{
    // Serao usado o algoritmo de busca sequencial que retornara o index do vetor caso o valor estiver no vetor ou -1 caso nao estiver
    for (int i = 0; i < p->tamanho; ++i)
    {
        if (num == *(p->valores + i))
        {
            return i;
        }
    }
    return -1;
}

int inserir(struct lista *p, int num, int mode)
{
    // O valor sera inserido ao final do vetor, caso houver espaco retorna 0, caso contrario retorna -1
    // Se o mode = 0, o num será inserido no final. Qualquer valor diferente para mode fará num ser inserido no começo
    // Se for um conjunto e ja houver o valor, retornará -2
	if (p->tamanho != p->cap)
	{
		if (p->type == 0) {
			if(buscar(p, num) != -1) {
				return -2;
			}
		}
		
		if (mode) {
			for(int i = p->tamanho; i > 0; i--) {
				*(p->valores + i) = *(p->valores + i - 1);
			}
			*(p->valores) = num;
			++(p->tamanho);
			return 0;
		} else {
			*(p->valores + p->tamanho) = num;
        	++(p->tamanho);
        	return 0;
		}
	}
	
    return -1;
}

int alterar(struct lista *p, int newNum, int oldNum)
{
    // Caso o numero que se deseja alterar estiver no vetor, sera retornado 0, caso contrario, -1 sera retornado
    // Caso hajam 2 numeros iguais, o primeiro numero a aparecer no vetor serao o alterado
    if (buscar(p, oldNum) != -1)
    {
        *(p->valores + buscar(p, oldNum)) = newNum;
        return 0;
    }

    return -1;
}

int excluir(struct lista *p, int num)
{
    // Caso o numero que se deseja excluir estiver no vetor, serao retornado 0, caso contrario, -1 sera retornado
    // Caso hajam 2 numeros iguais, o primeiro numero a aparecer no vetor serao o exclui­do
    if (buscar(p, num) != -1)
    {
        for (int i = buscar(p, num); i < p->tamanho; ++i)
        {
            int aux;
            aux = *(p->valores + i);
            *(p->valores + i) = *(p->valores + i + 1);
            *(p->valores + i + 1) = aux;
        }
        *(p->valores + p->tamanho - 1) = 0;
        --(p->tamanho);
        return 0;
    }

    return -1;
}

int ordenar(struct lista *p)
{
    // Serao usado o algoritmo de ordenacao bubble-sort para colocar em ordem crescente os valores do vetor, desprezando o lixo, caso houver
    // Se nao houver nenhum valor no vetor, a funcao retornara -1, caso o bubble-sort funcione, retornara 0

    if(p->tamanho != 0) {
        for (int i = 0; i < p->tamanho - 1; ++i)
        {
            for (int j = i + 1; j < p->tamanho; ++j)
            {
                if (*(p->valores + i) > *(p->valores + j))
                {
                    int aux;
                    aux = *(p->valores + i);
                    *(p->valores + i) = *(p->valores + j);
                    *(p->valores + j) = aux;
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
            printf("%d ", *(p->valores + i));
        }
        printf("\n");
        return 0;
    }
    return -1;
}
