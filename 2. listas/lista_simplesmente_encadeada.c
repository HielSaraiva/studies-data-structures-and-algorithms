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

int main() {
	struct no *lista = NULL;
	lista = malloc(sizeof(struct no));
	struct s_dados dados1;
}

void inserir_comeco(struct no **lista, struct s_dados dados)
{
	if(*lista == NULL)
	{
		struct no *aux = malloc(sizeof(struct no));
		aux->dados = dados;
		aux->prox = NULL;
		*lista = aux;
	}
	else
	{
		// Inserir no in�cio:
		struct no *aux = malloc(sizeof(struct no));
		aux->dados = dados;
		aux->prox = *lista;
		*lista = aux;
	}
}

struct no *buscar(const struct no *lista, char matricula[])
{
	struct no *aux = lista;
	while(aux != NULL && aux->dados->matricula)
	{
		aux = aux->prox;
	}
}

void listar(const struct no *lista)
{
	struct no *aux = lista;
	while(aux != NULL)
	{
		printf("%d\n", aux->dados);
		aux = aux->prox;
	}
}

void ler(char *str)
{
    fpurge(stdin);
    fflush(stdin);
    gets(str);
}
