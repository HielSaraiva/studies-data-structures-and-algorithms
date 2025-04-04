def busca_binaria(lista, alvo):
    esquerda, direita = 0, len(lista) - 1

    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        if lista[meio] == alvo:
            return meio
        elif lista[meio] < alvo:
            esquerda = meio + 1
        else:
            direita = meio - 1

    return -1

numeros = [0, 3, 6, 7, 23, 48, 67]

print(busca_binaria(numeros, 2))
print(busca_binaria(numeros, 6))