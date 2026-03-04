// Hashmap:
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_ARRAY 10

// Estrutura das listas (Separate Chaining)
typedef struct no {
    int chave;
    int valor;
    struct no *prox;
} no;

// Estrutura do hashmap
typedef struct hashmap {
    no* tabela[TAMANHO_ARRAY];
} hashmap;

// Função de Hash simples
int hash(int chave) {
    return chave % TAMANHO_ARRAY;
}

// Inicialização
void init(hashmap *map) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        map->tabela[i] = NULL;
    }
}

// Put
void put(hashmap *map, int chave, int valor) {
    int indice = hash(chave);

    no *atual = map->tabela[indice];

    // Verifica se chave já existe
    while (atual != NULL) {
        if (atual->chave == chave) {
            atual->valor = valor; // Atualiza valor
            return;
        }
        atual = atual->prox;
    }

    // Cria novo nó
    no *novo = malloc(sizeof(no));
    novo->chave = chave;
    novo->valor = valor;

    // Insere no início da lista
    novo->prox = map->tabela[indice];
    map->tabela[indice] = novo;
}

// Get
int get(hashmap *map, int chave) {
    int indice = hash(chave);

    no *atual = map->tabela[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor;
        }
        atual = atual->prox;
    }

    return -1; // Não encontrado
}

// Delete
void delete(hashmap *map, int chave) {
    int indice = hash(chave);

    no *atual = map->tabela[indice];
    no *anterior = NULL;

    while (atual != NULL) {
        if (atual->chave == chave) {

            // Se for o primeiro nó
            if (anterior == NULL) {
                map->tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
}

// Printar
void printMap(hashmap *map) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Indice %d: ", i);

        no *atual = map->tabela[i];

        while (atual != NULL) {
            printf("(%d, %d) -> ", atual->chave, atual->valor);
            atual = atual->prox;
        }

        printf("NULL\n");
    }
}

int main() {
    hashmap map;
    hashmap *mapP = &map;

    init(mapP);

    put(mapP, 1, 100);
    put(mapP, 2, 200);
    put(mapP, 3, 300);
    put(mapP, 4, 300);
    put(mapP, 5, 300);
    put(mapP, 11, 300);

    printMap(mapP);

    printf("Pegando 25: %d\n", get(mapP, 25));

    delete(mapP, 25);

    printMap(mapP);

    return 0;
}