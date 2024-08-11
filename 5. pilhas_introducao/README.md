# Implementar essas operações em uma Pilha

- inserir()
- remover()
- espiar()
- listarTodos()

## Dados da questão

### Versão 1

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
