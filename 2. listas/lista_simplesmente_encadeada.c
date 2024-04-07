#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_dados
{
	char matricula[30]; // chave
	char nome[255];
	char fone[15];
	float notas[2];
};

struct no
{
	struct s_dados dados;
	struct no *prox;
};

// Prototipos de funcoes:
void listar(struct no *lista);
struct no *buscar(struct no *lista, char matricula[]);
void alterar(struct no *lista, char matricula[], struct s_dados dados);
void inserir_final(struct no **lista, struct s_dados dados);
void inserir_comeco(struct no **lista, struct s_dados dados);
int remover(struct no **lista, char matricula[]);
int esvaziar(struct no **lista);
struct no *pega_no_anterior(struct no *lista, struct no *no);

int main()
{
	// Iniciando lista:
	struct no *lista = NULL;
	
	// Iniciando dados1:
	struct s_dados dados1;
	strcpy(dados1.nome, "Hiel Saraiva");
	strcpy(dados1.matricula, "202301");
	strcpy(dados1.fone, "85996852901");
	dados1.notas[0] = 7.8f;
    dados1.notas[1] = 9.6f;

    // Iniciando dados2:
    struct s_dados dados2;
    strcpy(dados2.nome, "Geni Saraiva");
    strcpy(dados2.matricula, "202302");
    strcpy(dados2.fone, "85988441830");
    dados2.notas[0] = 10.0f;
    dados2.notas[1] = 8.5f;

    // Iniciando dados3:
    struct s_dados dados3;
    strcpy(dados3.nome, "Rodrigo");
    strcpy(dados3.matricula, "202303");
    strcpy(dados3.fone, "85988442342");
    dados3.notas[0] = 1.0f;
    dados3.notas[1] = 3.5f;

    // Iniciando dados4:
    struct s_dados dados4;
    strcpy(dados4.nome, "Conrado");
    strcpy(dados4.matricula, "202304");
    strcpy(dados4.fone, "85988442233");
    dados4.notas[0] = 5.0f;
    dados4.notas[1] = 4.5f;

	// Testando funcoes:
    inserir_final(&lista, dados1);
    inserir_final(&lista, dados2);
    inserir_final(&lista, dados3);
    //alterar(lista, "202301", dados4);

    //listar(lista);
    //printf("\n%s\n", ((buscar(lista, "202301"))->dados).nome);

    //remover(&lista, "202303");
    esvaziar(&lista);
    listar(lista);

    inserir_final(&lista, dados1);
    inserir_final(&lista, dados2);
    inserir_final(&lista, dados3);
    listar(lista);
}

// Inserir no comeco(C):
void inserir_comeco(struct no **lista, struct s_dados dados)
{
	if (*lista == NULL)
	{
		// Se nao houver nenhum no:
		struct no *aux = malloc(sizeof(struct no));
		aux->dados = dados;
		aux->prox = NULL;
		*lista = aux;
	}
	else
	{
		// Se ja houver algum no:
		struct no *aux = malloc(sizeof(struct no));
		aux->dados = dados;
		aux->prox = *lista;
		*lista = aux;
	}
}

// Inserir no final(C):
void inserir_final(struct no **lista, struct s_dados dados)
{
	if (*lista == NULL)
	{
		// Se nao houver nenhum no:
		struct no *aux = malloc(sizeof(struct no));
		aux->dados = dados;
		aux->prox = NULL;
		*lista = aux;
	}
	else
	{
		// Se ja houver algum no:
		struct no *aux1 = malloc(sizeof(struct no));
		aux1->dados = dados;
		aux1->prox = NULL;

        // aux2 percorre a lista até o último dado:
        struct no *aux2 = *lista;
        while(aux2->prox != NULL)
        {
            aux2 = aux2->prox;
        }
        (aux2->prox) = aux1;
	}
}

// Inserir ordenando(TO DO):

// Remover(C):
int remover(struct no **lista, char matricula[])
{
    struct no *aux = buscar(*lista, matricula);
    if(*lista == NULL || aux == NULL) {
        return -1; // nao ha o que remover
    }

    if(aux == *lista) { // esta no comeco
        *lista = (*lista)->prox;
        free(aux);
    } else if(aux->prox == NULL) { // esta no fim
        struct no *ant = pega_no_anterior(*lista, aux);
        ant->prox = NULL;
        free(aux);
    } else { //esta no meio
        struct no *ant = pega_no_anterior(*lista, aux);
        ant->prox = aux->prox;
        free(aux);
    }
    return 0; // dado removido da lista
}

// Esvaziar lista(C):
int esvaziar(struct no **lista) {
    if(*lista == NULL) {
        return -1; // a lista ja esta vazia
    }

    while(*lista != NULL) {
        struct no *aux = *lista;
        (*lista) = (*lista)->prox;
        free(aux);
    }
    return 0; // lista esvaziada
}

// Alterar(C):
void alterar(struct no *lista, char matricula[], struct s_dados dados)
{
    struct no *no = buscar(lista, matricula);
    if (no)
    {
        no->dados = dados;
    }
}

// Buscar(C):
struct no *buscar(struct no *lista, char matricula[])
{
	struct no *aux = lista;
	while (aux != NULL && strcmp((aux->dados).matricula, matricula) != 0)
	{
		aux = aux->prox;
	}
	return aux;
}

// Listar todos(C):
void listar(struct no *lista)
{
	struct no *aux = lista;
	while (aux != NULL)
	{
		printf("\n%s\n", aux->dados.nome);
		printf("%s\n", aux->dados.matricula);
		printf("%s\n", aux->dados.fone);
		printf("%.2f %.2f\n", aux->dados.notas[0], aux->dados.notas[1]);
		aux = aux->prox;
	}
}

// Funcoes auxiliares(C):
struct no *pega_no_anterior(struct no *lista, struct no *no)
{
    struct no *aux = lista;
    while(aux != NULL && aux->prox != no) {
        aux = aux->prox;
    }
    return aux;
}