def busca_linear(lista, alvo):
    for i in range(len(lista)):
        if lista[i] == alvo:
            return i 
    return -1

numeros = [0, 3, 6, 7, 23, 48, 67]

print(busca_linear(numeros, 2))
print(busca_linear(numeros, 6))