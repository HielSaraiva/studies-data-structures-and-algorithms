# Implementar essas operações em uma Pilha

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

struct pilha
{
    int cap;
    int topo;
    int *dados;
};

void iniciar(struct fila *p)
{
    p->topo = -1;
    p->cap = capacidade;
    p->dados = malloc(cap * sizeof(int))
}
``````