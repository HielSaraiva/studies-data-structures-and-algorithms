cmake_minimum_required(VERSION 3.28)
project(data_structures C)

set(CMAKE_C_STANDARD 11)

add_executable(lista_v1 "1. listas_introducao/lista_v1.c")
add_executable(lista_v2 "1. listas_introducao/lista_v2.c")
add_executable(lista_v3 "1. listas_introducao/lista_v3.c")

add_executable(lista_circular_duplamente_encadeada "2. listas/lista_circular_duplamente_encadeada.c")
add_executable(lista_circular_simplesmente_encadeada "2. listas/lista_circular_simplesmente_encadeada.c")
add_executable(lista_duplamente_encadeada "2. listas/lista_duplamente_encadeada.c")
add_executable(lista_simplesmente_encadeada "2. listas/lista_simplesmente_encadeada.c")

add_executable(fila_v1 "3. filas_introducao/fila_v1.c")

add_executable(fila_duplamente_encadeada "4. filas/fila_duplamente_encadeada.c")
add_executable(fila_simplesmente_encadeada_v1 "4. filas/fila_simplesmente_encadeada_v1.c")
add_executable(fila_simplesmente_encadeada_v2 "4. filas/fila_simplesmente_encadeada_v2.c")

add_executable(pilha_v1 "5. pilhas_introducao/pilha_v1.c")

add_executable(pilha_duplamente_encadeada "6. pilhas/pilha_duplamente_encadeada.c")
add_executable(pilha_simplesmente_encadeada "6. pilhas/pilha_simplesmente_encadeada.c")

add_executable(arvore_binaria "7. arvores/arvore_binaria.c")
