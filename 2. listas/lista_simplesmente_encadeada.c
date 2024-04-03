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
void listar(const struct no *lista);
struct no *buscar(const struct no *lista, char matricula[]);
// void alterar(struct no *lista, int valor, int novo_valor);
void inserir_final(struct no **lista, struct s_dados dados);
void inserir_comeco(struct no **lista, struct s_dados dados);

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


	// Testando funcoes:
    inserir_comeco(&lista, dados1);
	listar(lista);

	
}

// Inserir no comeco:
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

// Inserir no final:
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
		struct no *aux = malloc(sizeof(struct no));
		aux->dados = dados;
		aux->prox = NULL;
		(*lista)->prox = aux;
	}
}

// Inserir ordenando:

// Remover:

// Ordenar:

// Alterar:
//void alterar(struct no *lista, int valor, int novo_valor)
//{
//	struct no *no = buscar(lista, valor);
//	if (no)
//	{
//		no->valor = novo_valor;
//	}
//}

// Esvaziar lista:

// Buscar:
struct no *buscar(const struct no *lista, char matricula[])
{
	struct no *aux = lista;
	while (aux != NULL && aux->dados.matricula)
	{
		aux = aux->prox;
	}
}

// Listar todos:
void listar(const struct no *lista)
{
	struct no *aux = lista;
	while (aux->prox != NULL)
	{
		printf("\n%s\n", aux->dados.nome);
		printf("%s\n", aux->dados.matricula);
		printf("%s\n", aux->dados.fone);
		printf("%f %f\n", aux->dados.notas[0], aux->dados.notas[1]);
		aux = aux->prox;
	}
}