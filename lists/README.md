## Lista Encadeada Simples

É uma sequência de nós com objetos (dados) do mesmo tipo. Uma lista é definida por um ponteiro que aponta para o primeiro número de uma sequência. Se uma lista (ponteiro) estiver vazia, então esse ponteiro aponta para **NULL**. O campo prox da lista aponta para o próximo elemento na sequência ou para **NULL**, quando o nó é o último na sequência.

## Lista Duplamente Encadeada

É uma sequência de nós com objetos (dados) do mesmo tipo. Uma lista é definida por um ponteiro que aponta para o primeiro número de uma sequência. Se uma lista (ponteiro) estiver vazia, então esse ponteiro aponta para **NULL**. O campo prox da lista aponta para o próximo elemento na sequência ou para **NULL**, quando o nó é o último na sequência. O campo ant aponta para o elemento anterior na sequência ou para **NULL**, quando é o primeiro na sequência.

## Lista Circular Simples/Duplamente Encadeada

As listas mencionadas acima também podem ser implementadas de forma circular. Assim, quando ***simplesmente encadeadas***, seu último elemento terá o próximo ponteiro apontando para o primeiro, enquanto listas ***duplamente encadeadas*** terão a última com o próximo ponteiro apontando para o primeiro elemento, e a primeira com o ponteiro anterior apontando para o último.