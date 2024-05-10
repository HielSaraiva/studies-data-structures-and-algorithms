## Lista Simplesmente Encadeada:
É uma sequência de nós com objetos (dados) do mesmo tipo. Uma lista é definida por um ponteiro que aponta para o primeiro no de uma sequência. Se uma lista (ponteiro) está vazia, então esse ponteiro aponta para **NULL**. O campo prox da lista aponta para o próximo elemento da sequência ou para **NULL**, quando o nó é o último da sequência. 

## Lista Duplamente Encadeada:
É uma sequência de nós com objetos (dados) do mesmo tipo. Uma lista é definida por um ponteiro que aponta para o primeiro no de uma sequência. Se uma lista (ponteiro) está vazia, então esse ponteiro aponta para **NULL**. O campo prox da lista aponta para o próximo elemento da sequência ou para **NULL**, quando o nó é o último da sequência. O campo ant aponta para o elemento anterior da sequência ou para **NULL**, quando é o primeiro da sequência. 

## Lista Circular Simplesmente/Duplamente Encadeada:
As listas citadas acima podem também ser implementadas de forma circular. Assim, quando ***simplesmente encadeadas***, o último elemento delas terá o ponteiro próximo apontando para o primeiro, enquanto as listas ***duplamente encadeadas*** terão o último com o ponteiro próximo apontando para o primeiro elemento, e o primeiro com o ponteiro anterior apontando para o último.
