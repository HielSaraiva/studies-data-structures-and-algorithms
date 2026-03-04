cmake_minimum_required(VERSION 3.28)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

add_executable(lista_v1 "01. estruturas_de_dados/01. listas_introducao/lista_v1.c")
add_executable(lista_v2 "01. estruturas_de_dados/01. listas_introducao/lista_v2.c")
add_executable(lista_v3 "01. estruturas_de_dados/01. listas_introducao/lista_v3.c")

add_executable(lista_circular_duplamente_encadeada "01. estruturas_de_dados/02. listas/lista_circular_duplamente_encadeada.c")
add_executable(lista_circular_simplesmente_encadeada "01. estruturas_de_dados/02. listas/lista_circular_simplesmente_encadeada.c")
add_executable(lista_duplamente_encadeada "01. estruturas_de_dados/02. listas/lista_duplamente_encadeada.c")
add_executable(lista_simplesmente_encadeada "01. estruturas_de_dados/02. listas/lista_simplesmente_encadeada.c")

add_executable(fila_v1 "01. estruturas_de_dados/03. filas_introducao/fila_v1.c")

add_executable(fila_duplamente_encadeada "01. estruturas_de_dados/04. filas/fila_duplamente_encadeada.c")
add_executable(fila_simplesmente_encadeada_v1 "01. estruturas_de_dados/04. filas/fila_simplesmente_encadeada_v1.c")
add_executable(fila_simplesmente_encadeada_v2 "01. estruturas_de_dados/04. filas/fila_simplesmente_encadeada_v2.c")

add_executable(pilha_v1 "01. estruturas_de_dados/05. pilhas_introducao/pilha_v1.c")

add_executable(pilha_duplamente_encadeada "01. estruturas_de_dados/06. pilhas/pilha_duplamente_encadeada.c")
add_executable(pilha_simplesmente_encadeada "01. estruturas_de_dados/06. pilhas/pilha_simplesmente_encadeada.c")

add_executable(arvore_binaria "01. estruturas_de_dados/07. arvores/arvore_binaria_busca.c")

add_executable(hashmap "01. estruturas_de_dados/08. hashmap/hashmap.c")
