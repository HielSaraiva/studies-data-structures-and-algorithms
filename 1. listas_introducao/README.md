# Implementar essas operações em uma Lista

* INSERIR
* ALTERAR
* EXCLUIR
* BUSCAR
* ORDENAR
* LISTAR-TODOS

## Dados da questão

### Versão 1

   ``````
   #define capacidade 10

   struct lista
   {
      int tamanho;
      int cap;
      int vetor[capacidade];
   };

   void iniciar(struct lista *p)
   {
      p->tamanho = 0;
      p->cap = capacidade;
   }
   ``````

##

### Versão 2

   ``````
   #define capacidade 10

   struct lista
   {
      int tamanho;
      int cap;
      int *valores;
   };

   void iniciar(struct lista *p)
   {
      p->tamanho = 0;
      p->cap = capacidade;
      p->valores = malloc(capacidade * sizeof(int));
   }
   ``````

##

### Versão 3

   ``````
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

   void iniciar(struct lista *p, int type)
   {
      p->tamanho = 0;
      p->cap = capacidade;
      p->type = type;
      all_null(p);
   }
   ``````
