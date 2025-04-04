# Implementar essas operações em uma Fila

- inserir()
- remover()
- espiar()
- listarTodos()
- estaVazia()
- tamanho()
- limpar()

## Dados da questão

### Versão 1
``````java
#define capacidade 10

struct fila
{
    int fim;
    int cap;
    int vetor[capacidade];
};

void iniciar(struct fila *p)
{
    p->fim = -1;
    p->cap = capacidade;
}
``````