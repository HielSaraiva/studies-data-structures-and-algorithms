def merge(lista, inicio, meio, fim):
    esquerda = lista[inicio:meio+1]
    direita = lista[meio+1:fim+1]

    i = j = 0
    k = inicio

    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            lista[k] = esquerda[i]
            i += 1
        else:
            lista[k] = direita[j]
            j += 1
        k += 1

    while i < len(esquerda):
        lista[k] = esquerda[i]
        i += 1
        k += 1

    while j < len(direita):
        lista[k] = direita[j]
        j += 1
        k += 1

def merge_sort(lista, inicio, fim):
    if inicio < fim:
        meio = (inicio + fim) // 2
        merge_sort(lista, inicio, meio)
        merge_sort(lista, meio+1, fim)
        merge(lista, inicio, meio, fim)


numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

merge_sort(numeros, 0, len(numeros) - 1)
print(numeros)