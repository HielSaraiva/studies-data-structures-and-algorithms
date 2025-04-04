def partition(lista, inicio, fim):
    pivo = lista[fim]
    i = inicio - 1

    for j in range(inicio, fim):
        if lista[j] <= pivo:
            i += 1
            lista[i], lista[j] = lista[j], lista[i]
    
    lista[i + 1], lista[fim] = lista[fim], lista[i + 1]
    return i + 1

def quick_sort(lista, inicio, fim):
    if inicio < fim:
        part = partition(lista, inicio, fim)
        quick_sort(lista, inicio, part - 1)
        quick_sort(lista, part + 1, fim)
        
numeros = [5, 123, 1, 35, 26, 12, 34, 31, 0, 93, 12, 21]
print(numeros)

quick_sort(numeros, 0, len(numeros) - 1)
print(numeros)